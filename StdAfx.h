
#pragma once


#define _AFX_SECURE_NO_WARNINGS     // MFC关闭运行时安全警告 
#define _ATL_SECURE_NO_WARNINGS     // ATL关闭运行时安全警告
#define _CRT_SECURE_NO_WARNINGS     // C关闭运行时安全警告
#define _CRT_NONSTDC_NO_WARNINGS    // CPOSIX关闭运行时安全警告
#define _SCL_SECURE_NO_WARNINGS     // STL关闭运行时安全警告


#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#include "afx.h"
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#include <afxole.h>         // MFC OLE 类
#include <afxodlgs.h>       // MFC OLE 对话框类
#include <afxdisp.h>        // MFC Automation classes
#endif // _AFX_NO_AFXCMN_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>   // MFC ODBC 数据库类
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>   // MFC DAO 数据库类
#endif // _AFX_NO_DAO_SUPPORT

#include <vector>
using namespace std;

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>  // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>   // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT
/*#include <tchar.h>*/



/*************宏定义***************/
//#define kent_background
#define kent_foreground

//#define kent_forever


//#define kent_forever_background



#if defined lol_home_background || defined kent_background
#define _kent_background_
#elif defined kent_forever_background
//#define _kent_background_
#define _kent_background_new_
#else
#define _kent_foreground_
#endif



#ifndef WINVER        // 指定要求的最低平台是 Windows Vista。
#define WINVER 0x0501    // 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif

#ifndef _WIN32_WINNT    // 指定要求的最低平台是 Windows Vista。
#define _WIN32_WINNT 0x0501  // 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif      

//数据库相关

#include "Cv901.h"//可可网络验证

#include <TLHELP32.H>
#include "VMProtectSDK.h"
#include <io.h>//Rain  用来输出调试信息
#include <fcntl.h>//Rain
#include <algorithm>
#include "stdio.h" 
#include "Md5.h"
#include <process.h>
#include "resource.h"
#include <afxcontrolbars.h>
#include <afxdisp.h>
#include <iostream>
#include "math.h"
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <list>
#include<fstream>


#ifdef _kent_foreground_
#include "Cdm_basis.h"
#elif defined _kent_background_new_
#include "CTSPlugInterFace.h"
#include "dm.h"//包含不同库文件
#else
#include "dm.h"//包含不同库文件
#endif

#include "Csydtdll.h"
#include "CDama2Ctrl.h"
#import ".\\UUWiseHelper.dll"
using namespace UUWiseHelperLib;


#include <log4cpp/Category.hh>
#include "log4cpp/FileAppender.hh"
#include "log4cpp/PatternLayout.hh"
#include "log4cpp/LayoutAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/RollingFileAppender.hh"
#include "json\json.h"
#include "curl\curl.h"

#include "Ckent_request.h"
#include "global.h"


#include "Kent_log.h"
#include "afxdialogex.h"
#include "kent_herosDlg.h"

#include "kent_reg_login.h"
#include "kent_reg_login_ever.h"
#include "kent_reg_modifyDlg.h"
#include "kent_reg_modify_everDlg.h"
#include "kent_reg_rechargeDlg.h"
#include "kent_reg_recharge_everDlg.h"
#include "kent_reg_regDlg.h"
#include "kent_reg_reg_everDlg.h"

#include "kent_registerDlg.h"
#include "Kent_gameDlg.h"
#include "Kent_studioDlg.h"
#include "Kent_helpDlg.h"

#include "kent_windows.h"
#include "script.h"
#include "Kent_ctrlDlg.h"
#include "Kent_forever.h"
#include "kent_whole.h"
#include "vc6.h"
#include "menuDlg.h"
#include <afxdisp.h>
#include <afxdisp.h>
#include <afxdisp.h>
#include <afxdisp.h>
#include <afxdisp.h>



#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif