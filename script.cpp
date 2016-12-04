#include "StdAfx.h"


void ScriptInfo::script_main(void)
{
	/*****************窗口识别*****************/
	//static clock_t clock0,clock1,clock2,clock3,clock4,clock5,clock6,clock7;
	//clock0 = clock();
	kent_windows_instance->identity_windows(); 
	//clock1 = clock();
	//Kent_log_instance->write_log(_T("time-identity_windows:"),clock1 - clock0);
	/*****************窗口状态获取*****************/
	kent_windows_instance->kent_getwindowstate();
	//clock2 = clock();
	//Kent_log_instance->write_log(_T("time-kent_getwindowstate:"),clock2 - clock1);
	/*****************绑定窗口*****************/
	if(!kent_windows_instance->kent_bind_window()){
		CString tmp;
		tmp.Format(_T("后台绑定失败错误码:%d。窗口绑定失败，请关闭uac以及360金山等安全软件，用管理员权限运行！"),kent_windows_instance->error_code);
		MessageBox(NULL,tmp,_T("窗口绑定失败"),MB_OK);
		is_run=false;//绑定失败
	}
	//clock3 = clock();
	//Kent_log_instance->write_log(_T("time-kent_bind_window:"),clock3 - clock2);
	if(rand()%10 < 5){
		kent_windows_instance->collapse_detect();//崩溃检测
	}
	//clock4 = clock();
	//Kent_log_instance->write_log(_T("time-collapse_detect:"),clock4 - clock3);
	kent_windows_instance->reconnect_protect();//重连保护
	//clock5 = clock();
	//Kent_log_instance->write_log(_T("time-reconnect_protect:"),clock5 - clock4);
	kent_windows_instance->gamestage_ctrl();
	//clock6 = clock();
	//Kent_log_instance->write_log(_T("time-gamestage_ctrl:"),clock6 - clock5);
	switch(kent_windows_instance->kent_stage_now)
	{
	case Kent_waiting:		Sleep(3000);break;
	case Kent_matching:		kent_windows_instance->Kent_do_start();break;
	case Kent_selceting:	kent_windows_instance->Kent_do_select();break;
	case Kent_loading:		Sleep(6000);break;
	case Kent_ingame:
		if(kent_windows_instance->kent_stage_last != kent_windows_instance->kent_stage_now){
			Sleep(5000);
			kent_windows_instance->game_state=Kent_game_init;//每一局游戏初始化
			kent_windows_instance->game_data_init();//参数初始化
			kent_windows_instance->do_first_add = false;
		}else{
			if(TRUE == Kent_log_instance->is_common_match_mode){//召唤师峡谷
				kent_windows_instance->game_do_normal();
			}else if(TRUE == Kent_log_instance->is_distort_match_mode){//扭曲丛林
				kent_windows_instance->game_do_distort();
			}else if(TRUE == Kent_log_instance->is_colosseum_match_mode){//大乱斗
				kent_windows_instance->game_do_colosseum();
			}else{//统治战场
				kent_windows_instance->game_detect();//游戏监控
				switch(kent_windows_instance->game_state)
				{
				case Kent_game_init:	kent_windows_instance->game_init();//死亡后初始化
					kent_windows_instance->game_state=Kent_game_occupy;break;
				case Kent_game_occupy:	
					if(occupy_mode_standby == Kent_log_instance->kent_hero_occupy_mode){
						kent_windows_instance->game_tour_standby();
					}else{
						kent_windows_instance->game_tour_occupy();
					}
					break;
				case Kent_game_attack:	kent_windows_instance->game_attack();break;
				case Kent_game_die:		kent_windows_instance->game_die();break;
				}
			}
			kent_windows_instance->game_state_last=kent_windows_instance->game_state;
		}
		break;
	case kent_overing:
		if(!kent_windows_instance->Kent_do_gameover()){//需要结束
			this->is_run = false;
		}
		break;
	}
	if(kent_windows_instance->kent_stage_last != kent_windows_instance->kent_stage_now){
		kent_windows_instance->kent_stage_last = kent_windows_instance->kent_stage_now;
		switch (kent_windows_instance->kent_stage_now)
		{
		case Kent_waiting:
			kent_log.info("Kent_waiting");
			break;
		case Kent_matching:
			kent_log.info("Kent_matching");
			break;
		case Kent_selceting:
			kent_log.info("Kent_selceting");
			break;
		case Kent_loading:
			kent_log.info("Kent_loading");
			break;
		case Kent_ingame:
			kent_log.info("Kent_ingame");
			break;
		case kent_overing:
			kent_log.info("kent_overing");
			break;
		default:
			break;
		}
	}
	
	if(Kent_ingame != kent_windows_instance->kent_stage_now){
		kent_windows_instance->game_state=Kent_game_none;
	}
	//clock7 = clock();
	//Kent_log_instance->write_log(_T("time-action:"),clock7 - clock6);
}
/*****************启动线程*****************/
bool WINAPI EntryScript(LPVOID param)
{
	ScriptInfo * Kent_Script = (ScriptInfo *)param;
	Kent_Script->kent_windows_instance->dm=Kent_Script->dm;

	if(!Kent_Script->Kent_SysCheck()){//系统不符合要求，初始化失败
		Kent_Script->is_run = false;
		return false;
	}
	if(!Kent_Script->kent_windows_instance->kent_windows_init()){//没有发现游戏大厅，初始化失败
		Kent_Script->is_run = false;
		return false;
	}
	/*****************创建kent游戏控制对象*****************/
	// 开始脚本循环
	while (1){
		// 检测脚本是否要结束
		if (Kent_Script->is_run == false)
			break;
		Kent_Script->script_main();
	}

	if(Kent_Script->kent_windows_instance->Hwnd_connect){
		Kent_Script->dm->SetWindowState(Kent_Script->kent_windows_instance->Hwnd_connect,9);//取消置顶
	}
	if(Kent_Script->kent_windows_instance->Hwnd_game){
		Kent_Script->dm->SetWindowState(Kent_Script->kent_windows_instance->Hwnd_game,9);//取消置顶
	}
	if(Kent_Script->kent_windows_instance->Hwnd_login){
		Kent_Script->dm->SetWindowState(Kent_Script->kent_windows_instance->Hwnd_login,9);//取消置顶
	}
	Kent_Script->dm->UnBindWindow();
	return true;
}
ScriptInfo::ScriptInfo(void)
{
	is_dmguard=false;
	is_run=false;
	thread_handle=NULL;
	kent_windows_instance=new kent_windows();
}
ScriptInfo::~ScriptInfo(void)
{
	delete kent_windows_instance;
}
bool ScriptInfo::StartScript(void)
{
	if(true == is_run)
	{
		return true;
	}
	is_run=true;
	thread_handle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)EntryScript,this,0,NULL);
	Sleep(2000);
	if(thread_handle == INVALID_HANDLE_VALUE)
	{
		return false;
	}
	return true;
}
bool ScriptInfo::StopScript(void)
{
	is_run = false;
	if(NULL==thread_handle)
	{
		return true;
	}
	// 等待最多3秒,如果超时,就强制结束线程.危险.(有资源泄漏)
	if (WAIT_OBJECT_0 != WaitForSingleObject(thread_handle,1000))
	{
		// 先解绑窗口. 避免窗口崩溃
		dm->UnBindWindow();
		TerminateThread(thread_handle,0);
	}

	if(kent_windows_instance->Hwnd_connect){
		dm->SetWindowState(kent_windows_instance->Hwnd_connect,9);//取消置顶
	}
	if(kent_windows_instance->Hwnd_game){
		dm->SetWindowState(kent_windows_instance->Hwnd_game,9);//取消置顶
	}
	if(kent_windows_instance->Hwnd_login){
		dm->SetWindowState(kent_windows_instance->Hwnd_login,9);//取消置顶
	}
	
	dm->UnBindWindow();
	CloseHandle(thread_handle);
	thread_handle=NULL;
	return true;
}
bool ScriptInfo::Kent_SysCheck(void)
{
	long Kent_ScreenWidth=dm->GetScreenWidth();
	long Kent_ScreenHeight=dm->GetScreenHeight();
	if(Kent_ScreenHeight<768 || Kent_ScreenWidth<1280)
	{
		MessageBox(NULL,_T("请调整系统分辨率，不要小于1280*768！"),_T("系统分辨率太小"),MB_OK);
		return false;
	}
	if(32!=dm->GetScreenDepth())
	{
		dm->SetScreen(Kent_ScreenWidth,Kent_ScreenHeight,32);
	}
	return true;
}
void ScriptInfo::open_dmguard()
{
#ifdef _kent_background_
	if(!is_dmguard)
	{
		Kent_log_instance->write_log(_T("np"),dm->DmGuard(1,_T("np")));
		if(0 == dm->Is64Bit()){
			Kent_log_instance->write_log(_T("np2"),dm->DmGuard(1,_T("np2")));
			Kent_log_instance->write_log(_T("display"),dm->DmGuard(1,_T("display")));
			Kent_log_instance->write_log(_T("block"),dm->DmGuard(1,_T("block")));
			Kent_log_instance->write_log(_T("b2"),dm->DmGuard(1,_T("b2")));
		}
		is_dmguard=true;
	}
#endif
}

