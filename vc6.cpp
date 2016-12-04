//������һ��ȫ�ֵ�CVc6App

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
	/*****************��־����*****************/
	Kent_log_instance=new Kent_log();
	/*****************�����ű�����*****************/
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
//ȫ�ֶ���
CVc6App theApp;
BOOL CVc6App::InitInstance()
{
#ifndef _DEBUG
	HANDLE hMutex = CreateMutex(NULL, false, _T("kent_you_knows_client"));
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		CloseHandle(hMutex);
		MessageBox(NULL,_T("�����Ѿ��������У������ظ�������"), _T("��ʾ"), MB_OK +MB_ICONWARNING);
		return FALSE;
	}
	if(VMProtectIsDebuggerPresent(true)){
		MessageBox(NULL,VMProtectDecryptStringW(_T("�������")),_T("����"),MB_OK);
		return false;
	}
#endif
	
	TCHAR buffer[MAX_PATH];
	GetModuleFileName(NULL,buffer,MAX_PATH);
	CString path_buffer(buffer);
	path_buffer = path_buffer.Left(path_buffer.ReverseFind(_T('\\')));//·��

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
		//��ʼ������̨
		InitConsoleWindow();//Rain
		std::wcout.imbue(locale("chs"));
		std::wcout<<_T("kent ��ʼ")<<endl;
		//setlocale(LC_ALL,"chs");
	}

	//����additivityΪfalse���滻���е�appender
	kent_log.setAdditivity(false);
	//����appender
	CString log_path=(CString)path_buffer+_T("\\KentClient.log");
	
	log4cpp::Appender* appender = new
		log4cpp::RollingFileAppender("RollingFileAppender",
		UnicodeToASCII(log_path.GetBuffer()),1024*1024);//�����־�ļ�1M
	log_path.ReleaseBuffer();//������־·��
	//����Layout
	log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
	pLayout->setConversionPattern("%d %p: %m%n");
	appender->setLayout(pLayout);
	//appender->setLayout(new log4cpp::BasicLayout());
	//��appender���󸽵�category��
	kent_log.setAppender(appender);
	if(Kent_Debug)
	{
		log4cpp::OstreamAppender *ConsoleAppender = new//����ģʽ�Ĵ���
			log4cpp::OstreamAppender("console", &std::cout);
		//ConsoleAppender->setLayout(new log4cpp::BasicLayout());
		ConsoleAppender->setLayout(pLayout);
		kent_log.setAppender(ConsoleAppender);
		kent_log.setPriority(log4cpp::Priority::DEBUG);
	}else{
		//����category�����ȼ������ڴ����ȼ�����־������¼
		kent_log.setPriority(log4cpp::Priority::WARN);
	}
	// ��¼һЩ��־
	kent_log.info("log start");

	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	CWinApp::InitInstance();

	AfxEnableControlContainer();
	CoInitialize(NULL);




	
VMProtectBeginUltra("regDm");//lbl.dyf���
#ifdef _kent_foreground_
	dm=new Cdm_basis();
	CString need_version=_T("3.1233");
	if(!Kent_log_instance->RegDll(Kent_log_instance->kent_root_path + _T("\\dm.dll")))
	{
		delete dm;
		dm=NULL;
		MessageBox(NULL,_T("ע����ʧ��,���ѹ���Թ���ԱȨ������"),_T("����"),MB_OK);
		return false;
	}
	if (!dm->CreateDispatch(_T("dm.dmsoft")))
	{
		delete dm;
		dm=NULL;
		MessageBox(NULL,_T("��������ʧ��,����Ƿ�����ע��"),_T("����"),MB_OK);
		return false;
	}
	CString tmp = dm->Ver();
	if (need_version.Compare(dm->Ver()))
	{
		MessageBox(NULL,_T("�汾�Ų���ȷ,��ǰ�汾:")+dm->Ver()+_T("���ѹ���Թ���ԱȨ������"),_T("����"),MB_OK);
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
		MessageBox(NULL,_T("ע����ʧ��,���ѹ���Թ���ԱȨ������"),_T("����"),MB_OK);
		return false;
	}
	if (!dm->CreateDispatch(_T("lbl.dyf"))){
		delete dm;
		dm=NULL;
		MessageBox(NULL,_T("��������ʧ��,����Ƿ�����ע��"),_T("����"),MB_OK);
		return false;
	}
	if (need_version.Compare(dm->Ver())){
		MessageBox(NULL,_T("�汾�Ų���ȷ,��ǰ�汾:")+dm->Ver()+_T("���ѹ���Թ���ԱȨ������"),_T("����"),MB_OK);
		delete dm;
		dm=NULL;
		return false;
	}
	//У��md5
	CString result = ValueMD5(Kent_log_instance->kent_root_path+_T("\\TSPlug.dll"));
	CString result2;
	for (int i=5;i<15;i++){
		result2+=result[i];
	}
	CString result3=_T("67469e925d");
	if (result2.Compare(result3)){
		MessageBox(NULL,_T("TSPlug.dll�ļ��𻵣�����������"),_T("����"),MB_OK);
		return false;
	}

#elif defined _kent_background_
	dm=new Idmsoft();
	CString need_version=_T("5.1416");
	if(!Kent_log_instance->RegDll(Kent_log_instance->kent_root_path+_T("\\lbl.dll"))){
		delete dm;
		dm=NULL;
		MessageBox(NULL,_T("ע����ʧ��,���ѹ���Թ���ԱȨ������"),_T("����"),MB_OK);
		return false;
	}
	if (!dm->CreateDispatch(_T("lbl.dyf"))){
		delete dm;
		dm=NULL;
		MessageBox(NULL,_T("��������ʧ��,����Ƿ�����ע��"),_T("����"),MB_OK);
		return false;
	}
	if (need_version.Compare(dm->Ver())){
		MessageBox(NULL,_T("�汾�Ų���ȷ,��ǰ�汾:")+dm->Ver()+_T("���ѹ���Թ���ԱȨ������"),_T("����"),MB_OK);
		delete dm;
		dm=NULL;
		return false;
	}
	//У��md5
	CString result = ValueMD5(Kent_log_instance->kent_root_path+_T("\\lbl.dll"));
	CString result2;
	for (int i=5;i<15;i++){
		result2+=result[i];
	}
	CString result3=_T("67469e925d");
	if (result2.Compare(result3)){
		MessageBox(NULL,_T("lbl.dll�ļ��𻵣�����������"),_T("����"),MB_OK);
		return false;
	}
#endif
VMProtectEnd();





	dm->SetShowErrorMsg(0);//�ر���Ϣ��ʾ
	/*****************dm���󴫵�*****************/
	Kent_log_instance->dm=dm;
	script_info->dm=dm;
	/*****************��Ϸ�����ĳ�ʼ������*****************/
	Kent_log_instance->option_init();
	Kent_log_instance->kent_get_config();
	/*****************��ʼ��*****************/
	if(!Kent_log_instance->kent_kss_init()){
		return false;//��ʼ��ʧ��
	}
	
#if defined kent_background || defined kent_foreground
	Kent_log_instance->dama2_init();
	Kent_log_instance->sydt_init();
	Kent_log_instance->uuwise_init();
#endif

	/*****************�������ڶ���*****************/
	Kent_ctrlDlg dlg;
	dlg.Kent_log_instance=Kent_log_instance;
	dlg.script_info=script_info;
//	m_pMainWnd = dlg;//���øô���Ϊ������
	while(0 < dlg.DoModal()){break;}
	
	log4cpp::Category::shutdown();
	return FALSE;
}