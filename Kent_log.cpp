#include "stdafx.h"

Kent_log::Kent_log(void)
{
	TCHAR buffer[MAX_PATH];
	GetModuleFileName( NULL, buffer, MAX_PATH );
	CString path_buffer(buffer);
	path_buffer = path_buffer.Left(path_buffer.ReverseFind(_T('\\')));
	kent_root_path=_T("");
	kent_root_path=(CString)path_buffer;
	
	CString ResPath;
	GetPrivateProfileString(_T("MAIN"),_T("ResPath"),_T(""),ResPath.GetBuffer(200),200,path_buffer+_T("\\config.ini"));
	ResPath.ReleaseBuffer();

	kent_res_path=kent_root_path+_T("\\")+ResPath;//目录释放地点

	//游戏参数的初始化
	kent_skill_hero_select.push_back(0);
	kent_skill_hero_select.push_back(0);
	kent_skill_hero_select.push_back(0);
	kent_skill_hero_select.push_back(0);
	kent_hero_select.push_back(_T(""));
	kent_hero_select.push_back(_T(""));
	kent_hero_select.push_back(_T(""));
	kent_hero_select.push_back(_T(""));
	kent_hero_occupy_mode = occupy_mode_rand;
	kent_game_match_mode = match_mode_Random;
	kent_hook_mode = hook_mode_background;
	kent_bind_mode = bind_mode_AI;
	kent_hero_die_call_chance = die_call_chance_0;
	kent_hero_rand = true;
	kent_hero_allrand = false;
	kent_hero_ruizi = true;
	kent_hero_occupy_rand_start = false;
	kent_hero_occupy_rand_die = false;
	kent_reconnect_normal = false;
	kent_reconnect_fast =false;
	kent_reconnect_qq_num = _T("");
	kent_reconnect_qq_password = _T("");
	kent_reconnect_qq_area = _T("上次登录大区");

	kent_hero_die_call = _T("...|艹|(⊙o⊙)…|lol");
	is_common_match_mode = FALSE;
	is_distort_match_mode = FALSE;
	is_dominate_match_mode = FALSE;
	is_colosseum_match_mode = FALSE;
	kent_reg_login_user = _T("");
	kent_reg_login_key = _T("");
	kent_shutdown_hour = 0;
	kent_shutdown = false;
	kent_nextstop = false;
	kent_nextshutdown = false;
	kent_nowstop = false;
	kent_nowstart = false;
	kent_nowshutdown = false;
	kent_nowrestart = false;

	resetaccount = false;

	kent_studio_qq_name = _T("");
	kent_studio_now_ip = 0;
	kent_studio_stop_ip = 32000;
	kent_studio_now_stage = 0;
	kent_studio_stop_stage = 30;

	kent_studio_finish_enable = false;
	kent_force_downcpu = false;
	
	kent_change_task = false;
	kent_change_task_time = 10;
	kent_change_task_num = 2;

	kent_studio_ip_adr = _T("");
	kent_studio_port = 16688;
	kent_autorun = false;

	kent_identify_choose = _T("不使用");
	kent_game_resolution = 0;
	kent_identify_sydt_code = _T("");
	kent_studio_dama2_user = _T("");
	kent_studio_dama2_key = _T("");
	kent_studio_uuwise_key = _T("");
	kent_studio_uuwise_user = _T("");
	kent_studio_can_connect = 0;


#if defined kent_forever_background || defined kent_forever
	config_path = _T("C:\\lol_config.ini");
#else
#ifdef kent_han
	config_path = _T("C:\\han_config.ini");//韩服配置
#else
	config_path = _T("C:\\kent_config.ini");
#endif
#endif

}
Kent_log::~Kent_log(void)
{
	if(kent_kss){
		kent_kss->ks_exit();
		delete kent_kss;
	}
}
// 判断目录是否存在
BOOL Kent_log::Kent_FolderExists(CString s)
{
    DWORD attr; 
    attr = GetFileAttributes(s); 
    return (attr != (DWORD)(-1) ) &&
        ( attr & FILE_ATTRIBUTE_DIRECTORY); 
}
// 创建目录
BOOL Kent_log::Kent_CreateDir(CString P)
{
    int len=P.GetLength();
    if ( len <2 ) return false; 
    
    if('\\'==P[len-1])
    {
        P=P.Left(len-1);
        len=P.GetLength();
    }
    if ( len <=0 ) return false;
    
    if (len <=3) 
    {
        if (Kent_FolderExists(P))return true;
        else return false; 
    }
    
    if (Kent_FolderExists(P))return true;
 
    
    
    CString Parent;
    Parent=P.Left(P.ReverseFind('\\') );
    
    if(Parent.GetLength()<=0)return false; 
    
    BOOL Ret=Kent_CreateDir(Parent); 
    
    if(Ret) 
    {
        SECURITY_ATTRIBUTES sa;
        sa.nLength=sizeof(SECURITY_ATTRIBUTES);
        sa.lpSecurityDescriptor=NULL;
        sa.bInheritHandle=0;
        Ret=(CreateDirectory(P,&sa)==TRUE);
        return Ret;
    }
    else
        return FALSE;
}
//注册
BOOL Kent_log::RegDll(LPCTSTR file) 
{
	HMODULE hLib = LoadLibrary(file); 
	if (hLib < (HMODULE)HINSTANCE_ERROR) 	
	{ 
		return FALSE;
	} 
	HRESULT hResult = ::OleInitialize(NULL);
	if(hResult != S_OK)
	{
		FreeLibrary(hLib);
		return FALSE;
	}

	FARPROC lpDllEntryPoint = GetProcAddress(hLib,"DllRegisterServer"); 
	if (lpDllEntryPoint == NULL)
	{
		FreeLibrary(hLib);
		::OleUninitialize();
		return FALSE;
	}
	if(FAILED((*lpDllEntryPoint)()))
	{ 
		FreeLibrary(hLib);
		::OleUninitialize();
		return FALSE;
	}; 
	::OleUninitialize();
	FreeLibrary(hLib);
	return TRUE;
}
//系统参数是否达标检查
void Kent_log::kent_writeini(CString key,CString value)
{
	WritePrivateProfileString(_T("KENT"),key,value,config_path);
}
void Kent_log::kent_writeini(CString key,int value)
{
	CString tmp;
	tmp.Format(_T("%d"),value);
	WritePrivateProfileString(_T("KENT"),key,tmp,config_path);
}
void Kent_log::kent_writeini(CString key,CComboBox *value)
{
	CString tmp;
	tmp.Format(_T("%d"),value->GetCurSel());
	WritePrivateProfileString(_T("KENT"),key,tmp,config_path);
}
void Kent_log::kent_writeini(CString key,CButton *value)
{
	CString tmp;
	tmp.Format(_T("%d"),value->GetCheck());
	WritePrivateProfileString(_T("KENT"),key,tmp,config_path);
}
void Kent_log::kent_writeini(CString key,CEdit *value)
{
	CString tmp,out_str;
	value->GetWindowTextW(tmp);
	vector<CString> get_tmp = kent_split(tmp,_T("\r\n"));
	if(get_tmp.size()){
		vector<CString>::iterator iter = get_tmp.begin();
		out_str = *iter;
		for(iter++;iter != get_tmp.end();iter++)
		{
			out_str += _T("|");
			out_str += *iter;
		}
	}else{
		out_str = tmp;
	}
	WritePrivateProfileString(_T("KENT"),key,out_str,config_path);
}
CString Kent_log::kent_readini(CString key)
{
	CString tmp;
	GetPrivateProfileString(_T("KENT"),key,_T(""),tmp.GetBuffer(200),200,config_path);
	tmp.ReleaseBuffer();
	return tmp;
}
CString Kent_log::kent_readbackini(CString key)
{
	CString tmp;
	GetPrivateProfileString(_T("BACK"),key,_T(""),tmp.GetBuffer(200),200,config_path);
	tmp.ReleaseBuffer();
	return tmp;
}
void Kent_log::kent_writebackini(CString key,CString value)
{
	WritePrivateProfileString(_T("BACK"),key,value,config_path);
}
void Kent_log::kent_writebackini(CString key,int value)
{
	CString tmp;
	tmp.Format(_T("%d"),value);
	WritePrivateProfileString(_T("BACK"),key,tmp,config_path);
}
BOOL Kent_log::DeleteSection(CString SectionName)
{
	return ::WritePrivateProfileSection(SectionName, NULL, config_path);    
}
CString Kent_log::kent_chinese2han(CString key)
{
	CString tmp;
	GetPrivateProfileString(_T("TRANS"),key,_T(""),tmp.GetBuffer(200),200,kent_res_path+_T("\\trans.ini"));
	tmp.ReleaseBuffer();
	return tmp;
}
void Kent_log::option_init()
{
	/*****************初始化参数*****************/
	kent_skill_hero_select.at(0)=0;
	kent_skill_hero_select.at(1)=0;
	kent_skill_hero_select.at(2)=0;
	kent_skill_hero_select.at(3)=0;
	kent_hero_select.at(0)=(_T("黑暗之女"));
	kent_hero_select.at(1)=(_T("暗黑元首"));
	kent_hero_select.at(2)=(_T("寒冰射手"));
	kent_hero_select.at(3)=(_T("流浪法师"));

	kent_hero_occupy_mode = occupy_mode_rand;
	kent_game_match_mode = match_mode_Random;

	kent_hook_mode = hook_mode_background;
	kent_bind_mode = bind_mode_AI;
	kent_hero_die_call_chance = die_call_chance_0;
	kent_hero_rand = false;
	kent_hero_allrand = false;
	kent_hero_ruizi = true;
	kent_hero_occupy_rand_start = false;
	kent_hero_occupy_rand_die = false;
	kent_reconnect_normal = false;
	kent_reconnect_fast =false;
	kent_reconnect_qq_num = _T("");
	kent_reconnect_qq_password = _T("");
	kent_reconnect_qq_area = _T("上次登录大区");
	kent_hero_die_call = _T("...|艹|(⊙o⊙)…|lol");
	
	kent_reg_login_user = _T("");
	kent_reg_login_key = _T("");
	
	kent_shutdown_hour = 0;
	kent_shutdown = false;
	kent_nextstop = false;
	kent_nextshutdown = false;
	kent_nowstop = false;
	kent_nowstart = false;
	kent_nowshutdown = false;
	kent_nowrestart = false;

	resetaccount = false;

	kent_studio_qq_name = _T("");
	kent_studio_now_ip = 0;
	kent_studio_stop_ip = 32000;
	kent_studio_now_stage = 0;
	kent_studio_stop_stage = 30;
	kent_studio_finish_enable = false;
	kent_force_downcpu = false;
	
	kent_change_task = false;
	kent_change_task_time = 10;
	kent_change_task_num = 2;

	kent_studio_ip_adr = _T("");
	kent_studio_port = 16688;
	kent_autorun = false;

	kent_identify_choose = _T("不使用");
	kent_game_resolution = 0;
	kent_identify_sydt_code = _T("");
	kent_studio_dama2_user = _T("");
	kent_studio_dama2_key = _T("");
	kent_studio_uuwise_key = _T("");
	kent_studio_uuwise_user = _T("");
	kent_studio_can_connect = 0;
}
void Kent_log::kent_get_config()
{
	if(dm->IsFileExist(kent_res_path+_T("\\kent_config.ini")))
	{
		if(dm->IsFileExist(config_path)){
			DeleteFile(config_path);
		}
		Sleep(200);
		MoveFile(kent_res_path+_T("\\kent_config.ini"),config_path);
		Sleep(500);
	}
	//从文件中读取配置信息
	CString tmp;
	/*********************Heros 读取**********************/
	//kent_skill_hero_select
	tmp=kent_readini(_T("kent_skill_hero_select1"));
	if(0 != tmp.Compare(_T(""))){kent_skill_hero_select.at(0)=(int)abs(_ttoi(tmp));;}
	tmp =kent_readini(_T("kent_skill_hero_select2"));
	if(0 != tmp.Compare(_T(""))){kent_skill_hero_select.at(1)=(int)abs(_ttoi(tmp));;}
	tmp =kent_readini(_T("kent_skill_hero_select3"));
	if(0 != tmp.Compare(_T(""))){kent_skill_hero_select.at(2)=(int)abs(_ttoi(tmp));;}
	//kent_hero_select
	tmp =kent_readini(_T("kent_hero_select1"));
	if(0 != tmp.Compare(_T(""))){kent_hero_select.at(0)=tmp;}
	tmp =kent_readini(_T("kent_hero_select2"));
	if(0 != tmp.Compare(_T(""))){kent_hero_select.at(1)=tmp;}
	tmp =kent_readini(_T("kent_hero_select3"));
	if(0 != tmp.Compare(_T(""))){kent_hero_select.at(2)=tmp;}
	//kent_hero_occupy_mode
	tmp =kent_readini(_T("kent_hero_occupy_mode"));
	if(0 != tmp.Compare(_T(""))){kent_hero_occupy_mode=(d_occupy_mode)(int)abs(_ttoi(tmp));}
	//kent_game_match_mode
	tmp =kent_readini(_T("kent_game_match_mode"));
	if(0 != tmp.Compare(_T(""))){kent_game_match_mode=(d_match_mode)(int)abs(_ttoi(tmp));}
	//kent_hook_mode
	tmp =kent_readini(_T("kent_hook_mode"));
	if(0 != tmp.Compare(_T(""))){kent_hook_mode=(d_hook_mode)(int)abs(_ttoi(tmp));}
	//kent_bind_mode
	tmp =kent_readini(_T("kent_bind_mode"));
	if(0 != tmp.Compare(_T(""))){kent_bind_mode=(d_bind_mode)(int)abs(_ttoi(tmp));}
	//kent_hero_die_call_chance
	tmp =kent_readini(_T("kent_hero_die_call_chance"));
	if(0 != tmp.Compare(_T(""))){kent_hero_die_call_chance=(d_die_call_chance)(int)abs(_ttoi(tmp));}
	//kent_hero_rand
	tmp =kent_readini(_T("kent_hero_rand"));
	if(0 != tmp.Compare(_T(""))){kent_hero_rand=((0==_ttoi(tmp))?false:true);}
	//kent_hero_allrand
	tmp =kent_readini(_T("kent_hero_allrand"));
	if(0 != tmp.Compare(_T(""))){kent_hero_allrand=((0==_ttoi(tmp))?false:true);}
	//kent_hero_ruizi
	tmp =kent_readini(_T("kent_hero_ruizi"));
	if(0 != tmp.Compare(_T(""))){kent_hero_ruizi=((0==_ttoi(tmp))?false:true);}
	//kent_hero_occupy_rand_start
	tmp =kent_readini(_T("kent_hero_occupy_rand_start"));
	if(0 != tmp.Compare(_T(""))){kent_hero_occupy_rand_start=((0==_ttoi(tmp))?false:true);}
	//kent_hero_occupy_rand_die
	tmp =kent_readini(_T("kent_hero_occupy_rand_die"));
	if(0 != tmp.Compare(_T(""))){kent_hero_occupy_rand_die=((0==_ttoi(tmp))?false:true);}
	//kent_reconnect_normal
	tmp =kent_readini(_T("kent_reconnect_normal"));
	if(0 != tmp.Compare(_T(""))){kent_reconnect_normal=((0==_ttoi(tmp))?false:true);}
	//kent_reconnect_fast
	tmp =kent_readini(_T("kent_reconnect_fast"));
	if(0 != tmp.Compare(_T(""))){kent_reconnect_fast=((0==_ttoi(tmp))?false:true);}
	//kent_reconnect_qq_num
	tmp =kent_readini(_T("kent_reconnect_qq_num"));
	if(0 != tmp.Compare(_T(""))){kent_reconnect_qq_num=tmp;}
	//kent_reconnect_qq_password
	tmp =kent_readini(_T("kent_reconnect_qq_password"));
	if(0 != tmp.Compare(_T(""))){kent_reconnect_qq_password=tmp;}
	//kent_reconnect_qq_area
	tmp =kent_readini(_T("kent_reconnect_qq_area"));
	if(0 != tmp.Compare(_T(""))){kent_reconnect_qq_area=tmp;}
	//kent_hero_die_call
	tmp =kent_readini(_T("kent_hero_die_call"));
	if(0 != tmp.Compare(_T(""))){kent_hero_die_call=tmp;}

	//kent_reg_login_user
	tmp =kent_readini(_T("kent_reg_login_user"));
	if(0 != tmp.Compare(_T(""))){kent_reg_login_user=tmp;}
	//kent_reg_login_key
	tmp =kent_readini(_T("kent_reg_login_key"));
	if(0 != tmp.Compare(_T(""))){kent_reg_login_key=tmp;}


	//kent_identify_sydt_code
	tmp =kent_readini(_T("kent_identify_sydt_code"));
	if(0 != tmp.Compare(_T(""))){kent_identify_sydt_code=tmp;}
	//kent_studio_qq_name
	tmp =kent_readini(_T("kent_studio_qq_name"));
	if(0 != tmp.Compare(_T(""))){kent_studio_qq_name=tmp;}
	//kent_studio_now_ip
	tmp =kent_readini(_T("kent_studio_now_ip"));
	if(0 != tmp.Compare(_T(""))){kent_studio_now_ip=(int)abs(_ttoi(tmp));}
	//kent_studio_stop_ip
	tmp =kent_readini(_T("kent_studio_stop_ip"));
	if(0 != tmp.Compare(_T(""))){kent_studio_stop_ip=(int)abs(_ttoi(tmp));}
	//kent_studio_now_stage
	tmp =kent_readini(_T("kent_studio_now_stage"));
	if(0 != tmp.Compare(_T(""))){kent_studio_now_stage=(int)abs(_ttoi(tmp));}
	//kent_studio_stop_stage
	tmp =kent_readini(_T("kent_studio_stop_stage"));
	if(0 != tmp.Compare(_T(""))){kent_studio_stop_stage=(int)abs(_ttoi(tmp));}
	//kent_studio_finish_enable
	tmp =kent_readini(_T("kent_studio_finish_enable"));
	if(0 != tmp.Compare(_T(""))){kent_studio_finish_enable=((0==_ttoi(tmp))?false:true);}
	//kent_autorun
	tmp =kent_readini(_T("kent_autorun"));
	if(0 != tmp.Compare(_T(""))){kent_autorun=((0==_ttoi(tmp))?false:true);}
	//kent_force_downcpu
	tmp =kent_readini(_T("kent_force_downcpu"));
	if(0 != tmp.Compare(_T(""))){kent_force_downcpu=((0==_ttoi(tmp))?false:true);}
	//kent_change_task
	tmp =kent_readini(_T("kent_change_task"));
	if(0 != tmp.Compare(_T(""))){kent_change_task=((0==_ttoi(tmp))?false:true);}
	//kent_change_task_time
	tmp =kent_readini(_T("kent_change_task_time"));
	if(0 != tmp.Compare(_T(""))){kent_change_task_time=(int)abs(_ttoi(tmp));}
	//kent_change_task_num
	tmp =kent_readini(_T("kent_change_task_num"));
	if(0 != tmp.Compare(_T(""))){kent_change_task_num=(int)abs(_ttoi(tmp));}

	//kent_studio_ip_adr
	tmp =kent_readini(_T("kent_studio_ip_adr"));
	if(0 != tmp.Compare(_T(""))){kent_studio_ip_adr=tmp;}
	//kent_studio_port
	tmp =kent_readini(_T("kent_studio_port"));
	if(0 != tmp.Compare(_T(""))){kent_studio_port=(int)abs(_ttoi(tmp));}
	//kent_identify_choose
	tmp =kent_readini(_T("kent_identify_choose"));
	if(0 != tmp.Compare(_T(""))){kent_identify_choose=tmp;}
	//kent_game_resolution
	tmp =kent_readini(_T("kent_game_resolution"));
	if(0 != tmp.Compare(_T(""))){kent_game_resolution=(int)abs(_ttoi(tmp));}
	//kent_studio_dama2_user
	tmp =kent_readini(_T("kent_studio_dama2_user"));
	if(0 != tmp.Compare(_T(""))){kent_studio_dama2_user=tmp;}
	//kent_studio_dama2_key
	tmp =kent_readini(_T("kent_studio_dama2_key"));
	if(0 != tmp.Compare(_T(""))){kent_studio_dama2_key=tmp;}
	//kent_studio_uuwise_key
	tmp =kent_readini(_T("kent_studio_uuwise_key"));
	if(0 != tmp.Compare(_T(""))){kent_studio_uuwise_key=tmp;}
	//kent_studio_uuwise_user
	tmp =kent_readini(_T("kent_studio_uuwise_user"));
	if(0 != tmp.Compare(_T(""))){kent_studio_uuwise_user=tmp;}
}
void Kent_log::kent_store_studio_config()
{
	kent_writeini(_T("kent_reg_login_user"),kent_reg_login_user);
	kent_writeini(_T("kent_reg_login_key"),kent_reg_login_key);
	kent_writeini(_T("kent_identify_choose"),kent_identify_choose);
	kent_writeini(_T("kent_identify_sydt_code"),kent_identify_sydt_code);
	kent_writeini(_T("kent_studio_dama2_user"),kent_studio_dama2_user);
	kent_writeini(_T("kent_studio_dama2_key"),kent_studio_dama2_key);
	kent_writeini(_T("kent_studio_uuwise_user"),kent_studio_uuwise_user);
	kent_writeini(_T("kent_studio_uuwise_key"),kent_studio_uuwise_key);
	kent_writeini(_T("kent_game_match_mode"),kent_game_match_mode);
	kent_writeini(_T("kent_game_resolution"),kent_game_resolution);
	kent_writeini(_T("kent_hero_select1"),kent_hero_select.at(0));
	kent_writeini(_T("kent_hero_select2"),kent_hero_select.at(1));
	kent_writeini(_T("kent_hero_select3"),kent_hero_select.at(2));
	kent_writeini(_T("kent_hero_ruizi"),kent_hero_ruizi);
	kent_writeini(_T("kent_hero_rand"),kent_hero_rand);
	
	kent_writeini(_T("kent_studio_finish_enable"),kent_studio_finish_enable);
	kent_writeini(_T("kent_force_downcpu"),kent_force_downcpu);
	kent_writeini(_T("kent_change_task"),kent_change_task);
	kent_writeini(_T("kent_change_task_time"),kent_change_task_time);
	kent_writeini(_T("kent_change_task_num"),kent_change_task_num);
	kent_writeini(_T("kent_autorun"),kent_autorun);
	

	kent_writeini(_T("kent_reconnect_normal"),kent_reconnect_normal);
	kent_writeini(_T("kent_reconnect_fast"),kent_reconnect_fast);

	kent_writeini(_T("kent_reconnect_qq_num"),kent_reconnect_qq_num);
	kent_writeini(_T("kent_reconnect_qq_password"),kent_reconnect_qq_password);
	kent_writeini(_T("kent_studio_qq_name"),kent_studio_qq_name);
	kent_writeini(_T("kent_reconnect_qq_area"),kent_reconnect_qq_area);
	kent_writeini(_T("kent_studio_now_ip"),kent_studio_now_ip);
	kent_writeini(_T("kent_studio_now_stage"),kent_studio_now_stage);
	kent_writeini(_T("kent_studio_stop_ip"),kent_studio_stop_ip);
	kent_writeini(_T("kent_studio_stop_stage"),kent_studio_stop_stage);

}
void Kent_log::write_log(CString txt)
{
#ifdef _DEBUG
	CTime tm;
	tm=CTime::GetCurrentTime();
	CString tmp=tm.Format("%Y-%m-%d %X: ");
	dm->WriteFile(_T("lol_kent.log"),tmp+txt+_T("\r\n"));
	std::wcout<<(LPCTSTR)txt<<endl;
#endif
}
void Kent_log::write_log(long num)
{
#ifdef _DEBUG
	CTime tm;
	tm=CTime::GetCurrentTime();
	CString tmp;
	tmp.Format(_T("%d"),num);
	tmp=tm.Format("%Y-%m-%d %X: ")+tmp;
	dm->WriteFile(_T("lol_kent.log"),tmp+_T("\r\n"));
	std::wcout<<num<<endl;
#endif
}
void Kent_log::write_log(CString key,CString txt)
{
#ifdef _DEBUG
	CTime tm;
	tm=CTime::GetCurrentTime();
	CString tmp=tm.Format("%Y-%m-%d %X: ");
	dm->WriteFile(_T("lol_kent.log"),tmp+key+_T("\t")+txt+_T("\r\n"));
	std::wcout<<(LPCTSTR)key<<_T("\t")<<(LPCTSTR)txt<<endl;
#endif
}
void Kent_log::write_log(CString key,long num)
{
#ifdef _DEBUG
	CTime tm;
	tm=CTime::GetCurrentTime();
	CString tmp;
	tmp.Format(_T("%d"),num);
	tmp=tm.Format("%Y-%m-%d %X: ")+key+_T("\t")+tmp;
	dm->WriteFile(_T("lol_kent.log"),tmp+_T("\r\n"));
	std::wcout<<(LPCTSTR)key<<_T("\t")<<num<<endl;
#endif
}
bool Kent_log::reg_dm()
{
#ifdef _kent_background_
	// 步骤5 收费用户注册
VMProtectBeginUltra("lbl.dyf_reg");//lbl.dyf_reg标记
	long ret = dm->RegEx(VMProtectDecryptStringW(_T("xuguruogu4d5b2fec9695cadfa3e998e44acfbd09")),_T(""),_T("122.10.92.197|122.10.93.166|42.51.15.137|98.126.127.97"));
	if (ret != 1)
	{
		CString tmp;
		tmp.Format(_T("插件注册失败,返回值是:%d"),ret);
		MessageBox(NULL,tmp,_T("错误"),MB_OK);
		return false;
	}
VMProtectEnd();
#endif

	dm->SetDictPwd(_T("kent217"));
	//dm->SetExactOcr(0);//关闭精准识别
	dm->SetPath(kent_res_path);
	dm->SetDict(0,_T("dm_soft.txt"));
#ifdef kent_han
	dm->SetDict(3,_T("Hnumip.txt"));
	dm->SetDict(4,_T("Hnumstage.txt"));
#else
	dm->SetDict(1,_T("numip.txt"));
	dm->SetDict(2,_T("numstage.txt"));
	dm->SetDict(3,_T("GameIpL.txt"));
	dm->SetDict(4,_T("GameIpS.txt"));
#endif
	dm->UseDict(0);
	dm->SetMouseDelay(_T("dx"),60);
	dm->SetMouseDelay(_T("normal"),60);
	dm->SetMouseDelay(_T("windows"),60);
	dm->SetKeypadDelay(_T("dx"),60);
	dm->SetKeypadDelay(_T("normal"),60);
	dm->SetKeypadDelay(_T("windows"),60);
	dm->SetPicPwd(_T("kent217"));
	if(1 == dm->CheckUAC()){
		dm->SetUAC(0);//关闭UAC
	}
	return true;
}
void Kent_log::delete_log()
{
#ifdef _DEBUG
	DeleteFile(_T("lol_kent.log"));
#endif
}
vector<CString> Kent_log::kent_split(CString str_in,CString str_split)
{
	vector<CString> tmp;
	_TCHAR *p;
	p = _tcstok(str_in.GetBuffer(),str_split);
    while(p)
    {
		tmp.push_back(p);
        p = _tcstok(NULL,str_split);
    }
	str_in.ReleaseBuffer();
	return tmp;
}
/******************验证类别的函数*********************/
bool Kent_log::kent_kss_init(){
	kent_kss = new Cv901();
	if(!RegDll(kent_root_path+_T("\\kssPluginCom.dll")))
	{
		delete kent_kss;
		kent_kss=NULL;
		MessageBox(NULL,_T("注册kssPluginCom.dll,请解压后以管理员权限运行"),_T("错误"),MB_OK);
		return false;
	}
	if (!kent_kss->CreateDispatch(_T("ksreg.v901")))
	{
		delete kent_kss;
		kent_kss=NULL;
		MessageBox(NULL,_T("创建kssPluginCom对象失败,检查是否正常注册"),_T("错误"),MB_OK);
		return false;
	}
VMProtectBeginUltra("kent_kss_init");//kent_kss_init标记

	CString result = ValueMD5(kent_root_path+_T("\\kssPluginCom.dll"));
	CString result2;
	if(0 == result.GetLength()){
		MessageBox(NULL,_T("没有找到kssPluginCom.dll"),_T("错误"),MB_OK);
		return false;
	}
	for (int i=5;i<15;i++){
		result2+=result[i];
	}
	if (result2.Compare(VMProtectDecryptStringW(_T("e9ceb27837")))){
		MessageBox(NULL,VMProtectDecryptStringW(_T("kssPluginCom.dll文件损坏，请重新下载")),_T("错误"),MB_OK);
		return false;
	}

	CString v_rsamod = __TEXT("74687704111378830280665360989253296458770718923682256637528473930561054297809");  // v_rsa mod = __TEXT("") 就是关闭RSA功能，服务端也应关闭RSA
	CString v_rsapubkey = __TEXT("53507");  //v_rsapubkey = __TEXT("")  就是关闭RSA功能，服务端也应关闭RSA

    // ★★★★★★ 该数据从管理端获取后设置到这里：【软件列表】->右上角【取签名数据】按钮单击即可获取。
	signData = __TEXT("");
	signData += __TEXT("5d1a2bffdf66e63eefc50b3efbc6ec62f15b8250e354c27c2bd0a91fa19370f56a9d5749917bc3d68f08765b1234fc73f228");
	signData += __TEXT("48036036f547abf2e334fc1672769dc3096f86b03c4e9d275b78fe4a6080b4a1029ef3abdf07863cf9fb36455f9096c2ccf0");
	signData += __TEXT("fa3da70ab673ab2d525dd28665f0c484796a750ee0c95aa5c1e930f1d572081d97ee49875c306d1cbb59ee799c328bd9c2f8");
	signData += __TEXT("0bb176ba7ce3325f34974fbfa27e99cf154ec993f6762a5522d5022bfd2ce5ecd9c9b7a31e52eda37db3cde950080608036f");
	signData += __TEXT("edabb0c762777e72498afc77374f3f524f81345a9cb6d0bfeeda90651fab126fe7ac26767f9f1a786c12350c00c3211fa898");
	signData += __TEXT("e7820d38bc654309c14f2111bcddf1fd383898f30d39b111c5b3af06bc7c19dbeb7c3dc9ebec6f55d3f92613aaa47a03d234");
	signData += __TEXT("6951b42ecea7670a137b48cdd24231348962fc64557080b50efa1a3926198782f909fe4e9aa73ec96eba44e330a662398bc9");
	signData += __TEXT("a40b5de93e78fdcbded9dc0f4996f9ec001c5f93020b39b760a83026c5cf263546e487839591201bffe442443d770648fc1e");

	CString v_bdinfo = __TEXT("");	// 用户的绑定信息。
    // 1、如果这里的值不为空，该数据会由服务端效验，也就是说如果服务端数据库里相应用户的绑定信息与该值不相同，会被服务端认为非法，也就是验证不能通过。
    // 2、如果这里的值为空，登陆成功后通过ks_GetData (4)取得服务器返回的用户绑定信息，也就是说你可以用ks_GetData (4)的值来处理你自己的应用。

	CString LicenseKey = __TEXT("");
	LicenseKey += __TEXT("BZTlVrngwdj7juTRIH0t8FPFQJlNPwHyF4iIG4YMg5VM+TR4bvw1SE3yxWDcj/7hyONEjrG9QfvNmkLx");
	LicenseKey += __TEXT("pPct4GVlzXvBtWMxFqB3AqkfkwJniZSsrtALJbn2ghQMJo/hzwCJ8811VgFEoh2bmFtPmSgTxQJSjr40");
	LicenseKey += __TEXT("kAgWbD/bbY5FjJeB/pPGzwUZ5rUwQHeNUw+uqNFxmmHW3rJKteSIbt2+IsRb6MTepiSBya6ao/0aEtDF");
	LicenseKey += __TEXT("ct5TaxyoFws1aVlqbbl6azoGVSML63E7UZmGeq+mi97YrFFppx1JtRrNFajUpzsTukLX3G3XWKmlXpxv");
	LicenseKey += __TEXT("xbW5HYEch8w+1++6uDXVPJT+dIGC2Zyf0N1gRMFo3z3aLuNoprIrBOzO4t3dRkvVSv8aAiCTQtWnvJdU");
	LicenseKey += __TEXT("FGWzWBgvgcRaiI97Q+Qfcn8qRW/NoJYwPOQ3PpTAYwBXZGVgYSSTb5+fRrlrLi9djiCjUreMO69dXPD8");
	LicenseKey += __TEXT("8ACHM7ob1UyoAnMRSVnhfe/hd5NoJxdaaZxHBWWDZK1GisT5DpYzs+VYDrTfTRtqoMR53CITjSW0vt+h");
	LicenseKey += __TEXT("4/jhvlbPYk/l8v9V75qyoxHIk8prGXDRQpdgNgLZ6J5OTbLy5wN6WbgjTiqQPwd3BXG4uZFDT+zBVSZn");
	LicenseKey += __TEXT("dg9MWwdlC6LN3OpgVjVgmsAtZ7nng7arszwGf4dmpJn5qN/HRCodDAWgJWN9gszbVjdC8+zolV/4Y8Yj");
	LicenseKey += __TEXT("/ZOiw25to38aQXHw474uE/BG67Bkb9OGUpBDvrgQCG9kvkmVgyD64UjDC9/1TpDIOGcesIqaFARSUznl");
	LicenseKey += __TEXT("IsAucZsUQVvDDdkfjKyH9O/QWS3JPeYu4QN3Mp5sEdP/+Uy1B6f/UXTsFozZhGdf3sMYCu5gS5qzk7/F");
	LicenseKey += __TEXT("Qs9ihXFCQUoIzqs0TDvJq7Jz8FHL1SVLYAlRGmzLwfjsQgWDLAojQf/phSVS8wmbPgdw0Syu4ETMEcvV");
	LicenseKey += __TEXT("f6p8wzCfWX2Ga4HxtR/fntladDBJDlMP+jZ4tbdf9rrj5FgPP7NGmE3wOVO4rU9G10p5PadygmDaYR2Q");
	LicenseKey += __TEXT("590VGcAMwMk6iUuilHmqhqzNLocKHQzjTjbSe3NnJGhy6lk5YrU1VAL7fV3aIuupiBKFds/+ul+eUeM7");
	LicenseKey += __TEXT("2p5eb6uQfJZLn+dpccWbD4tg2fCeLSLf0f8DtII2F+xLxWtZRJl5BrzbwC4l0+2MU/hB+44W2mXIDr+0");
	LicenseKey += __TEXT("MnZ+Bw7PKEIc9NCYaKfVwssRfTXPIn0sXSwEtw3rDQ/yazJkrHEOkrkw2RIyDvDSeSg9E77PXLjPNQqr");
	LicenseKey += __TEXT("MZ7pfbyyhHSMeMK7NB7Do5gozfxGBRYFivPGoudqB/hBUFWCfHNGuaB1j1T1qhgED5zXUjO6KW8zgNg/");
	LicenseKey += __TEXT("8NrppUCz7y4r6RdHwfk/YxDMjKzevQY1vvB7mVVn3Ys/Vvg70vP1w4i7o3UOqYMFNZH+WpHUK53lEr3u");
	LicenseKey += __TEXT("nUSjy34NRP0bV0UZZIW2HFlswnE8zDGdz8M353QVsHdezaj9SNK/Q6vbVjvxIt/GrhsczZjkYpFT064E");
	LicenseKey += __TEXT("dMkoiFJYbWWmWaTLijRaRjJlfUB1Tga9Sh/fikCtVMosimqDkz82eKVAiwLfE6IFal1RGdvO5S4Jw6en");
	LicenseKey += __TEXT("oNGHu5xFn03mrjNeK96UOGet5vpb8yhAfbNje4JIZedUnG+p/5JV1OkVNH0KUDtkZe7xi3nnu43AZ9Gq");
	LicenseKey += __TEXT("8DnHN8f9VqsxRh5rjfsjKMY7Du4=");
	

	//KS授权信息
	kent_kss->ks_setLicense(LicenseKey);

    //初始化扩展参数，一般情况下无需修改
    kent_kss->ks_setExtVal(0,dm->GetMachineCode(),_T("C:\\kss.ini"), 10000/*超时时间*/, 1/*有备用服务器*/,v_rsamod,v_rsapubkey,_T(""),_T(""),_T(""));
#if defined lol_home_background
    // ★★★★★★此参数请查阅管理端【软件列表】里[软件编号]的值
    v_softcode = 1000005;
	//设置软件编号参数与软件密钥参数，本接口只可调用一次
	kent_kss->ks_setSoftVal(v_softcode,_T("8JoaiDhRUnjlEl5NWSifSw5F"));
#elif defined lol_home_foreground
    // ★★★★★★此参数请查阅管理端【软件列表】里[软件编号]的值
    v_softcode = 1000004;
	//设置软件编号参数与软件密钥参数，本接口只可调用一次
	kent_kss->ks_setSoftVal(v_softcode,_T("5tsFkwI9xSDG97iF5711X872"));
#elif defined kent_background
    // ★★★★★★此参数请查阅管理端【软件列表】里[软件编号]的值
    v_softcode = 1000003;
	//设置软件编号参数与软件密钥参数，本接口只可调用一次
	kent_kss->ks_setSoftVal(v_softcode,_T("uJ23Xl7K6Bf4Zd9i5pW2Ib9b"));
#elif defined kent_foreground
    // ★★★★★★此参数请查阅管理端【软件列表】里[软件编号]的值
    v_softcode = 1000002;
	//设置软件编号参数与软件密钥参数，本接口只可调用一次
	kent_kss->ks_setSoftVal(v_softcode,_T("7kz5X3HhaIVIJ5j248bRXTA4"));
#elif defined kent_han
    // ★★★★★★此参数请查阅管理端【软件列表】里[软件编号]的值
    v_softcode = 1000008;
	//设置软件编号参数与软件密钥参数，本接口只可调用一次
	kent_kss->ks_setSoftVal(v_softcode,_T("fnZA6RbGHf3Cl865gUPSfWh8"));
#elif defined kent_forever
    // ★★★★★★此参数请查阅管理端【软件列表】里[软件编号]的值
    v_softcode = 1000011;
	//设置软件编号参数与软件密钥参数，本接口只可调用一次
	kent_kss->ks_setSoftVal(v_softcode,_T("ibbb2danf547z6uX8Hw9Z6ns"));

#elif defined kent_forever_background
    // ★★★★★★此参数请查阅管理端【软件列表】里[软件编号]的值
    v_softcode = 1000007;
	//设置软件编号参数与软件密钥参数，本接口只可调用一次
	kent_kss->ks_setSoftVal(v_softcode,_T("qi1I2IjFPIlltflG5Ps8sANF"));


#endif
	kent_kss->ks_setUserVal(1,kent_reg_login_user,kent_reg_login_key,_T(""));

	//注册
	//CString tmp = kent_kss_identify->ks_reguser(v_softcode,_T("kent"),_T("libenli09"),_T("kentyouknows"),_T(""),_T(""),_T(""));
	
	//充值
	//CString tmp = kent_kss_identify->ks_prepaid(v_softcode,_T("xuguruogu"),_T("xuguS4751Bm1zz8pbC2Bc8RU823IBQ49"));
	
	//解绑
	//CString tmp = kent_kss_identify->ks_unbind(v_softcode,1,_T("xuguruogu"),_T("libenli09test"));

	//设置用户信息
	//kent_kss_identify->ks_setUserVal(1,_T("xuguruogu"),_T("libenli09"),_T(""));

	//用户检查
	//int i_rnd = (int)(49 * rand() / (RAND_MAX + 1.0));
	//CString v_msgstr = kent_kss_identify->ks_IdCheck(signData.Mid(i_rnd*8, 8), 0);
	//if(iserrno(v_msgstr)){
	//	MessageBox(NULL,kent_kss_identify->ks_GetMsg(v_msgstr),_T("错误"),MB_OK);
	//}if(signData.Mid(i_rnd * 8 + 400, 8) != v_msgstr){
	//	MessageBox(NULL,_T("软件验证失败，将关闭程序"),_T("错误"),MB_OK);
	//	ExitProcess(0);
	//}

	//修改用户资料
	//CString tempstr = kent_kss_identify->ks_edit(v_softcode,_T("xuguruogu"),_T("kent123"),_T("libenli09test"),_T(""));
	//if(iserrno(tempstr)){
	//MessageBox(NULL,kent_kss_identify->ks_GetMsg(tempstr),_T("错误"),MB_OK);
	//}

	//查询用户信息
	//CString tmp = kent_kss_identify->ks_viewinfo(v_softcode,_T("xuguruogu"));
#if defined kent_background || defined kent_foreground || defined kent_han
	this->kent_version=_T("4.0");
#elif defined lol_home_background || defined lol_home_foreground
	this->kent_version=_T("6.8");
#else
	this->kent_version=_T("2.8");
#endif
VMProtectEnd();
	return true;
}
void Kent_log::kent_check_version()
{
	CString s_isup = kent_kss->ks_GetData(v_softcode * 10 + 1);//服务端软件是否强制更新
	CString s_version = kent_kss->ks_GetData(v_softcode * 10 + 2);//服务端软件版本
	CString s_downurl = kent_kss->ks_GetData(v_softcode * 10 + 3);//服务端软件下载地址
	CString s_notice = kent_kss->ks_GetData(v_softcode * 10 + 5);//服务端软件公告

	double now_version = _tstof(kent_version);
	double new_version = _tstof(s_version);
	if(new_version > now_version*10 + 0.01){//有更新
		MessageBox(NULL,s_notice,_T("更新提示"),MB_OK);
#if defined kent_background || defined kent_foreground || defined kent_han
		ShellExecute(NULL,_T("open"),s_downurl,NULL,NULL,SW_SHOWNORMAL);
#endif
		if(s_isup == _T("1")){//强制更新
			exit(0);
		}
	}
}
CPoint Kent_log::choose_large_area(CString str_in){
	CPoint tmp;
	if(0 == str_in.Compare(_T("上次登录大区"))){tmp.SetPoint(0, 0);
	}else if(0 == str_in.Compare(_T("艾欧尼亚"))){tmp.SetPoint(105, 277);
	}else if(0 == str_in.Compare(_T("祖安"))){tmp.SetPoint(236, 277);
	}else if(0 == str_in.Compare(_T("诺克萨斯"))){tmp.SetPoint(366, 277);
	}else if(0 == str_in.Compare(_T("班德尔城"))){tmp.SetPoint(499, 277);
	}else if(0 == str_in.Compare(_T("皮尔特若夫"))){tmp.SetPoint(640, 277);

	}else if(0 == str_in.Compare(_T("战争学院"))){tmp.SetPoint(105, 325);
	}else if(0 == str_in.Compare(_T("巨神峰"))){tmp.SetPoint(236, 325);
	}else if(0 == str_in.Compare(_T("雷瑟守备"))){tmp.SetPoint(366, 325);
	}else if(0 == str_in.Compare(_T("钢铁烈阳"))){tmp.SetPoint(499, 325);
	}else if(0 == str_in.Compare(_T("裁决之地"))){tmp.SetPoint(640, 325);

	}else if(0 == str_in.Compare(_T("黑色玫瑰"))){tmp.SetPoint(105, 369);
	}else if(0 == str_in.Compare(_T("暗影岛"))){tmp.SetPoint(236, 369);
	}else if(0 == str_in.Compare(_T("均衡教派"))){tmp.SetPoint(366, 369);
	}else if(0 == str_in.Compare(_T("水晶之痕"))){tmp.SetPoint(499, 369);
	}else if(0 == str_in.Compare(_T("影流"))){tmp.SetPoint(640, 369);

	}else if(0 == str_in.Compare(_T("守望之海"))){tmp.SetPoint(105,  414);
	}else if(0 == str_in.Compare(_T("征服之海"))){tmp.SetPoint(236,  414);
	}else if(0 == str_in.Compare(_T("卡拉曼达"))){tmp.SetPoint(366,  414);
	}else if(0 == str_in.Compare(_T("皮城戒备"))){tmp.SetPoint(499,  414);


	}else if(0 == str_in.Compare(_T("比尔吉沃特"))){tmp.SetPoint(105,  500);
	}else if(0 == str_in.Compare(_T("德玛西亚"))){tmp.SetPoint(236,  500);
	}else if(0 == str_in.Compare(_T("弗雷尔卓德"))){tmp.SetPoint(366,  500);
	}else if(0 == str_in.Compare(_T("无畏先锋"))){tmp.SetPoint(499,  500);
	}else if(0 == str_in.Compare(_T("恕瑞玛"))){tmp.SetPoint(640,  500);

	}else if(0 == str_in.Compare(_T("扭曲丛林"))){tmp.SetPoint(105,  545);
	}else if(0 == str_in.Compare(_T("巨龙之巢"))){tmp.SetPoint(236,  545);
	}else if(0 == str_in.Compare(_T("教育网专区"))){tmp.SetPoint(105,  631);
	}else{tmp.SetPoint(0,0);}
	return tmp;
}
/******************代答*********************/
bool Kent_log::sydt_init(){
	kent_sydt = new Csydtdll();
	if(!RegDll(kent_root_path+_T("\\sydt.dll"))){
		delete kent_sydt;
		MessageBox(NULL,_T("注册sydt.dll插件失败,请使用管理员权限运行,您依然可以正常使用"),_T("错误"),MB_OK);
		return false;
	}
	if (!kent_sydt->CreateDispatch(_T("sy.dt.1"))){
		delete kent_sydt;
		MessageBox(NULL,_T("创建Csydtdll对象失败,检查是否正常注册,您依然可以正常使用"),_T("错误"),MB_OK);
		return false;
	}//验证文件cloud.dll MD5
VMProtectBeginUltra("sydt_init");//sydt_init标记
	CString result = ValueMD5(kent_root_path+_T("\\sydt.dll"));
	CString result2;
	for (int i=5;i<15;i++){
		result2+=result[i];
	}
	if (result2.Compare(VMProtectDecryptStringW(_T("b3df5d04ce")))){
		MessageBox(NULL,_T("sydt.dll文件损坏，请重新下载"),_T("错误"),MB_OK);
		exit(1);
	}
	CString ret = kent_sydt->Send(_T("clearmac"),_T(""));
	ASSERT(0 == ret.Compare(_T("1")));
VMProtectEnd();
	return true;
}
bool Kent_log::dama2_init(){
	kent_dama2 = new CDama2Ctrl();
	if(!RegDll(kent_root_path+_T("\\Dama2.dll"))){
		delete kent_dama2;
		MessageBox(NULL,_T("注册Dama2.dll插件失败,请使用管理员权限运行,您依然可以正常使用"),_T("错误"),MB_OK);
		return false;
	}
	if (!kent_dama2->CreateDispatch(_T("Dama2Ctrl"))){
		delete kent_dama2;
		MessageBox(NULL,_T("创建Csydtdll对象失败,检查是否正常注册,您依然可以正常使用"),_T("错误"),MB_OK);
		return false;
	}//验证文件cloud.dll MD5
VMProtectBeginUltra("dama2_init");//sydt_init标记
	CString result = ValueMD5(kent_root_path+_T("\\Dama2.dll"));
	CString result2;
	for (int i=5;i<15;i++){
		result2+=result[i];
	}
	if (result2.Compare(VMProtectDecryptStringW(_T("e519a8d10c")))){
		MessageBox(NULL,_T("Dama2.dll文件损坏，请重新下载"),_T("错误"),MB_OK);
		exit(1);
	}
VMProtectEnd();
	return true;
}
bool Kent_log::uuwise_init()
{
	//kent_uuwise = new CCaptchaRecognizer();
	HMODULE hDll = LoadLibrary(_T("UUWiseHelper.dll"));
	if (hDll == NULL)
	{
		return FALSE;
	}
	FARPROC pfn = GetProcAddress(hDll, "DllRegisterServer");
	if (pfn != NULL)
	{
		HRESULT hr = pfn();
		if(!SUCCEEDED(hr))
		{
			return FALSE;
		}
	}
	kent_uuwise.CreateInstance(_T("UUWiseHelper.CaptchaRecognizer"));
	//验证文件cloud.dll MD5
VMProtectBeginUltra("UUWise_init");//UUWise_init标记
	CString result = ValueMD5(kent_root_path+_T("\\UUWiseHelper.dll"));
	CString result2;
	for (int i=5;i<15;i++){
		result2+=result[i];
	}
	if (result2.Compare(VMProtectDecryptStringW(_T("083936b7f3")))){
		MessageBox(NULL,_T("UUWiseHelper.dll文件损坏，请重新下载"),_T("错误"),MB_OK);
		exit(1);
	}
VMProtectEnd();
	return true;
}

bool Kent_log::FinishTask()//完成任务
{
	Json::Value root_finishtask;//对象
	root_finishtask["qq_num"] = UnicodeToUTF8(kent_reconnect_qq_num.GetBuffer()).c_str();kent_reconnect_qq_num.ReleaseBuffer();//QQ账号
	root_finishtask["qq_key"] = UnicodeToUTF8(kent_reconnect_qq_password.GetBuffer()).c_str();kent_reconnect_qq_password.ReleaseBuffer();//QQ密码
	root_finishtask["qq_name"] = UnicodeToUTF8(kent_studio_qq_name.GetBuffer()).c_str();kent_studio_qq_name.ReleaseBuffer();//名字
	root_finishtask["qq_area"] = UnicodeToUTF8(kent_reconnect_qq_area.GetBuffer()).c_str();kent_reconnect_qq_area.ReleaseBuffer();//大区
	root_finishtask["now_ip"] = kent_studio_now_ip;//当前金币
	root_finishtask["stop_ip"] = kent_studio_stop_ip;//停止金币
	root_finishtask["now_stage"] = kent_studio_now_stage;//当前等级
	root_finishtask["stop_stage"] = kent_studio_stop_stage;//停止等级

	Json::FastWriter writer_finishtask;
	string jsondoc_finishtask = writer_finishtask.write(root_finishtask);

	char request_finishtask[1024];
	sprintf_s(request_finishtask,"http://%s:%d/finishtask/%s",UnicodeToUTF8(kent_studio_ip_adr.GetBuffer()).c_str(),kent_studio_port,jsondoc_finishtask.c_str());
	kent_studio_ip_adr.ReleaseBuffer();

	Ckent_request kent_request;
	string response_finishtask = kent_request.request_ans(request_finishtask);

	if(0 == response_finishtask.length()){//空错误
		kent_log.error("err:response_finishtask NULL");
		kent_studio_can_connect = 0;//不可以连接
		return false;
	}else if('e' == response_finishtask.at(0)){//err
		kent_log.error(response_finishtask);
		kent_studio_can_connect = 0;//不可以连接
		return false;
	}

	kent_reconnect_qq_num = _T("");
	kent_reconnect_qq_password = _T("");
	kent_studio_qq_name = _T("");
	kent_reconnect_qq_area = _T("");
	kent_studio_now_ip = 0;
	kent_studio_now_stage = 0;
	kent_studio_stop_ip = 0;
	kent_studio_now_ip = 0;
	kent_studio_stop_stage = 0;
	kent_store_studio_config();

	return true;
}
bool Kent_log::GetNewTask()//获取新的任务
{
	Json::Value root_getnewtask;//对象
	root_getnewtask["user"] = UnicodeToUTF8(kent_reg_login_user.GetBuffer()).c_str();kent_reg_login_user.ReleaseBuffer();//辅助账号

	Json::FastWriter writer_getnewtask;
	string jsondoc_getnewtask = writer_getnewtask.write(root_getnewtask);
	char request_getnewtask[1024];
	sprintf_s(request_getnewtask,"http://%s:%d/getnewtask/%s",UnicodeToUTF8(kent_studio_ip_adr.GetBuffer()).c_str(),kent_studio_port,jsondoc_getnewtask.c_str());
	kent_studio_ip_adr.ReleaseBuffer();

	Ckent_request kent_request;
	string response_getnewtask = kent_request.request_ans(request_getnewtask);//获取配置信息
	if(0 == response_getnewtask.length()){//空错误
		kent_log.error("err:response_getnewtask NULL");
		return false;
	}else if('e' == response_getnewtask.at(0)){//err
		kent_log.error(response_getnewtask);
		return false;
	}

	Json::Reader JsonReader;//json解析
	Json::Value root_response_getnewtask;//表示一个json格式的对象
	if(!JsonReader.parse(response_getnewtask,root_response_getnewtask)
		||!root_response_getnewtask["qq_num"].isString() ||!root_response_getnewtask["qq_key"].isString()
		||!root_response_getnewtask["qq_name"].isString() ||!root_response_getnewtask["qq_area"].isString()
		||!root_response_getnewtask["now_ip"].isInt()||!root_response_getnewtask["now_stage"].isInt()
		||!root_response_getnewtask["stop_ip"].isInt()||!root_response_getnewtask["stop_stage"].isInt())//解析json
	{
		kent_log.error("err:failed to parse getnewtask response");
		return false;
	}//解析配置

	//更新配置
	kent_reconnect_qq_num = UTF8ToUnicode(root_response_getnewtask["qq_num"].asString()).c_str();
	kent_reconnect_qq_password = UTF8ToUnicode(root_response_getnewtask["qq_key"].asString()).c_str();
	kent_studio_qq_name = UTF8ToUnicode(root_response_getnewtask["qq_name"].asString()).c_str();
	kent_reconnect_qq_area = UTF8ToUnicode(root_response_getnewtask["qq_area"].asString()).c_str();
	kent_studio_now_ip = root_response_getnewtask["now_ip"].asInt();
	kent_studio_now_stage = root_response_getnewtask["now_stage"].asInt();
	kent_studio_stop_ip = root_response_getnewtask["stop_ip"].asInt();
	kent_studio_stop_stage = root_response_getnewtask["stop_stage"].asInt();

	kent_store_studio_config();//存储信息

	return TRUE;
}
bool Kent_log::GetNewAccount()//获取新的账号
{
	char request_getnewaccount[1024];
	sprintf_s(request_getnewaccount,"http://%s:%d/getnewaccount/tmp",UnicodeToUTF8(kent_studio_ip_adr.GetBuffer()).c_str(),kent_studio_port);
	kent_studio_ip_adr.ReleaseBuffer();

	Ckent_request kent_request;
	string response_getnewaccount = kent_request.request_ans(request_getnewaccount);//获取配置信息
	if(0 == response_getnewaccount.length()){//空错误
		kent_log.error("err:response_getnewtask NULL");
		return false;
	}else if('e' == response_getnewaccount.at(0)){//err
		kent_log.error(response_getnewaccount);
		return false;
	}

	Json::Reader JsonReader;//json解析
	Json::Value root_response_getnewaccount;//表示一个json格式的对象
	if(!JsonReader.parse(response_getnewaccount,root_response_getnewaccount)
		||!root_response_getnewaccount["user"].isString() ||!root_response_getnewaccount["key"].isString())//解析json
	{
		kent_log.error("err:failed to parse getnewaccount response");
		return false;
	}//解析配置

	//更新配置
	kent_reg_login_user = UTF8ToUnicode(root_response_getnewaccount["user"].asString()).c_str();
	kent_reg_login_key = UTF8ToUnicode(root_response_getnewaccount["key"].asString()).c_str();
	
	kent_kss->ks_setUserVal(1,kent_reg_login_user,kent_reg_login_key,_T(""));

	kent_store_studio_config();//存储信息

	return TRUE;
}
bool Kent_log::TitleTask()//完成任务
{
	Json::Value root_titletask;//对象
	root_titletask["qq_num"] = UnicodeToUTF8(kent_reconnect_qq_num.GetBuffer()).c_str();kent_reconnect_qq_num.ReleaseBuffer();//QQ账号
	root_titletask["qq_key"] = UnicodeToUTF8(kent_reconnect_qq_password.GetBuffer()).c_str();kent_reconnect_qq_password.ReleaseBuffer();//QQ密码
	root_titletask["qq_name"] = UnicodeToUTF8(kent_studio_qq_name.GetBuffer()).c_str();kent_studio_qq_name.ReleaseBuffer();//名字
	root_titletask["qq_area"] = UnicodeToUTF8(kent_reconnect_qq_area.GetBuffer()).c_str();kent_reconnect_qq_area.ReleaseBuffer();//大区
	root_titletask["now_ip"] = kent_studio_now_ip;//当前金币
	root_titletask["stop_ip"] = kent_studio_stop_ip;//停止金币
	root_titletask["now_stage"] = kent_studio_now_stage;//当前等级
	root_titletask["stop_stage"] = kent_studio_stop_stage;//停止等级

	Json::FastWriter writer_titletask;
	string jsondoc_titletask = writer_titletask.write(root_titletask);

	char request_titletask[1024];
	sprintf_s(request_titletask,"http://%s:%d/titletask/%s",UnicodeToUTF8(kent_studio_ip_adr.GetBuffer()).c_str(),kent_studio_port,jsondoc_titletask.c_str());
	kent_studio_ip_adr.ReleaseBuffer();

	Ckent_request kent_request;
	string response_titletask = kent_request.request_ans(request_titletask);

	if(0 == response_titletask.length()){//空错误
		kent_log.error("err:response_titletask NULL");
		kent_studio_can_connect = 0;//不可以连接
		return false;
	}else if('e' == response_titletask.at(0)){//err
		kent_log.error(response_titletask);
		kent_studio_can_connect = 0;//不可以连接
		return false;
	}

	kent_reconnect_qq_num = _T("");
	kent_reconnect_qq_password = _T("");
	kent_studio_qq_name = _T("");
	kent_reconnect_qq_area = _T("");
	kent_studio_now_ip = 0;
	kent_studio_now_stage = 0;
	kent_studio_stop_ip = 0;
	kent_studio_now_ip = 0;
	kent_studio_stop_stage = 0;
	kent_store_studio_config();


	return true;
}

bool Kent_log::StoreBack(//存储
	int cnt,
	CString kent_reconnect_qq_num,
	CString kent_reconnect_qq_password,
	CString kent_reconnect_qq_area,
	CString kent_studio_qq_name,
	int kent_studio_now_ip,
	int kent_studio_stop_ip,
	int kent_studio_now_stage,
	int kent_studio_stop_stage)
{
	CString tmp;
	tmp.Format(_T("%d"),cnt);
	
	kent_writebackini(_T("kent_reconnect_qq_num") + tmp,kent_reconnect_qq_num);
	kent_writebackini(_T("kent_reconnect_qq_password") + tmp,kent_reconnect_qq_password);
	kent_writebackini(_T("kent_reconnect_qq_area") + tmp,kent_reconnect_qq_area);
	kent_writebackini(_T("kent_studio_qq_name") + tmp,kent_studio_qq_name);
	kent_writebackini(_T("kent_studio_now_ip") + tmp,kent_studio_now_ip);
	kent_writebackini(_T("kent_studio_stop_ip") + tmp,kent_studio_stop_ip);
	kent_writebackini(_T("kent_studio_now_stage") + tmp,kent_studio_now_stage);
	kent_writebackini(_T("kent_studio_stop_stage") + tmp,kent_studio_stop_stage);
	return true;
}
bool Kent_log::ReadBack(//duqu
	int cnt,
	CString *kent_reconnect_qq_num,
	CString *kent_reconnect_qq_password,
	CString *kent_reconnect_qq_area,
	CString *kent_studio_qq_name,
	int *kent_studio_now_ip,
	int *kent_studio_stop_ip,
	int *kent_studio_now_stage,
	int *kent_studio_stop_stage)
{
	CString tmpcnt;
	tmpcnt.Format(_T("%d"),cnt);

	CString tmp;
	//kent_reconnect_qq_num
	tmp =kent_readbackini(_T("kent_reconnect_qq_num")+tmpcnt);
	*kent_reconnect_qq_num=tmp;
	//kent_reconnect_qq_password
	tmp =kent_readbackini(_T("kent_reconnect_qq_password")+tmpcnt);
	*kent_reconnect_qq_password=tmp;
	//kent_reconnect_qq_area
	tmp =kent_readbackini(_T("kent_reconnect_qq_area")+tmpcnt);
	*kent_reconnect_qq_area=tmp;
	//kent_studio_qq_name
	tmp =kent_readbackini(_T("kent_studio_qq_name")+tmpcnt);
	*kent_studio_qq_name=tmp;
	//kent_studio_now_ip
	tmp =kent_readbackini(_T("kent_studio_now_ip")+tmpcnt);
	*kent_studio_now_ip=(int)abs(_ttoi(tmp));
	//kent_studio_stop_ip
	tmp =kent_readbackini(_T("kent_studio_stop_ip")+tmpcnt);
	*kent_studio_stop_ip=(int)abs(_ttoi(tmp));
	//kent_studio_now_stage
	tmp =kent_readbackini(_T("kent_studio_now_stage")+tmpcnt);
	*kent_studio_now_stage=(int)abs(_ttoi(tmp));
	//kent_studio_stop_stage
	tmp =kent_readbackini(_T("kent_studio_stop_stage")+tmpcnt);
	*kent_studio_stop_stage=(int)abs(_ttoi(tmp));
	return true;
}

class QqBack{
public:
	CString kent_reconnect_qq_num;
	CString kent_reconnect_qq_password;
	CString kent_reconnect_qq_area;
	CString kent_studio_qq_name;
	int kent_studio_now_ip;
	int kent_studio_stop_ip;
	int kent_studio_now_stage;
	int kent_studio_stop_stage;
};

bool Kent_log::ChangeToNext(int BackNum)//更换任务
{
	if(BackNum < 1){
		return false;
	}
	int num = 0,nownum = 0;
	CString tmp;

	//num
	tmp =kent_readbackini(_T("num"));
	if(0 != tmp.Compare(_T(""))){nownum=(d_bind_mode)(int)abs(_ttoi(tmp));}//读取总共的数目

	num = nownum>BackNum?nownum:BackNum;//取最大的一个

	list<QqBack> backlist;

	QqBack QqBack_tmp;

	QqBack_tmp.kent_reconnect_qq_num = kent_reconnect_qq_num;
	QqBack_tmp.kent_reconnect_qq_password = kent_reconnect_qq_password;
	QqBack_tmp.kent_reconnect_qq_area = kent_reconnect_qq_area;
	QqBack_tmp.kent_studio_qq_name = kent_studio_qq_name;
	QqBack_tmp.kent_studio_now_ip = kent_studio_now_ip;
	QqBack_tmp.kent_studio_stop_ip = kent_studio_stop_ip;
	QqBack_tmp.kent_studio_now_stage = kent_studio_now_stage;
	QqBack_tmp.kent_studio_stop_stage = kent_studio_stop_stage;

	backlist.push_back(QqBack_tmp);


	CString qq_num;
	CString qq_password;
	CString qq_area;
	CString qq_name;
	int now_ip;
	int stop_ip;
	int now_stage;
	int stop_stage;


	for(int i = 0;i<nownum;i++){//读取所有当前备用
		ReadBack(i+1,&qq_num,&qq_password,&qq_area,&qq_name,&now_ip,&stop_ip,&now_stage,&stop_stage);

		QqBack_tmp.kent_reconnect_qq_num = qq_num;
		QqBack_tmp.kent_reconnect_qq_password = qq_password;
		QqBack_tmp.kent_reconnect_qq_area = qq_area;
		QqBack_tmp.kent_studio_qq_name = qq_name;
		QqBack_tmp.kent_studio_now_ip = now_ip;
		QqBack_tmp.kent_studio_stop_ip = stop_ip;
		QqBack_tmp.kent_studio_now_stage = now_stage;
		QqBack_tmp.kent_studio_stop_stage = stop_stage;
		backlist.push_back(QqBack_tmp);
	}

	for(int i = nownum;i<num;i++){//补齐备用
		if(!GetNewTask()){//获取失败
			break;
		}

		QqBack_tmp.kent_reconnect_qq_num = kent_reconnect_qq_num;
		QqBack_tmp.kent_reconnect_qq_password = kent_reconnect_qq_password;
		QqBack_tmp.kent_reconnect_qq_area = kent_reconnect_qq_area;
		QqBack_tmp.kent_studio_qq_name = kent_studio_qq_name;
		QqBack_tmp.kent_studio_now_ip = kent_studio_now_ip;
		QqBack_tmp.kent_studio_stop_ip = kent_studio_stop_ip;
		QqBack_tmp.kent_studio_now_stage = kent_studio_now_stage;
		QqBack_tmp.kent_studio_stop_stage = kent_studio_stop_stage;

		backlist.push_back(QqBack_tmp);
	}

	//参数:backlist
	list<QqBack>::iterator iter = backlist.end();
	iter--;
	kent_reconnect_qq_num = iter->kent_reconnect_qq_num;
	kent_reconnect_qq_password = iter->kent_reconnect_qq_password;
	kent_reconnect_qq_area = iter->kent_reconnect_qq_area;
	kent_studio_qq_name = iter->kent_studio_qq_name;
	kent_studio_now_ip = iter->kent_studio_now_ip;
	kent_studio_stop_ip = iter->kent_studio_stop_ip;
	kent_studio_now_stage = iter->kent_studio_now_stage;
	kent_studio_stop_stage = iter->kent_studio_stop_stage;

	backlist.pop_back();//删除最后一个

	int strorecnt = 0;
	for(list<QqBack>::iterator iter = backlist.begin();iter != backlist.end();iter++)
	{
		StoreBack(strorecnt+1,iter->kent_reconnect_qq_num,iter->kent_reconnect_qq_password,iter->kent_reconnect_qq_area,iter->kent_studio_qq_name,iter->kent_studio_now_ip,iter->kent_studio_stop_ip,iter->kent_studio_now_stage,iter->kent_studio_stop_stage);
		strorecnt++;
	}

	StoreBack(0,kent_reconnect_qq_num,kent_reconnect_qq_password,kent_reconnect_qq_area,kent_studio_qq_name,kent_studio_now_ip,kent_studio_stop_ip,kent_studio_now_stage,kent_studio_stop_stage);

	kent_writebackini(_T("num"),strorecnt);
	
	return true;
}

void Kent_log::SetAutoRun(bool IsAuto)
{
	//写入注册表,开机自启动 
	HKEY hKey; 
	//找到系统的启动项 
	LPCTSTR lpRun = _T("Software\\Microsoft\\Windows\\CurrentVersion\\Run");
	//打开启动项Key
	if(ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, lpRun, 0, KEY_ALL_ACCESS, &hKey))
	{
		if(IsAuto)
		{
			TCHAR pFileName[MAX_PATH] = {0};
			//得到程序自身的全路径 
			DWORD dwRet = GetModuleFileName(NULL, pFileName, MAX_PATH); 
			//添加一个子Key,并设置值 // 下面的"getip"是应用程序名字（不加后缀.exe）
			RegSetValueEx(hKey, _T("KentAutoRun"), 0, REG_SZ, (BYTE *)pFileName, dwRet*sizeof(DWORD));
		}else{
			RegDeleteValue(hKey, _T("KentAutoRun"));
		}
		//关闭注册表 
		RegCloseKey(hKey);
	}
}

bool Kent_log::IsAutoRun()
{
	//写入注册表,开机自启动 
	HKEY hKey; 
	//找到系统的启动项 
	LPCTSTR lpRun = _T("Software\\Microsoft\\Windows\\CurrentVersion\\Run");
	//打开启动项Key
	if(ERROR_SUCCESS != RegOpenKeyEx(HKEY_LOCAL_MACHINE, lpRun, 0, KEY_READ, &hKey))
		return false;

	TCHAR pFileName[MAX_PATH] = {0};
	DWORD dwSize = MAX_PATH * sizeof(DWORD);
	DWORD dwType = REG_SZ;
	if (ERROR_SUCCESS != RegQueryValueEx(hKey,_T("KentAutoRun"), 0, &dwType, (BYTE *)&pFileName, &dwSize))
    {
		RegCloseKey(hKey);
		return false;
    }else
	{
		RegCloseKey(hKey);
		return true;
	}
}