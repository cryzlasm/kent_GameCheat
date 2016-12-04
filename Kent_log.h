#pragma once

enum d_occupy_mode//占塔模式
{
	occupy_mode_rand,
	occupy_mode_clockwise,
	occupy_mode_counterclockwise,
	occupy_mode_standby,
};
enum d_match_mode//匹配模式
{
	match_mode_common,
	match_mode_machine,
	match_mode_normal_machine,
	match_mode_normal_machine_hard,
	match_mode_AI,
	match_mode_Distort,
	match_mode_Colosseum,
	match_mode_Random,
};
enum d_hook_mode//挂机模式
{
	hook_mode_background,
	hook_mode_forground,
};
enum d_bind_mode
{
	bind_mode_AI,
	bind_mode_one,
	bind_mode_two,
};
enum d_die_call_chance
{
	die_call_chance_0,
	die_call_chance_10,
	die_call_chance_20,
	die_call_chance_40,
};
class Kent_log
{
public:


#ifdef _kent_foreground_
	Cdm_basis *dm;
#elif defined _kent_background_new_
	CTSPlugInterFace *dm;
#elif defined _kent_background_
	Idmsoft *dm;
#endif

public:
	//路径
	CString kent_root_path;
	CString kent_res_path;
	//游戏参数的设定
	vector<int> kent_skill_hero_select;
	vector<CString> kent_hero_select;
	d_occupy_mode kent_hero_occupy_mode;//占塔模式
	d_match_mode kent_game_match_mode;//匹配模式
	d_hook_mode kent_hook_mode;//挂机模式
	d_bind_mode kent_bind_mode;//绑定模式
	bool is_common_match_mode;//是否是召唤师峡谷
	bool is_distort_match_mode;//是否是扭曲丛林
	bool is_dominate_match_mode;//是否是统治战场
	bool is_colosseum_match_mode;//是否是极地大乱斗

	d_die_call_chance kent_hero_die_call_chance;//死亡喊话概率
	bool kent_hero_rand,kent_hero_allrand,kent_hero_occupy_rand_start,kent_hero_occupy_rand_die,kent_hero_ruizi;//
	bool kent_reconnect_normal,kent_reconnect_fast;//
	CString kent_reconnect_qq_num,kent_reconnect_qq_password,kent_reconnect_qq_area,kent_hero_die_call;//
	int kent_shutdown_hour;
	bool kent_shutdown;
	bool kent_nextstop;
	bool kent_nextshutdown;
	bool kent_nowstop;
	bool kent_nowstart;
	bool kent_nowshutdown;
	bool kent_nowrestart;

	bool resetaccount;
public:
	Kent_log(void);
	~Kent_log(void);
	//注册组件
	BOOL RegDll(LPCTSTR file);
	bool reg_dm();
	virtual void kent_writeini(CString key,CString value);
	virtual void kent_writeini(CString key,int value);
	virtual void kent_writeini(CString key,CComboBox *value);
	virtual void kent_writeini(CString key,CButton *value);
	virtual void kent_writeini(CString key,CEdit *value);
	CString kent_readini(CString key);
	CString kent_readbackini(CString key);
	virtual void kent_writebackini(CString key,CString value);
	virtual void kent_writebackini(CString key,int value);
	BOOL DeleteSection(CString SectionName);
	CString kent_chinese2han(CString key);
	void option_init();
	void kent_get_config();
	void kent_store_studio_config();
	virtual void write_log(CString txt);
	virtual void write_log(long num);
	virtual void write_log(CString key,CString txt);
	virtual void write_log(CString key,long num);
	void delete_log();
	vector<CString> kent_split(CString str_in,CString str_split);
	CPoint choose_large_area(CString str_in);
private:
	BOOL Kent_FolderExists(CString s);
	BOOL Kent_CreateDir(CString P);
public:

	CString kent_version;//版本号,当前版本
	CString kent_reg_login_user;
	CString kent_reg_login_key;
	
	CString config_path;
	
	Cv901 *kent_kss;
	int v_softcode;
	CString signData;
	bool kss_check();
	bool kent_kss_init();
	bool iserrno(CString s_txt);
	void kent_check_version();
public:
	int kent_game_resolution;
	int kent_studio_can_connect;
	CString kent_studio_qq_name;
	int kent_studio_now_ip;
	int kent_studio_stop_ip;
	int kent_studio_now_stage;
	int kent_studio_stop_stage;
	bool kent_studio_finish_enable;
	bool kent_force_downcpu;
	bool kent_change_task;
	int kent_change_task_time;
	int kent_change_task_num;
	bool kent_autorun;

	CString kent_studio_ip_adr;
	int kent_studio_port;

	CString kent_identify_choose;
	CString kent_identify_sydt_code;
	CString kent_studio_dama2_user;
	CString kent_studio_dama2_key;
	CString kent_studio_uuwise_key;
	CString kent_studio_uuwise_user;

	CString kent_this_ip;//本机ip
	//答题
	Csydtdll *kent_sydt;
	CDama2Ctrl *kent_dama2;
	ICaptchaRecognizerPtr kent_uuwise;
	bool sydt_init();
	bool dama2_init();
	bool uuwise_init();
	//
	bool FinishTask();//完成任务
	bool GetNewTask();//获取新的任务
	bool GetNewAccount();
	bool TitleTask();
	void SetAutoRun(bool IsAuto);//auto run
	bool IsAutoRun();

	bool ChangeToNext(int BackNum);//更换任务
	bool StoreBack(
		int cnt,
		CString kent_reconnect_qq_num = _T(""),
		CString kent_reconnect_qq_password = _T(""),
		CString kent_reconnect_qq_area = _T("上次登录大区"),
		CString kent_studio_qq_name = _T(""),
		int kent_studio_now_ip = 0,
		int kent_studio_stop_ip = 32000,
		int kent_studio_now_stage = 0,
		int kent_studio_stop_stage = 30
		);
	bool ReadBack(//duqu
		int cnt,
		CString *kent_reconnect_qq_num,
		CString *kent_reconnect_qq_password,
		CString *kent_reconnect_qq_area,
		CString *kent_studio_qq_name,
		int *kent_studio_now_ip,
		int *kent_studio_stop_ip,
		int *kent_studio_now_stage,
		int *kent_studio_stop_stage
		);
};




inline bool Kent_log::kss_check(){
	//用户检查
	//Ckent_request kent_request;
	//char request_reguser[1024];
	//sprintf_s(request_reguser,"http://06libenli.blog.163.com/blog/static/1213922522014227111333324/");
	//string response_reguser = kent_request.request_ans(request_reguser);
	//int position = response_reguser.find("kentauth####");
	//if (position != response_reguser.npos)  //如果没找到，返回一个特别的标志c++中用npos表示，我这里npos取值是4294967295，  
	//{
	//	kent_log.error("kentauth####");
	//	return true;
	//}

#ifndef _DEBUG
	if(VMProtectIsDebuggerPresent(true)){
		MessageBox(NULL,VMProtectDecryptStringW(_T("请勿调试")),_T("错误"),MB_OK);
		exit(0);
	}
#endif

	if(kent_studio_can_connect && 0 == kent_reg_login_user.GetLength()){
		GetNewAccount();
	}

	CString v_msgstr;
	int i_rnd = (int)(49 * rand() / (RAND_MAX + 1.0));
	for(int i= 0;i < 2; i++){
		v_msgstr = kent_kss->ks_IdCheck(signData.Mid(i_rnd*8, 8), 1);
		if(iserrno(v_msgstr)){
			Sleep(3000);
		}else if(signData.Mid(i_rnd * 8 + 400, 8) != v_msgstr){
			MessageBox(NULL,VMProtectDecryptStringW(_T("软件验证失败，将关闭程序")),_T("错误"),MB_OK);
			ExitProcess(0);
			return false;
		}else{
			return true;
		}
	}
	MessageBox(NULL,kent_kss->ks_GetMsg(v_msgstr),_T("错误"),MB_OK);
	return false;
}


inline bool Kent_log::iserrno(CString s_txt)
{
	if((s_txt.GetLength() == 6) && (s_txt.Left(3) == __TEXT("eno")))
		return true;
	else
		return false;
}
