
#include "stdafx.h"


IMPLEMENT_DYNAMIC(kent_helpDlg, CDialogEx)

kent_helpDlg::kent_helpDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(kent_helpDlg::IDD, pParent)
{
}
kent_helpDlg::~kent_helpDlg()
{
}
void kent_helpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, kent_help_str);
}
BEGIN_MESSAGE_MAP(kent_helpDlg, CDialogEx)

END_MESSAGE_MAP()
BOOL kent_helpDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CString str_help;

#ifdef lol_home_background
	str_help=_T("TIMO辅助增强版（支持后台）\r\n");
	str_help+=_T("TIMO辅助免费体验群：127559445\r\n");
	str_help+=_T("TIMO辅助VIP售后2群：231965630（请满意五星好评，备注淘宝名字加群，否则拒绝）\r\n");
	str_help+=_T("由于不及时加入售后群，版本更新被封号，买家自行承担！\r\n");
#endif
#ifdef lol_home_foreground
	str_help=_T("TIMO辅助基础版（不支持后台）\r\n");
	str_help+=_T("TIMO辅助免费体验群：127559445\r\n");
	str_help+=_T("TIMO辅助VIP售后2群：231965630（请满意五星好评，备注淘宝名字加群，否则拒绝）\r\n");
	str_help+=_T("由于不及时加入售后群，版本更新被封号，买家自行承担！\r\n");
#endif
#if defined lol_home_foreground || defined lol_home_background
	str_help+=_T("全新采用C++平台开发，更加稳定安全.\r\n");
	str_help+=_T("加大随机数的应用，避免被行为检测.\r\n");
	str_help+=_T("增强版可以全新后台挂机，不用枯燥的等待！\r\n\r\n");
#endif
#ifdef kent_background
	str_help=_T("kent辅助(增强版，可以后台)\r\n");
	str_help+=_T("售后群：361989735(请注明自己的旺旺账号以及是否好评，否则拒绝！)\r\n");
	str_help+=_T("kent交流群4：109555078\r\n\r\n");
#endif

#ifdef kent_foreground
	str_help=_T("kent辅助(基础版，不能后台)\r\n");
	str_help+=_T("售后群：361989735(请注明自己的旺旺账号以及是否好评，否则拒绝！)\r\n");
	str_help+=_T("kent交流群4：109555078\r\n\r\n");
#endif
	str_help+=_T("增强版和基础版的区别:\r\n");
	str_help+=_T("1、增强版采取各种内核级别防护方法，更加安全。\r\n");
	str_help+=_T("2、并且提供后台运行支持（可以遮挡游戏界面，做其他的事）\r\n\r\n");
	
	str_help+=_T("使用方法:\r\n");
	str_help+=_T("1、注册账号（新注册账号即有1小时试用）\r\n");
	str_help+=_T("2、登录账号\r\n");
	str_help+=_T("3、打开游戏进入游戏大厅\r\n");
	str_help+=_T("4、点击开始\r\n");
	str_help+=_T("5、购买充值卡，向您的账户充值相应天数。\r\n");


#ifdef kent_han
	str_help = _T("");
#endif

	kent_help_str.SetWindowText(str_help);
	kent_option_update();
	return true;
}
void kent_helpDlg::kent_option_update()
{
	return;
}
void kent_helpDlg::kent_store_config()
{
	return;
}
void kent_helpDlg::kent_return_config()
{
	return;
}
