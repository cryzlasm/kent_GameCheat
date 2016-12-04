//定义了一个全局的CVc6App

#include "stdafx.h"
#include "CDama2Ctrl.h"
#include "Csydtdll.h"
#include "CTSPlugInterFace.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


BEGIN_MESSAGE_MAP(CVc6App, CWinApp)
	
END_MESSAGE_MAP()

void InitConsoleWindow()//Rain
	{
int nCrt = 0;
FILE* fp;
AllocConsole();
nCrt = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
fp = _fdopen(nCrt, "w");
*stdout = *fp;
setvbuf(stdout, NULL, _IONBF, 0);
}


CVc6App::CVc6App()
{
	/*****************日志对象*****************/
	Kent_log_instance=new Kent_log();
	/*****************创建脚本对象*****************/
	script_info=new ScriptInfo();
	script_info->Kent_log_instance=Kent_log_instance;
	script_info->kent_windows_instance->Kent_log_instance=Kent_log_instance;
}
CVc6App::~CVc6App()
{
	delete script_info;
	if(dm){
		dm->UnBindWindow();
		delete dm;
	}
	delete Kent_log_instance;
}
//全局对象
CVc6App theApp;
BOOL CVc6App::InitInstance()
{
#ifndef _DEBUG
	HANDLE hMutex = CreateMutex(NULL, false, _T("kent_you_knows_client"));
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		CloseHandle(hMutex);
		MessageBox(NULL,_T("程序已经在运行中，不能重复启动！"), _T("提示"), MB_OK +MB_ICONWARNING);
		return FALSE;
	}
	if(VMProtectIsDebuggerPresent(true)){
		MessageBox(NULL,VMProtectDecryptStringW(_T("请勿调试")),_T("错误"),MB_OK);
		return false;
	}
#endif
	
	TCHAR buffer[MAX_PATH];
	GetModuleFileName(NULL,buffer,MAX_PATH);
	CString path_buffer(buffer);
	path_buffer = path_buffer.Left(path_buffer.ReverseFind(_T('\\')));//路径

	AllocConsole();
	
	system("echo. > C:\\WINDOWS\\system32\\drivers\\etc\\hosts");

	FreeConsole();
	
	CString debugon;
	bool Kent_Debug = false;
	GetPrivateProfileString(_T("DEBUG"),_T("debug"),_T(""),debugon.GetBuffer(200),200,path_buffer+_T("\\config.ini"));
	debugon.ReleaseBuffer();

	if(1 == _ttoi(debugon))
	{
		Kent_Debug = true;
	}

	if(Kent_Debug)
	{
		//初始化控制台
		InitConsoleWindow();//Rain
		std::wcout.imbue(locale("chs"));
		std::wcout<<_T("kent 开始")<<endl;
		//setlocale(LC_ALL,"chs");
	}

	//设置additivity为false，替换已有的appender
	kent_log.setAdditivity(false);
	//创建appender
	CString log_path=(CString)path_buffer+_T("\\KentClient.log");
	
	log4cpp::Appender* appender = new
		log4cpp::RollingFileAppender("RollingFileAppender",
		UnicodeToASCII(log_path.GetBuffer()),1024*1024);//最大日志文件1M
	log_path.ReleaseBuffer();//设置日志路径
	//设置Layout
	log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
	pLayout->setConversionPattern("%d %p: %m%n");
	appender->setLayout(pLayout);
	//appender->setLayout(new log4cpp::BasicLayout());
	//把appender对象附到category上
	kent_log.setAppender(appender);
	if(Kent_Debug)
	{
		log4cpp::OstreamAppender *ConsoleAppender = new//调试模式的窗口
			log4cpp::OstreamAppender("console", &std::cout);
		//ConsoleAppender->setLayout(new log4cpp::BasicLayout());
		ConsoleAppender->setLayout(pLayout);
		kent_log.setAppender(ConsoleAppender);
		kent_log.setPriority(log4cpp::Priority::DEBUG);
	}else{
		//设置category的优先级，低于此优先级的日志不被记录
		kent_log.setPriority(log4cpp::Priority::WARN);
	}
	// 记录一些日志
	kent_log.info("log start");

	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	CWinApp::InitInstance();

	AfxEnableControlContainer();
	CoInitialize(NULL);




	
VMProtectBeginUltra("regDm");//lbl.dyf标记
#ifdef _kent_foreground_
	dm=new Cdm_basis();
	CString need_version=_T("3.1233");
	if(!Kent_log_instance->RegDll(Kent_log_instance->kent_root_path + _T("\\dm.dll")))
	{
		delete dm;
		dm=NULL;
		MessageBox(NULL,_T("注册插件失败,请解压后以管理员权限运行"),_T("错误"),MB_OK);
		return false;
	}
	if (!dm->CreateDispatch(_T("dm.dmsoft")))
	{
		delete dm;
		dm=NULL;
		MessageBox(NULL,_T("创建对象失败,检查是否正常注册"),_T("错误"),MB_OK);
		return false;
	}
	CString tmp = dm->Ver();
	if (need_version.Compare(dm->Ver()))
	{
		MessageBox(NULL,_T("版本号不正确,当前版本:")+dm->Ver()+_T("请解压后以管理员权限运行"),_T("错误"),MB_OK);
		delete dm;
		dm=NULL;
		return false;
	}
#elif defined _kent_background_new_
	
	dm=new CTSPlugInterFace();
	CString need_version=_T("5.1416");
	if(!Kent_log_instance->RegDll(Kent_log_instance->kent_root_path+_T("\\TSPlug.dll"))){
		delete dm;
		dm=NULL;
		MessageBox(NULL,_T("注册插件失败,请解压后以管理员权限运行"),_T("错误"),MB_OK);
		return false;
	}
	if (!dm->CreateDispatch(_T("lbl.dyf"))){
		delete dm;
		dm=NULL;
		MessageBox(NULL,_T("创建对象失败,检查是否正常注册"),_T("错误"),MB_OK);
		return false;
	}
	if (need_version.Compare(dm->Ver())){
		MessageBox(NULL,_T("版本号不正确,当前版本:")+dm->Ver()+_T("请解压后以管理员权限运行"),_T("错误"),MB_OK);
		delete dm;
		dm=NULL;
		return false;
	}
	//校验md5
	CString result = ValueMD5(Kent_log_instance->kent_root_path+_T("\\TSPlug.dll"));
	CString result2;
	for (int i=5;i<15;i++){
		result2+=result[i];
	}
	CString result3=_T("67469e925d");
	if (result2.Compare(result3)){
		MessageBox(NULL,_T("TSPlug.dll文件损坏，请重新下载"),_T("错误"),MB_OK);
		return false;
	}

#elif defined _kent_background_
	dm=new Idmsoft();
	CString need_version=_T("5.1416");
	if(!Kent_log_instance->RegDll(Kent_log_instance->kent_root_path+_T("\\lbl.dll"))){
		delete dm;
		dm=NULL;
		MessageBox(NULL,_T("注册插件失败,请解压后以管理员权限运行"),_T("错误"),MB_OK);
		return false;
	}
	if (!dm->CreateDispatch(_T("lbl.dyf"))){
		delete dm;
		dm=NULL;
		MessageBox(NULL,_T("创建对象失败,检查是否正常注册"),_T("错误"),MB_OK);
		return false;
	}
	if (need_version.Compare(dm->Ver())){
		MessageBox(NULL,_T("版本号不正确,当前版本:")+dm->Ver()+_T("请解压后以管理员权限运行"),_T("错误"),MB_OK);
		delete dm;
		dm=NULL;
		return false;
	}
	//校验md5
	CString result = ValueMD5(Kent_log_instance->kent_root_path+_T("\\lbl.dll"));
	CString result2;
	for (int i=5;i<15;i++){
		result2+=result[i];
	}
	CString result3=_T("67469e925d");
	if (result2.Compare(result3)){
		MessageBox(NULL,_T("lbl.dll文件损坏，请重新下载"),_T("错误"),MB_OK);
		return false;
	}
#endif
VMProtectEnd();





	dm->SetShowErrorMsg(0);//关闭消息提示
	/*****************dm对象传递*****************/
	Kent_log_instance->dm=dm;
	script_info->dm=dm;
	/*****************游戏参数的初始化参数*****************/
	Kent_log_instance->option_init();
	Kent_log_instance->kent_get_config();
	/*****************初始化*****************/
	if(!Kent_log_instance->kent_kss_init()){
		return false;//初始化失败
	}
	
#if defined kent_background || defined kent_foreground
	Kent_log_instance->dama2_init();
	Kent_log_instance->sydt_init();
	Kent_log_instance->uuwise_init();
#endif

	/*****************创建窗口对象*****************/
	Kent_ctrlDlg dlg;
	dlg.Kent_log_instance=Kent_log_instance;
	dlg.script_info=script_info;
//	m_pMainWnd = dlg;//设置该窗口为主窗口
	while(0 < dlg.DoModal()){break;}
	
	log4cpp::Category::shutdown();
	return FALSE;
}