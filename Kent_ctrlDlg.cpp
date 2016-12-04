#include "stdafx.h"
#include "Kent_ctrlDlg.h"

#define WM_SHOWTASK (WM_USER+1001)

#define kent_needconnectPort 17294


IMPLEMENT_DYNAMIC(Kent_ctrlDlg, CDialogEx)
Kent_ctrlDlg::Kent_ctrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Kent_ctrlDlg::IDD, pParent)
{
#if defined kent_forever_background || defined kent_forever
	m_hIcon = AfxGetApp()->LoadIcon(IDI_EVER);
#else
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
#endif
}
Kent_ctrlDlg::~Kent_ctrlDlg(void)
{

}
void Kent_ctrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Kent_ctrlDlg, CDialogEx)
	//{{AFX_MSG_MAP(CVc6Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_MENU, &Kent_ctrlDlg::OnBnClickedButtonMenu)
	ON_BN_CLICKED(IDC_BUTTON_START, &Kent_ctrlDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &Kent_ctrlDlg::OnBnClickedButtonStop)
	ON_MESSAGE(WM_HOTKEY,OnHotKey)
	ON_MESSAGE(WM_SHOWTASK,OnShowTask)
	ON_WM_TIMER()
END_MESSAGE_MAP()

BOOL Kent_ctrlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	/*****************图标设置*****************/
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	/*****************标题设置*****************/

	srand((unsigned)time(NULL));
	char tmp[20]="";
	int title_len=4+rand()%10;
	for(int i=0;i<title_len;i++)
	{
		(rand()%2)?tmp[i]='a'+rand()%26:tmp[i]='A'+rand()%26;
	}
	CString title=tmp;
	SetWindowText(title);
	RegisterHotKey(GetSafeHwnd(),1001,NULL,VK_F10);//注册热键
	RegisterHotKey(GetSafeHwnd(),1002,NULL,VK_F11);
	//托盘显示
    m_nid.cbSize  = (DWORD)sizeof(NOTIFYICONDATA);
    m_nid.hWnd    = this->m_hWnd;
#if defined kent_forever_background || defined kent_forever
	m_nid.uID = IDI_EVER;
#else
	m_nid.uID = IDR_MAINFRAME;
#endif
    m_nid.uFlags  = NIF_ICON | NIF_MESSAGE | NIF_TIP ;
    m_nid.uCallbackMessage = WM_SHOWTASK;// 自定义的消息名称
#if defined kent_forever_background || defined kent_forever
    m_nid.hIcon   = LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_EVER));
#else
    m_nid.hIcon   = LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
#endif
    //_tcscpy_s(m_nid.szTip, _T("kent"));// 信息提示条为"服务器程序"，VS2008 UNICODE编码用wcscpy_s()函数
#if defined lol_home_background || defined lol_home_foreground
	_tcscpy_s(m_nid.szTip, _T("撸友之家"));
#elif defined kent_background || defined kent_foreground || defined kent_han
	_tcscpy_s(m_nid.szTip, _T("kent"));
#elif defined kent_forever_background
	_tcscpy_s(m_nid.szTip, _T("lol辅助"));
#elif defined kent_forever
	_tcscpy_s(m_nid.szTip, _T("lol辅助"));
#endif

    Shell_NotifyIcon(NIM_ADD, &m_nid);// 在托盘区添加图标
#if !defined kent_forever_background && !defined kent_forever
	SetTimer(1, (int)(3000.0), NULL);//检测注册状态时钟
#endif

	
 //   CString strData;
	//strData = _T("그레이브즈");
	//strData = _T("卡卡");
 //   if(OpenClipboard())
 //   {
 //       EmptyClipboard();
 //       HGLOBAL hClipboardData;
 //       hClipboardData=GlobalAlloc(GMEM_DDESHARE,strData.GetLength()+1);
 //       char* pchData;
 //       pchData=(char*)GlobalLock(hClipboardData);
	//	strcpy(pchData,UnicodeToANSI(strData.GetBuffer()).c_str());strData.ReleaseBuffer();
 //       GlobalUnlock(hClipboardData);
 //       SetClipboardData(CF_TEXT,hClipboardData);
 //       CloseClipboard();
 //   }
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}
void Kent_ctrlDlg::OnBnClickedButtonMenu()
{
#if defined kent_forever_background || defined kent_forever
	Kent_forever Dlg;
	Dlg.Kent_log_instance=Kent_log_instance;
	Dlg.kent_reg_login_ever.Kent_log_instance = Kent_log_instance;
	Dlg.kent_reg_reg_everDlg.Kent_log_instance = Kent_log_instance;
	Dlg.kent_reg_recharge_everDlg.Kent_log_instance = Kent_log_instance;
	Dlg.kent_reg_modify_everDlg.Kent_log_instance = Kent_log_instance;
	EnableWindow(false);
	Dlg.DoModal();
#else
	CmenuDlg menuDlg;
	menuDlg.Kent_log_instance=Kent_log_instance;
	menuDlg.kent_herosDlg.Kent_log_instance=Kent_log_instance;
	menuDlg.kent_gameDlg.Kent_log_instance=Kent_log_instance;
	menuDlg.kent_studioDlg.Kent_log_instance=Kent_log_instance;
	menuDlg.kent_helpDlg.Kent_log_instance=Kent_log_instance;
	
	menuDlg.kent_registerDlg.Kent_log_instance=Kent_log_instance;
	menuDlg.kent_registerDlg.kent_reg_login.Kent_log_instance=Kent_log_instance;
	menuDlg.kent_registerDlg.kent_reg_modifyDlg.Kent_log_instance=Kent_log_instance;
	menuDlg.kent_registerDlg.kent_reg_rechargeDlg.Kent_log_instance=Kent_log_instance;
	menuDlg.kent_registerDlg.kent_reg_regDlg.Kent_log_instance=Kent_log_instance;
	
	EnableWindow(false);
	menuDlg.DoModal();
#endif
}
void Kent_ctrlDlg::OnBnClickedButtonStart()
{
	if(script_info->is_run){
		return;
	}
VMProtectBeginUltra("OnBnClickedButtonStart");//OnBnClickedButtonStart标记
	if(!Kent_log_instance->reg_dm()){//在线注册大漠失败
		return;
	}
	if(!Kent_log_instance->kss_check()){
		Kent_ctrlDlg::OnBnClickedButtonMenu();//打开对话框
		return;
	}
	Kent_log_instance->kent_check_version();
VMProtectEnd();

	Kent_log_instance->delete_log();
	script_info->open_dmguard();//开启大漠盾

	script_info->StartScript();
	kent_tips(VMProtectDecryptStringW(_T("开始")));
}
void Kent_ctrlDlg::OnBnClickedButtonStop()
{
	if(script_info->is_run){
		script_info->StopScript();
		kent_tips(VMProtectDecryptStringW(_T("结束")));
	}
#ifndef kent_han
	CString kent_gamepath = Kent_log_instance->kent_readini(_T("game_path"));
	if(0 != kent_gamepath.GetLength() && Kent_log_instance->dm->IsFileExist(kent_gamepath+_T("\\TCLS\\Client.exe"))){
		DeleteFile(kent_gamepath+_T("\\Config\\input.ini"));
		DeleteFile(kent_gamepath+_T("\\Config\\Game.cfg"));
	}
#endif
}
void Kent_ctrlDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}
HCURSOR Kent_ctrlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
LRESULT Kent_ctrlDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (message == WM_CLOSE)
    {
        EndDialog(0);
    }
	return CDialog::WindowProc(message, wParam, lParam);
}
void Kent_ctrlDlg::OnDestroy() 
{
	script_info->StopScript();
	UnregisterHotKey(m_hWnd, 1001);//解除注册
	UnregisterHotKey(m_hWnd, 1002);
	// 在托盘区删除图标
    Shell_NotifyIcon(NIM_DELETE, &m_nid);
	CDialog::OnDestroy();
}
void Kent_ctrlDlg::OnCancel()
{//屏蔽Esc
	CDialog::OnCancel();
}
void Kent_ctrlDlg::OnClose()
{//关闭按钮
	Kent_ctrlDlg::OnBnClickedButtonStop();
	CDialog::OnClose();
}
void Kent_ctrlDlg::OnOK()
{//OK按钮
	CDialog::OnOK();
}
LRESULT Kent_ctrlDlg::OnHotKey(WPARAM wParam,LPARAM lParam)
{
	if(wParam== 1001)
	{
		OnBnClickedButtonStart();
	}else if (wParam== 1001||wParam == 1002)
    {
		OnBnClickedButtonStop();
    }
    return 0;
}
void Kent_ctrlDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	// TODO: Add your message handler code here
	if(nType == SIZE_MINIMIZED)  
	{
		ShowWindow(SW_HIDE); // 当最小化市，隐藏主窗口              
	}
}
LRESULT Kent_ctrlDlg::OnShowTask(WPARAM wParam, LPARAM lParam)
{
#if defined kent_forever_background || defined kent_forever
	if(wParam != IDI_EVER)//主图标消息
		return 1;
#else
	if(wParam != IDR_MAINFRAME)//主图标消息
		return 1;
#endif
	switch(lParam)
	{
	case WM_RBUTTONUP:                                        // 右键起来时弹出菜单
		{
			LPPOINT lpoint = new tagPOINT;
			::GetCursorPos(lpoint);// 得到鼠标位置
			CMenu menu;
			menu.CreatePopupMenu();// 声明一个弹出式菜单
			menu.AppendMenu(MF_STRING, IDC_BUTTON_START, _T("开始"));
			menu.AppendMenu(MF_STRING, IDC_BUTTON_STOP, _T("结束"));
			menu.AppendMenu(MF_STRING, WM_DESTROY, _T("关闭"));
			SetForegroundWindow();
			menu.TrackPopupMenu(TPM_LEFTALIGN, lpoint->x ,lpoint->y, this);
			HMENU hmenu = menu.Detach();
			menu.DestroyMenu();
			delete lpoint;
		}
		break;
	case WM_LBUTTONDBLCLK:// 双击左键的处理
		{
			this->ShowWindow(SW_SHOWNORMAL);// 显示主窗口
		}
		break;
	case WM_LBUTTONDOWN:
		{
			this->ShowWindow(SW_SHOWNORMAL);// 显示主窗口
		}
	}
	return 0;
}
void Kent_ctrlDlg::kent_tips(CString Info)
{
#if defined lol_home_background || defined lol_home_foreground
	_tcscpy_s(m_nid.szInfoTitle,_T("撸友之家提示"));
#elif defined kent_background || defined kent_foreground || defined kent_han
	_tcscpy_s(m_nid.szInfoTitle,_T("kent提示"));
#elif defined kent_forever_background
	_tcscpy_s(m_nid.szInfoTitle,_T("lol打假"));
#elif defined kent_forever
	_tcscpy_s(m_nid.szInfoTitle,_T("lol辅助"));

#endif

	_tcscpy_s(m_nid.szInfo,Info);
	m_nid.uFlags = NIF_INFO;
	m_nid.uTimeout=1000;
	m_nid.uVersion=NOTIFYICON_VERSION;
	Shell_NotifyIcon(NIM_MODIFY,&m_nid);
}
DWORD  WINAPI ThreadUpdateConfig(LPVOID param);//注册账号更新配置线程
void Kent_ctrlDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if(1 != nIDEvent)return;
	
	if(1 == Kent_log_instance->kent_studio_can_connect){
		Kent_log_instance->kent_nowstart = false;
		Kent_log_instance->kent_nowstop = false;
		Kent_log_instance->resetaccount = false;
		Kent_log_instance->kent_nowshutdown = false;
		Kent_log_instance->kent_nowrestart = false;
	}
	
	if(Kent_log_instance->resetaccount){//重置账号
		Kent_log_instance->resetaccount = false;
		Kent_log_instance->kent_reg_login_key = _T("");
		Kent_log_instance->kent_reg_login_user = _T("");
		Kent_log_instance->GetNewAccount();
	}

	if(Kent_log_instance->kent_nowstart){//立刻开始
		Kent_log_instance->kent_nowstart = false;
		OnBnClickedButtonStart();
	}

	if(Kent_log_instance->kent_nowstop){//立刻停止
		Kent_log_instance->kent_nowstop = false;
		OnBnClickedButtonStop();
	}

	if(Kent_log_instance->kent_nowshutdown){//立刻关机
		Kent_log_instance->kent_nowshutdown = false;
		OnBnClickedButtonStop();
		system("shutdown -s -t 10");
	}
	
	if(Kent_log_instance->kent_nowrestart){//立刻重启
		Kent_log_instance->kent_nowrestart = false;
		OnBnClickedButtonStop();
		system("shutdown -r -t 10");
	}

	HANDLE ThreadUpdateConfigHandle = CreateThread(NULL, 0, ThreadUpdateConfig, Kent_log_instance, 0, NULL);
	
	if(ThreadUpdateConfigHandle == INVALID_HANDLE_VALUE)
	{
		kent_log.error("err:failed to createthread ThreadUpdateConfig");
	}else{
		CloseHandle(ThreadUpdateConfigHandle);
	}
	
	KillTimer(nIDEvent);
	CDialog::OnTimer(nIDEvent);
	SetTimer(nIDEvent, (int)(10000.0), NULL);//设置10秒
}
DWORD WINAPI ThreadUpdateConfig(LPVOID param)
{  
	Kent_log *Kent_log_instance = (Kent_log *)param;
	Ckent_request kent_request;

	Json::Value root_reguser;//对象
	if(0 == Kent_log_instance->kent_reg_login_user.GetLength())
	{
		root_reguser["user"] = UnicodeToUTF8(_T("none")).c_str();//辅助账号
	}else{
		root_reguser["user"] = UnicodeToUTF8(Kent_log_instance->kent_reg_login_user.GetBuffer()).c_str();Kent_log_instance->kent_reg_login_user.ReleaseBuffer();//辅助账号
		root_reguser["key"] = UnicodeToUTF8(Kent_log_instance->kent_reg_login_key.GetBuffer()).c_str();Kent_log_instance->kent_reg_login_key.ReleaseBuffer();//辅助密码
		root_reguser["qq_num"] = UnicodeToUTF8(Kent_log_instance->kent_reconnect_qq_num.GetBuffer()).c_str();Kent_log_instance->kent_reconnect_qq_num.ReleaseBuffer();//QQ账号
		root_reguser["qq_key"] = UnicodeToUTF8(Kent_log_instance->kent_reconnect_qq_password.GetBuffer()).c_str();Kent_log_instance->kent_reconnect_qq_password.ReleaseBuffer();//QQ密码
		root_reguser["qq_name"] = UnicodeToUTF8(Kent_log_instance->kent_studio_qq_name.GetBuffer()).c_str();Kent_log_instance->kent_studio_qq_name.ReleaseBuffer();//名字
		root_reguser["qq_area"] = UnicodeToUTF8(Kent_log_instance->kent_reconnect_qq_area.GetBuffer()).c_str();Kent_log_instance->kent_reconnect_qq_area.ReleaseBuffer();//大区
		root_reguser["now_ip"] = Kent_log_instance->kent_studio_now_ip;//当前金币
		root_reguser["stop_ip"] = Kent_log_instance->kent_studio_stop_ip;//停止金币
		root_reguser["now_stage"] = Kent_log_instance->kent_studio_now_stage;//当前等级
		root_reguser["stop_stage"] = Kent_log_instance->kent_studio_stop_stage;//停止等级
	}

	Json::FastWriter writer_reguser;
	string jsondoc_reguser = writer_reguser.write(root_reguser);

	char request_reguser[1024];
	sprintf_s(request_reguser,"http://%s:%d/regusers/%s",UnicodeToUTF8(Kent_log_instance->kent_studio_ip_adr.GetBuffer()).c_str(),Kent_log_instance->kent_studio_port,jsondoc_reguser.c_str());
	Kent_log_instance->kent_studio_ip_adr.ReleaseBuffer();


	//string request = "http://localhost:16688/regusers/"+jsondoc_reguser;
	//Ckent_request kent_request;
	string response_reguser = kent_request.request_ans(request_reguser);

	if(0 == response_reguser.length()){//空错误
		kent_log.error("err:response_reguser NULL");
		Kent_log_instance->kent_studio_can_connect = 0;//不可以连接
		return 0;
	}else if('e' == response_reguser.at(0)){//err
		//kent_log.warn(response_reguser);//避免长时间，修改为警告
		Kent_log_instance->kent_studio_can_connect = 0;//不可以连接
		return 0;
	}

	if(0 == Kent_log_instance->kent_studio_can_connect){//
		Kent_log_instance->kent_studio_can_connect = 1;
	}else{
		Kent_log_instance->kent_studio_can_connect = 2;
	}


	Json::Reader JsonReader_reguser;//json解析
	Json::Value root_response_reguser;//表示一个json格式的对象
	if(!JsonReader_reguser.parse(response_reguser,root_response_reguser) || !root_response_reguser["IsNeedUpdate"].isBool())//解析json失败
	{
		kent_log.error("err:failed to parse getconfig response");
		return 0;
	}

	if(!root_response_reguser["IsNeedUpdate"].asBool()){//不需要更新配置
		return 0;
	}

	kent_log.info("getconfig");

	Json::Value root_getconfig;//对象
	if(0 == Kent_log_instance->kent_reg_login_user.GetLength())
	{
		root_getconfig["user"] = UnicodeToUTF8(_T("none")).c_str();//辅助账号
	}else
	{
		root_getconfig["user"] = UnicodeToUTF8(Kent_log_instance->kent_reg_login_user.GetBuffer()).c_str();Kent_log_instance->kent_reg_login_user.ReleaseBuffer();//辅助账号
	}

	Json::FastWriter writer_getconfig;
	string jsondoc_getconfig = writer_getconfig.write(root_getconfig);
	char request_getconfig[1024];
	sprintf_s(request_getconfig,"http://%s:%d/getconfig/%s",UnicodeToUTF8(Kent_log_instance->kent_studio_ip_adr.GetBuffer()).c_str(),Kent_log_instance->kent_studio_port,jsondoc_getconfig.c_str());
	Kent_log_instance->kent_studio_ip_adr.ReleaseBuffer();

	string response_getconfig = kent_request.request_ans(request_getconfig);//获取配置信息
	if(0 == response_getconfig.length()){//空错误
		kent_log.error("err:response_getconfig NULL");
		return 0;
	}else if('e' == response_getconfig.at(0)){//err
		kent_log.error(response_getconfig);
		return 0;
	}

	Json::Reader JsonReader_getconfig;//json解析
	Json::Value root_response_getconfig;//表示一个json格式的对象
	if(!JsonReader_getconfig.parse(response_getconfig,root_response_getconfig) ||!root_response_getconfig["identify_choose"].isString()
		||!root_response_getconfig["match_mode"].isString() ||!root_response_getconfig["shutdown"].isBool() ||!root_response_getconfig["stop"].isBool()
		||!root_response_getconfig["stop_now"].isBool() ||!root_response_getconfig["start"].isBool()
		||!root_response_getconfig["select1"].isString() ||!root_response_getconfig["select2"].isString() ||!root_response_getconfig["select3"].isString()
		||!root_response_getconfig["rand"].isBool() ||!root_response_getconfig["ruizi"].isBool())//解析json
	{
		kent_log.error("err:failed to parse getconfig response");
		return 0;
	}//解析配置

	//更新配置
	Kent_log_instance->kent_identify_choose = UTF8ToUnicode(root_response_getconfig["identify_choose"].asString()).c_str();
	Kent_log_instance->kent_identify_sydt_code = UTF8ToUnicode(root_response_getconfig["sydt_code"].asString()).c_str();
	Kent_log_instance->kent_studio_dama2_user = UTF8ToUnicode(root_response_getconfig["dama2_user"].asString()).c_str();
	Kent_log_instance->kent_studio_dama2_key = UTF8ToUnicode(root_response_getconfig["dama2_key"].asString()).c_str();
	Kent_log_instance->kent_studio_uuwise_user = UTF8ToUnicode(root_response_getconfig["uuwise_user"].asString()).c_str();
	Kent_log_instance->kent_studio_uuwise_key = UTF8ToUnicode(root_response_getconfig["uuwise_key"].asString()).c_str();
	Kent_log_instance->kent_nextshutdown = root_response_getconfig["shutdown"].asBool();
	Kent_log_instance->kent_nextstop = root_response_getconfig["stop"].asBool();
	Kent_log_instance->kent_nowstop = root_response_getconfig["stop_now"].asBool();
	Kent_log_instance->kent_nowstart = root_response_getconfig["start"].asBool();
	Kent_log_instance->kent_nowshutdown = root_response_getconfig["shutdown_now"].asBool();
	Kent_log_instance->kent_nowrestart = root_response_getconfig["restart_now"].asBool();
	Kent_log_instance->kent_force_downcpu = root_response_getconfig["downcpu"].asBool();
	Kent_log_instance->kent_change_task = root_response_getconfig["change_task"].asBool();
	Kent_log_instance->kent_change_task_time = root_response_getconfig["change_time"].asInt();
	Kent_log_instance->kent_change_task_num = root_response_getconfig["change_num"].asInt();

	Kent_log_instance->resetaccount = root_response_getconfig["resetaccount"].asBool();
	Kent_log_instance->kent_autorun = root_response_getconfig["autorun"].asBool();
	Kent_log_instance->SetAutoRun(Kent_log_instance->kent_autorun);

	CString match_mode = UTF8ToUnicode(root_response_getconfig["match_mode"].asString()).c_str();
	Kent_log_instance->kent_game_resolution = root_response_getconfig["resolution"].asInt();
	if(_T("统治战场匹配") == match_mode){
		Kent_log_instance->kent_game_match_mode = match_mode_common;
	}else if(_T("召唤师峡谷简单人机") == match_mode){
		Kent_log_instance->kent_game_match_mode = match_mode_normal_machine;
	}else if(_T("召唤师峡谷一般人机") == match_mode){
		Kent_log_instance->kent_game_match_mode = match_mode_normal_machine_hard;
	}else if(_T("扭曲丛林匹配") == match_mode){
		Kent_log_instance->kent_game_match_mode = match_mode_Distort;
	}else if(_T("极地大乱斗匹配") == match_mode){
		Kent_log_instance->kent_game_match_mode = match_mode_Colosseum;
	}else if(_T("随机地图(不含统治)" == match_mode)){
		Kent_log_instance->kent_game_match_mode = match_mode_Random;
	}else{
		Kent_log_instance->kent_game_match_mode = match_mode_Random;//无法识别就默认随机
	}
	
	Kent_log_instance->kent_hero_select.at(0) = UTF8ToUnicode(root_response_getconfig["select1"].asString()).c_str();
	Kent_log_instance->kent_hero_select.at(1) = UTF8ToUnicode(root_response_getconfig["select2"].asString()).c_str();
	Kent_log_instance->kent_hero_select.at(2) = UTF8ToUnicode(root_response_getconfig["select3"].asString()).c_str();
	Kent_log_instance->kent_hero_ruizi = root_response_getconfig["ruizi"].asBool();
	Kent_log_instance->kent_hero_rand = root_response_getconfig["rand"].asBool();

	Kent_log_instance->kent_studio_finish_enable = true;//开启完成条件
	Kent_log_instance->kent_reconnect_normal = true;
	Kent_log_instance->kent_reconnect_fast = false;



	Kent_log_instance->kent_store_studio_config();//存储配置

	return 0;
}
