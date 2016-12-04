//用来判定窗口，窗口初始化，绑定窗口操作
#include "stdafx.h"

//构造函数
kent_windows::kent_windows()
{
	error_code = 0;
	dm=NULL;
	Hwnd_login=0;
	Hwnd_game=0;
	Hwnd_connect=0;
	iswindows=Kent_unavailable;
	kent_stage_now=Kent_waiting;
	kent_stage_last=Kent_waiting;
	kent_gamepath=_T("");
	bind_fail_cnt=0;
	isingame_num=false;
	isstart_num = Kent_start_waiting;
	isselect_num=false;
	isloading_num=false;
	isstart_num=Kent_start_waiting;
	isgameover_num=gameover_none;
	win_num=0;
	lose_num=0;
	kent_home = kent_home_left;
	kent_normal_started = false;
	kent_distort_started = false;
	if(m_IsSmallWindow){
		addr_skill.push_back(CPoint(420, 696)),addr_skill.push_back(CPoint(463, 698)),addr_skill.push_back(CPoint(505, 699)),addr_skill.push_back(CPoint(548, 698)),addr_skill.push_back(CPoint(597, 698)),addr_skill.push_back(CPoint(636, 700));
		tour1.push_back(CPoint(926, 615)),tour1.push_back(CPoint(866, 658)),tour1.push_back(CPoint(891, 729)),tour1.push_back(CPoint(961, 730)),tour1.push_back(CPoint(987, 658));
		tour2.push_back(CPoint(530,400)),tour2.push_back(CPoint(530,400)),tour2.push_back(CPoint(530,400)),tour2.push_back(CPoint(530,400)),tour2.push_back(CPoint(530,400));
		tour_stay.push_back(CPoint(926, 602)),tour_stay.push_back(CPoint(846, 650)),tour_stay.push_back(CPoint(877, 742)),tour_stay.push_back(CPoint(973, 744)),tour_stay.push_back(CPoint(1004, 651));
	}else{
		addr_skill.push_back(CPoint(555,655)),addr_skill.push_back(CPoint(595,655)),addr_skill.push_back(CPoint(640,655)),addr_skill.push_back(CPoint(683,655)),addr_skill.push_back(CPoint(720,658)),addr_skill.push_back(CPoint(757,658));
		tour1.push_back(CPoint(1189,577)),tour1.push_back(CPoint(1133,618)),tour1.push_back(CPoint(1155,686)),tour1.push_back(CPoint(1222,686)),tour1.push_back(CPoint(1245,618));
		tour2.push_back(CPoint(605,375)),tour2.push_back(CPoint(605,360)),tour2.push_back(CPoint(645,305)),tour2.push_back(CPoint(605,305)),tour2.push_back(CPoint(625,360));
		tour_stay.push_back(CPoint(1187,562)),tour_stay.push_back(CPoint(1112,610)),tour_stay.push_back(CPoint(1146,695)),tour_stay.push_back(CPoint(1229,695)),tour_stay.push_back(CPoint(1263,610));
	}

	location.x=500;location.y=500;location_last.x=500;location_last.y=500;
	danger1.x=0,danger1.y=0,danger2.x=0,danger2.y=0;
	attack.push_back(_T("q")),attack.push_back(_T("w")),attack.push_back(_T("e")),attack.push_back(_T("r"));
	add_order.push_back(_T("r")),add_order.push_back(_T("q")),add_order.push_back(_T("w")),add_order.push_back(_T("e"));
	mouse_shapes_store_normal.push_back(_T("7010f54a")),mouse_shapes_store_normal.push_back(_T("60e1d975")),mouse_shapes_store_normal.push_back(_T("7010f54a"));
	mouse_shapes_store_needoccupy.push_back(_T("4f308614"));
	mouse_shapes_store_attack.push_back(_T("15075583")),mouse_shapes_store_attack.push_back(_T("106ab3d4")),mouse_shapes_store_attack.push_back(_T("45e14ed4"));
	mouse_shapes_store_occupied.push_back(_T("1c532bbf")),mouse_shapes_store_occupied.push_back(_T("420d8df5")),mouse_shapes_store_occupied.push_back(_T("7ba1911a"));
	occupy=false;
	target=0;
	stay_which_tour=0;
	game_state=Kent_game_none;
	game_state_last=Kent_game_none;
	m_IsSmallWindow = false;
	do_first_add = false;
	script_time =CTime::GetCurrentTime();

	
	Kent_game_inuse_time = CTime::GetCurrentTime();//计时
	Kent_login_inuse_time = CTime::GetCurrentTime();//计时
	Kent_connect_inuse_time = CTime::GetCurrentTime();//计时
}
kent_windows::~kent_windows()
{
	//if(NULL!=dm)
	//{
	//	if(dm->IsFileExist(kent_gamepath+_T("\\Config\\Game.kent")))
	//	{
	//		dm->CopyFile(kent_gamepath+_T("\\Config\\Game.kent"),kent_gamepath+_T("\\Config\\Game.cfg"),1);
	//		dm->DeleteFile(kent_gamepath+_T("\\Config\\Game.kent"));
	//	}
	//	if(dm->IsFileExist(kent_gamepath+_T("\\Config\\input.kent")))
	//	{
	//		dm->CopyFile(kent_gamepath+_T("\\Config\\input.kent"),kent_gamepath+_T("\\Config\\input.ini"),1);
	//		dm->DeleteFile(kent_gamepath+_T("\\Config\\input.kent"));
	//	}
	//}
}
//初始化
bool kent_windows::kent_windows_init(void)
{
	Hwnd_login=0;
	Hwnd_game=0;
	Hwnd_connect=0;
	iswindows=Kent_unavailable;
	kent_stage_now=Kent_waiting;
	kent_stage_last=Kent_waiting;
	kent_gamepath=_T("");
	bind_fail_cnt=0;
	isingame_num=false;
	isstart_num = Kent_start_waiting;
	isselect_num=false;
	isloading_num=false;
	isstart_num=Kent_start_waiting;
	isgameover_num=gameover_none;
	win_num=0;
	lose_num=0;
	location.x=600;location.y=500;location_last.x=600;location_last.y=500;
	danger1.x=0,danger1.y=0,danger2.x=0,danger2.y=0;
	occupy=false;
	target=0;
	stay_which_tour=0;
	m_IsSmallWindow = false;
	game_state=Kent_game_none;
	game_state_last=Kent_game_none;
	do_first_add = false;
	//上面是简单的重复初始化
	identity_windows();
	kent_gamepath = Kent_log_instance->kent_readini(_T("game_path"));
#ifdef kent_han
	if(0 == kent_gamepath.GetLength() ||!dm->IsFileExist(kent_gamepath+_T("\\lol.launcher.exe"))){
#else
	if(0 == kent_gamepath.GetLength() ||!dm->IsFileExist(kent_gamepath+_T("\\TCLS\\Client.exe"))){
#endif
		if(0!=Hwnd_login)
		{
			kent_gamepath=dm->GetWindowProcessPath(Hwnd_login);
		}else if(0!=Hwnd_game)
		{
			kent_gamepath=dm->GetWindowProcessPath(Hwnd_game);
		}else if(0!=Hwnd_connect)
		{
			kent_gamepath=dm->GetWindowProcessPath(Hwnd_connect);
		}else
		{
			MessageBox(NULL,_T("请打开游戏大厅再打开辅助"),_T("没有发现游戏大厅"),MB_OK);//绑定失败
			return false;
		}
		kent_gamepath=kent_gamepath.Left(kent_gamepath.ReverseFind(_T('\\')));
		kent_gamepath=kent_gamepath.Left(kent_gamepath.ReverseFind(_T('\\')));
#ifdef kent_han
		kent_gamepath=kent_gamepath.Left(kent_gamepath.ReverseFind(_T('\\')));
		kent_gamepath=kent_gamepath.Left(kent_gamepath.ReverseFind(_T('\\')));
		kent_gamepath=kent_gamepath.Left(kent_gamepath.ReverseFind(_T('\\')));
		kent_gamepath=kent_gamepath.Left(kent_gamepath.ReverseFind(_T('\\')));
		kent_gamepath=kent_gamepath.Left(kent_gamepath.ReverseFind(_T('\\')));
		Kent_log_instance->kent_writeini(_T("game_path"),kent_gamepath);
#else
		Kent_log_instance->kent_writeini(_T("game_path"),kent_gamepath);
		kent_gamepath+=_T("\\Game");
#endif
	}else{
#ifndef kent_han
		kent_gamepath+=_T("\\Game");
#endif
		if(0 == Hwnd_login &&0 == Hwnd_game &&0 == Hwnd_connect){
			restart_whole_game();//启动英雄联盟
		}
	}
	
	Kent_log_instance->write_log(_T("kent_gamepath路径:"),kent_gamepath.GetString());
	/*****************游戏文件的修改*****************/

	Sleep(50);
	if(1 == Kent_log_instance->kent_studio_can_connect){
		CopyFile(Kent_log_instance->kent_res_path+_T("\\hosts"),_T("C:\\Windows\\System32\\drivers\\etc\\hosts"),1);
	}
	Sleep(50);
	CopyFile(Kent_log_instance->kent_res_path+_T("\\hud1024x768.ini"),kent_gamepath+_T("\\DATA\\Menu\\HUD\\hud1024x768.ini"),1);
	CopyFile(Kent_log_instance->kent_res_path+_T("\\hud1280x720.ini"),kent_gamepath+_T("\\DATA\\Menu\\HUD\\hud1280x720.ini"),1);
	Sleep(50);
	CopyFile(Kent_log_instance->kent_res_path+_T("\\Game.cfg"),kent_gamepath+_T("\\Config\\Game.cfg"),1);
	Sleep(50);
	CopyFile(Kent_log_instance->kent_res_path+_T("\\input.ini"),kent_gamepath+_T("\\Config\\input.ini"),1);
	
	WritePrivateProfileString(_T("HUD"),_T("ItemShopPrevY"),_T("0"),kent_gamepath+_T("\\Config\\Game.cfg"));
	WritePrivateProfileString(_T("HUD"),_T("ItemShopPrevX"),_T("0"),kent_gamepath+_T("\\Config\\Game.cfg"));
	WritePrivateProfileString(_T("General"),_T("WindowMode"),_T("2"),kent_gamepath+_T("\\Config\\Game.cfg"));//窗口模式
	WritePrivateProfileString(_T("General"),_T("ItemShopPrevY"),_T("0"),kent_gamepath+_T("\\Config\\Game.cfg"));
	WritePrivateProfileString(_T("General"),_T("ItemShopPrevX"),_T("0"),kent_gamepath+_T("\\Config\\Game.cfg"));
	if(!kent_gamepath.IsEmpty()){//非空
		if(1 == Kent_log_instance->kent_game_resolution){//1024*768
			WritePrivateProfileString(_T("General"),_T("Height"),_T("768"),kent_gamepath+_T("\\Config\\Game.cfg"));
			WritePrivateProfileString(_T("General"),_T("Width"),_T("1024"),kent_gamepath+_T("\\Config\\Game.cfg"));
			WritePrivateProfileString(_T("HUD"),_T("ItemShopPrevResizeHeight"),_T("768"),kent_gamepath+_T("\\Config\\Game.cfg"));
			WritePrivateProfileString(_T("HUD"),_T("ItemShopPrevResizeWidth"),_T("1024"),kent_gamepath+_T("\\Config\\Game.cfg"));
			WritePrivateProfileString(_T("HUD"),_T("ItemShopResizeHeight"),_T("0"),kent_gamepath+_T("\\Config\\Game.cfg"));
			WritePrivateProfileString(_T("HUD"),_T("ItemShopResizeWidth"),_T("0"),kent_gamepath+_T("\\Config\\Game.cfg"));
		}else{
			WritePrivateProfileString(_T("General"),_T("Height"),_T("720"),kent_gamepath+_T("\\Config\\Game.cfg"));
			WritePrivateProfileString(_T("General"),_T("Width"),_T("1280"),kent_gamepath+_T("\\Config\\Game.cfg"));
			WritePrivateProfileString(_T("HUD"),_T("ItemShopPrevResizeHeight"),_T("720"),kent_gamepath+_T("\\Config\\Game.cfg"));
			WritePrivateProfileString(_T("HUD"),_T("ItemShopPrevResizeWidth"),_T("1280"),kent_gamepath+_T("\\Config\\Game.cfg"));
			WritePrivateProfileString(_T("HUD"),_T("ItemShopResizeHeight"),_T("36"),kent_gamepath+_T("\\Config\\Game.cfg"));
			WritePrivateProfileString(_T("HUD"),_T("ItemShopResizeWidth"),_T("250"),kent_gamepath+_T("\\Config\\Game.cfg"));
		}
	}

	script_time =CTime::GetCurrentTime();
	start_time =CTime::GetCurrentTime();
	
	Kent_game_inuse_time = CTime::GetCurrentTime();//计时
	Kent_login_inuse_time = CTime::GetCurrentTime();//计时
	Kent_connect_inuse_time = CTime::GetCurrentTime();//计时
	return true;
}
//识别窗口
bool kent_windows::identity_windows(void)
{
#ifndef kent_han
	if(rand()%10 < 3){
		kent_TerminateProcess(_T("BsSndRpt.exe"));
		kent_TerminateProcess(_T("QTalk.exe"));
		kent_TerminateProcess(_T("CrossProxy.exe"));
	}
#endif

	if(!dm->GetWindowState(Hwnd_game,0)){
		Hwnd_game=dm->FindWindow(_T(""),_T("League of Legends (TM) Client"));
		if(0==Hwnd_game)
		{
			Hwnd_game=dm->FindWindow(_T("RiotWindowClass"),_T(""));
		}
	}else{
		return true;
	}

	if(!dm->GetWindowState(Hwnd_login,0)){
#ifdef kent_han
		Hwnd_login=dm->FindWindow(_T(""),_T("PVP.Net 클라이언트"));
#else
		Hwnd_login=dm->FindWindow(_T(""),_T("PVP.net 客户端"));
#endif
		if(0==Hwnd_login)
		{
			Hwnd_login=dm->FindWindow(_T("ApolloRuntimeContentWindow"),_T(""));
		}
	}

#ifdef kent_han
	if(!dm->GetWindowState(Hwnd_connect,0)){
		Hwnd_connect=dm->FindWindow(_T(""),_T("LoL Patcher"));
		if(0==Hwnd_connect)
		{
			Hwnd_connect=dm->FindWindow(_T("LOLPATCHER"),_T(""));
		}
	}
#else
	if(!dm->GetWindowState(Hwnd_connect,0)){
		Hwnd_connect=dm->FindWindow(_T(""),_T("英雄联盟登录程序"));
	}
#endif

	return true;
}
//判定当前操作窗口以及状态
bool kent_windows::kent_getwindowstate(void)
{
	static d_kent_windowstate iswindows_old = Kent_unavailable;
	if(0!=Hwnd_game){//对游戏窗口进行判定
		VARIANT x1,x2,y1,y2;
		int w,h;
		dm->GetWindowRect(Hwnd_game,& x1,& y1,& x2,& y2);
		w=abs(x1.intVal-x2.intVal);
		h=abs(y1.intVal-y2.intVal);
		if(w<=1300 && w>=1260 && h<=740 && h>=700){//game判定是否绑定
			m_IsSmallWindow = false;
			if(iswindows!=Kent_game_inuse){iswindows=Kent_game_waiting;}
		}else if(w<=1050 && w>=1000 && h<=780 && h>=750){
			m_IsSmallWindow = true;//小窗口
			if(iswindows!=Kent_game_inuse){iswindows=Kent_game_waiting;}
		}else{//game不可用状态
			iswindows=Kent_game_unavailable;
		}
	}else if(0 != Hwnd_login){//对大厅窗口进行判定
		VARIANT x1,x2,y1,y2;
		int w,h;
		dm->GetWindowRect(Hwnd_login,& x1,& y1,& x2,& y2);
		w=abs(x1.intVal-x2.intVal);
		h=abs(y1.intVal-y2.intVal);
		if(w==1152 && h==720){//login判定是否绑定
		if(iswindows!=Kent_login_inuse){iswindows=Kent_login_waiting;}
		}else if(w>160 || h>27){iswindows=Kent_login_needresize;}//login需要调整大小
		else{iswindows=Kent_login_unavailable;}//login不可用状态

		if(0 != Hwnd_connect){kent_TerminateProcess(_T("Client.exe"));}//关闭登录窗口
	}else if(0  != Hwnd_connect){//对登陆窗口进行判定
		VARIANT x1,x2,y1,y2;
		int w,h;
		dm->GetWindowRect(Hwnd_connect,& x1,& y1,& x2,& y2);
		w=abs(x1.intVal-x2.intVal);
		h=abs(y1.intVal-y2.intVal);
		if(w==1280 && h==768){//登陆判定是否绑定
			if(iswindows!=Kent_connect_inuse){iswindows=Kent_connect_waiting;}
		}else{//需要调整大小后绑定
			iswindows=Kent_connect_needresize;
		}
	}else{//不可用状态
		iswindows=Kent_unavailable;
	}

	if(iswindows != iswindows_old){
		iswindows_old = iswindows;
		switch (iswindows)
		{
		case Kent_unavailable:
			kent_log.info("Change to Kent_unavailable");
			break;
		case Kent_login_waiting:
			kent_log.info("Change to Kent_login_waiting");
			break;
		case Kent_login_inuse:
			kent_log.info("Change to Kent_login_inuse");
			break;
		case Kent_login_unavailable:
			kent_log.info("Change to Kent_login_unavailable");
			break;
		case Kent_login_needresize:
			kent_log.info("Change to Kent_login_needresize");
			break;
		case Kent_game_waiting:
			kent_log.info("Change to Kent_game_waiting");
			break;
		case Kent_game_inuse:
			kent_log.info("Change to Kent_game_inuse");
			break;
		case Kent_game_unavailable:
			kent_log.info("Change to Kent_game_unavailable");
			break;
		case Kent_connect_waiting:
			kent_log.info("Change to Kent_connect_waiting");
			break;
		case Kent_connect_inuse:
			kent_log.info("Change to Kent_connect_inuse");
			break;
		case Kent_connect_needresize:
			kent_log.info("Change to Kent_connect_needresize");
			break;
		default:
			break;
		}
	}
	return true;
}//绑定窗口操作
bool kent_windows::kent_bind_window(void)
{
	//调整大小
	if(Kent_login_needresize==iswindows)//需要调整大小
	{
		dm->SetWindowSize(Hwnd_login,1152,720);
		Sleep(2000);
		dm->SetWindowState(Hwnd_login,2);//最小化
		Sleep(2000);
		dm->SetWindowState(Hwnd_login,5);//恢复
		Sleep(2000);
		iswindows=Kent_login_waiting;
	}else if(Kent_connect_needresize==iswindows)//需要调整大小
	{
		dm->SetWindowSize(Hwnd_connect,1280,768);
		Sleep(2000);
		dm->SetWindowState(Hwnd_connect,2);//最小化
		Sleep(2000);
		dm->SetWindowState(Hwnd_connect,5);//恢复
		Sleep(2000);
		iswindows=Kent_connect_waiting;
	}
	if(Hwnd_game){//最小化其他窗口
		dm->SetWindowState(Hwnd_login,2);
		dm->SetWindowState(Hwnd_connect,2);
	}
#if defined _kent_foreground_
	Kent_log_instance->kent_hook_mode = hook_mode_forground;//设置为前台模式
#endif
	if(hook_mode_forground == Kent_log_instance->kent_hook_mode)
	{
	/******************前台挂机模式******************/
		if(Kent_login_waiting==iswindows){//login绑定
			dm->UnBindWindow();
			Sleep(500);
			dm->SetWindowState(Hwnd_login,1);//激活
			Sleep(500);
			dm->SetWindowState(Hwnd_login,8);//置顶
			bind_fail_cnt=0;
			Sleep(1000);
			dm->BindWindow(Hwnd_login,_T("normal"),_T("normal"),_T("normal"),0);
			Sleep(1000);
			iswindows=Kent_login_inuse;
		}else if(Kent_connect_waiting==iswindows){//connect绑定
			dm->UnBindWindow();
			Sleep(500);
			dm->SetWindowState(Hwnd_connect,1);//激活
			Sleep(500);
			dm->SetWindowState(Hwnd_connect,8);//置顶
			bind_fail_cnt=0;
			Sleep(1000);
			dm->BindWindow(Hwnd_connect,_T("normal"),_T("normal"),_T("normal"),0);
			Sleep(1000);
			iswindows=Kent_connect_inuse;
		}else if(Kent_game_waiting==iswindows){//game绑定
			dm->UnBindWindow();
			Sleep(500);
			dm->SetWindowState(Hwnd_game,1);//激活
			Sleep(1500);
			dm->SetWindowState(Hwnd_game,8);//置顶
			Sleep(1000);
			dm->BindWindow(Hwnd_game,_T("normal"),_T("normal"),_T("normal"),0);
			Sleep(1000);
			//dm->DownCpu(30);
			bind_fail_cnt=0;
			iswindows=Kent_game_inuse;
		}
	}else{
	/******************后台挂机模式******************/
		long dm_ret;
		switch(iswindows)
		{
		case Kent_login_waiting:
			dm->UnBindWindow();
			dm->ForceUnBindWindow(Hwnd_login);
			Sleep(2000);
			if(bind_mode_AI == Kent_log_instance->kent_bind_mode)
			{
				/******************智能设置******************/
				dm_ret=dm->BindWindow(Hwnd_login,_T("gdi2"),_T("dx"),_T("dx"), 1);//绑定login窗口
				error_code = dm->GetLastError();//后台绑定错误码
				if(0==dm_ret){//没有绑定成功
					dm_ret = dm->UnBindWindow();
					bind_fail_cnt+=1;
					iswindows=Kent_login_waiting;
					Kent_log_instance->write_log(_T("Hwnd_login后台绑定失败错误码:"),error_code);
					dm_ret = dm->UnBindWindow();
					dm->ForceUnBindWindow(Hwnd_login);
					dm->MoveWindow(Hwnd_login,-20,0);
					Sleep(500);
					dm_ret=dm->BindWindow(Hwnd_login,_T("dx2"),_T("dx"),_T("dx"), 1);//绑定login窗口
					error_code = dm->GetLastError();//后台绑定错误码
					if(0==dm_ret){//绑定失败
						dm_ret = dm->UnBindWindow();
						dm->ForceUnBindWindow(Hwnd_login);
						bind_fail_cnt+=1;
						iswindows=Kent_login_waiting;
						Kent_log_instance->write_log(_T("Hwnd_login后台绑定失败错误码:"),error_code);
					}else{
						iswindows=Kent_login_inuse;
						bind_fail_cnt=0;
						dm_ret = dm->SetWindowState(Hwnd_login,9);
						dm_ret = dm->SetWindowState(Hwnd_login,7);
						Sleep(500);
					}
				}else{
					//验证是否成功
					CString is_success_color = dm->GetAveRGB(30,30,1000,700);
					if(_T("000000") == is_success_color){//绑定失败，需要重新绑定
						dm_ret = dm->UnBindWindow();
						dm->ForceUnBindWindow(Hwnd_login);
						dm->MoveWindow(Hwnd_login,-20,0);
						Sleep(500);
						dm_ret=dm->BindWindow(Hwnd_login,_T("dx2"),_T("dx"),_T("dx"), 1);//绑定login窗口
						error_code = dm->GetLastError();//后台绑定错误码
						if(0==dm_ret){//绑定失败
							dm_ret = dm->UnBindWindow();
							dm->ForceUnBindWindow(Hwnd_login);
							bind_fail_cnt+=1;
							iswindows=Kent_login_waiting;
							Kent_log_instance->write_log(_T("Hwnd_login后台绑定失败错误码:"),error_code);
						}else{
							iswindows=Kent_login_inuse;
							bind_fail_cnt=0;
							dm_ret = dm->SetWindowState(Hwnd_login,9);
							dm_ret = dm->SetWindowState(Hwnd_login,7);
							Sleep(500);
						}
					}else{//确认绑定成功
						bind_fail_cnt=0;
						iswindows=Kent_login_inuse;
						dm_ret = dm->SetWindowState(Hwnd_login,9);
						dm_ret = dm->SetWindowState(Hwnd_login,7);
						Sleep(500);
					}
				}
			}else if(bind_mode_one == Kent_log_instance->kent_bind_mode){
				/******************绑定模式1******************/
				dm_ret=dm->BindWindow(Hwnd_login,_T("gdi2"),_T("dx"),_T("dx"), 1);//绑定login窗口
				error_code = dm->GetLastError();//后台绑定错误码
				if(0==dm_ret){//没有绑定成功
					dm_ret = dm->UnBindWindow();
					bind_fail_cnt+=1;
					iswindows=Kent_login_waiting;
					Kent_log_instance->write_log(_T("Hwnd_login后台绑定失败错误码:"),error_code);
				}else{//绑定成功
					bind_fail_cnt=0;
					iswindows=Kent_login_inuse;
					dm_ret = dm->SetWindowState(Hwnd_login,9);
					dm_ret = dm->SetWindowState(Hwnd_login,7);
					Sleep(500);
				}
			}else{
				/******************绑定模式2******************/
				dm->MoveWindow(Hwnd_login,-20,0);
				dm->ForceUnBindWindow(Hwnd_login);
				Sleep(500);
				dm_ret=dm->BindWindow(Hwnd_login,_T("dx2"),_T("dx"),_T("dx"), 1);//绑定login窗口
				error_code = dm->GetLastError();//后台绑定错误码
				if(0==dm_ret){//没有绑定成功
					dm_ret = dm->UnBindWindow();
					dm->ForceUnBindWindow(Hwnd_login);
					bind_fail_cnt+=1;
					iswindows=Kent_login_waiting;
					Kent_log_instance->write_log(_T("Hwnd_login后台绑定失败错误码:"),error_code);
				}else{//绑定成功
					bind_fail_cnt=0;
					iswindows=Kent_login_inuse;
					dm_ret = dm->SetWindowState(Hwnd_login,9);
					dm_ret = dm->SetWindowState(Hwnd_login,7);
					Sleep(500);
				}
			}
			if(dm->IsBind(Hwnd_login)){
				dm->EnableFakeActive(1);//假激活
				dm->EnableIme(0);//关闭输入法
				iswindows=Kent_login_inuse;
			}
			break;
		case Kent_connect_waiting://设置为前台
			dm->UnBindWindow();
			Sleep(2000);
			dm->SetWindowState(Hwnd_connect,1);//激活
			dm->SetWindowState(Hwnd_connect,8);//置顶
			dm->EnableIme(0);//关闭输入法
			bind_fail_cnt=0;
			iswindows=Kent_connect_inuse;
			Sleep(500);
			dm->MoveWindow(Hwnd_connect,0,0);
			Sleep(500);
			break;
		case Kent_game_waiting:
			dm->UnBindWindow();
			dm->ForceUnBindWindow(Hwnd_game);
			dm->SetWindowState(Hwnd_login,2);//最小化login
			Sleep(15000);

			//dm_ret=dm->BindWindowEx(Hwnd_game,_T("dx2"),_T("dx.mouse.position.lock.api|dx.mouse.position.lock.message|dx.mouse.clip.lock.api|dx.mouse.input.lock.api|dx.mouse.api|dx.mouse.cursor|dx.mouse.focus.input.api|dx.mouse.focus.input.message|dx.mouse.state.message|dx.mouse.input.lock.api2"),_T("dx.keypad.input.lock.api|dx.keypad.api|dx.keypad.state.api"),_T("dx.public.active.api|dx.public.active.api2|dx.public.prevent.block"),1);
			//error_code = dm->GetLastError();//后台绑定错误码
			//if(0==dm_ret)//没有绑定成功
			//{
			//	bind_fail_cnt+=1;
			//	Kent_log_instance->write_log(_T("Hwnd_game后台绑定失败错误码:"),error_code);
			//}else
			//{
			//	bind_fail_cnt=0;
			//	iswindows=Kent_game_inuse;
			//	dm->MoveWindow(Hwnd_game,-20,0);//普通绑定，置顶
			//	dm_ret = dm->SetWindowState(Hwnd_game,9);
			//	dm_ret = dm->SetWindowState(Hwnd_game,7);
			//	dm->EnableIme(0);//关闭输入法
			//	Sleep(500);
			//}

			dm_ret=dm->BindWindowEx(Hwnd_game,_T("dx"),_T("dx.mouse.position.lock.api|dx.mouse.position.lock.message|dx.mouse.clip.lock.api|dx.mouse.input.lock.api|dx.mouse.api|dx.mouse.cursor|dx.mouse.focus.input.api|dx.mouse.focus.input.message|dx.mouse.state.message|dx.mouse.input.lock.api2"),_T("dx.keypad.input.lock.api|dx.keypad.api|dx.keypad.state.api"),_T("dx.public.active.api|dx.public.active.api2|dx.public.prevent.block"),1);
			error_code = dm->GetLastError();//后台绑定错误码
			if(0==dm_ret){//没有绑定成功
				dm_ret = dm->UnBindWindow();
				bind_fail_cnt+=1;
				iswindows=Kent_game_waiting;
				Kent_log_instance->write_log(_T("Hwnd_game后台绑定失败错误码:"),error_code);
			}else{
				//验证是否成功
				CString is_success_color = dm->GetAveRGB(30,30,1000,700);
				if(_T("000000") == is_success_color){//绑定失败，需要重新绑定
					dm_ret = dm->UnBindWindow();
					dm->ForceUnBindWindow(Hwnd_game);
					dm->MoveWindow(Hwnd_game,-20,0);
					Sleep(500);
					dm_ret=dm->BindWindowEx(Hwnd_game,_T("dx"),_T("dx.mouse.position.lock.api|dx.mouse.position.lock.message|dx.mouse.clip.lock.api|dx.mouse.input.lock.api|dx.mouse.api|dx.mouse.cursor|dx.mouse.focus.input.api|dx.mouse.focus.input.message|dx.mouse.state.message|dx.mouse.input.lock.api2"),_T("dx.keypad.input.lock.api|dx.keypad.api|dx.keypad.state.api"),_T("dx.public.active.api|dx.public.active.api2|dx.public.prevent.block"),1);
					error_code = dm->GetLastError();//后台绑定错误码
					if(0==dm_ret){//绑定失败
						dm_ret = dm->UnBindWindow();
						dm->ForceUnBindWindow(Hwnd_game);
						bind_fail_cnt+=1;
						iswindows=Kent_game_waiting;
						Kent_log_instance->write_log(_T("Hwnd_login后台绑定失败错误码:"),error_code);
					}else{
						bind_fail_cnt=0;
						iswindows=Kent_game_inuse;
						dm_ret = dm->SetWindowState(Hwnd_game,9);
						dm_ret = dm->SetWindowState(Hwnd_game,7);
						Sleep(500);
					}
				}else{//确认绑定成功
					bind_fail_cnt=0;
					iswindows=Kent_game_inuse;
					dm_ret = dm->SetWindowState(Hwnd_game,9);
					dm_ret = dm->SetWindowState(Hwnd_game,7);
					Sleep(500);
				}
			}
			if(dm->IsBind(Hwnd_game)){
				dm->EnableFakeActive(1);//假激活
				dm->EnableIme(0);//关闭输入法
				iswindows=Kent_game_inuse;
			}
			break;
		default:
			break;
		}
	}
	if(bind_fail_cnt > 3){
		Kent_log_instance->kent_hook_mode = hook_mode_forground;//设置为前台模式
		restart_windows_init();
	}//失败绑定
	return true;//不能判定失败绑定
}
//对游戏进行全局控制
CString kent_windows::file_name(CString thefile)
{
	return Kent_log_instance->kent_res_path+"\\"+thefile;
}
bool kent_windows::isingame(void)
{
	if(Kent_game_inuse==iswindows)
	{
		VARIANT isingame_x1,isingame_y1,isingame_x2,isingame_y2;
		if(m_IsSmallWindow){
			dm->FindPic(822,534,905,579, file_name(_T("小地图3.bmp")), _T("303030"), 0.75, 0,& isingame_x1,& isingame_y1);
			dm->FindPic(822,534,905,579, file_name(_T("小地图4.bmp")), _T("303030"), 0.75, 0,& isingame_x2,& isingame_y2);
		}else{
			dm->FindPic(1070, 490, 1190, 560, file_name(_T("小地图1.bmp")), _T("303030"), 0.75, 0,& isingame_x1,& isingame_y1);
			dm->FindPic(1070, 490, 1190, 560, file_name(_T("小地图2.bmp")), _T("303030"), 0.75, 0,& isingame_x2,& isingame_y2);
		}
		if(isingame_x1.intVal>0 || isingame_x2.intVal>0){
			isingame_num=true;
			return true;
		}else{
			isingame_num=false;
			return false;
		}
	}else{
		return false;
	}
}
bool kent_windows::isstart(void)
{
	if(Kent_login_inuse==iswindows)
	{
		VARIANT isPLAY_x, isPLAY_y,isPLAY_x1, isPLAY_y1,isstart_x3,isstart_y3, isstart_x5, isstart_y5,isstart_x6, isstart_y6,isstart_x7, isstart_y7;

#ifdef kent_han
        dm->FindPic(462, 1, 682, 84, file_name(_T("韩PLAY.bmp")),_T("202020"), 0.9, 0,& isPLAY_x,& isPLAY_y);
        dm->FindPic(462, 1, 682, 84, file_name(_T("韩PLAY1.bmp")),_T("202020"), 0.9, 0,& isPLAY_x1,& isPLAY_y1);
        dm->FindPic(770,621,869,674, file_name(_T("韩回到大厅.bmp")),_T("303030"), 0.8, 0, & isstart_x5, & isstart_y5);
		dm->FindPic(416, 258, 746, 357, file_name(_T("韩现在开始.bmp")), _T("303030"), 0.7, 0, &isstart_x7, &isstart_y7);
		CPoint isstart_x8 = kent_search_str(143,119,162,139,_T("IP"),_T("f0f0f0-606060"),0.8,1);


		if(isstart_x7.intVal>0)//现在开始
		{
			isstart_num=Kent_start_gotoselect;
		}else if(isstart_x5.intVal>0||isstart_x8.x>0)//回到大厅
		{
			isstart_num=Kent_start_over;
		}else if(isPLAY_x.intVal > 0 || isPLAY_x1.intVal>0 || dm->GetColorNum(504, 13,642, 59, _T("303030-151515"), 1.0) > 3000)//匹配
		{
			isstart_num=Kent_start_match;
		}else{isstart_num=Kent_start_none;}
#else
        dm->FindPic(474, 3, 697, 97, file_name(_T("PLAY.bmp")),_T("404040"), 0.7, 0,& isPLAY_x,& isPLAY_y);
        dm->FindPic(474, 3, 697, 97, file_name(_T("PLAY1.bmp")),_T("404040"), 0.7, 0,& isPLAY_x1,& isPLAY_y1);
        dm->FindPic(734, 620, 906, 707, file_name(_T("回到大厅.bmp")),_T("303030"), 0.8, 0, & isstart_x5, & isstart_y5);
        dm->FindPic(916, 619, 1108, 713, file_name(_T("再来一局.bmp")), _T("303030"), 0.7, 0, & isstart_x6, & isstart_y6);
        dm->FindPic(350, 250, 800, 450, file_name(_T("进入英雄选择.bmp")),_T("303030"), 0.7, 0, & isstart_x3, & isstart_y3);
		dm->FindPic(574, 410, 806, 481, file_name(_T("现在开始.bmp")), _T("303030"), 0.7, 0, &isstart_x7, &isstart_y7);
		CPoint isstart_x8 = kent_search_str(143, 117,188, 146,_T("金币"),_T("ffffff-606060"),0.8,1);
		if(isstart_x3.intVal>0 || isstart_x7.intVal>0)
		{
			isstart_num=Kent_start_gotoselect;
		}else if(isstart_x5.intVal>0 || isstart_x6.intVal>0||isstart_x8.x>0)
		{
			isstart_num=Kent_start_over;
		}else if(isPLAY_x.intVal > 0 || isPLAY_x1.intVal>0 || dm->GetColorNum(513,15,641,66, _T("751010-301010"), 1.0) > 2000)
		{
			isstart_num=Kent_start_match;
		}else{isstart_num=Kent_start_none;}
#endif

	}else{isstart_num=Kent_start_none;}
	if(Kent_start_none==isstart_num){return false;}
	else{return true;}
}
bool kent_windows::isselect(void)
{
	if(Kent_login_inuse==iswindows){
        long start_num0 = dm->GetColorNum(255,107,356,141, _T("d26c1b-353535"), 1.0);
        long start_num1 = dm->GetColorNum(362, 106, 459, 134,_T("161616-252525"), 1.0);
		if(start_num0>1500 && start_num1>1000){
			isselect_num=true;
			return true;
		}
	}
	isselect_num=false;
	return false;
}
bool kent_windows::isloading(void)
{
	if(Kent_game_inuse==iswindows)
	{
		VARIANT isselect_x, isselect_y;
		if(m_IsSmallWindow){
#ifdef kent_han
			dm->FindPic(600, 330, 700, 400, file_name(_T("韩VS.bmp")), _T("404040"), 0.7, 0, & isselect_x, & isselect_y);
#else
			dm->FindPic(486, 364,538, 402, file_name(_T("VS.bmp")), _T("404040"), 0.7, 0, & isselect_x, & isselect_y);
#endif
		}else{
#ifdef kent_han
			dm->FindPic(600, 330, 700, 400, file_name(_T("韩VS.bmp")), _T("404040"), 0.7, 0, & isselect_x, & isselect_y);
#else
			dm->FindPic(600, 330, 700, 400, file_name(_T("VS.bmp")), _T("404040"), 0.7, 0, & isselect_x, & isselect_y);
#endif
		}
		if(isselect_x.intVal>0){
			isloading_num=true;
			return true;
		}
	}
	isloading_num=false;
	return false;
}
bool kent_windows::isgameover(void)
{
	if(Kent_game_inuse==iswindows)
	{
		VARIANT win_x, win_y,lose_x,lose_y,win15_x, win15_y,lose15_x,lose15_y;

		if(m_IsSmallWindow){
			
			dm->FindPic(401, 251, 624, 360, file_name(_T("胜利.bmp")), _T("303030"), 0.7, 0, & win_x, & win_y);
			if(win_x.intVal>=0){
				kent_log.info("Swin");
				isgameover_num=gameover_win; return true;
			}else{
				dm->FindPic(401, 251, 624, 360, file_name(_T("失败.bmp")), _T("303030"), 0.7, 0, & lose_x, & lose_y);
				if(lose_x.intVal>=0){
					kent_log.info("Slose");
					isgameover_num=gameover_lose;return true;
				}else{
					dm->FindPic(374, 185, 637, 326, file_name(_T("胜利15.bmp")), _T("303030"), 0.7, 0, & win15_x, & win15_x);
					if(win15_x.intVal>=0){
						kent_log.info("Swin15");
						isgameover_num=gameover15_win; return true;
					}else{
						dm->FindPic(374, 185, 637, 326, file_name(_T("失败15.bmp")), _T("303030"), 0.7, 0, & lose15_x, & lose15_x);
						if(lose15_x.intVal>=0){
							kent_log.info("Slose15");
							isgameover_num=gameover15_lose;return true;
						}
					}
				}
			}
		}else{
			
			//CPoint tmp = kent_search_str(602, 447, 680, 467,_T("继续游戏"),_T("fde9a3-606060"),0.8,2);
			//if(tmp.x > 0){
			//	return true;
			//}
			
			
			dm->FindPic(528, 229, 757, 338, file_name(_T("胜利.bmp")), _T("303030"), 0.7, 0, & win_x, & win_y);
			if(win_x.intVal>=0){
				kent_log.info("win");
				isgameover_num=gameover_win; return true;
			}else{
				dm->FindPic(528, 229, 757, 338, file_name(_T("失败.bmp")), _T("303030"), 0.7, 0, & lose_x, & lose_y);
				if(lose_x.intVal>=0){
					kent_log.info("lose");
					isgameover_num=gameover_lose;return true;
				}else{
					dm->FindPic(470, 153, 794, 320, file_name(_T("胜利15.bmp")), _T("303030"), 0.7, 0, & win15_x, & win15_x);
					if(win15_x.intVal>=0){
						kent_log.info("win15");
						isgameover_num=gameover15_win; return true;
					}else{
						dm->FindPic(470, 153, 794, 320, file_name(_T("失败15.bmp")), _T("303030"), 0.7, 0, & lose15_x, & lose15_x);
						if(lose15_x.intVal>=0){
							kent_log.info("lose15");
							isgameover_num=gameover15_lose;return true;
						}
					}
				}
			}
		}
		//kent_log.info("no_win_lose");
	}
	isgameover_num=gameover_none;
	return false;
}
bool kent_windows::iscanselect()
{
	CString get_avr_color = dm->GetAveHSV(711, 441, 734, 470);
	int a1=get_avr_color.Find('.');
	int a2=get_avr_color.ReverseFind('.');
	if(a1>=0 && a2>=0){
		int sum=kent_strtoi(get_avr_color.Mid(a1+1,a2-a1-1));
		if(sum > 10){//未选定
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
//全局控制
static bool Kent_rnd_delay(int kent_time)
{
	Sleep(kent_time*(1-0.5*std::rand()/RAND_MAX));
	return true;
}
bool kent_windows::gamestage_ctrl(void)
{
	static CTime game_none_time;//连续判定失败最早的时间
	bool IsGameNone = false;
	if(true==isingame()){
		if(kent_stage_last != kent_stage_now){
			kent_log.info("Kent_ingame");
		}
		IsGameNone = true;//明确判定为ingame,不让更新
		kent_stage_now=Kent_ingame;
	}else if(true==isgameover()){
		if(kent_stage_last != kent_stage_now){
			kent_log.info("kent_overing");
		}
		kent_stage_now=kent_overing;
		game_state=Kent_game_none;
	}else if(true==isstart()){
		if(kent_stage_last != kent_stage_now){
			kent_log.info("Kent_matching");
		}
		kent_stage_now=Kent_matching;
		game_state=Kent_game_none;
	}else if(true==isselect()){
		if(kent_stage_last != kent_stage_now){
			kent_log.info("Kent_selceting");
		}
		kent_stage_now=Kent_selceting;
		game_state=Kent_game_none;
	}else if(true==isloading()){
		if(kent_stage_last != kent_stage_now){
			kent_log.info("Kent_loading");
		}
		kent_stage_now=Kent_loading;
		game_state=Kent_game_none;
	}else{
		kent_log.info("Kent_waiting");
		
		kent_stage_now=Kent_waiting;
		if(Kent_game_inuse==iswindows){//拥有游戏窗口
			IsGameNone = true;//但是没有明确判定
			CTimeSpan timeSpan = CTime::GetCurrentTime() - game_none_time;
			if(timeSpan.GetTotalSeconds() >20){
				kent_log.info("Kent_ingame...when can not recognize...");
				kent_stage_now=Kent_ingame;
			}
		}
	}

	if(!IsGameNone){//有准确的判定，则更新时间
		game_none_time = CTime::GetCurrentTime();//判断
	}

#ifdef kent_han
	if(Kent_login_inuse == iswindows){
		VARIANT reconnect_x, reconnect_y;
		dm->FindPic(521, 392, 730, 459, file_name(_T("韩重新连接.bmp")), _T("303030"), 0.8, 0, &reconnect_x,&reconnect_y);//弹出确认框
		if(reconnect_x.intVal > 0){
			dm->MoveTo(569, 408);
			Sleep(200);
			dm->MoveTo(569+10, 408);
			Sleep(200);
			dm->LeftClick();
			Sleep(300);
		}
		VARIANT conform_x, conform_y;
		dm->FindPic(493,371,665,443, file_name(_T("韩确定.bmp")), _T("303030"), 0.8, 0, &conform_x,&conform_y);//弹出确认框
		if(conform_x.intVal > 0){
			dm->MoveTo(conform_x.intVal + 20, conform_y.intVal + 10);
			Sleep(200);
			dm->MoveTo(conform_x.intVal + 25, conform_y.intVal + 10);
			Sleep(200);
			dm->LeftClick();
			Sleep(300);
		}
	}
#else
	if(Kent_login_inuse == iswindows){
		VARIANT confirm_x,confirm_y,shut_x,shut_y,reconnect_x, reconnect_y,waiting_x,waiting_y;
		if(rand()%10 < 5){
			dm->FindPic(300, 300, 900, 500, file_name(_T("确认.bmp")), _T("404040"), 0.75, 0, &confirm_x, &confirm_y);//弹出确认框
			if(confirm_x.intVal > 0){
				dm->MoveTo(confirm_x.intVal + 35, confirm_y.intVal + 12);
				Sleep(200);
				dm->MoveTo(confirm_x.intVal + 45, confirm_y.intVal + 12);
				Sleep(200);
				dm->LeftClick();
				Sleep(300);
			}
		}

		dm->FindPic(300, 300, 900, 500, file_name(_T("关闭.bmp")), _T("303030"), 0.7, 0, &shut_x, &shut_y);//弹出确认框
		if(shut_x.intVal > 0){
			dm->MoveTo(shut_x.intVal + 35, shut_y.intVal + 12);
			Sleep(200);
			dm->MoveTo(shut_x.intVal + 45, shut_y.intVal + 12);
			Sleep(200);
			dm->LeftClick();
			Sleep(300);
		}

		dm->FindPic(521, 392, 730, 459, file_name(_T("重新连接.bmp")), _T("454545"), 0.7, 0, &reconnect_x,&reconnect_y);//弹出确认框
		if(reconnect_x.intVal > 0){
			dm->MoveTo(576,410);
			Sleep(200);
			dm->MoveTo(576+10,410);
			Sleep(200);
			dm->LeftClick();
			Sleep(300);
		}else{
			CPoint tmp = kent_search_str(492,298, 638,432,_T("重新连接"),_T("ffffff-404040"),0.8,3);
			if(tmp.x>0){
				dm->MoveTo(576,410);
				Sleep(200);
				dm->MoveTo(576+10,410);
				Sleep(200);
				dm->LeftClick();
				Sleep(300);
				Kent_log_instance->write_log(_T("找到文字：重新连接"));
			}
		}
		dm->FindPic(481, 79, 669, 122, file_name(_T("等待游戏结果.bmp")), _T("303030"), 0.75, 0, &waiting_x,&waiting_y);//弹出确认框
		if(waiting_x.intVal > 0){
			dm->MoveTo(579, 133);
			Sleep(200);
			dm->MoveTo(589, 133);
			Sleep(200);
			dm->LeftClick();
			Sleep(300);
		}else{
			CPoint tmp = kent_search_str(481, 79, 669, 122,_T("等待游戏结果"),_T("ffffff-404040"),0.8,4);
			if(tmp.x>0){
				dm->MoveTo(tmp.x,tmp.y);
				Sleep(200);
				dm->MoveTo(tmp.x+5,tmp.y);
				Sleep(200);
				dm->LeftClick();
				Sleep(300);
				Kent_log_instance->write_log(_T("找到文字：等待游戏结果"));
			}
		}
	}
#endif

	return true;
}
bool kent_windows::Kent_do_start(void)
{
	VARIANT remind_x, remind_y,remind_x1, remind_y1;
	//kent_TerminateProcess(_T("CrossProxy.exe"));
	Sleep(2000);
	if(Kent_start_none==isstart_num || Kent_start_waiting==isstart_num)
	{
		Kent_rnd_delay(1000);
	}else if(Kent_start_match==isstart_num)//开始匹配
	{
/*******************获取当前金币数量***********************/
		kent_get_now_ip_satge();
		if(isneedchangeqq()){//完成任务
			MessageBox(NULL,_T("任务完成"),_T("任务完成"),MB_OK);
			exit(0);
			/*
			bool isdone = false;
			for(int i = 0;i<3;i++){
				if(Kent_log_instance->FinishTask()){
					isdone = true;//获取新任务成功
					restart_whole_game();//重启
					break;
				}else{
					Sleep(30000);//3秒后再试
				}
			}
			if(!isdone){
				MessageBox(NULL,_T("获取新任务失败"),_T("连接中控台获取新任务失败"),MB_OK);
			}
			restart_whole_game();//重启游戏
			start_time =CTime::GetCurrentTime();//更新开始时间
			return true;
			*/
		}

		if(Kent_log_instance->kent_studio_can_connect && Kent_log_instance->kent_change_task){//更换任务
			CTime now_time=CTime::GetCurrentTime();//获取当前时间
			CTimeSpan timeSpan = now_time - start_time;
			if(Kent_log_instance->kent_change_task_time <= (double)timeSpan.GetTotalMinutes()/60){
				restart_whole_game();//重启游戏
				Kent_log_instance->ChangeToNext(Kent_log_instance->kent_change_task_num);//更换任务
				start_time = now_time;//获取当前时间
				return true;
			}
		}

VMProtectBeginUltra("Kent_do_start");//game over
		if(rand()%20 < 4){//随机行为进行验证
			if(!Kent_log_instance->kss_check()){
				exit(0);
			}
		}
VMProtectEnd();
		dm->MoveTo(570, 40);//开始
        Kent_rnd_delay(200);
        dm->MoveTo(590,40);//开始
        dm->LeftClick(); 
        Sleep(5000);
		CString ShapeNormal=dm->GetCursorShape();

#ifdef kent_han
		dm->MoveTo(479,91);//关掉那个叉
        dm->LeftClick();
        Sleep(1000);
#else
		CPoint IsRedAllert = kent_search_str(143,119,162,139,_T("玩家对战"),_T("c9cdcd-303030"),0.8,2);
		if(IsRedAllert.x<=0){//关掉那个红色警告
			dm->MoveTo(238,40);//关掉那个红色警告
			Sleep(300);
			dm->MoveTo(238,42);//关掉那个红色警告
			dm->LeftClick();
		}

		dm->MoveTo(300, 105);//玩家对战
		Sleep(300);
		if(dm->GetCursorShape()!=ShapeNormal){
			dm->MoveTo(238,40);//关掉那个红色警告
			Sleep(300);
			dm->MoveTo(238,42);//关掉那个红色警告
			dm->LeftClick();
		}

		for(int x=570;x<1150;x+=10){
			dm->MoveTo(x,116);//关掉那个叉
			Sleep(30);
			if(dm->GetCursorShape()!=ShapeNormal){
				dm->LeftClick();
				Sleep(100);
			}
		}

#endif
		d_match_mode kent_game_match_mode_back;
		if(match_mode_Random == Kent_log_instance->kent_game_match_mode){//随机地图
			kent_game_match_mode_back = match_mode_Random;
			switch(rand()%5){
			case 0:
				Kent_log_instance->kent_game_match_mode = match_mode_normal_machine;
				break;
			case 1:
				Kent_log_instance->kent_game_match_mode = match_mode_normal_machine_hard;
				break;
			case 2:
				Kent_log_instance->kent_game_match_mode = match_mode_Distort;
				break;
			case 3:
#if defined kent_forever ||defined kent_forever_background 
				Kent_log_instance->kent_game_match_mode = match_mode_normal_machine_hard;
#else
				Kent_log_instance->kent_game_match_mode = match_mode_Colosseum;
#endif
				break;
			case 4:
				Kent_log_instance->kent_game_match_mode = match_mode_common;
				break;
			default:
				Kent_log_instance->kent_game_match_mode = match_mode_Distort;
				break;
			}
		}else{
			kent_game_match_mode_back = Kent_log_instance->kent_game_match_mode;//备份
		}

		if(match_mode_AI == Kent_log_instance->kent_game_match_mode || match_mode_common == Kent_log_instance->kent_game_match_mode || match_mode_machine == Kent_log_instance->kent_game_match_mode){
			//统治战场
			//if(match_mode_normal_machine != Kent_log_instance->kent_game_match_mode && match_mode_normal_machine_hard != Kent_log_instance->kent_game_match_mode){//统治战场
			if(match_mode_common == Kent_log_instance->kent_game_match_mode || match_mode_AI == Kent_log_instance->kent_game_match_mode){
				dm->MoveTo(300, 105);//玩家对战
				Kent_rnd_delay(200);
				dm->MoveTo(310,105);//玩家对战
				Kent_rnd_delay(200);
				dm->LeftClick();
			}else{
				dm->MoveTo(300, 165);//人机对战
				Kent_rnd_delay(200);
				dm->MoveTo(310,165);//人机对战
				Kent_rnd_delay(200);
				dm->LeftClick();
			}
			Sleep(2500);
			dm->MoveTo(440,165);//统治战场
			Kent_rnd_delay(200);
			dm->MoveTo(450,165);//统治战场
			Kent_rnd_delay(200);
			dm->LeftClick();
			Sleep(2500);
			dm->MoveTo(630,140);//水晶之痕
			Kent_rnd_delay(200);
			dm->MoveTo(640,140);//水晶之痕
			Kent_rnd_delay(200);
			dm->LeftClick();
			Sleep(2500);
			dm->MoveTo(800, 140);//匹配模式
			Kent_rnd_delay(200);
			dm->MoveTo(810, 140);//匹配模式
			Kent_rnd_delay(200);
			dm->LeftClick();
			Sleep(10000);
			long is_canstart_num_gray = dm->GetColorNum(607,621,759,660, _T("737373-303030"), 1.0);
			long is_canstart_num_red = dm->GetColorNum(607,621,759,660, _T("cf771a-303030"), 1.0);//通过比色来判定是否可以点击开始
			int cnt=0;
			for(int i=0;i<5;i++)
			{
				if(is_canstart_num_red < is_canstart_num_gray)
				{
					Sleep(5000);
					is_canstart_num_gray = dm->GetColorNum(607,621,759,660, _T("737373-303030"), 1.0);
					is_canstart_num_red = dm->GetColorNum(607,621,759,660, _T("cf771a-303030"), 1.0);//通过比色来判定是否可以点击开始
				}else{
					break;
				}
			}
			if(is_canstart_num_red < is_canstart_num_gray){//不可以匹配，召唤师峡谷人机
				dm->MoveTo(300, 165);//人机对战
				Kent_rnd_delay(200);
				dm->MoveTo(310,165);//人机对战
				Kent_rnd_delay(200);
				dm->LeftClick();
				Sleep(2500);
				dm->MoveTo(534, 140);//经典战场
				Kent_rnd_delay(200);
				dm->MoveTo(544, 140);//经典战场
				Kent_rnd_delay(200);
				dm->LeftClick();
				Sleep(2500);
				dm->MoveTo(630,140);//召唤师峡谷
				Kent_rnd_delay(200);
				dm->MoveTo(640,140);//召唤师峡谷
				Kent_rnd_delay(200);
				dm->LeftClick();
				Sleep(2500);
				dm->MoveTo(800, 160);//简单
				Kent_rnd_delay(200);
				dm->MoveTo(810, 160);//简单
				Kent_rnd_delay(200);
				dm->LeftClick(); 
				Sleep(2500);
				Kent_log_instance->is_common_match_mode = true;
				Kent_log_instance->is_distort_match_mode = false;
				Kent_log_instance->is_dominate_match_mode = false;//统治战场
				Kent_log_instance->is_colosseum_match_mode = false;
			}else{
				Kent_log_instance->is_common_match_mode = false;
				Kent_log_instance->is_distort_match_mode = false;
				Kent_log_instance->is_dominate_match_mode = true;//统治战场
				Kent_log_instance->is_colosseum_match_mode = false;
			}
		}else if(match_mode_normal_machine == Kent_log_instance->kent_game_match_mode || match_mode_normal_machine_hard == Kent_log_instance->kent_game_match_mode){//人机对战
			dm->MoveTo(300, 165);//人机对战
			Kent_rnd_delay(200);
			dm->MoveTo(310,165);//人机对战
			Kent_rnd_delay(200);
			dm->LeftClick();
			Sleep(2500);
			dm->MoveTo(534, 140);//经典战场
			Kent_rnd_delay(200);
			dm->MoveTo(544, 140);//经典战场
			Kent_rnd_delay(200);
			dm->LeftClick();
			Sleep(2500);
			dm->MoveTo(630,140);//召唤师峡谷
			Kent_rnd_delay(200);
			dm->MoveTo(640,140);//召唤师峡谷
			Kent_rnd_delay(200);
			dm->LeftClick();
			Sleep(2500);
			if(match_mode_normal_machine == Kent_log_instance->kent_game_match_mode)
			{
				dm->MoveTo(800, 160);//简单
				Kent_rnd_delay(200);
				dm->MoveTo(810, 160);//简单
				Kent_rnd_delay(200);
			}else{
				dm->MoveTo(800, 187);//一般
				Kent_rnd_delay(200);
				dm->MoveTo(810, 187);//一般
				Kent_rnd_delay(200);
			}
			dm->LeftClick(); 
			Sleep(2500);
			Kent_log_instance->is_common_match_mode = true;
			Kent_log_instance->is_distort_match_mode = false;
			Kent_log_instance->is_dominate_match_mode = false;//统治战场
			Kent_log_instance->is_colosseum_match_mode = false;
		}else if(match_mode_Distort == Kent_log_instance->kent_game_match_mode){//扭曲丛林匹配
			dm->MoveTo(300, 105);//玩家对战
			Kent_rnd_delay(200);
			dm->MoveTo(310,105);//玩家对战
			Kent_rnd_delay(200);
			dm->LeftClick();
			Sleep(2500);
			dm->MoveTo(534, 140);//经典战场
			Kent_rnd_delay(200);
			dm->MoveTo(544, 140);//经典战场
			Kent_rnd_delay(200);
			dm->LeftClick();
			Sleep(2500);
			dm->MoveTo(630,183);//扭曲丛林
			Kent_rnd_delay(200);
			dm->MoveTo(640,183);//扭曲丛林
			Kent_rnd_delay(200);
			dm->LeftClick();
			Sleep(2500);
			dm->MoveTo(800, 140);//匹配模式
			Kent_rnd_delay(200);
			dm->MoveTo(810, 140);//匹配模式
			Kent_rnd_delay(200);
			dm->LeftClick();
			Sleep(10000);
			long is_canstart_num_gray = dm->GetColorNum(607,621,759,660, _T("737373-303030"), 1.0);
			long is_canstart_num_red = dm->GetColorNum(607,621,759,660, _T("cf771a-303030"), 1.0);//通过比色来判定是否可以点击开始
			int cnt=0;
			for(int i=0;i<5;i++)
			{
				if(is_canstart_num_red < is_canstart_num_gray)
				{
					Sleep(5000);
					is_canstart_num_gray = dm->GetColorNum(607,621,759,660, _T("737373-303030"), 1.0);
					is_canstart_num_red = dm->GetColorNum(607,621,759,660, _T("cf771a-303030"), 1.0);//通过比色来判定是否可以点击开始
				}else{
					break;
				}
			}
			if(is_canstart_num_red < is_canstart_num_gray){//不可以匹配，召唤师峡谷人机
				dm->MoveTo(300, 165);//人机对战
				Kent_rnd_delay(200);
				dm->MoveTo(310,165);//人机对战
				Kent_rnd_delay(200);
				dm->LeftClick();
				Sleep(2500);
				dm->MoveTo(534, 140);//经典战场
				Kent_rnd_delay(200);
				dm->MoveTo(544, 140);//经典战场
				Kent_rnd_delay(200);
				dm->LeftClick();
				Sleep(2500);
				dm->MoveTo(630,140);//召唤师峡谷
				Kent_rnd_delay(200);
				dm->MoveTo(640,140);//召唤师峡谷
				Kent_rnd_delay(200);
				dm->LeftClick();
				Sleep(2500);
				dm->MoveTo(800, 160);//简单
				Kent_rnd_delay(200);
				dm->MoveTo(810, 160);//简单
				Kent_rnd_delay(200);
				dm->LeftClick(); 
				Sleep(2500);
				Kent_log_instance->is_common_match_mode = true;//召唤师峡谷
				Kent_log_instance->is_distort_match_mode = false;
				Kent_log_instance->is_dominate_match_mode = false;//统治战场
				Kent_log_instance->is_colosseum_match_mode = false;
			}else{
				Kent_log_instance->is_common_match_mode = false;
				Kent_log_instance->is_distort_match_mode = true;//扭曲丛林
				Kent_log_instance->is_dominate_match_mode = false;//
				Kent_log_instance->is_colosseum_match_mode = false;
			}
		}else{//极地大乱斗
			dm->MoveTo(300, 105);//玩家对战
			Kent_rnd_delay(200);
			dm->MoveTo(310,105);//玩家对战
			Kent_rnd_delay(200);
			dm->LeftClick();
			Sleep(2500);//421,189
			dm->MoveTo(534, 189);//大乱斗
			Kent_rnd_delay(200);
			dm->MoveTo(544, 189);//大乱斗
			Kent_rnd_delay(200);
			dm->LeftClick();
			Sleep(2500);
			dm->MoveTo(630,140);//嚎哭深渊
			Kent_rnd_delay(200);
			dm->MoveTo(640,140);//嚎哭深渊
			Kent_rnd_delay(200);
			dm->LeftClick();
			Sleep(2500);
			dm->MoveTo(800, 140);//匹配模式
			Kent_rnd_delay(200);
			dm->MoveTo(810, 140);//匹配模式
			Kent_rnd_delay(200);
			dm->LeftClick();
			Sleep(10000);
			long is_canstart_num_gray = dm->GetColorNum(607,621,759,660, _T("737373-303030"), 1.0);
			long is_canstart_num_red = dm->GetColorNum(607,621,759,660, _T("cf771a-303030"), 1.0);//通过比色来判定是否可以点击开始
			int cnt=0;
			for(int i=0;i<5;i++)
			{
				if(is_canstart_num_red < is_canstart_num_gray)
				{
					Sleep(5000);
					is_canstart_num_gray = dm->GetColorNum(607,621,759,660, _T("737373-303030"), 1.0);
					is_canstart_num_red = dm->GetColorNum(607,621,759,660, _T("cf771a-303030"), 1.0);//通过比色来判定是否可以点击开始
				}else{
					break;
				}
			}
			if(is_canstart_num_red < is_canstart_num_gray){//不可以匹配，召唤师峡谷人机
				dm->MoveTo(300, 165);//人机对战
				Kent_rnd_delay(200);
				dm->MoveTo(310,165);//人机对战
				Kent_rnd_delay(200);
				dm->LeftClick();
				Sleep(2500);
				dm->MoveTo(534, 140);//经典战场
				Kent_rnd_delay(200);
				dm->MoveTo(544, 140);//经典战场
				Kent_rnd_delay(200);
				dm->LeftClick();
				Sleep(2500);
				dm->MoveTo(630,140);//召唤师峡谷
				Kent_rnd_delay(200);
				dm->MoveTo(640,140);//召唤师峡谷
				Kent_rnd_delay(200);
				dm->LeftClick();
				Sleep(2500);
				dm->MoveTo(800, 160);//简单
				Kent_rnd_delay(200);
				dm->MoveTo(810, 160);//简单
				Kent_rnd_delay(200);
				dm->LeftClick(); 
				Sleep(2500);
				Kent_log_instance->is_common_match_mode = true;//召唤师峡谷
				Kent_log_instance->is_distort_match_mode = false;
				Kent_log_instance->is_dominate_match_mode = false;//统治战场
				Kent_log_instance->is_colosseum_match_mode = false;
			}else{
				Kent_log_instance->is_common_match_mode = false;
				Kent_log_instance->is_distort_match_mode = false;
				Kent_log_instance->is_dominate_match_mode = false;//统治战场
				Kent_log_instance->is_colosseum_match_mode = true;
			}
		}

		Sleep(4000);
		long is_canstart_num_gray = dm->GetColorNum(607,621,759,660, _T("737373-303030"), 1.0);
		long is_canstart_num_red = dm->GetColorNum(607,621,759,660, _T("cf771a-303030"), 1.0);//通过比色来判定是否可以点击开始
		for(int i=0;i<10;i++)
		{
			if(is_canstart_num_red > is_canstart_num_gray+500){//可以匹配
				dm->MoveTo(680, 650);//系统匹配队友
				Kent_rnd_delay(200);
				dm->MoveTo (690, 650);//系统匹配队友
				Kent_rnd_delay(200);
				dm->LeftClick();
				Sleep(4000);
				break;
			}
			is_canstart_num_gray = dm->GetColorNum(607,621,759,660, _T("737373-303030"), 1.0);
			is_canstart_num_red = dm->GetColorNum(607,621,759,660, _T("cf771a-303030"), 1.0);//通过比色来判定是否可以点击开始
		}


		is_canstart_num_gray = dm->GetColorNum(607,621,759,660, _T("737373-303030"), 1.0);
		is_canstart_num_red = dm->GetColorNum(607,621,759,660, _T("cf771a-303030"), 1.0);//通过比色来判定是否可以点击开始
		for(int i=0;i<10;i++)
		{
			if(is_canstart_num_red > is_canstart_num_gray+500){//匹配没有点击结束
				Sleep(4000);
				is_canstart_num_gray = dm->GetColorNum(607,621,759,660, _T("737373-303030"), 1.0);
				is_canstart_num_red = dm->GetColorNum(607,621,759,660, _T("cf771a-303030"), 1.0);//通过比色来判定是否可以点击开始
				continue;
			}
			break;
		}

		for(int i=0;i<5;i++)
		{
			Sleep(3000);
			if(dm->GetColorNum(513,15,641,66, _T("751010-301010"), 1.0) < 2000){//匹配没有点击结束
				break;
			}
			Sleep(4000);
		}

		Kent_log_instance->kent_game_match_mode = kent_game_match_mode_back;//还原
		//修改大小
		WritePrivateProfileString(_T("HUD"),_T("ItemShopPrevY"),_T("0"),kent_gamepath+_T("\\Config\\Game.cfg"));
		WritePrivateProfileString(_T("HUD"),_T("ItemShopPrevX"),_T("0"),kent_gamepath+_T("\\Config\\Game.cfg"));
		WritePrivateProfileString(_T("General"),_T("WindowMode"),_T("2"),kent_gamepath+_T("\\Config\\Game.cfg"));//窗口模式
		WritePrivateProfileString(_T("General"),_T("ItemShopPrevY"),_T("0"),kent_gamepath+_T("\\Config\\Game.cfg"));
		WritePrivateProfileString(_T("General"),_T("ItemShopPrevX"),_T("0"),kent_gamepath+_T("\\Config\\Game.cfg"));
		if(!kent_gamepath.IsEmpty()){//非空
			if(1 == Kent_log_instance->kent_game_resolution){//1024*768
				WritePrivateProfileString(_T("General"),_T("Height"),_T("768"),kent_gamepath+_T("\\Config\\Game.cfg"));
				WritePrivateProfileString(_T("General"),_T("Width"),_T("1024"),kent_gamepath+_T("\\Config\\Game.cfg"));
				WritePrivateProfileString(_T("HUD"),_T("ItemShopPrevResizeHeight"),_T("768"),kent_gamepath+_T("\\Config\\Game.cfg"));
				WritePrivateProfileString(_T("HUD"),_T("ItemShopPrevResizeWidth"),_T("1024"),kent_gamepath+_T("\\Config\\Game.cfg"));
				WritePrivateProfileString(_T("HUD"),_T("ItemShopResizeHeight"),_T("0"),kent_gamepath+_T("\\Config\\Game.cfg"));
				WritePrivateProfileString(_T("HUD"),_T("ItemShopResizeWidth"),_T("0"),kent_gamepath+_T("\\Config\\Game.cfg"));
			}else{
				WritePrivateProfileString(_T("General"),_T("Height"),_T("720"),kent_gamepath+_T("\\Config\\Game.cfg"));
				WritePrivateProfileString(_T("General"),_T("Width"),_T("1280"),kent_gamepath+_T("\\Config\\Game.cfg"));
				WritePrivateProfileString(_T("HUD"),_T("ItemShopPrevResizeHeight"),_T("720"),kent_gamepath+_T("\\Config\\Game.cfg"));
				WritePrivateProfileString(_T("HUD"),_T("ItemShopPrevResizeWidth"),_T("1280"),kent_gamepath+_T("\\Config\\Game.cfg"));
				WritePrivateProfileString(_T("HUD"),_T("ItemShopResizeHeight"),_T("36"),kent_gamepath+_T("\\Config\\Game.cfg"));
				WritePrivateProfileString(_T("HUD"),_T("ItemShopResizeWidth"),_T("250"),kent_gamepath+_T("\\Config\\Game.cfg"));
			}
		}

	}else if(Kent_start_gotoselect==isstart_num)
	{
#ifdef kent_han
        dm->MoveTo(475, 406);//点击现在开始
        Kent_rnd_delay(200);
        dm->MoveTo(480, 406);//点击现在开始
        Kent_rnd_delay(200);
#else
        dm->MoveTo(690,440);//点击现在开始
        Kent_rnd_delay(200);
        dm->MoveTo(700, 440);//点击现在开始
        Kent_rnd_delay(200);
#endif
        dm->LeftClick(); 
        Kent_rnd_delay(2000);
	}else if(Kent_start_over==isstart_num)
	{
        dm->MoveTo(792,662);//继续游戏
        Kent_rnd_delay(200);
        dm->MoveTo(785,662);//继续游戏
        Kent_rnd_delay(200);
        dm->LeftClick();
        Sleep(4000);
	}
	script_time =CTime::GetCurrentTime();
	return true;
}
bool kent_windows::isneedchangeqq(){
	if(Kent_log_instance->kent_studio_finish_enable){
		if(Kent_log_instance->kent_studio_stop_ip && Kent_log_instance->kent_studio_stop_stage){//两者同时完成
			if(Kent_log_instance->kent_studio_now_ip >= Kent_log_instance->kent_studio_stop_ip && Kent_log_instance->kent_studio_now_stage >= Kent_log_instance->kent_studio_stop_stage){
				return true;
			}else{
				return false;
			}
		}else if(Kent_log_instance->kent_studio_stop_ip){//停止金币
			if(Kent_log_instance->kent_studio_now_ip >= Kent_log_instance->kent_studio_stop_ip){
				return true;
			}else{
				return false;
			}
		}else if(Kent_log_instance->kent_studio_stop_stage){//停止等级
			if(Kent_log_instance->kent_studio_now_stage >= Kent_log_instance->kent_studio_stop_stage){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
		//if(Kent_log_instance->kent_studio_now_ip > Kent_log_instance->kent_studio_stop_ip){//已经完成任务
		//	//MessageBox(NULL,_T("任务完成"),_T("任务完成"),MB_OK);
		//	bool isdone = false;
		//	for(int i = 0;i<3;i++){
		//		if(Kent_log_instance->FinishTask()){
		//			isdone = true;//获取新任务成功
		//			restart_whole_game();//重启
		//			break;
		//		}else{
		//			Sleep(30000);
		//		}
		//	}
		//	if(!isdone){
		//		MessageBox(NULL,_T("获取新任务失败"),_T("连接中控台获取新任务失败"),MB_OK);
		//	}
		//}
	}
	return false;
}
void kent_windows::kent_get_now_ip_satge(){
#ifdef kent_han
	dm->UseDict(3);//使用金币数字字库
	Kent_log_instance->kent_studio_now_ip = _ttoi(dm->Ocr(1023,12,1065,25,_T("f0f0f0-707070"),0.8));//获取当前金币数
	dm->UseDict(4);//使用等级数字字库
	Kent_log_instance->kent_studio_now_stage = _ttoi(dm->Ocr(741,43,754,55,_T("c7b698-606060"),0.8));//获取当前等级
#else
	dm->UseDict(1);//使用金币数字字库
	Kent_log_instance->kent_studio_now_ip = _ttoi(dm->Ocr(1024,11,1073, 28,_T("f0f0f0-606060"),0.9));//获取当前金币数
	dm->UseDict(2);//使用等级数字字库
	Kent_log_instance->kent_studio_now_stage = _ttoi(dm->Ocr(740, 43,755,56,_T("c8b799-505050"),0.9));//获取当前等级
#endif
	dm->UseDict(0);//使用0字库
	Kent_log_instance->kent_writeini(_T("kent_studio_now_ip"),Kent_log_instance->kent_studio_now_ip);
}
bool kent_windows::Kent_do_select(void)
{
	//随机选择英雄
    if(false == isselect())
	{
		Kent_rnd_delay(1000);
	}else{//选择英雄
		if(Kent_log_instance->kent_hero_allrand){
			//直接随机
			Kent_log_instance->write_log(_T("直接随机"));
			add_order.at(0) = _T("r");
			add_order.at(1) = _T("q");
			add_order.at(2) = _T("w");
			add_order.at(3) = _T("e");
			dm->MoveTo(290,185);//随机
			Kent_rnd_delay(500);
			dm->LeftClick();
			Kent_rnd_delay(3000);
		}else{
			//确定英雄排列顺序
			Kent_log_instance->write_log(_T("尝试选定英雄"));
			vector<int> heros_select_order;
			for(int i=1;i<4;i++)
			{//3个，其中0代表随机，最后添加
				heros_select_order.push_back(i);
			}
			if(Kent_log_instance->kent_hero_rand)
			{//打乱顺序
				random_shuffle(heros_select_order.begin(),heros_select_order.end());
			}
			heros_select_order.push_back(0);//0代表随机，最后添加
			int try_cnt;//尝试次数
			//if((Kent_log_instance->is_common_match_mode == true || Kent_log_instance->is_distort_match_mode == true) && Kent_log_instance->kent_hero_ruizi){//召唤师峡谷
			if(Kent_log_instance->kent_hero_ruizi){//召唤师峡谷
				heros_select_order.insert(heros_select_order.begin(),4);//插入3,瑞兹
				try_cnt = 5;
			}else{
				try_cnt = 4;
			}
			int tmp_kent_skill_hero_select=0;
			for(int i=0; i < try_cnt;i++)
			{
				if(iscanselect() || !isselect()){break;}//选定或者不在选择页面
				if(heros_select_order.at(i))
				{//正常选择
					dm->MoveTo(790, 122);//搜索
					Kent_rnd_delay(50);
					dm->LeftClick();
					Kent_rnd_delay(200);
#ifdef kent_han
					CString str = Kent_log_instance->kent_chinese2han(Kent_log_instance->kent_hero_select.at(heros_select_order.at(i) - 1));
					//dm->SetClipboard(tmp);
					if(OpenClipboard((HWND)Hwnd_login))
					{
						wchar_t * pBuf;
						EmptyClipboard();
						HGLOBAL hClip  = (wchar_t *)GlobalAlloc(GHND,sizeof(wchar_t) + str.GetLength()*2);
						pBuf = (wchar_t*)GlobalLock(hClip);
						wcscpy(pBuf,str);
						GlobalUnlock(hClip);
						SetClipboardData(CF_UNICODETEXT,hClip);
						CloseClipboard();
					}
					dm->KeyDownChar(_T("ctrl"));
					Sleep(200);
					dm->KeyPressChar(_T("v"));
					Sleep(200);
					dm->KeyUpChar(_T("ctrl"));
#else
#ifdef _kent_foreground_
					CString str = Kent_log_instance->kent_hero_select.at(heros_select_order.at(i) - 1);
					if(OpenClipboard((HWND)Hwnd_login))
					{
						wchar_t * pBuf;
						EmptyClipboard();
						HGLOBAL hClip  = (wchar_t *)GlobalAlloc(GHND,sizeof(wchar_t) + str.GetLength()*2);
						pBuf = (wchar_t*)GlobalLock(hClip);
						wcscpy(pBuf,str);
						GlobalUnlock(hClip);
						SetClipboardData(CF_UNICODETEXT,hClip);
						CloseClipboard();
					}
					dm->KeyDownChar(_T("ctrl"));
					Sleep(200);
					dm->KeyPressChar(_T("v"));
					Sleep(200);
					dm->KeyUpChar(_T("ctrl"));
#else
					dm->SendString2(Hwnd_login,Kent_log_instance->kent_hero_select.at(heros_select_order.at(i) - 1));
#endif
#endif
					tmp_kent_skill_hero_select = Kent_log_instance->kent_skill_hero_select.at(heros_select_order.at(i) - 1);
					Kent_rnd_delay(1000);
					dm->MoveTo(290, 185);
					Kent_rnd_delay(50);
					dm->LeftClick();
					Sleep(2000);
					Kent_log_instance->write_log(_T("尝试选择:"),Kent_log_instance->kent_hero_select.at(heros_select_order.at(i) - 1));
				}else{//随机
					dm->MoveTo(790,122);//搜索
					Kent_rnd_delay(50);
					dm->LeftClick();
					Kent_rnd_delay(500);
					dm->MoveTo(290,185);//随机
					Kent_rnd_delay(500);
					dm->LeftClick();
					Sleep(3000);
					tmp_kent_skill_hero_select = 0;
					Kent_log_instance->write_log(_T("最终还是随机选择"));
					break;
				}
			}
			add_order.at(0)=_T("r");
			switch (tmp_kent_skill_hero_select)
			{//加点顺序
			case 0:add_order.at(1)=_T("q");add_order.at(2)=_T("w");add_order.at(3)=_T("e");break;
			case 1:add_order.at(1)=_T("q");add_order.at(2)=_T("e");add_order.at(3)=_T("w");break;
			case 2:add_order.at(1)=_T("w");add_order.at(2)=_T("q");add_order.at(3)=_T("e");break;
			case 3:add_order.at(1)=_T("w");add_order.at(2)=_T("e");add_order.at(3)=_T("q");break;
			case 4:add_order.at(1)=_T("e");add_order.at(2)=_T("q");add_order.at(3)=_T("w");break;
			case 5:add_order.at(1)=_T("e");add_order.at(2)=_T("w");add_order.at(3)=_T("q");break;
			default:add_order.at(1)=_T("q");add_order.at(2)=_T("w");add_order.at(3)=_T("e");break;
			}
		}
		gamestage_ctrl();
		if(isselect())
		{
			dm->MoveTo(780,455);//开始
			Kent_rnd_delay(500);
			dm->LeftClick();
			Sleep(3000);
		}
	}
	script_time =CTime::GetCurrentTime();
	return true;
}
bool kent_windows::Kent_do_gameover(void)
{
	if(gameover_none != isgameover_num){
		
VMProtectBeginUltra("Kent_do_start VMProtectIsDebugger");//Kent_do_start VMProtectIsDebugger
#ifndef _DEBUG
	if(!VMProtectIsDebuggerPresent(true)){
		if(rand()%20 < 3){//随机行为进行验证
			if(!Kent_log_instance->kss_check()){
				exit(0);
			}
		}
	}
#endif
VMProtectEnd();

VMProtectBeginUltra("game over");//game over
	do_first_add = false;//清空加点
		//kent_TerminateProcess(_T("CrossProxy.exe"));
#ifdef _kent_background_
		dm->EnableFakeActive(1);
#endif
		Sleep(1000);
		if(gameover_win == isgameover_num || gameover_lose == isgameover_num){
			if(m_IsSmallWindow){
				dm->MoveTo(507, 569);
				Kent_rnd_delay(200);
				dm->MoveTo(517, 569);
			}else{
				dm->MoveTo(645, 545);
				Kent_rnd_delay(200);
				dm->MoveTo(645, 545);
			}
		}else{
			if(m_IsSmallWindow){
				dm->MoveTo(507, 481);
				Kent_rnd_delay(200);
				dm->MoveTo(517, 481);
			}else{
				dm->MoveTo(635,456);
				Kent_rnd_delay(200);
				dm->MoveTo(645,456);
			}
		}
        dm->LeftClick();
		Sleep(2000);
#ifdef _kent_background_
		dm->EnableFakeActive(0);
		dm->UnBindWindow();
#endif

		if(Kent_log_instance->kent_nextshutdown){
			Kent_log_instance->kent_nextshutdown = false;
			system("shutdown -s -t 10");
			return false;
		}

		if(Kent_log_instance->kent_nextstop){
			Kent_log_instance->kent_nextstop = false;
			return false;
		}

		if(Kent_log_instance->kent_shutdown){
			CTime now_time=CTime::GetCurrentTime();//获取当前时间
			CTimeSpan timeSpan = now_time - start_time;
			if(Kent_log_instance->kent_shutdown_hour < (double)timeSpan.GetTotalMinutes()/60){
				system("shutdown -s -t 10");
				return false;
			}
		}

		Sleep(10000);
		if(Hwnd_game){
			dm->SetWindowState(Hwnd_game,13);
			dm->SetWindowState(Hwnd_login,12);
			Sleep(2000);
		}
		if(kent_overing!=kent_stage_last){
			if(gameover_lose==isgameover_num){
				lose_num += 1;
			}else{
				win_num += 1;
			}
		}

		dm->SetWindowState(Hwnd_login,5);
		if(!Kent_log_instance->kss_check()){
			exit(0);
		}
#ifdef _kent_background_
		dm->EnableFakeActive(0);//假激活
#endif
		script_time =CTime::GetCurrentTime();
VMProtectEnd();
	}else{
		Kent_rnd_delay(1000);
	}
	return true;
}
/*************游戏private***************/
bool kent_windows::get_location()
{
	VARIANT loc_x1, loc_y1,loc_x2, loc_y2,loc_x3, loc_y3,loc_x4, loc_y4;

	if(m_IsSmallWindow){
		dm->FindPic(741, 517, 1024, 768, file_name(_T("位置5.bmp")), _T("202020"), 0.9, 0, &loc_x1, &loc_y1);
		if(loc_x1.intVal>0){
			location.x=loc_x1.intVal+26;
			location.y=loc_y1.intVal+23;
		}else{
			dm->FindPic(741, 517, 1024, 768, file_name(_T("位置6.bmp")), _T("202020"), 0.9, 0, &loc_x2, &loc_y2);
			if(loc_x2.intVal>0){
				location.x=loc_x2.intVal+26;
				location.y=loc_y2.intVal+23;
			}else{
				dm->FindPic(741, 517, 1024, 768, file_name(_T("位置7.bmp")), _T("202020"), 0.9, 0, &loc_x3, &loc_y3);
				 if(loc_x3.intVal>0){
					location.x=loc_x3.intVal+26;
					location.y=loc_y3.intVal+23;
				 }else{
					 dm->FindPic(741, 517, 1024, 768, file_name(_T("位置8.bmp")), _T("202020"), 0.9, 0, &loc_x4, &loc_y4);
					 if(loc_x4.intVal>0){
						location.x=loc_x4.intVal+26;
						location.y=loc_y4.intVal+23;
					 }else{
						 return false;
					 }
				 }
			}
		}
	}else{
		dm->FindPic(1050, 540, 1280, 720, file_name(_T("位置1.bmp")), _T("202020"), 0.9, 0, &loc_x1, &loc_y1);
		if(loc_x1.intVal>0){
			location.x=loc_x1.intVal+30;
			location.y=loc_y1.intVal+22;
		}else{
			dm->FindPic(1050, 540, 1280, 720, file_name(_T("位置2.bmp")), _T("202020"), 0.9, 0, &loc_x2, &loc_y2);
			if(loc_x2.intVal>0){
				location.x=loc_x2.intVal+30;
				location.y=loc_y2.intVal+22;
			}else{
				dm->FindPic(1050, 540, 1280, 720, file_name(_T("位置3.bmp")), _T("202020"), 0.9, 0, &loc_x3, &loc_y3);
				 if(loc_x3.intVal>0){
					location.x=loc_x3.intVal+30;
					location.y=loc_y3.intVal+22;
				 }else{
					 dm->FindPic(1050, 540, 1280, 720, file_name(_T("位置4.bmp")), _T("202020"), 0.9, 0, &loc_x4, &loc_y4);
					 if(loc_x4.intVal>0){
						location.x=loc_x4.intVal+30;
						location.y=loc_y4.intVal+22;
					 }else{
						 return false;
					 }
				 }
			}
		}
	}
	
	return true;
}
d_game_mouse_shape kent_windows::get_mouseshape()
{
	CString shape=dm->GetCursorShape();
	if(shape.Compare(mouse_shapes_store_needoccupy.at(0)) == 0)
	{
		return mouse_shape_needoccupy;
	}else if(shape.Compare(mouse_shapes_store_attack.at(0))==0 || shape.Compare(mouse_shapes_store_attack.at(1))==0 || shape.Compare(mouse_shapes_store_attack.at(2))==0){
		return mouse_shape_attack;
	}else if(shape.Compare(mouse_shapes_store_occupied.at(0))==0 || shape.Compare(mouse_shapes_store_occupied.at(1))==0 || shape.Compare(mouse_shapes_store_occupied.at(2))==0){
		return mouse_shape_occupied;
	}else if(shape.Compare(mouse_shapes_store_normal.at(0))==0 || shape.Compare(mouse_shapes_store_normal.at(1))==0 || shape.Compare(mouse_shapes_store_normal.at(2))==0){
		return mouse_shape_normal;
	}else{
		return mouse_shape_unknow;
	}
}
bool kent_windows::gettourloc(CPoint loc)
{
    double pi = 3.14,angle = 0;
	CPoint now_loc;
	for(double R=0;R<30;R++)
	{
		now_loc.x=(long)(loc.x+R*cos(angle*pi/180));
		now_loc.y=(long)(loc.y+R*sin(angle*pi/180));
		dm->MoveTo(now_loc.x,now_loc.y);
		Sleep(3);
		if( mouse_shape_needoccupy == get_mouseshape()){
			return true;
		}else{
			angle = angle + 15;
		}
	}
	return false;
}
int kent_windows::kent_strtoi(CString data_in)
{
	int sum=0;
	for(int i=0;i<data_in.GetLength();i++)
	{
		int tmp;
		_stscanf_s(data_in.Mid(i,1),_T("%x"),&tmp);
		sum=sum*16+tmp;
	}
	return sum;
}
bool kent_windows::screen_lock(bool lock)
{
	CString ave_color;
	if(m_IsSmallWindow){
		ave_color = dm->GetAveRGB(988, 552, 1011, 571);
	}else{
		ave_color = dm->GetAveRGB(1248, 519, 1266, 534);
	}
	
	int tmp0=kent_strtoi(ave_color.Mid(0,2));
	int tmp1=kent_strtoi(ave_color.Mid(2,2));
	int tmp2=kent_strtoi(ave_color.Mid(4,2));
	int ave_color_sum =kent_strtoi(ave_color.Mid(0,2))+kent_strtoi(ave_color.Mid(2,2))+kent_strtoi(ave_color.Mid(4,2));
	ave_color_sum=tmp0+tmp1+tmp2;
	bool islock;
	if(ave_color_sum>300)
	{
		islock=true;
	}else{
		islock=false;
	}

	if(islock != lock)
	{
		dm->KeyDown(89);
		Kent_rnd_delay(300);
		dm->KeyUp(89);
		//dm->KeyPressChar(_T("y"));
		//Sleep(30);

		//kent_log.info("y");
		if(true == lock && false == islock){
			//kent_log.info("sapce");
			dm->KeyDown(32);
			Kent_rnd_delay(300);
			dm->KeyUp(32);
			//dm->KeyPressChar(_T("space"));Sleep(30);
		}
	}

	if(m_IsSmallWindow){
		ave_color = dm->GetAveRGB(988, 552, 1011, 571);
	}else{
		ave_color = dm->GetAveRGB(1248, 519, 1266, 534);
	}
	tmp0=kent_strtoi(ave_color.Mid(0,2));
	tmp1=kent_strtoi(ave_color.Mid(2,2));
	tmp2=kent_strtoi(ave_color.Mid(4,2));
	ave_color_sum =kent_strtoi(ave_color.Mid(0,2))+kent_strtoi(ave_color.Mid(2,2))+kent_strtoi(ave_color.Mid(4,2));
	ave_color_sum=tmp0+tmp1+tmp2;
	if(ave_color_sum>300)
	{
		islock=true;
	}else{
		islock=false;
	}
	if(true == islock && false == lock){
		if(m_IsSmallWindow){
			dm->MoveTo(998,562);
		}else{
			dm->MoveTo(1255,527);
		}
		
		dm->LeftClick();
	}
	return true;
}
bool kent_windows::isbuypanel()
{
	VARIANT isbuy_x,isbuy_y;
	if(m_IsSmallWindow){
		dm->FindPic(300, 0, 800, 250,file_name(_T("搜索叉叉small.bmp")),_T("202020"),0.9,0,&isbuy_x,&isbuy_y);
		//kent_log.info("buy panel:%d,%d",isbuy_x.intVal,isbuy_y.intVal);
	}else{
		dm->FindPic(300, 0, 800, 250,file_name(_T("搜索叉叉.bmp")),_T("202020"),0.9,0,&isbuy_x,&isbuy_y);
	}
	if(isbuy_x.intVal>0){return true;}else{return false;}
}
bool kent_windows::iscold(long i)
{
	//技能是否在冷却中
	long iscold_num1 = dm->GetColorNum(addr_skill.at(0).x-14,addr_skill.at(0).y-14,addr_skill.at(0).x+14,addr_skill.at(0).y+14, _T("090DB1-202020"), 1.0);
	long iscold_num2 = dm->GetColorNum(addr_skill.at(0).x-14,addr_skill.at(0).y-14,addr_skill.at(0).x+14,addr_skill.at(0).y+14, _T("F2F2F2-202020"), 1.0);
	if(iscold_num1 > 150 && iscold_num2 > 12)
	{
		return true;
	}else{
		return false;
	}
}
bool kent_windows::ismove()
{
	static int ismove_cnt=0;
	if(location_last==location){
		ismove_cnt+=1;
	}else{
		ismove_cnt=0;
	}
	location_last=location;
	if(ismove_cnt>0){
		Kent_log_instance->write_log(_T("notmove"));
		return false;
	}else{
		return true;
	}
}
bool kent_windows::isdanger()
{
	double distance1=pow((location.x-danger1.x),2)+pow((location.y-danger1.y),2);
	double distance2=pow((location.x-danger2.x),2)+pow((location.y-danger2.y),2);
	if(distance1 < NUM_isdanger || distance2 < NUM_isdanger)
	{
		Kent_log_instance->write_log(_T("danger"));
		return true;
	}else{
		return false;
	}
}
bool kent_windows::isinprocess()
{
	VARIANT isinprocess_x, isinprocess_y;
	if(m_IsSmallWindow){
		dm->FindPic(358, 590, 665, 621, file_name(_T("正在占领防御塔.bmp")), _T("303030"), 0.9, 0, &isinprocess_x, &isinprocess_y);
	}else{
		dm->FindPic(425, 530, 830, 566, file_name(_T("正在占领防御塔.bmp")), _T("303030"), 0.9, 0, &isinprocess_x, &isinprocess_y);
	}
	
	if(isinprocess_x.intVal>0)
	{
		Kent_log_instance->write_log(_T("inprocess"));
		return true;
	}else{
		return false;
	}
}
bool kent_windows::isdie()
{
	long white_num;
	if(m_IsSmallWindow){
		white_num=dm->GetColorNum(25, 708, 55, 723, _T("ffffff-000000"), 1.0);
	}else{
		white_num=dm->GetColorNum(25, 660, 55, 675, _T("ffffff-000000"), 1.0);
	}
	CString AveHSV0 = dm->GetAveHSV(55,133, 150, 233);
	CString AveHSV1 = dm->GetAveHSV(900,172, 1000,272);
	vector<CString> AveHSV0_vector = Kent_log_instance->kent_split(AveHSV0,_T("."));
	vector<CString> AveHSV1_vector = Kent_log_instance->kent_split(AveHSV0,_T("."));
	if(white_num > 8 && (_ttoi(AveHSV0_vector.at(1)) < 20 || _ttoi(AveHSV1_vector.at(1)) < 20))
	{
		Kent_log_instance->write_log(_T("die"));
		return true;
	}else{
		return false;
	}
}
bool kent_windows::isinitial()
{
	VARIANT isinitial_x0, isinitial_y0,isinitial_x1, isinitial_y1,isinitial_x2, isinitial_y2,isinitial_x3, isinitial_y3;
	if(m_IsSmallWindow){
		dm->FindPic( 970, 6, 1013, 26, file_name(_T("00.bmp")), _T("505050"), 0.8, 0, &isinitial_x0, &isinitial_y0);
		dm->FindPic( 970, 6, 1013, 26, file_name(_T("01.bmp")), _T("505050"), 0.8, 0, &isinitial_x1, &isinitial_y1);
		dm->FindPic( 970, 6, 1013, 26, file_name(_T("0.bmp")), _T("505050"), 0.8, 0, &isinitial_x2, &isinitial_y2);
		dm->FindPic( 970, 6, 1013, 26, file_name(_T("1.bmp")), _T("505050"), 0.8, 0, &isinitial_x3, &isinitial_y3);
	}else{
		dm->FindPic( 1226, 6, 1248, 26, file_name(_T("00.bmp")), _T("505050"), 0.8, 0, &isinitial_x0, &isinitial_y0);
		dm->FindPic( 1226, 6, 1248, 26, file_name(_T("01.bmp")), _T("505050"), 0.8, 0, &isinitial_x1, &isinitial_y1);
		dm->FindPic( 1245, 6, 1260, 26, file_name(_T("0.bmp")), _T("505050"), 0.8, 0, &isinitial_x2, &isinitial_y2);
		dm->FindPic( 1245, 6, 1260, 26, file_name(_T("1.bmp")), _T("505050"), 0.8, 0, &isinitial_x3, &isinitial_y3);
	}
	if(isinitial_x0.intVal>0){
		return true;
	}else if(isinitial_x1.intVal>0){
		if(isinitial_x2.intVal>0){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
bool kent_windows::ishealth()
{
	CString health_color;
	CString health_color1;
	if(m_IsSmallWindow){
		health_color=dm->GetColor(460, 740);
		health_color1=dm->GetColor(620, 740);
	}else{
		health_color=dm->GetColor(577, 696);
		health_color1 = dm->GetColor(750, 696);
	}

	if(kent_strtoi(health_color.Mid(0,2))+kent_strtoi(health_color.Mid(2,2))+kent_strtoi(health_color.Mid(4,2))<150 && kent_strtoi(health_color1.Mid(0,2))+kent_strtoi(health_color1.Mid(2,2))+kent_strtoi(health_color1.Mid(4,2))<100)
	{
		Kent_log_instance->write_log(_T("nothealth"));
		return false;
	}else{
		return true;
	}
}
bool kent_windows::isneedadd()
{
	VARIANT isadd_x, isadd_y;
	if(m_IsSmallWindow){
		dm->FindPic(399, 630, 573, 666, file_name(_T("加点.bmp")),_T("353535"),0.8,0, &isadd_x, &isadd_y);
	}else{
		dm->FindPic(526, 579, 704, 625, file_name(_T("加点.bmp")),_T("353535"),0.8,0, &isadd_x, &isadd_y);
	}
	if(isadd_x.intVal>0){
		return true;
	}else{
		return false;
	}
}
int kent_windows::nearesttour()
{
	vector<CPoint>::iterator iter;
	for(unsigned i=0;i<tour1.size();i++){
		double dis=pow(tour1.at(i).x - location.x,2)+pow(tour1.at(i).y - location.y,2);
		if(dis < NUM_isneartour){
			return i;
		}
	}
	return -1;
}
bool kent_windows::isenemyexist()
{
	VARIANT enemy_x0, enemy_y0,enemy_x1, enemy_y1;
	if(m_IsSmallWindow){
		dm->FindPic(150, 100, 874, 668, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0, &enemy_x0, &enemy_y0);
		dm->FindPic(150, 100, 874, 668, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0, &enemy_x1, &enemy_y1);
	}else{
		dm->FindPic(150, 100, 1130, 620, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0, &enemy_x0, &enemy_y0);
		dm->FindPic(150, 100, 1130, 620, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0, &enemy_x1, &enemy_y1);
	}
	if(enemy_x0.intVal>0 || enemy_x1.intVal>0)
	{
		return true;
	}
	else{
		return false;
	}
}
bool kent_windows::isneedback(int last_tour)
{
	double dis=pow((tour1.at(last_tour).x-location.x),2)+pow((tour1.at(last_tour).y-location.y),2);
	int red_num=dm->GetColorNum(tour1.at(last_tour).x-18, tour1.at(last_tour).y-18, tour1.at(last_tour).x+18,tour1.at(last_tour).y+18, _T("ff0000-603030"), 1.0);
	if(dis < NUM_isneartour1 && red_num > 40){
		return true;
	}else{
		return false;
	}
}
bool kent_windows::isbeside_protect_tour()
{
	double dis = pow((tour1.at(stay_which_tour).x - location.x),2) + pow((tour1.at(stay_which_tour).y - location.y),2);
	if(dis < pow(33,2)){
		return true;
	}else{
		return false;
	}
}
bool kent_windows::game_buy()
{
	Kent_log_instance->write_log(_T("购买"));
	Sleep(2000);
	if(false == isbuypanel()){
		dm->KeyPressChar(_T("p"));//购买P
		Sleep(2000);
	}
	Sleep(1000);
	VARIANT isbuy_x,isbuy_y,buy_x,buy_y;
	if(m_IsSmallWindow){
		dm->FindPic(300, 0, 800, 250,file_name(_T("搜索叉叉small.bmp")),_T("202020"),0.9,0,&isbuy_x,&isbuy_y);
		//kent_log.info("buy panel:%d,%d",isbuy_x.intVal,isbuy_y.intVal);
	}else{
		dm->FindPic(300, 0, 800, 250,file_name(_T("搜索叉叉.bmp")),_T("202020"),0.9,0,&isbuy_x,&isbuy_y);
	}
	if(isbuy_x.intVal>0){//已经打开了购买
		
		if(m_IsSmallWindow){
			dm->MoveTo(isbuy_x.intVal-300,isbuy_y.intVal-30);//打开推荐页面
		}else{
			dm->MoveTo(isbuy_x.intVal-457,isbuy_y.intVal-24);//打开推荐页面
		}
		dm->LeftClick();
		Sleep(500);

		dm->MoveTo(isbuy_x.intVal-8,isbuy_y.intVal-31);//小的图标
		dm->LeftClick();
		Sleep(500);

		dm->MoveTo(isbuy_x.intVal,isbuy_y.intVal+250);
		Sleep(1500);

		dm->FindPic( isbuy_x.intVal - 553, isbuy_y.intVal + 129, isbuy_x.intVal, isbuy_y.intVal + 345, file_name(_T("buy.bmp")), _T("101010"), 1, 0, &buy_x, &buy_y);
		int tmp_x = buy_x.intVal;
		int tmp_y = buy_y.intVal;
		for(int i=0;i<4;i++)
		{
			if(buy_x.intVal>0 && buy_y.intVal>0){
				dm->MoveTo(buy_x.intVal + 20, buy_y.intVal + 40);
				Kent_rnd_delay(50);
				dm->LeftDoubleClick();
				Sleep(500);
				dm->MoveTo(isbuy_x.intVal,isbuy_y.intVal+250);
				Sleep(500);
			}else{
				break;
			}
			dm->FindPic( isbuy_x.intVal - 553, isbuy_y.intVal + 129, isbuy_x.intVal, isbuy_y.intVal + 345, file_name(_T("buy.bmp")), _T("101010"), 1, 0, &buy_x, &buy_y);
			if(tmp_x == buy_x.intVal && tmp_y == buy_y.intVal){break;}
		}

		VARIANT buy1_x,buy1_y;
		dm->FindPic( isbuy_x.intVal - 553, isbuy_y.intVal + 129, isbuy_x.intVal, isbuy_y.intVal + 345, file_name(_T("buy1.bmp")), _T("101010"), 1, 0, &buy1_x, &buy1_y);
		dm->MoveTo(buy1_x.intVal + 20, buy1_y.intVal + 40);
		dm->LeftClick();
		Sleep(500);
		dm->MoveTo(isbuy_x.intVal,isbuy_y.intVal+250);
		Sleep(500);
		dm->FindPic( isbuy_x.intVal + 53, isbuy_y.intVal + 47, isbuy_x.intVal+380, isbuy_y.intVal + 350, file_name(_T("buy.bmp")), _T("101010"), 1, 0, &buy_x, &buy_y);
		tmp_x = buy_x.intVal;
		tmp_y = buy_y.intVal;
		for(int i=0;i<400;i++)
		{
			if(buy_x.intVal>0 && buy_y.intVal>0){
				dm->MoveTo(buy_x.intVal + 20, buy_y.intVal + 40);
				Kent_rnd_delay(50);
				dm->LeftDoubleClick();
				Sleep(500);
				dm->MoveTo(isbuy_x.intVal,isbuy_y.intVal+250);
				Sleep(500);
			}else{
				break;
			}
			dm->FindPic( isbuy_x.intVal + 53, isbuy_y.intVal + 47, isbuy_x.intVal+380, isbuy_y.intVal + 350, file_name(_T("buy.bmp")), _T("101010"), 1, 0, &buy_x, &buy_y);
			if(tmp_x == buy_x.intVal && tmp_y == buy_y.intVal){break;}
		}

		dm->FindPic( isbuy_x.intVal - 553, isbuy_y.intVal + 129, isbuy_x.intVal, isbuy_y.intVal + 345, file_name(_T("buy.bmp")), _T("101010"), 1, 0, &buy_x, &buy_y);
		tmp_x = buy_x.intVal;
		tmp_y = buy_y.intVal;
		for(int i=0;i<4;i++)
		{
			if(buy_x.intVal>0 && buy_y.intVal>0){
				dm->MoveTo(buy_x.intVal + 20, buy_y.intVal + 40);
				Kent_rnd_delay(50);
				dm->LeftDoubleClick();
				Sleep(500);
				dm->MoveTo(isbuy_x.intVal,isbuy_y.intVal+250);
				Sleep(500);
			}else{
				break;
			}
			dm->FindPic( isbuy_x.intVal - 553, isbuy_y.intVal + 129, isbuy_x.intVal, isbuy_y.intVal + 345, file_name(_T("buy.bmp")), _T("101010"), 1, 0, &buy_x, &buy_y);
			if(tmp_x == buy_x.intVal && tmp_y == buy_y.intVal){break;}
		}

	}
	Sleep(1000);
	if(true == isbuypanel()){
		dm->KeyPressChar(_T("p"));//购买P
		Sleep(2000);
	}
	screen_lock (true);//视角锁定
	Sleep(1000);
	script_time =CTime::GetCurrentTime();
	return true;
}
bool kent_windows::game_add_skill()
{
	dm->KeyDownChar(_T("ctrl"));//alt
	Kent_rnd_delay(40);
	if(!Kent_log_instance->is_dominate_match_mode){//非统治
		dm->KeyPressChar(add_order.at(0));
		int tmp = rand();
		for(int i=0;i<3;i++){
			dm->KeyPressChar(add_order.at((i + tmp)%3 + 1));
			Kent_rnd_delay(40);
		}
	}else{//统治
		for(int i=0;i<4;i++){
			dm->KeyPressChar(add_order.at(i));
			Kent_rnd_delay(40);
		}
	}
	dm->KeyUpChar(_T("ctrl"));
	return true;
}
/*************游戏public***************/
bool kent_windows::game_data_init()
{
	//游戏参数设定
	target=0;
	bool tmp_restarted;//是否重启
	if(Kent_log_instance->is_common_match_mode || Kent_log_instance->is_distort_match_mode || Kent_log_instance->is_dominate_match_mode || Kent_log_instance->is_colosseum_match_mode){
		tmp_restarted = false;
	}else{
		tmp_restarted = true;
	}

	if(m_IsSmallWindow){
		addr_skill.at(0).SetPoint(420, 696);addr_skill.at(1).SetPoint(463, 698);addr_skill.at(2).SetPoint(505, 699);addr_skill.at(3).SetPoint(548, 698);addr_skill.at(4).SetPoint(597, 698);addr_skill.at(5).SetPoint(636, 700);
		tour1.at(0).SetPoint(926, 615);tour1.at(1).SetPoint(866, 658);tour1.at(2).SetPoint(891, 729);tour1.at(3).SetPoint(961, 730);tour1.at(4).SetPoint(987, 658);
		tour2.at(0).SetPoint(530, 400);tour2.at(1).SetPoint(530, 400);tour2.at(2).SetPoint(530, 400);tour2.at(3).SetPoint(530, 400);tour2.at(4).SetPoint(530, 400);
		tour_stay.at(0).SetPoint(926, 602);tour_stay.at(1).SetPoint(846, 650);tour_stay.at(2).SetPoint(877, 742);tour_stay.at(3).SetPoint(973, 744);tour_stay.at(4).SetPoint(1004, 651);
	}else{
		addr_skill.at(0).SetPoint(555,655);addr_skill.at(1).SetPoint(595,655);addr_skill.at(2).SetPoint(640,655);addr_skill.at(3).SetPoint(683,655);addr_skill.at(4).SetPoint(720,658);addr_skill.at(5).SetPoint(757,658);
		tour1.at(0).SetPoint(1189,577);tour1.at(1).SetPoint(1133,618);tour1.at(2).SetPoint(1155,686);tour1.at(3).SetPoint(1222,686);tour1.at(4).SetPoint(1245,618);
		tour2.at(0).SetPoint(605,375);tour2.at(1).SetPoint(605,360);tour2.at(2).SetPoint(645,305);tour2.at(3).SetPoint(605,305);tour2.at(4).SetPoint(625,360);
		tour_stay.at(0).SetPoint(1187,562);tour_stay.at(1).SetPoint(1112,610);tour_stay.at(2).SetPoint(1146,695);tour_stay.at(3).SetPoint(1229,695);tour_stay.at(4).SetPoint(1263,610);
	}

	//if(match_mode_normal_machine == Kent_log_instance->kent_game_match_mode || match_mode_normal_machine_hard == Kent_log_instance->kent_game_match_mode || !Kent_log_instance->is_common_match_mode){
	if(true == Kent_log_instance->is_common_match_mode || (tmp_restarted && (match_mode_normal_machine == Kent_log_instance->kent_game_match_mode || match_mode_normal_machine_hard == Kent_log_instance->kent_game_match_mode))){//召唤师峡谷
		CString tmp0,tmp1;//down
		if(m_IsSmallWindow){
			tmp0 = dm->GetAveHSV(836, 729, 875, 760);//down
			tmp1 = dm->GetAveHSV(993, 579, 1019, 606);//up
		}else{
			tmp0 = dm->GetAveHSV(1101, 654, 1169, 713);//down
			tmp1 = dm->GetAveHSV(1220, 542, 1273, 593);//up
		}
		vector<CString> tmp_vector0 = Kent_log_instance->kent_split(tmp0,_T("."));
		vector<CString> tmp_vector1 = Kent_log_instance->kent_split(tmp1,_T("."));
		if(_ttoi(tmp_vector0.at(2)) > _ttoi(tmp_vector1.at(2))){//down
			kent_home = kent_home_normal_down;
			if(m_IsSmallWindow){
				myhome_loc.x = 843; myhome_loc.y = 743; armyhome_loc.x = 997;armyhome_loc.y = 599;
			}else{
				myhome_loc.x = 1105; myhome_loc.y = 705; armyhome_loc.x = 1261;armyhome_loc.y = 560;
			}
			Kent_log_instance->write_log(_T("kent_home_normal_down"));
		}else{
			kent_home = kent_home_normal_up;
			if(m_IsSmallWindow){
				myhome_loc.x = 997; myhome_loc.y = 599; armyhome_loc.x = 843;armyhome_loc.y = 743;
			}else{
				myhome_loc.x = 1265; myhome_loc.y = 554; armyhome_loc.x = 1127;armyhome_loc.y = 690;
			}
			Kent_log_instance->write_log(_T("kent_home_normal_up"));
		}
		kent_normal_started = false;//没有完全开始
		Kent_log_instance->is_common_match_mode = true;
	}else if(true == Kent_log_instance->is_distort_match_mode || (tmp_restarted && match_mode_Distort == Kent_log_instance->kent_game_match_mode)){//扭曲丛林
		if(m_IsSmallWindow){
			CString tmp0 = dm->GetAveHSV(836, 658, 865, 692);//left
			CString tmp1 = dm->GetAveHSV(1001, 663, 1015, 693);//right
			vector<CString> tmp_vector0 = Kent_log_instance->kent_split(tmp0,_T("."));
			vector<CString> tmp_vector1 = Kent_log_instance->kent_split(tmp1,_T("."));
			if(_ttoi(tmp_vector0.at(2)) > _ttoi(tmp_vector1.at(2))){//left
				kent_home = kent_home_left;
				myhome_loc.x = 864; myhome_loc.y = 683; armyhome_loc.x = 992;armyhome_loc.y = 681;
				Kent_log_instance->write_log(_T("kent_home_left"));
			}else{//right
				kent_home = kent_home_right;
				myhome_loc.x = 992; myhome_loc.y = 681; armyhome_loc.x = 864;armyhome_loc.y = 683;
				Kent_log_instance->write_log(_T("kent_home_right"));
			}
		}else{
			CString tmp0 = dm->GetAveHSV(1105, 613, 1119, 652);//left
			CString tmp1 = dm->GetAveHSV(1259, 613, 1274, 653);//right
			vector<CString> tmp_vector0 = Kent_log_instance->kent_split(tmp0,_T("."));
			vector<CString> tmp_vector1 = Kent_log_instance->kent_split(tmp1,_T("."));
			if(_ttoi(tmp_vector0.at(2)) > _ttoi(tmp_vector1.at(2))){//left
				kent_home = kent_home_left;
				myhome_loc.x = 1133; myhome_loc.y = 638; armyhome_loc.x = 1241;armyhome_loc.y = 638;
				Kent_log_instance->write_log(_T("kent_home_left"));
			}else{//right
				kent_home = kent_home_right;
				myhome_loc.x = 1241; myhome_loc.y = 638; armyhome_loc.x = 1133;armyhome_loc.y = 638;
				Kent_log_instance->write_log(_T("kent_home_right"));
			}
		}
		kent_distort_started = false;//没有完全开始
		Kent_log_instance->is_distort_match_mode = true;
	}else if(true == Kent_log_instance->is_colosseum_match_mode || (tmp_restarted && match_mode_Colosseum == Kent_log_instance->kent_game_match_mode)){//大乱斗
		if(m_IsSmallWindow){
			CString tmp0 = dm->GetAveHSV(839, 729, 863, 755);//left
			CString tmp1 = dm->GetAveHSV(989, 585, 1015, 613);//right
			vector<CString> tmp_vector0 = Kent_log_instance->kent_split(tmp0,_T("."));
			vector<CString> tmp_vector1 = Kent_log_instance->kent_split(tmp1,_T("."));
			if(_ttoi(tmp_vector0.at(2)) > _ttoi(tmp_vector1.at(2))){//left
				kent_home = kent_home_normal_down;
				myhome_loc.x = 845; myhome_loc.y = 746; armyhome_loc.x = 1002;armyhome_loc.y = 598;
				Kent_log_instance->write_log(_T("kent_home_normal_down"));
			}else{//right
				kent_home = kent_home_normal_up;
				myhome_loc.x = 1002; myhome_loc.y = 598; armyhome_loc.x = 845;armyhome_loc.y = 746;
				Kent_log_instance->write_log(_T("kent_home_normal_up"));
			}
		}else{
			CString tmp0 = dm->GetAveHSV(1104, 680, 1138, 710);//left
			CString tmp1 = dm->GetAveHSV(1241, 543, 1275, 573);//right
			vector<CString> tmp_vector0 = Kent_log_instance->kent_split(tmp0,_T("."));
			vector<CString> tmp_vector1 = Kent_log_instance->kent_split(tmp1,_T("."));
			if(_ttoi(tmp_vector0.at(2)) > _ttoi(tmp_vector1.at(2))){//left
				kent_home = kent_home_normal_down;
				myhome_loc.x = 1132; myhome_loc.y = 681; armyhome_loc.x = 1244;armyhome_loc.y = 578;
				Kent_log_instance->write_log(_T("kent_home_normal_down"));
			}else{//right
				kent_home = kent_home_normal_up;
				myhome_loc.x = 1244; myhome_loc.y = 578; armyhome_loc.x = 1132;armyhome_loc.y = 681;
				Kent_log_instance->write_log(_T("kent_home_normal_up"));
			}
		}
		Sleep(30*1000);
		Kent_log_instance->is_colosseum_match_mode = true;
	}else{//统治战场
		if(m_IsSmallWindow){
			CString tmp0 = dm->GetAveHSV(833, 686,860, 730);//left
			CString tmp1 = dm->GetAveHSV(993, 687, 1017, 719);//right
			vector<CString> tmp_vector0 = Kent_log_instance->kent_split(tmp0,_T("."));
			vector<CString> tmp_vector1 = Kent_log_instance->kent_split(tmp1,_T("."));
			if(_ttoi(tmp_vector0.at(2)) > _ttoi(tmp_vector1.at(2))){//left
				kent_home = kent_home_left;
				myhome_loc.x = 840; myhome_loc.y = 709; armyhome_loc.x = 1011;armyhome_loc.y = 708;
				Kent_log_instance->write_log(_T("kent_home_left"));
			}else{//right
				kent_home = kent_home_right;
				armyhome_loc.x = 840; armyhome_loc.y = 709; myhome_loc.x = 1011;myhome_loc.y = 708;
				Kent_log_instance->write_log(_T("kent_home_right"));
			}
		}else{
			CString tmp0 = dm->GetAveHSV(1104, 642,1127, 688);//left
			CString tmp1 = dm->GetAveHSV(1252, 641, 1273, 688);//right
			vector<CString> tmp_vector0 = Kent_log_instance->kent_split(tmp0,_T("."));
			vector<CString> tmp_vector1 = Kent_log_instance->kent_split(tmp1,_T("."));
			if(_ttoi(tmp_vector0.at(2)) > _ttoi(tmp_vector1.at(2))){//left
				kent_home = kent_home_left;
				myhome_loc.x = 1108; myhome_loc.y = 662; armyhome_loc.x = 1268;armyhome_loc.y = 663;
				Kent_log_instance->write_log(_T("kent_home_left"));
			}else{//right
				kent_home = kent_home_right;
				armyhome_loc.x = 1244; armyhome_loc.y = 578; myhome_loc.x = 1132;myhome_loc.y = 681;
				Kent_log_instance->write_log(_T("kent_home_right"));
			}
		}
		Sleep(30*1000);
		Kent_log_instance->is_dominate_match_mode = true;
	}
	script_time =CTime::GetCurrentTime();
	
	game_buy();//购买
	if(Kent_log_instance->kent_force_downcpu){
		dm->DownCpu(40);//强制降低cpu
	}
	
	return true;
}
bool kent_windows::game_die()
{
	Kent_log_instance->write_log(_T("Kent_game_die"));
	//过程结束点
	if(false == isdie()){
		game_state=Kent_game_init;//死亡结束，复活，触发初始化
	}
	if(Kent_game_die != game_state_last  && Kent_game_die == game_state){
		game_buy();
		dm->KeyPressChar(_T("4"));
		Sleep(2000);
		int chance;
		switch(Kent_log_instance->kent_hero_die_call_chance){
		case die_call_chance_0:chance=0;break;
		case die_call_chance_10:chance=10;break;
		case die_call_chance_20:chance=20;break;
		case die_call_chance_40:chance=40;break;
		default:chance=0;break;
		}
		if(rand()%100 < chance){//选择随机喊话内容
			vector<CString> die_call_words = Kent_log_instance->kent_split(Kent_log_instance->kent_hero_die_call,_T("|"));
			if(die_call_words.size()){
				dm->KeyPressChar(_T("enter"));
				Sleep(1000);
				dm->SendString2(Hwnd_game,die_call_words.at(rand()%die_call_words.size()));
				Sleep(1000);
				dm->KeyPressChar(_T("enter"));
				Sleep(1000);
			}
		}
	}
	Sleep(500);
	return true;
}
bool kent_windows::game_attack()
{
	Kent_log_instance->write_log(_T("Kent_game_attack"));
	for(int j =0; j<4;j++)
	{
		for(int i=0;i<4;i++)
		{
			VARIANT enemy_x0,enemy_y0,enemy_x1, enemy_y1;
			int enemy_x = 640,enemy_y = 307;
			if(m_IsSmallWindow){
				dm->FindPic(150, 100, 874, 668, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0, &enemy_x0, &enemy_y0);
				dm->FindPic(150, 100, 874, 668, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0, &enemy_x1, &enemy_y1);
			}else{
				dm->FindPic(150, 100, 1130, 620, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0, &enemy_x0, &enemy_y0);
				dm->FindPic(150, 100, 1130, 620, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0, &enemy_x1, &enemy_y1);
			}
			if(enemy_x0.intVal>0){
				enemy_x=enemy_x0.intVal - 65;
				enemy_y=enemy_y0.intVal + 119;
			}else if(enemy_x1.intVal>0){
				enemy_x = enemy_x1.intVal + 61;
				enemy_y = enemy_y1.intVal + 119;
			}
			dm->MoveTo(enemy_x,enemy_y);
			if(enemy_x0.intVal>0 || enemy_x1.intVal>0 || mouse_shape_attack == get_mouseshape())
			{
				if(mouse_shape_attack == get_mouseshape()){
					dm->RightClick();//普攻
				}else{
					dm->KeyDownChar(_T("shift"));//alt
					dm->RightClick();//普攻
					dm->KeyUpChar(_T("shift"));
				}
				dm->KeyPressChar(attack.at(i));//
				dm->KeyDownChar(_T("alt"));//alt
				dm->KeyPressChar(attack.at(i));//
				dm->KeyUpChar(_T("alt"));
				Kent_log_instance->write_log(_T("按键"),attack.at(i));
			}
		}
		if(false == ishealth()){
			dm->KeyPressChar(_T("d"));//
			dm->KeyPressChar(_T("f"));//
		}
		Sleep(150);
	}
	for(int i=0;i<5;i++)
	{
		game_go_backward();
		Sleep(250);
	}
	

	return true;
}
/*************游戏统治战场***************/
bool kent_windows::game_init()
{
	Kent_log_instance->write_log(_T("Kent_game_init"));
	get_location();//初始化location
	ismove();//初始化ismove
	target=rand()%5;
	if(Kent_log_instance->kent_hero_occupy_rand_die)//复活后占塔模式随机
	{
		switch (rand()%4)
		{
		case 0:Kent_log_instance->kent_hero_occupy_mode = occupy_mode_rand;break;
		case 1:Kent_log_instance->kent_hero_occupy_mode = occupy_mode_clockwise;break;
		case 2:Kent_log_instance->kent_hero_occupy_mode = occupy_mode_counterclockwise;break;
		case 3:Kent_log_instance->kent_hero_occupy_mode = occupy_mode_standby;break;
		default:
			break;
		}
	}
	if(occupy_mode_standby == Kent_log_instance->kent_hero_occupy_mode)
	{
		if(kent_home_right == kent_home){//家在右边
			stay_which_tour = rand() % 2 + 1;
			target = stay_which_tour;
		}else{
			stay_which_tour = rand() % 2 + 3;
			target = stay_which_tour;
		}
	}
	occupy=false;//未努力占领状态
	return true;
}
bool kent_windows::game_detect()
{
	get_location();
	if(Kent_game_occupy==game_state || Kent_game_attack==game_state)
	{
		if(isdie()){
			game_state=Kent_game_die;
			occupy=false;
		}else if(Kent_game_occupy == game_state && false == isinprocess() && true == isenemyexist()){
			game_state=Kent_game_attack;
			occupy=false;
		}else if(Kent_game_attack == game_state && false == isenemyexist()){
			game_state = Kent_game_occupy;
			occupy = false;
		}
	}

	if(-1 == nearesttour() && Kent_game_occupy == game_state)
	{
		for(int i = 0;i<8;i++)
		{
			kent_bat_red = get_batman_red();//获取红兵
			if(kent_bat_red.size()>1){
				int batcnt = rand()%kent_bat_red.size();
				dm->MoveTo(kent_bat_red.at(batcnt).x+32,kent_bat_red.at(batcnt).y+32);
				dm->KeyPressChar(attack.at(i%3));//
				Kent_log_instance->write_log(_T("按键"),attack.at(i%3));
				dm->KeyDownChar(_T("shift"));//alt
				dm->RightClick();//普攻
				dm->KeyUpChar(_T("shift"));
			}else{
				break;
			}
			Sleep(150);
			if(isenemyexist()){
				game_state=Kent_game_attack;
				occupy=false;
				break;
			}
		}
	}
	return true;
}
bool kent_windows::game_tour_occupy()
{
	Kent_log_instance->write_log(_T("Kent_game_occupy"));
	static int near_which_tour_last=-1;
	if(rand()%10<4){
		if(true == isbuypanel())
		{
			dm->KeyPressChar(_T("p"));//关闭购买P
			Kent_rnd_delay(500);
		}
	}
	if(isneedadd()){//加点
		if(!do_first_add){
			game_data_init();
			do_first_add = true;
		}
		game_add_skill();
	}
	get_location();
	int near_which_tour_now=nearesttour();
	if(near_which_tour_now != -1 && near_which_tour_last != near_which_tour_now)//看看最近的这个塔的情况
	{
		occupy=false;//路过该塔，先处理这一个
		target=near_which_tour_now;//记录最近占领的塔，后面一个判断将进行是否回防的判断
	}
	near_which_tour_last=near_which_tour_now;
	if(-1 != near_which_tour_last && -1 == near_which_tour_now && true == isneedback(near_which_tour_last))
	{
		occupy=false;//回防
		target=near_which_tour_last;
	}
	if(true == isinprocess()){
		Kent_rnd_delay(100);
	}else if(true == isdie()){//开始阶段
		Kent_rnd_delay(500);
	}else if(false == occupy){//还没有执行占塔逻辑，占领塔
		screen_lock (false);//解除视角锁定
		dm->MoveTo(tour1.at(target).x, tour1.at(target).y);
		Sleep(200);
		dm->LeftDown();
		Kent_rnd_delay(1000);
		dm->LeftUp();
		Sleep(200);
		if(true == gettourloc(tour2.at(target))){
			dm->RightClick();
			kent_log.info("goto occupy...");
			occupy=true;//改变状态
		}else if(true == isenemyexist()){
			kent_log.info("goto enemy...");
			dm->RightClick();
			occupy=true;//改变状态
		}else{
			kent_log.info("goto next...");
			dm->MoveR(rand()%60-30,rand()%60-30);
			dm->KeyDownChar(_T("shift"));//shift
			dm->RightClick();
			dm->KeyUpChar(_T("shift"));//shift
			if(occupy_mode_rand == Kent_log_instance->kent_hero_occupy_mode){
				target = (target+rand()%4)%5;//随机决定下一个占塔
			}else if(occupy_mode_clockwise == Kent_log_instance->kent_hero_occupy_mode){
				target = (target+4)%5;//顺时针占塔
			}else if(occupy_mode_counterclockwise == Kent_log_instance->kent_hero_occupy_mode){
				target = (target+1)%5;//逆时针占塔
			}else{
				target = (target+rand()%4)%5;//
			}
			occupy = false;//继续占塔
		}
	}else if(!ismove()){
		//target = (target+rand()%4)%5;//随机决定下一个占塔
		occupy=false;
	}else{
		Sleep(300);
	}
	screen_lock (true);//视角锁定
	return true;
}
bool kent_windows::game_tour_standby()
{
	Kent_log_instance->write_log(_T("Kent_game_standby"));
	static int near_which_tour_last=-1;
	if(true == isbuypanel())
	{
		dm->KeyPressChar(_T("p"));//关闭购买P
		Kent_rnd_delay(500);
	}
	get_location();
	int near_which_tour_now=nearesttour();
	if(near_which_tour_now!=-1 && near_which_tour_last!=near_which_tour_now)//看看最近的这个塔的情况
	{
		occupy=false;//路过该塔，先处理这一个
		target=near_which_tour_now;//记录最近占领的塔，后面一个判断将进行是否回防的判断
	}
	near_which_tour_last=near_which_tour_now;
	if(true == isinprocess()){
		Kent_rnd_delay(100);
	}else if(true == isdie()){//开始阶段
		Kent_rnd_delay(500);
	}else if(false == occupy){//还没有执行占塔逻辑，占领塔
		screen_lock (false);//解除视角锁定
		dm->MoveTo(tour1.at(target).x, tour1.at(target).y);
		Sleep(200);
		dm->LeftDown();
		Kent_rnd_delay(1000);
		dm->LeftUp();
		Sleep(200);
		if(true == gettourloc(tour2.at(target))){
			dm->RightClick();
			occupy=true;//改变状态
		}else{
			dm->MoveTo(tour2.at(target).x, tour2.at(target).y);//去那个塔附近
			dm->KeyDownChar(_T("shift"));//shift
			dm->RightClick();
			dm->KeyUpChar(_T("shift"));//shift
			target = stay_which_tour;
		}
		occupy=true;//改变状态
		screen_lock(true);//视角锁定
	}else{
		if(true == isbeside_protect_tour()){//在守护的塔附近
			screen_lock (false);//解除视角锁定
			dm->MoveTo(tour1.at(target).x, tour1.at(target).y);
			dm->LeftClick();
			Sleep(100);
			if(true == gettourloc(tour2.at(target))){//绕圈形式检测塔的位置
				dm->RightClick();
			}else{
				int red_num = dm->GetColorNum(tour1.at(stay_which_tour).x - 30, tour1.at(stay_which_tour).y - 30, tour1.at(stay_which_tour).x + 30, tour1.at(stay_which_tour).y + 30, _T("eb3322-404030"), 1.0);
				if(red_num > 30 || true == isenemyexist()){
					dm->MoveTo(tour1.at(stay_which_tour).x+5-(rand()%10),tour1.at(stay_which_tour).y)+5-(rand()%10);
					dm->KeyDownChar(_T("shift"));//shift移动攻击
					dm->RightClick();
					dm->KeyUpChar(_T("shift"));//shift
				}else{
					dm->MoveTo(tour_stay.at(stay_which_tour).x+rand()%5-rand()%5,tour_stay.at(stay_which_tour).y)+rand()%5-rand()%5;
					dm->KeyDownChar(_T("shift"));//shift移动攻击
					dm->RightClick();
					dm->KeyUpChar(_T("shift"));//shift
				}
			}
			screen_lock (true);//视角锁定
		}else if(false == ismove()){
			occupy=false;
		}else{
			Sleep(300);
		}
	}
	return true;
}
/*************游戏经典战场***************/
#define center_x 620
#define center_y 355
void kent_windows::game_do_normal(){
	if(rand()%10 < 3){
		if(true == isbuypanel()){
			dm->KeyPressChar(_T("p"));//关闭购买P
			Kent_rnd_delay(500);
		}
	}
	screen_lock(true);//锁定视角
	if(isneedadd()){//加点
		if(!do_first_add){
			game_data_init();
			do_first_add = true;
		}
		game_add_skill();
	}
	if(isdie()){//死亡
		game_state=Kent_game_die;
		game_die();
	}else{
		game_state=Kent_game_occupy;//为了兼容
		if(!ishealth()){//没血回家
			game_go_home();
		}
		kent_bat_blue = get_batman_blue();//获取蓝兵
		kent_bat_red = get_batman_red();//获取红兵
		nearest_anmy = get_nearest_anmy();//获取最近的敌人
		if(kent_bat_blue.size() + kent_bat_red.size() > 2){//看到了小兵，开始正常攻防
			kent_normal_started = true;
		}
		if(kent_normal_started){//已经完全开始
			/*************算法核心部分***************/
			int dis;
			if(nearest_anmy.x){
				dis = (int)sqrt(pow(nearest_anmy.x - center_x,2) + pow(nearest_anmy.y - center_y,2));
				//Kent_log_instance->write_log(_T("nearest_anmy_dis:"),dis);
			}else{
				dis = 1000;
			}
			if( dis < 330){
				game_normal_attack();//攻击撤退
				game_go_backward();//撤退
				Sleep(1000);
			}else if(nearest_anmy.x && ishealth() && game_is_need_assist(nearest_anmy)){//敌人存在，并且需要支援
				game_normal_attack();
			}else{
				int safe_dis = get_safe_dis(kent_bat_blue);
				//Kent_log_instance->write_log(_T("safe_distance:"),safe_dis);
				if(kent_bat_red.size() > 0){
					if(safe_dis < 50){//不在安全距离
						//Kent_log_instance->write_log(_T("notin_safe_distance"));
						game_go_backward();//撤退
						Sleep(1000);
					}else{//瞎逛
						game_do_lasthit();//补刀
						CPoint tmp = kent_bat_blue.at(rand() % kent_bat_blue.size());
						dm->MoveTo(tmp.x-2+rand()%4,tmp.y-2+rand()%4);
						dm->KeyDownChar(_T("shift"));//alt
						dm->RightClick();
						dm->KeyUpChar(_T("shift"));
					}
				}else{
					if(game_is_tour_exist() && safe_dis < 60){//塔存在，并且安全距离低
						game_go_backward();//撤退
						Sleep(1000);
					}else{
						game_go_forward();
					}
				}
			}
		}else{//没有完全开始,中间瞎晃
			if(m_IsSmallWindow){
				if(kent_home_normal_down == kent_home){
					dm->MoveTo(914-3+rand()%6,682-3+rand()%6);
				}else{
					dm->MoveTo(945-3+rand()%6,658-3+rand()%6);
				}
			}else{
				if(kent_home_normal_down == kent_home){
					dm->MoveTo(1179-3+rand()%6,635-3+rand()%6);
				}else{
					dm->MoveTo(1204-3+rand()%6,615-3+rand()%6);
				}
			}
			dm->KeyDownChar(_T("shift"));//alt
			dm->RightClick();
			dm->KeyUpChar(_T("shift"));
			Sleep(2000);
			//Kent_log_instance->write_log(_T("not_start_all"));
		}
	}
}
/*************经典战场private***************/
bool kent_windows::game_is_tour_exist()
{
	VARIANT tour_x, tour_y;
	CPoint tour;
	if(m_IsSmallWindow){
		if(kent_home_normal_down == kent_home){
			dm->FindPic(50, 0, 974, 384, file_name(_T("tour.bmp")), _T("202020"), 0.85, 0, &tour_x, &tour_y);
		}else{
			dm->FindPic(50, 384, 974, 768, file_name(_T("tour.bmp")), _T("202020"), 0.85, 0, &tour_x, &tour_y);
		}
	}else{
		if(kent_home_normal_down == kent_home){
			dm->FindPic(50, 0, 1230, 360, file_name(_T("tour.bmp")), _T("202020"), 0.85, 0, &tour_x, &tour_y);
		}else{
			dm->FindPic(50, 360, 1230, 720, file_name(_T("tour.bmp")), _T("202020"), 0.85, 0, &tour_x, &tour_y);
		}
	}
	tour.x = tour_x.intVal + 100;
	tour.y = tour_y.intVal + 150;
	if(tour_x.intVal > 0){
		int tmp = (int)sqrt(pow(tour.x - center_x,2) + (int)pow(tour.y - center_y,2));
		//Kent_log_instance->write_log(_T("tour_dis:"),tmp);
		if(tmp < 450){
			//Kent_log_instance->write_log(_T("tour_protect.............."));
			return true;
		}else{
			return false;
		}
	}else{
		//Kent_log_instance->write_log(_T("no tour exist..."));
		return false;
	}
}
void kent_windows::game_go_forward(){//前进
	dm->MoveTo(armyhome_loc.x-3+rand()%6,armyhome_loc.y-3+rand()%6);
	dm->KeyDownChar(_T("shift"));//alt
	dm->RightClick();
	dm->KeyUpChar(_T("shift"));
	Sleep(200);
	//Kent_log_instance->write_log(_T("go_forward"));
}
void kent_windows::game_go_backward(){//后退
	dm->MoveTo(myhome_loc.x-3+rand()%6,myhome_loc.y-3+rand()%6);
	dm->RightClick();
	//Kent_log_instance->write_log(_T("go_backward"));
}
void kent_windows::game_go_home(){//回家
	//Kent_log_instance->write_log(_T("go_home"));
	for(int i=0;i<5;i++){
		game_go_backward();
		Sleep(1000);
	}
	for(int iter = 0;iter<3;iter++){
		if(isenemyexist()){//移步到没敌人的地方
			for(int i=0;i<3;i++){
				game_go_backward();
				Sleep(500);
			}
			continue;
		}
		dm->KeyPressChar(_T("b"));//
		Sleep(200);
		dm->KeyPressChar(_T("b"));//
		for(int i=0;i < 15;i++){
			if(isenemyexist()){//继续回家
				game_go_backward();
				Sleep(500);
				break;
			}
			if(ishealth()){//nearhome
				goto kent_buy;
			}
			Sleep(500);
		}
	}
	
	//Kent_log_instance->write_log(_T("not_finished_go_home"));
	script_time =CTime::GetCurrentTime();
	return;

kent_buy:
	screen_lock(true);
	dm->MoveTo(center_x,center_y);
	//dm->RightClick();
	game_buy();
	//Kent_log_instance->write_log(_T("finished_go_home"));
	script_time =CTime::GetCurrentTime();
}
bool kent_windows::is_near_myhome(){
	if(!get_location()){//获取当前地址
		return true;
	}
	if(pow((location.x - myhome_loc.x),2)+pow((location.y - myhome_loc.y),2) < pow(10,2)){
		//Kent_log_instance->write_log(_T("near_myhome"));
		return true;
	}else{
		return false;
	}
}
vector<CPoint> kent_windows::get_batman_blue(){
	vector<CPoint> blue_point;
	CString batman_blue;
	if(m_IsSmallWindow){
		batman_blue = dm->FindPicEx(150, 100, 824, 668, file_name(_T("小兵蓝.bmp")), _T("080808"), 0.95, 0);
	}else{
		batman_blue = dm->FindPicEx(200, 150, 1070, 570, file_name(_T("小兵蓝.bmp")), _T("080808"), 0.95, 0);
	}
	vector<CString> blue_vector = Kent_log_instance->kent_split(batman_blue,_T("|"));
	for(vector<CString>::iterator iter = blue_vector.begin();iter != blue_vector.end();iter++){
		vector<CString> tmp = Kent_log_instance->kent_split(*iter,_T(","));
		CPoint abc;
		abc.SetPoint(_ttoi(tmp.at(1)) +32,_ttoi(tmp.at(2))+32);
		blue_point.push_back(abc);
	}
	return blue_point;
}
vector<CPoint> kent_windows::get_batman_red(){
	vector<CPoint> red_point;
	CString batman_red;
	if(m_IsSmallWindow){
		batman_red = dm->FindPicEx(150, 150, 824, 668, file_name(_T("小兵红.bmp")), _T("080808"), 0.95, 0);
	}else{
		batman_red = dm->FindPicEx(200, 150, 1070, 570, file_name(_T("小兵红.bmp")), _T("080808"), 0.95, 0);
	}
	vector<CString> red_vector = Kent_log_instance->kent_split(batman_red,_T("|"));
	for(vector<CString>::iterator iter = red_vector.begin();iter != red_vector.end();iter++){
		vector<CString> tmp = Kent_log_instance->kent_split(*iter,_T(","));
		CPoint abc;
		abc.SetPoint(_ttoi(tmp.at(1)),_ttoi(tmp.at(2)));
		red_point.push_back(abc);
	}
	return red_point;
}
int kent_windows::get_safe_dis(vector<CPoint> item)
{
	int safe_dis = 0;
	for(vector<CPoint>::iterator iter = item.begin();iter != item.end();iter++){
		int tmp;
		if(m_IsSmallWindow){
			if(kent_home_normal_down == kent_home){
				tmp = iter->x - iter->y - 128;
			}else{
				tmp = -iter->x + iter->y + 128;
			}
		}else{
			if(kent_home_normal_down == kent_home){
				tmp = iter->x - iter->y - 333;
			}else{
				tmp = -iter->x + iter->y + 333;
			}
		}
		if(tmp > safe_dis){
			safe_dis = tmp;
		}
	}
	safe_dis = (int)(safe_dis / sqrt(2)) + 5*item.size();
	if(item.size() < 2 ){
		safe_dis = 0;//自己兵线不够，安全距离为0
	}
	return safe_dis;
}
CPoint kent_windows::get_nearest_anmy(){
	vector<CPoint> anmy_point;
	CString anmy,anmy0,anmy1;
	int add_x,add_y;
	CPoint nearest_anmy;
	if(m_IsSmallWindow){
		if(kent_home_normal_down == kent_home){
			anmy0 = dm->FindPicEx(50, 100, 974, 568, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
			anmy1 = dm->FindPicEx(50, 100, 974, 568, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
		}else{
			anmy0 = dm->FindPicEx(50, 200, 974, 668, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
			anmy1 = dm->FindPicEx(50, 200, 974, 668, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
		}
	}else{
		if(kent_home_normal_down == kent_home){
			anmy0 = dm->FindPicEx(50, 100, 1170, 520, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
			anmy1 = dm->FindPicEx(50, 100, 1170, 520, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
		}else{
			anmy0 = dm->FindPicEx(50, 200, 1170, 620, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
			anmy1 = dm->FindPicEx(50, 200, 1170, 620, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
		}
	}
	if(anmy0.GetLength() > 0 || anmy1.GetLength() > 0){
		if(game_is_tour_exist()){
			game_go_backward();
			Sleep(1500);
			if(m_IsSmallWindow){
				if(kent_home_normal_down == kent_home){
					anmy0 = dm->FindPicEx(50, 100, 974, 568, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
					anmy1 = dm->FindPicEx(50, 100, 974, 568, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
				}else{
					anmy0 = dm->FindPicEx(50, 200, 974, 668, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
					anmy1 = dm->FindPicEx(50, 200, 974, 668, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
				}
			}else{
				if(kent_home_normal_down == kent_home){
					anmy0 = dm->FindPicEx(50, 100, 1170, 520, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
					anmy1 = dm->FindPicEx(50, 100, 1170, 520, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
				}else{
					anmy0 = dm->FindPicEx(50, 200, 1170, 620, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
					anmy1 = dm->FindPicEx(50, 200, 1170, 620, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
				}
			}
		}
	}
	if(anmy0.GetLength() > anmy1.GetLength()){
		anmy = anmy0;add_x = -45;add_y = 115;
	}else{
		anmy = anmy1;add_x = +61;add_y = 115;
	}
	if(anmy.GetLength() == 0){//没有发现
		nearest_anmy.x=0;
		nearest_anmy.y=0;
		return nearest_anmy;
	}
	vector<CString> anmy_vector = Kent_log_instance->kent_split(anmy,_T("|"));
	for(vector<CString>::iterator iter = anmy_vector.begin();iter != anmy_vector.end();iter++){
		vector<CString> tmp = Kent_log_instance->kent_split(*iter,_T(","));
		CPoint abc;
		abc.SetPoint(_ttoi(tmp.at(1)) + add_x,_ttoi(tmp.at(2)) + add_y);
		anmy_point.push_back(abc);
	}
	int near_dis = 0;
	for(vector<CPoint>::iterator iter = anmy_point.begin();iter != anmy_point.end();iter++){
		int tmp = (int)sqrt(pow(iter->x - center_x,2) + (int)pow(iter->y - center_y,2));
		if(tmp < near_dis || near_dis == 0){
			nearest_anmy = *iter;
			near_dis = tmp;
		}
	}
	return nearest_anmy;
}
void kent_windows::game_normal_attack()
{
	for(int j=0;j<2;j++)
	{
		CPoint nearest_anmy = get_nearest_anmy();
		if(nearest_anmy.x > 0)
		{
			dm->MoveTo(nearest_anmy.x,nearest_anmy.y);
			if(mouse_shape_attack == get_mouseshape()){
				dm->RightClick();//普攻
			}else{
				dm->KeyDownChar(_T("shift"));//alt
				dm->RightClick();//普攻
				dm->KeyUpChar(_T("shift"));
			}
			for(int i=0;i<4;i++)
			{
				dm->KeyPressChar(attack.at(i));//
				//Kent_log_instance->write_log(_T("按键"),attack.at(i));
			}
		}
		if(false == ishealth()){
			dm->KeyPressChar(_T("d"));//
			dm->KeyPressChar(_T("f"));//
			//Kent_log_instance->write_log(_T("按键"),_T("d、f"));
			game_go_backward();
			break;
		}
	}
}
bool kent_windows::game_is_need_assist(CPoint nearest_anmy)
{
	vector<CPoint> league_point;
	CString league,league0,league1;
	int add_x,add_y;
	
	if(m_IsSmallWindow){
		if(kent_home_normal_down == kent_home){
			league0 = dm->FindPicEx(50, 100, 974, 568, file_name(_T("盟友.bmp")), _T("151515"), 0.92, 0);
			league1 = dm->FindPicEx(50, 100, 974, 568, file_name(_T("盟友1.bmp")), _T("151515"), 0.92, 0);
		}else{
			league0 = dm->FindPicEx(50, 200, 974, 668, file_name(_T("盟友.bmp")), _T("151515"), 0.92, 0);
			league1 = dm->FindPicEx(50, 200, 974, 668, file_name(_T("盟友1.bmp")), _T("151515"), 0.92, 0);
		}
	}else{
		if(kent_home_normal_down == kent_home){
			league0 = dm->FindPicEx(150, 0, 1130, 520, file_name(_T("盟友.bmp")), _T("151515"), 0.92, 0);
			league1 = dm->FindPicEx(150, 0, 1130, 520, file_name(_T("盟友1.bmp")), _T("151515"), 0.92, 0);
		}else{
			league0 = dm->FindPicEx(150, 200, 1130, 720, file_name(_T("盟友.bmp")), _T("151515"), 0.92, 0);
			league1 = dm->FindPicEx(150, 200, 1130, 720, file_name(_T("盟友1.bmp")), _T("151515"), 0.92, 0);
		}
	}

	if(league0.GetLength() > league1.GetLength()){
		league = league0;add_x = -65;add_y = 139;
	}else{
		league = league1;add_x = +61;add_y = 139;
	}
	if(league.GetLength() == 0){//没有发现友军
		//Kent_log_instance->write_log(_T("no league exist..."));
		return false;
	}
	vector<CString> league_vector = Kent_log_instance->kent_split(league,_T("|"));
	for(vector<CString>::iterator iter = league_vector.begin();iter != league_vector.end();iter++){
		vector<CString> tmp = Kent_log_instance->kent_split(*iter,_T(","));
		CPoint abc;
		abc.SetPoint(_ttoi(tmp.at(1)) + add_x,_ttoi(tmp.at(2)) + add_y);
		league_point.push_back(abc);
	}
	for(vector<CPoint>::iterator iter = league_point.begin();iter != league_point.end();iter++){
		int tmp = (int)sqrt(pow(iter->x - nearest_anmy.x,2) + (int)pow(iter->y - nearest_anmy.y,2));
		//Kent_log_instance->write_log(_T("league_anmy_dis:"),tmp);
		if(tmp < 350){
			//Kent_log_instance->write_log(_T("支援ing...:"));
			return true;
		}
	}
	return false;
}
//补刀
void kent_windows::game_do_lasthit()
{
	for(vector<CPoint>::iterator iter=kent_bat_blue.begin();iter != kent_bat_blue.end();iter++)
	{
		CString lasthit_color;
		lasthit_color = dm->GetColor(iter->x+9,iter->y+3);
		int lasthit_cnt = kent_strtoi(lasthit_color.Mid(0,2))+kent_strtoi(lasthit_color.Mid(2,2))+kent_strtoi(lasthit_color.Mid(4,2));
		if(lasthit_cnt < 120)
		{
			//补刀
			dm->MoveTo(iter->x+32,iter->y+23);
			Sleep(50);
			dm->RightClick();//普攻
			Sleep(50);
			if(rand()%20 < 8){
				dm->KeyPressChar(attack.at(rand()%3));//技能补兵
				Sleep(50);
			}
			//Kent_log_instance->write_log(_T("技能补兵"));
			return;
		}
	}
}

/*************扭曲丛林战场***************/
void kent_windows::game_do_distort(){
	if(rand()%10 < 3){
		if(true == isbuypanel()){
			dm->KeyPressChar(_T("p"));//关闭购买P
			Kent_rnd_delay(500);
		}
	}
	screen_lock(true);//锁定视角
	if(isneedadd()){//加点
		if(!do_first_add){
			game_data_init();
			do_first_add = true;
		}
		game_add_skill();
	}
	if(isdie()){//死亡
		game_state=Kent_game_die;
		game_die(); 
	}else{
		game_state=Kent_game_occupy;//为了兼容
		if(!ishealth()){//没血回家
			game_go_home();
		}
		kent_bat_blue = distort_get_batman_blue();//获取蓝兵
		nearest_anmy = distort_get_nearest_anmy();//获取最近的敌人
		kent_bat_red = distort_get_batman_red();//获取红兵
		if(kent_bat_blue.size() + kent_bat_red.size() > 2){//看到了小兵，开始正常攻防
			kent_distort_started = true;
		}
		if(kent_distort_started){//已经完全开始
			/*************算法核心部分***************/
			int dis;
			if(nearest_anmy.x){
				dis = (int)sqrt(pow(nearest_anmy.x - center_x,2) + pow(nearest_anmy.y - center_y,2));
				Kent_log_instance->write_log(_T("nearest_anmy_dis:"),dis);
			}else{
				dis = 1000;
			}
			if( dis < 350){
				game_normal_attack();//攻击撤退
				game_go_backward();//撤退
				Sleep(1000);
			}else if(nearest_anmy.x && ishealth() && game_is_need_assist(nearest_anmy)){//敌人存在，并且需要支援
				game_normal_attack();
			}else{
				int safe_dis = distort_get_safe_dis(kent_bat_blue);
				Kent_log_instance->write_log(_T("safe_distance:"),safe_dis);
				if(kent_bat_red.size() > 0){
					if(safe_dis < 50){//不在安全距离
						Kent_log_instance->write_log(_T("notin_safe_distance"));
						game_go_backward();//撤退
						Sleep(1000);
					}else{//瞎逛
						game_do_lasthit();//补刀
						CPoint tmp = kent_bat_blue.at(rand() % kent_bat_blue.size());
						dm->MoveTo(tmp.x-3+rand()%6,tmp.y-3+rand()%6);
						dm->KeyDownChar(_T("shift"));//alt
						dm->RightClick();
						dm->KeyUpChar(_T("shift"));
					}
				}else{
					if(game_is_tour_exist() && safe_dis < 60){//塔存在，并且安全距离低
						game_go_backward();//撤退
						Sleep(1000);
					}else{
						game_go_forward();
					}
				}
			}
		}else{//没有完全开始,中间瞎晃
			if(m_IsSmallWindow){
				if(kent_home_left == kent_home){
					dm->MoveTo(893-3+rand()%6,708-3+rand()%6);
				}else{
					dm->MoveTo(958-3+rand()%6,707-3+rand()%6);
				}
			}else{
				if(kent_home_left == kent_home){
					dm->MoveTo(1162-3+rand()%6,663-3+rand()%6);
				}else{
					dm->MoveTo(1214-3+rand()%6,664-3+rand()%6);
				}
			}
			dm->KeyDownChar(_T("shift"));//alt
			dm->RightClick();
			dm->KeyUpChar(_T("shift"));
			Sleep(2000);
			Kent_log_instance->write_log(_T("not_start_all"));
		}
	}
}
vector<CPoint> kent_windows::distort_get_batman_blue(){
	vector<CPoint> blue_point;
	CString batman_blue;
	if(m_IsSmallWindow){
		batman_blue = dm->FindPicEx(150, 200, 824, 668, file_name(_T("小兵蓝.bmp")), _T("080808"), 0.95, 0);
	}else{
		batman_blue = dm->FindPicEx(200, 150, 1070, 570, file_name(_T("小兵蓝.bmp")), _T("080808"), 0.95, 0);
	}
	vector<CString> blue_vector = Kent_log_instance->kent_split(batman_blue,_T("|"));
	for(vector<CString>::iterator iter = blue_vector.begin();iter != blue_vector.end();iter++){
		vector<CString> tmp = Kent_log_instance->kent_split(*iter,_T(","));
		CPoint abc;
		abc.SetPoint(_ttoi(tmp.at(1)) +32,_ttoi(tmp.at(2))+32);
		blue_point.push_back(abc);
	}
	return blue_point;
}
vector<CPoint> kent_windows::distort_get_batman_red(){
	vector<CPoint> red_point;
	CString batman_red;
	if(m_IsSmallWindow){
		batman_red = dm->FindPicEx(150, 300, 824, 668, file_name(_T("小兵红.bmp")), _T("080808"), 0.95, 0);
	}else{
		batman_red = dm->FindPicEx(200, 280, 1070, 570, file_name(_T("小兵红.bmp")), _T("080808"), 0.95, 0);
	}
	vector<CString> red_vector = Kent_log_instance->kent_split(batman_red,_T("|"));
	for(vector<CString>::iterator iter = red_vector.begin();iter != red_vector.end();iter++){
		vector<CString> tmp = Kent_log_instance->kent_split(*iter,_T(","));
		CPoint abc;
		abc.SetPoint(_ttoi(tmp.at(1)),_ttoi(tmp.at(2)));
		red_point.push_back(abc);
	}
	return red_point;
}
/*************扭曲丛林private***************/
CPoint kent_windows::distort_get_nearest_anmy(){
	vector<CPoint> anmy_point;
	CString anmy,anmy0,anmy1;
	int add_x,add_y;
	CPoint nearest_anmy;
	if(m_IsSmallWindow){
		if(kent_home_left == kent_home){
			anmy0 = dm->FindPicEx(150, 100, 974, 668, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
			anmy1 = dm->FindPicEx(150, 100, 974, 668, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
		}else{
			anmy0 = dm->FindPicEx(50, 100, 874, 568, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
			anmy1 = dm->FindPicEx(50, 100, 874, 568, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
		}
	}else{
		if(kent_home_left == kent_home){
			anmy0 = dm->FindPicEx(150, 100, 1230, 620, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
			anmy1 = dm->FindPicEx(150, 100, 1230, 620, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
		}else{
			anmy0 = dm->FindPicEx(50, 100, 1130, 620, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
			anmy1 = dm->FindPicEx(50, 100, 1130, 620, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
		}
	}
	if(anmy0.GetLength() > 0 || anmy1.GetLength() > 0){
		if(game_is_tour_exist()){
			game_go_backward();
			Sleep(1500);
			if(m_IsSmallWindow){
				if(kent_home_left == kent_home){
					anmy0 = dm->FindPicEx(150, 100, 974, 668, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
					anmy1 = dm->FindPicEx(150, 100, 974, 668, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
				}else{
					anmy0 = dm->FindPicEx(50, 100, 874, 568, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
					anmy1 = dm->FindPicEx(50, 100, 874, 568, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
				}
			}else{
				if(kent_home_left == kent_home){
					anmy0 = dm->FindPicEx(150, 100, 1230, 620, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
					anmy1 = dm->FindPicEx(150, 100, 1230, 620, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
				}else{
					anmy0 = dm->FindPicEx(50, 100, 1130, 620, file_name(_T("敌人.bmp")), _T("151515"), 0.92, 0);
					anmy1 = dm->FindPicEx(50, 100, 1130, 620, file_name(_T("敌人1.bmp")), _T("151515"), 0.92, 0);
				}
			}
		}
	}
	if(anmy0.GetLength() > anmy1.GetLength()){
		anmy = anmy0;add_x = -45;add_y = 115;
	}else{
		anmy = anmy1;add_x = +61;add_y = 115;
	}
	if(anmy.GetLength() == 0){//没有发现
		nearest_anmy.x=0;
		nearest_anmy.y=0;
		return nearest_anmy;
	}
	vector<CString> anmy_vector = Kent_log_instance->kent_split(anmy,_T("|"));
	for(vector<CString>::iterator iter = anmy_vector.begin();iter != anmy_vector.end();iter++){
		vector<CString> tmp = Kent_log_instance->kent_split(*iter,_T(","));
		CPoint abc;
		abc.SetPoint(_ttoi(tmp.at(1)) + add_x,_ttoi(tmp.at(2)) + add_y);
		anmy_point.push_back(abc);
	}
	int near_dis = 0;
	for(vector<CPoint>::iterator iter = anmy_point.begin();iter != anmy_point.end();iter++){
		int tmp = (int)sqrt(pow(iter->x - center_x,2) + (int)pow(iter->y - center_y,2));
		if(tmp < near_dis || near_dis == 0){
			nearest_anmy = *iter;
			near_dis = tmp;
		}
	}
	return nearest_anmy;
}
int kent_windows::distort_get_safe_dis(vector<CPoint> item)
{
	int safe_dis = 0;
	for(vector<CPoint>::iterator iter = item.begin();iter != item.end();iter++){
		int tmp;
		if(m_IsSmallWindow){
			if(kent_home_left == kent_home){//左侧
				tmp = iter->x - 512;
			}else{
				tmp = -iter->x + 512;
			}
		}else{
			if(kent_home_left == kent_home){//左侧
				tmp = iter->x - 636;
			}else{
				tmp = -iter->x + 636;
			}
		}
		if(tmp > safe_dis){
			safe_dis = tmp;
		}
	}
	safe_dis = safe_dis + 5*item.size();
	if(item.size() < 2 ){
		safe_dis = 0;//自己兵线不够，安全距离为0
	}
	return safe_dis;
}

/*************大乱斗***************/
void kent_windows::game_do_colosseum(){
	if(rand()%10 < 3){
		if(true == isbuypanel()){
			dm->KeyPressChar(_T("p"));//关闭购买P
			Kent_rnd_delay(500);
		}
	}
	screen_lock(true);//锁定视角
	if(isneedadd()){//加点
		if(!do_first_add){
			game_data_init();
			do_first_add = true;
		}
		game_add_skill();
	}
	if(isdie()){//死亡
		game_state=Kent_game_die;
		game_die(); 
	}else{
		game_state=Kent_game_occupy;//为了兼容
		kent_hero_blue = get_heros_blue();
		nearest_anmy = get_nearest_anmy();//获取最近的敌人
		/*************算法核心部分***************/
		int dis;
		if(nearest_anmy.x){
			dis = (int)sqrt(pow(nearest_anmy.x - center_x,2) + pow(nearest_anmy.y - center_y,2));
			Kent_log_instance->write_log(_T("nearest_anmy_dis:"),dis);
		}else{
			dis = 1000;
		}
		if( dis < 340 && kent_hero_blue.size() >= rand() % 2 + 1){
			colosseum_normal_attack();//攻击
			game_go_backward();//撤退
			Sleep(500);
		}else{
			int safe_dis = colosseum_get_safe_dis(kent_hero_blue);//自己的英雄作为安全距离参考
			Kent_log_instance->write_log(_T("safe_distance:"),safe_dis);
			if(nearest_anmy.x > 0){
				if(safe_dis < 30){//不在安全距离
					Kent_log_instance->write_log(_T("notin_safe_distance"));
					game_go_backward();//撤退
					Sleep(500);
				}else{//瞎逛
					CPoint tmp = kent_hero_blue.at(rand() % kent_hero_blue.size());
					dm->MoveTo(tmp.x-30+rand()%60,tmp.y-30+rand()%60);
					dm->KeyDownChar(_T("shift"));//alt
					dm->RightClick();
					dm->KeyUpChar(_T("shift"));
				}
			}else{
				if(game_is_tour_exist() && safe_dis < 60){//塔存在，并且安全距离低
					game_go_backward();//撤退
					Sleep(500);
				}else{
					game_go_forward();
				}
			}
		}
	}
}

/*************大乱斗private***************/
vector<CPoint> kent_windows::get_heros_blue(){
	vector<CPoint> league_point;
	CString league,league0,league1;
	int add_x,add_y;
	if(m_IsSmallWindow){
		if(kent_home_normal_down == kent_home){
			league0 = dm->FindPicEx(100, 0, 924, 568, file_name(_T("盟友.bmp")), _T("151515"), 0.92, 0);
			league1 = dm->FindPicEx(100, 0, 924, 568, file_name(_T("盟友1.bmp")), _T("151515"), 0.92, 0);
		}else{
			league0 = dm->FindPicEx(100, 200, 924, 768, file_name(_T("盟友.bmp")), _T("151515"), 0.92, 0);
			league1 = dm->FindPicEx(100, 200, 924, 768, file_name(_T("盟友1.bmp")), _T("151515"), 0.92, 0);
		}
	}else{
		if(kent_home_normal_down == kent_home){
			league0 = dm->FindPicEx(150, 0, 1130, 520, file_name(_T("盟友.bmp")), _T("151515"), 0.92, 0);
			league1 = dm->FindPicEx(150, 0, 1130, 520, file_name(_T("盟友1.bmp")), _T("151515"), 0.92, 0);
		}else{
			league0 = dm->FindPicEx(150, 200, 1130, 720, file_name(_T("盟友.bmp")), _T("151515"), 0.92, 0);
			league1 = dm->FindPicEx(150, 200, 1130, 720, file_name(_T("盟友1.bmp")), _T("151515"), 0.92, 0);
		}
	}
	if(league0.GetLength() > league1.GetLength()){
		league = league0;add_x = -65;add_y = 139;
	}else{
		league = league1;add_x = +61;add_y = 139;
	}
	
	if(league.GetLength() == 0){//没有发现友军
		Kent_log_instance->write_log(_T("no league exist..."));
		return league_point;
	}
	vector<CString> league_vector = Kent_log_instance->kent_split(league,_T("|"));
	for(vector<CString>::iterator iter = league_vector.begin();iter != league_vector.end();iter++){
		vector<CString> tmp = Kent_log_instance->kent_split(*iter,_T(","));
		CPoint abc;
		abc.SetPoint(_ttoi(tmp.at(1)) + add_x,_ttoi(tmp.at(2)) + add_y);
		league_point.push_back(abc);
	}
	return league_point;
}
bool kent_windows::colosseum_is_need_assist()
{
	for(vector<CPoint>::iterator iter = kent_hero_blue.begin();iter != kent_hero_blue.end();iter++){
		int tmp = (int)sqrt(pow(iter->x - nearest_anmy.x,2) + (int)pow(iter->y - nearest_anmy.y,2));
		Kent_log_instance->write_log(_T("league_anmy_dis:"),tmp);
		if(tmp < 350){
			Kent_log_instance->write_log(_T("支援ing...:"));
			return true;
		}
	}
	return false;
}
int kent_windows::colosseum_get_safe_dis(vector<CPoint> item)
{
	int safe_dis = 0;
	for(vector<CPoint>::iterator iter = item.begin();iter != item.end();iter++){
		int tmp;
		if(m_IsSmallWindow){
			if(kent_home_normal_down == kent_home){
				tmp = iter->x - iter->y - 128;
			}else{
				tmp = -iter->x + iter->y + 128;
			}
		}else{
			if(kent_home_normal_down == kent_home){
				tmp = iter->x - iter->y - 333;
			}else{
				tmp = -iter->x + iter->y + 333;
			}
		}
		if(tmp > safe_dis){
			safe_dis = tmp;
		}
	}
	safe_dis = (int)(safe_dis / sqrt(2)) + 10*item.size();
	return safe_dis;
}
void kent_windows::colosseum_normal_attack()
{
	for(int j=0;j<2;j++)
	{
		CPoint nearest_anmy = get_nearest_anmy();
		if(nearest_anmy.x > 0)
		{
			dm->MoveTo(nearest_anmy.x,nearest_anmy.y);
			if(mouse_shape_attack == get_mouseshape()){
				dm->RightClick();//普攻
			}else{
				dm->KeyDownChar(_T("shift"));//alt
				dm->RightClick();//普攻
				dm->KeyUpChar(_T("shift"));
			}
			for(int i=0;i<4;i++)
			{
				dm->KeyPressChar(attack.at(i));//
				Kent_log_instance->write_log(_T("按键"),attack.at(i));
			}
		}
		if(false == ishealth()){
			dm->KeyPressChar(_T("d"));//
			dm->KeyPressChar(_T("f"));//
			Kent_log_instance->write_log(_T("按键"),_T("d、f"));
		}
	}
}
/*************游戏重连保护***************/
void kent_windows::restart_windows_init()
{
	iswindows=Kent_unavailable;
	kent_stage_now=Kent_waiting;
	kent_stage_last=Kent_waiting;
	bind_fail_cnt=0;
	isingame_num=false;
	isstart_num = Kent_start_waiting;
	isselect_num=false;
	isloading_num=false;
	isstart_num=Kent_start_waiting;
	isgameover_num=gameover_none;
	occupy=false;
	target=0;
	stay_which_tour=0;
	game_state=Kent_game_none;
	game_state_last=Kent_game_none;
	script_time =CTime::GetCurrentTime();

	Kent_game_inuse_time = CTime::GetCurrentTime();//计时
	Kent_login_inuse_time = CTime::GetCurrentTime();//计时
	Kent_connect_inuse_time = CTime::GetCurrentTime();//计时
}
void kent_windows::restart_whole_game(){
	kent_TerminateProcess(_T("League of Legends.exe"));
	kent_TerminateProcess(_T("LolClient.exe"));
	kent_TerminateProcess(_T("CrossProxy.exe"));
	kent_TerminateProcess(_T("BsSndRpt.exe"));
	kent_TerminateProcess(_T("QTalk.exe"));
	Sleep(100);
	kent_TerminateProcess(_T("TASLogin.exe"));
	Sleep(100);
	kent_TerminateProcess(_T("TenSafe_1.exe"));
#ifdef kent_han
	kent_TerminateProcess(_T("LoLLauncher.exe"));
	ShellExecute(NULL,_T("open"),kent_gamepath+_T("\\lol.launcher.exe"),NULL,NULL,SW_SHOWNORMAL);
#else
	kent_TerminateProcess(_T("Client.exe"));
	kent_TerminateProcess(_T("lol.launcher_tencent.exe"));
	ShellExecute(NULL,_T("open"),kent_gamepath.Left(kent_gamepath.ReverseFind(_T('\\')))+_T("\\TCLS\\Client.exe"),NULL,NULL,SW_SHOWNORMAL);
	//CString pathtmp=_T("\"")+kent_gamepath.Left(kent_gamepath.ReverseFind(_T('\\')))+_T("\\TCLS\\Client.exe")+_T("\"");
	//system(UnicodeToANSI(pathtmp.GetBuffer()).c_str());pathtmp.ReleaseBuffer();
#endif
	Sleep(10000);//延时10s
	Kent_log_instance->write_log(_T("启动英雄联盟"));
	Sleep(2000);
	restart_windows_init();
}
void kent_windows::collapse_detect()
{
	long Hwnd_disconnect = 0;
	if(Kent_game_inuse == iswindows && false == isingame_num){
		Hwnd_disconnect = dm->FindWindow(_T(""),_T("连接断开"));
		if(0 == Hwnd_disconnect){
			Hwnd_disconnect = dm->FindWindow(_T(""),_T("网络不稳"));
		}
	}else{
		Hwnd_disconnect = 0;
	}

	CPoint kent_gaming;
	VARIANT gaming_x,gaming_y;
	gaming_x.intVal = 0;
	gaming_y.intVal = 0;
	if(Kent_login_inuse == iswindows){
#ifdef kent_han
		dm->FindPic(492, 296,657, 347, file_name(_T("韩游戏仍在进行中.bmp")), _T("303030"), 0.8, 0, &gaming_x, &gaming_y);//弹出确认框
#else
		kent_gaming = kent_search_str(485,295,664,353,_T("游戏仍在进行中"),_T("ffffff-555555"),0.7,3);
#endif
	}

	if(Kent_log_instance->kent_reconnect_normal){//需要判断是否重连
		if(0 != Hwnd_disconnect || Kent_unavailable == iswindows || Kent_login_unavailable == iswindows || kent_gaming.x > 0 || gaming_x.intVal > 0 || (Hwnd_game && dm->GetWindowState(Hwnd_game,6)))//窗口不在，发现正在游戏中，未响应
		{
			CTime now_time=CTime::GetCurrentTime();//获取当前时间
			CTimeSpan timeSpan = now_time - script_time;
			LONGLONG nTSeconds = timeSpan.GetTotalSeconds();
			if(nTSeconds > 150 || 0 != Hwnd_disconnect){//40秒之后或者出现连接不上的情况
				if(0 != Hwnd_disconnect){
					dm->WriteFile(_T("重启解释.txt"),_T("连接不上"));
				}else{
					dm->WriteFile(_T("重启解释.txt"),_T("40秒无有效窗口"));
				}
				restart_whole_game();
				return;
			}
		}else{
			script_time = CTime::GetCurrentTime();
		}
	}else{
		script_time = CTime::GetCurrentTime();
	}


	/*
	//读取当前金币判断是否掉线
	static int IpNotChangeCnt = 0;
	static int GameIpLast = 0;
	static int IpDetectCnt = 0;
	IpDetectCnt = (IpDetectCnt + 1)%10;

	if(Kent_game_inuse == iswindows && Kent_log_instance->kent_reconnect_normal){
		if(0 == IpDetectCnt)//10次循环检测一次
		{
			int GameIp;
			if(m_IsSmallWindow){//小窗口
				dm->UseDict(4);//使用小窗口金币数字字库
				GameIp = _ttoi(dm->Ocr(170, 735,248, 765,_T("e4dd8a-404040"),0.8));//获取当前金币数
				dm->UseDict(0);//使用0字库
			}else{//大窗口
				dm->UseDict(3);//使用大窗口金币数字字库
				GameIp = _ttoi(dm->Ocr(157, 690,229, 716,_T("e4dd8a-404040"),0.8));//获取当前金币数
				dm->UseDict(0);//使用0字库
			}
			Kent_log_instance->write_log(_T("金币:"),GameIp);

			if(GameIp>100)//至少三位数,识别数字有效
			{
				if(GameIpLast > 100 && GameIpLast == GameIp){
					IpNotChangeCnt++;
					if(IpNotChangeCnt >= 5)//重启
					{
						GameIpLast = 0;
						IpNotChangeCnt = 0;
						Kent_log_instance->write_log(_T("金币长时间不变"));
						restart_whole_game();//超时重启启动
						dm->WriteFile(_T("重启解释.txt"),_T("金币长时间不变,判断掉线"));
					}
				}else{
					IpNotChangeCnt = 0;
				}
				GameIpLast = GameIp;
			}else{//无效识别数字
				IpNotChangeCnt = 0;
			}
			Kent_log_instance->write_log(_T("IpNotChangeCnt:"),IpNotChangeCnt);
		}
	}else{
		IpNotChangeCnt = 0;
	}

	*/

	if(Kent_game_inuse == iswindows && Kent_log_instance->kent_reconnect_normal){
		VARIANT not_move_alerting_x, not_move_alerting_y;
		if(m_IsSmallWindow){
			dm->FindPic(483, 423,767, 524, file_name(_T("暂离警告确认.bmp")), _T("303030"), 0.8, 0, &not_move_alerting_x, &not_move_alerting_y);//弹出确认框
		}else{
#ifdef kent_han
			dm->FindPic(513, 402,833, 522, file_name(_T("韩暂离警告确认.bmp")), _T("303030"), 0.8, 0, &not_move_alerting_x, &not_move_alerting_y);//弹出确认框
#else
			dm->FindPic(615,431,727,493, file_name(_T("暂离警告确认.bmp")), _T("303030"), 0.8, 0, &not_move_alerting_x, &not_move_alerting_y);//弹出确认框
#endif
		}
		if(not_move_alerting_x.intVal>0){
			Kent_log_instance->write_log(_T("无操作-暂离警告"));
			dm->MoveTo(not_move_alerting_x.intVal + 40, not_move_alerting_y.intVal + 20);
			Sleep(200);
			dm->LeftClick();
			Sleep(2000);
			//dm->WriteFile(_T("重启解释.txt"),_T("找到图像：确认,判断掉线"));
		}
#ifndef kent_han
		else{
			CPoint tmp;
			if(m_IsSmallWindow){
				tmp= kent_search_str(483, 423,767, 524,_T("确认"),_T("ffffff-505050"),0.7,1);
			}else{
				tmp= kent_search_str(615,431,727,493,_T("确认"),_T("ffffff-505050"),0.7,1);
			}
			if(tmp.x>0){
				dm->MoveTo(tmp.x,tmp.y);
				Sleep(200);
				dm->MoveTo(tmp.x+5,tmp.y);
				Sleep(200);
				dm->LeftClick();
				Sleep(300);
				Kent_log_instance->write_log(_T("找到文字：确认"));
				Sleep(2000);
				//dm->WriteFile(_T("重启解释.txt"),_T("找到文字：确认,判断掉线"));
			}
		}
#endif
	}

	if(Kent_log_instance->kent_reconnect_normal)
	{
		//超时重启
		if(Kent_game_inuse == iswindows)
		{
			Kent_login_inuse_time = CTime::GetCurrentTime();//计时
			Kent_connect_inuse_time = CTime::GetCurrentTime();//计时
		}else if(Kent_login_inuse == iswindows)
		{
			Kent_game_inuse_time = CTime::GetCurrentTime();//计时
			Kent_connect_inuse_time = CTime::GetCurrentTime();//计时
		}else if(Kent_connect_inuse == iswindows)
		{
			Kent_game_inuse_time = CTime::GetCurrentTime();//计时
			Kent_login_inuse_time = CTime::GetCurrentTime();//计时
		}else{
			Kent_game_inuse_time = CTime::GetCurrentTime();//计时
			Kent_login_inuse_time = CTime::GetCurrentTime();//计时
			Kent_connect_inuse_time = CTime::GetCurrentTime();//计时
		}
		CTime now_time=CTime::GetCurrentTime();//获取当前时间
		CTimeSpan Kent_game_inuse_timeSpan = now_time - Kent_game_inuse_time;
		CTimeSpan Kent_login_inuse_timeSpan = now_time - Kent_login_inuse_time;
		CTimeSpan Kent_connect_inuse_timeSpan = now_time - Kent_connect_inuse_time;

		if(Kent_game_inuse_timeSpan.GetMinutes() > 60 || Kent_login_inuse_timeSpan.GetMinutes() > 15 || Kent_connect_inuse_timeSpan.GetMinutes() > 10){
			restart_whole_game();//超时重启启动
			dm->WriteFile(_T("重启解释.txt"),_T("窗口超时重启启动"));
		}
	}else{
		Kent_game_inuse_time = CTime::GetCurrentTime();//计时
		Kent_login_inuse_time = CTime::GetCurrentTime();//计时
		Kent_connect_inuse_time = CTime::GetCurrentTime();//计时
	}
}
bool kent_windows::kent_TerminateProcess(CString strProcessName)
{
	BOOL bResult;
	CString strTemp;
	HANDLE hSnapshot;				//内存进程的“快照”句柄
	PROCESSENTRY32 ProcessEntry;	//描述进程的结构   这个结构需要#include <TLHELP32.H>头文件
	vector<DWORD> vtPID;			//进程ID容器
	strProcessName.MakeLower();//小写字母
	//返回内存所有进程的快照。参数为TH32CS_SNAPPROCESS取有的进程,忽略参数2；
	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	//获取要结束的进程名称对应的所有进程ID
	ProcessEntry.dwSize = sizeof(PROCESSENTRY32);
	bResult = Process32First(hSnapshot,&ProcessEntry);//获取第一个进程
	while(bResult)
	{
		//判断是否为要结束的进程
		strTemp.Format(_T("%s"),ProcessEntry.szExeFile);
		strTemp.MakeLower();
		if(strTemp == strProcessName)
			vtPID.push_back(ProcessEntry.th32ProcessID);
		//获取下一个进程
		bResult = Process32Next(hSnapshot,&ProcessEntry);
	}
	//结束进程
	bResult = FALSE;
	vector<DWORD>::iterator it = vtPID.begin();
	for(;it!=vtPID.end();++it)
	{
		if(*it)
		{
			//获取进程句柄
			HANDLE hProcess;
			hProcess = OpenProcess(PROCESS_TERMINATE,FALSE,*it);//只申请关闭权限打开游戏
			//结束进程
			if(hProcess)
			{
				bResult = TerminateProcess(hProcess,0);
			}
			if(!bResult)
				break;
		}
	}
	CloseHandle(hSnapshot);
	if(bResult){return true;}
	else{return false;}
}
void kent_windows::reconnect_protect()
{
	if((Kent_log_instance->kent_reconnect_normal) && Kent_connect_inuse == iswindows){
		//开启重连保护
		VARIANT fastlogin_x, fastlogin_y,wrong_confirm_x,wrong_confirm_y;
		dm->FindPic(933,533,1106,580, file_name(_T("快速登录.bmp")), _T("303030"), 0.7, 0, &fastlogin_x, &fastlogin_y);//弹出确认框
		dm->FindPic(479, 345, 813, 560, file_name(_T("密码错误确定.bmp")), _T("303030"), 0.7, 0, &wrong_confirm_x, &wrong_confirm_y);//弹出确认框
		if(wrong_confirm_x.intVal>0){//密码输入错误
			dm->MoveTo(wrong_confirm_x.intVal + 33, wrong_confirm_y.intVal + 13);
			Sleep(200);
			dm->MoveTo(wrong_confirm_x.intVal + 53, wrong_confirm_y.intVal + 13);
			Sleep(200);
			dm->LeftClick();
			Sleep(200);
			Kent_log_instance->write_log(_T("崩溃-密码输入错误"));
		}
		if(Kent_log_instance->kent_reconnect_fast && fastlogin_x.intVal>0 && wrong_confirm_x.intVal <0){
			Sleep(500);
			dm->MoveTo(1020, 559);
			Sleep(200);
			dm->MoveTo(1050, 559);
			Sleep(200);
			dm->LeftClick();
			Sleep(1000);
			dm->MoveTo(1020,521);
			Sleep(200);
			dm->MoveTo(1030,521);
			Sleep(200);
			dm->LeftClick();
			Sleep(2000);
		}else{
			VARIANT otherlogin_x, otherlogin_y;
			dm->FindPic(933,533,1106,580, file_name(_T("其他账号登陆.bmp")), _T("303030"), 0.7, 0, &otherlogin_x, &otherlogin_y);//弹出确认框
			if(otherlogin_x.intVal >0 ){
				dm->MoveTo(1020, 559);
				Sleep(200);
				dm->MoveTo(1050, 559);
				Sleep(200);
				dm->LeftClick();
				Sleep(5000);
			}
			VARIANT qq_x, qq_y,wrong_confirm_x, wrong_confirm_y,login_confirm_x, login_confirm_y,verification_x, verification_y;
			dm->FindPic( 798, 232, 1064, 405, file_name(_T("qq账号.bmp")), _T("303030"), 0.7, 0, &qq_x, &qq_y);//弹出确认框
			dm->FindPic( 479, 345, 813, 560, file_name(_T("密码错误确定.bmp")), _T("303030"), 0.7, 0, &wrong_confirm_x, &wrong_confirm_y);//弹出确认框
			dm->FindPic( 798, 629, 1097, 757, file_name(_T("确认选择.bmp")), _T("303030"), 0.7, 0, &login_confirm_x, &login_confirm_y);//弹出确认框
			dm->FindPic( 586, 378, 900, 541, file_name(_T("验证码取消.bmp")), _T("303030"), 0.7, 0, &verification_x, &verification_y);//弹出确认框
			if(login_confirm_x.intVal>0){
				CPoint tmp = Kent_log_instance->choose_large_area(Kent_log_instance->kent_reconnect_qq_area);
				if(tmp.x){
					dm->MoveTo(1188, 696);
					Sleep(200);
					dm->MoveTo(1200, 696);
					Sleep(200);
					dm->LeftClick();
					Sleep(2000);
					dm->MoveTo(tmp.x, tmp.y);
					Sleep(200);
					dm->MoveTo(tmp.x+10, tmp.y);
					Sleep(150);
					dm->LeftClick();
					Sleep(150);
					dm->LeftClick();
					//dm->KeyPressChar(_T("enter"));
					Sleep(2000);
					
					long num_red = dm->GetColorNum(492, 430,621, 476, _T("cb2d00-303030"), 1.0);//通过比色来判定是否可以点击开始

					if(num_red>1000){
						dm->MoveTo(739, 451);
						Sleep(200);
						dm->MoveTo(749, 451);
						Sleep(200);
						dm->LeftClick();
						Sleep(2000);
					}

					return;
				}else{
					dm->MoveTo(941, 690);
					Sleep(200);
					dm->MoveTo(961, 690);
					Sleep(200);
					dm->LeftClick();
					Sleep(200);
					dm->LeftClick();
					Sleep(200);
				}

				Kent_log_instance->write_log(_T("崩溃-点击确认选择"));

			}else if(wrong_confirm_x.intVal>0){
				dm->MoveTo(wrong_confirm_x.intVal + 33, wrong_confirm_y.intVal + 13);
				Sleep(200);
				dm->MoveTo(wrong_confirm_x.intVal + 53, wrong_confirm_y.intVal + 13);
				Sleep(200);
				dm->LeftClick();
				Sleep(200);
				Kent_log_instance->write_log(_T("崩溃-密码输入错误"));
			}else if(verification_x.intVal>0 && 0 == dm->Ocr(485,352,549,383,_T("92c8ef-303030"),0.8).Compare(_T("验证码"))){
				Kent_log_instance->write_log(_T("崩溃-无法识别验证码"));
				dm->CaptureGif(556,389,686,441,Kent_log_instance->kent_root_path+_T("\\sydt.gif"),0,0);//截取图片
				ASSERT(dm->IsFileExist(Kent_log_instance->kent_root_path+_T("\\sydt.gif")));//断言
				CString answer;
				if(0 == Kent_log_instance->kent_identify_choose.Compare(_T("顺逸代答"))){
					CString bstr = Kent_log_instance->kent_sydt->Send(_T("sendvcode/myapi/")+Kent_log_instance->kent_identify_sydt_code+_T("/type/10001/timeout/60/note/备注/author/xuguruogu"), Kent_log_instance->kent_root_path+_T("\\sydt.gif"));//发送验证码
					if (bstr.GetAt(0)=='E'){
						MessageBox(NULL,bstr,_T("顺逸代答错误"),MB_OK);
						return;
					}
					for(int i=0;i<60;i++){
						Sleep(1000);
						answer = Kent_log_instance->kent_sydt->Send(_T("getanswer/id/")+bstr,_T(""));
						if(0 != answer.Left(4).Compare(_T("WAIT"))){
							break;
						}
					}
				}else if(0 == Kent_log_instance->kent_identify_choose.Compare(_T("打码兔"))){
					CString tmp = Kent_log_instance->kent_dama2->D2File3(_T("54c8b801af1c8670c1fa1f12a1e74e86"),Kent_log_instance->kent_studio_dama2_user,Kent_log_instance->kent_studio_dama2_key,Kent_log_instance->kent_root_path+_T("\\sydt.gif"),120,101);
					vector<CString> ans = Kent_log_instance->kent_split(tmp,_T(","));
					if(ans.size()<2){
						answer = _T("");
						MessageBox(NULL,tmp,_T("打码兔错误"),MB_OK);
						return;
					}else{
						answer = ans.at(1);
					}
				}else if(0 == Kent_log_instance->kent_identify_choose.Compare(_T("UU云"))){
					VARIANT tmp;
					_variant_t answer_var = Kent_log_instance->kent_uuwise->easyRecognizeFile(97690,_T("3006defbb89e4963ba5cafdf4d6c2ada"),_bstr_t(Kent_log_instance->kent_studio_uuwise_user),_bstr_t(Kent_log_instance->kent_studio_uuwise_key),_bstr_t(Kent_log_instance->kent_root_path+_T("\\sydt.gif")),1,&tmp);
					answer = COLE2T(answer_var.bstrVal);
					if(answer.Mid(0,1) == _T("-")){
						MessageBox(NULL,answer,_T("UU云错误"),MB_OK);
						return;
					}else{
						vector<CString> answer_split = Kent_log_instance->kent_split(answer,_T("_"));
						if(2 == answer_split.size()){
							answer = answer_split.at(1);
						}
					}
				}else{
					MessageBox(NULL,_T("无法识别验证码"),_T("无法识别验证码"),MB_OK);
					return;
				}
				dm->MoveTo(623,368);
				Sleep(500);
				dm->LeftClick();
				Sleep(500);
				cipher_input(answer);
				Sleep(1000);
				dm->MoveTo(516,463);
				Sleep(500);
				dm->LeftClick();
				Sleep(500);
				dm->KeyPressChar(_T("enter"));
				Sleep(6000);
			}else if(qq_x.intVal > 0){//输入qq号和密码
				if(Kent_log_instance->kent_studio_can_connect){//可以连接中控台
					if(Kent_log_instance->kent_reconnect_qq_num.IsEmpty() || Kent_log_instance->kent_reconnect_qq_password.IsEmpty()){//是空
						bool isdone = false;
						for(int i = 0;i<3;i++){
							if(Kent_log_instance->GetNewTask()){
								isdone = true;//获取新任务成功
								break;
							}else{
								Sleep(3000);
							}
						}
						if(!isdone){
							MessageBox(NULL,_T("获取新任务失败"),_T("连接中控台获取新任务失败"),MB_OK);
						}
					}
				}
				
				dm->SetWindowState(Hwnd_connect,2);//最小化
				Sleep(2000);
				dm->SetWindowState(Hwnd_connect,5);//恢复
				Sleep(2000);
				dm->MoveTo(1033,334);
				dm->LeftClick();
				for(int i=0;i<15;i++){
					dm->KeyPressChar(_T("back"));
				}
				cipher_input(Kent_log_instance->kent_reconnect_qq_num);
				dm->MoveTo(1043,400);
				dm->LeftClick();
				Sleep(500);
				for(int i=0;i<15;i++){
					dm->KeyPressChar(_T("back"));
				}
				cipher_input(Kent_log_instance->kent_reconnect_qq_password);
				Sleep(500);
				dm->KeyPressChar(_T("enter"));
				Sleep(500);
				dm->KeyPressChar(_T("enter"));
				Sleep(6000);
				Kent_log_instance->write_log(_T("崩溃-qq号码:")+Kent_log_instance->kent_reconnect_qq_num);
			}
		}
	}
}
void kent_windows::han_reconnect_protect()
{
	if((Kent_log_instance->kent_reconnect_normal) && Kent_connect_inuse == iswindows){//
		if(dm->GetColorNum(571,14,708,57, _T("b94f0d-404040"), 1.0) > 2000)//
		{
			dm->MoveTo(639,38);
			Sleep(100);
			dm->LeftClick();
			Sleep(10000);
		}
	}

	if((Kent_log_instance->kent_reconnect_normal) && Kent_login_inuse == iswindows && (Kent_start_none==isstart_num || Kent_start_waiting==isstart_num)){//
		VARIANT wrong_confirm_x,wrong_confirm_y;
		dm->FindPic(569,456,724,512, file_name(_T("韩确认.bmp")), _T("202020"), 0.8, 0, &wrong_confirm_x, &wrong_confirm_y);//弹出确认框
		if(wrong_confirm_x.intVal>0){//密码输入错误
			dm->MoveTo(wrong_confirm_x.intVal + 33, wrong_confirm_y.intVal + 13);
			Sleep(200);
			dm->MoveTo(wrong_confirm_x.intVal + 53, wrong_confirm_y.intVal + 13);
			Sleep(200);
			dm->LeftClick();
			Sleep(200);
			Kent_log_instance->write_log(_T("崩溃-密码输入错误"));
		}
		
		VARIANT acount_x, acount_y;
		dm->FindPic( 798, 232, 1064, 405, file_name(_T("韩账号.bmp")), _T("202020"), 0.8, 0, &acount_x, &acount_y);//
		if(acount_x.intVal > 0){
			if(Kent_log_instance->kent_studio_can_connect){//可以连接中控台
				if(Kent_log_instance->kent_reconnect_qq_num.IsEmpty() || Kent_log_instance->kent_reconnect_qq_password.IsEmpty()){//是空
					bool isdone = false;
					for(int i = 0;i<3;i++){
						if(Kent_log_instance->GetNewTask()){
							isdone = true;//获取新任务成功
							break;
						}else{
							Sleep(3000);
						}
					}
					if(!isdone){
						MessageBox(NULL,_T("获取新任务失败"),_T("连接中控台获取新任务失败"),MB_OK);
					}
				}
			}

			dm->MoveTo(256,288);
			dm->LeftClick();
			for(int i=0;i<15;i++){
				dm->KeyPressChar(_T("back"));
			}

			dm->SendString2(Hwnd_login,Kent_log_instance->kent_reconnect_qq_num);
			//cipher_input(Kent_log_instance->kent_reconnect_qq_num);

			dm->MoveTo(256,349);
			dm->LeftClick();
			Sleep(500);
			for(int i=0;i<15;i++){
				dm->KeyPressChar(_T("back"));
			}
			
			dm->SendString2(Hwnd_login,Kent_log_instance->kent_reconnect_qq_password);
			//cipher_input(Kent_log_instance->kent_reconnect_qq_password);
			Sleep(500);
			dm->KeyPressChar(_T("enter"));
			Sleep(10000);
			Kent_log_instance->write_log(_T("崩溃-qq号码:")+Kent_log_instance->kent_reconnect_qq_num);
		}
	}
}
void kent_windows::cipher_input(CString input_string){
	for(int i =0; i<input_string.GetLength();i++)
	{
		CString tmp= input_string.Mid(i,1);
		if(_T("!") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T("1"));dm->KeyUpChar(_T("shift"));}
		else if(_T("@") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T("2"));dm->KeyUpChar(_T("shift"));}
		else if(_T("#") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T("3"));dm->KeyUpChar(_T("shift"));}
		else if(_T("$") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T("4"));dm->KeyUpChar(_T("shift"));}
		else if(_T("%") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T("5"));dm->KeyUpChar(_T("shift"));}
		else if(_T("^") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T("6"));dm->KeyUpChar(_T("shift"));}
		else if(_T("&") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T("7"));dm->KeyUpChar(_T("shift"));}
		else if(_T("*") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T("8"));dm->KeyUpChar(_T("shift"));}
		else if(_T("(") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T("9"));dm->KeyUpChar(_T("shift"));}
		else if(_T(")") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T("0"));dm->KeyUpChar(_T("shift"));}
		else if(_T("_") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T("1"));dm->KeyUpChar(_T("shift"));}
		else if(_T("+") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T("="));dm->KeyUpChar(_T("shift"));}
		else if(_T("|") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T("\\"));dm->KeyUpChar(_T("shift"));}
		else if(_T(":") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T(";"));dm->KeyUpChar(_T("shift"));}
		else if(_T("<") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T(","));dm->KeyUpChar(_T("shift"));}
		else if(_T(">") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T("."));dm->KeyUpChar(_T("shift"));}
		else if(_T("?") == input_string.Mid(i,1)){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(_T("/"));dm->KeyUpChar(_T("shift"));}
		else if(input_string.GetAt(i)<='9' && input_string.GetAt(i)>='0'){dm->KeyPressChar(input_string.Mid(i,1));}
		else if(input_string.GetAt(i)<='z' && input_string.GetAt(i)>='a'){dm->KeyPressChar(input_string.Mid(i,1));}
		else if(input_string.GetAt(i)<='Z' && input_string.GetAt(i)>='A'){dm->KeyDownChar(_T("shift"));dm->KeyPressChar(input_string.Mid(i,1));dm->KeyUpChar(_T("shift"));}
		else{dm->KeyPressChar(input_string.Mid(i,1));}//大写
		Sleep(50);
		Kent_log_instance->write_log(_T("press"),input_string.Mid(i,1));
	}
}
CPoint kent_windows::kent_search_str(int x1,int y1,int x2,int y2,CString search_str,CString para,double blur_rate,int correct_num)
{
	VARIANT intX,intY;
	vector<CPoint> loc;
	CPoint result_loc = (0,0);
	for(int i = 0;i < search_str.GetLength();i++){
		dm->FindStrFast(x1,y1,x2,y2,search_str.Mid(i,1),para,0.7,&intX,&intY);
		if(intX.intVal > 0){
			CPoint tmp;
			tmp.SetPoint(intX.intVal,intY.intVal) ;
			loc.push_back(tmp);
		}
	}
	if((int)loc.size() >= correct_num){
		for(int i = 0;i<(int)loc.size();i++){
			result_loc += loc.at(i);
		}
		result_loc.SetPoint(result_loc.x / loc.size(),result_loc.y / loc.size());
	}
	return result_loc;
}

