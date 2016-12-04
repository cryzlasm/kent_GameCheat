
#include "stdafx.h"


IMPLEMENT_DYNAMIC(Kent_gameDlg, CDialogEx)
Kent_gameDlg::Kent_gameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Kent_gameDlg::IDD, pParent)
{

}
Kent_gameDlg::~Kent_gameDlg()
{
}
void Kent_gameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOIDC_MATCH_MODE, kent_game_match_mode);
	DDX_Control(pDX, IDC_COMBOIDC_HACK_MODE, kent_hook_mode);
	DDX_Control(pDX, IDC_COMBOIDC_BIND_MODE, kent_bind_mode);
	DDX_Control(pDX, IDC_CHECK_RECONNECT, kent_reconnect_normal);
	DDX_Control(pDX, IDC_CHECK_FAST_CONNECT, kent_reconnect_fast);
	DDX_Control(pDX, IDC_EDIT_HERO_SELECT1, kent_reconnect_qq_num);
	DDX_Control(pDX, IDC_EDIT_HERO_SELECT2, kent_reconnect_qq_password);
	DDX_Control(pDX, IDC_EDIT_SHUTDOWN_HOUR, kent_shutdown_hour);
	DDX_Control(pDX, IDC_CHECK_SHUTDOWN, kent_shutdown);
	DDX_Control(pDX, IDC_COMBO_QQ_AREA, kent_reconnect_qq_area);
	DDX_Control(pDX, IDC_CHECK_NEXTSTOP, kent_nextstop);
	DDX_Control(pDX, IDC_CHECK_NEXTSHUTDOWN, kent_nextshutdown);
	DDX_Control(pDX, IDC_STATIC_AREA, kent_reconnect_qq_area_text);
}
BEGIN_MESSAGE_MAP(Kent_gameDlg, CDialogEx)
END_MESSAGE_MAP()
// Kent_gameDlg message handlers
BOOL Kent_gameDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//
	kent_hook_mode.AddString(_T("后台"));
	kent_hook_mode.AddString(_T("前台"));
	//
	kent_bind_mode.AddString(_T("自动选择"));
	kent_bind_mode.AddString(_T("模式一"));
	kent_bind_mode.AddString(_T("模式二"));
	//
	kent_game_match_mode.AddString(_T("统治战场匹配"));
	kent_game_match_mode.AddString(_T("统治战场人机"));
	kent_game_match_mode.AddString(_T("召唤师峡谷简单人机"));
	kent_game_match_mode.AddString(_T("召唤师峡谷一般人机"));
	kent_game_match_mode.AddString(_T("自动选择(7级后统治)"));
	kent_game_match_mode.AddString(_T("扭曲丛林匹配"));
	kent_game_match_mode.AddString(_T("极地大乱斗匹配"));
	kent_game_match_mode.AddString(_T("随机地图"));

	kent_reconnect_qq_area.AddString(_T("上次登录大区"));

	kent_reconnect_qq_area.AddString(_T("艾欧尼亚"));
	kent_reconnect_qq_area.AddString(_T("祖安"));
	kent_reconnect_qq_area.AddString(_T("诺克萨斯"));
	kent_reconnect_qq_area.AddString(_T("班德尔城"));
	kent_reconnect_qq_area.AddString(_T("皮尔特若夫"));
	
	kent_reconnect_qq_area.AddString(_T("战争学院"));
	kent_reconnect_qq_area.AddString(_T("巨神峰"));
	kent_reconnect_qq_area.AddString(_T("雷瑟守备"));
	kent_reconnect_qq_area.AddString(_T("钢铁烈阳"));
	kent_reconnect_qq_area.AddString(_T("裁决之地"));

	kent_reconnect_qq_area.AddString(_T("黑色玫瑰"));
	kent_reconnect_qq_area.AddString(_T("暗影岛"));
	kent_reconnect_qq_area.AddString(_T("均衡教派"));
	kent_reconnect_qq_area.AddString(_T("水晶之痕"));
	kent_reconnect_qq_area.AddString(_T("影流"));

	kent_reconnect_qq_area.AddString(_T("守望之海"));
	kent_reconnect_qq_area.AddString(_T("征服之海"));
	kent_reconnect_qq_area.AddString(_T("卡拉曼达"));
	kent_reconnect_qq_area.AddString(_T("皮城戒备"));
	kent_reconnect_qq_area.AddString(_T("皮尔特若夫"));

	kent_reconnect_qq_area.AddString(_T("比尔吉沃特"));
	kent_reconnect_qq_area.AddString(_T("德玛西亚"));
	kent_reconnect_qq_area.AddString(_T("弗雷尔卓德"));
	kent_reconnect_qq_area.AddString(_T("无畏先锋"));
	kent_reconnect_qq_area.AddString(_T("恕瑞玛"));
	
	kent_reconnect_qq_area.AddString(_T("扭曲丛林"));
	kent_reconnect_qq_area.AddString(_T("巨龙之巢"));
	kent_reconnect_qq_area.AddString(_T("教育网专区"));

	kent_reconnect_qq_area.SetCurSel(0);

	kent_option_update();

#ifdef kent_han
	kent_reconnect_fast.ShowWindow(SW_HIDE);
	kent_reconnect_qq_area_text.ShowWindow(SW_HIDE);
	kent_reconnect_qq_area.ShowWindow(SW_HIDE);
#endif
	return true;
}
void Kent_gameDlg::kent_option_update()
{
#ifdef _kent_foreground_
	Kent_log_instance->kent_hook_mode = hook_mode_forground;
	Kent_log_instance->kent_bind_mode = bind_mode_AI;
#endif
	kent_hook_mode.SetCurSel(Kent_log_instance->kent_hook_mode);
	kent_bind_mode.SetCurSel(Kent_log_instance->kent_bind_mode);
	kent_game_match_mode.SetCurSel(Kent_log_instance->kent_game_match_mode);
	//
	kent_reconnect_normal.SetCheck(Kent_log_instance->kent_reconnect_normal);
	kent_reconnect_fast.SetCheck(Kent_log_instance->kent_reconnect_fast);
	//
	kent_reconnect_qq_num.SetWindowText(Kent_log_instance->kent_reconnect_qq_num);
	kent_reconnect_qq_password.SetWindowText(Kent_log_instance->kent_reconnect_qq_password);
	kent_reconnect_qq_area.SetWindowText(Kent_log_instance->kent_reconnect_qq_area);

	kent_shutdown.SetCheck(Kent_log_instance->kent_shutdown);
	kent_nextstop.SetCheck(Kent_log_instance->kent_nextstop);
	kent_nextshutdown.SetCheck(Kent_log_instance->kent_nextshutdown);
	CString tmp;
	tmp.Format(_T("%d"),Kent_log_instance->kent_shutdown_hour);
	kent_shutdown_hour.SetWindowText(tmp);
#ifdef _kent_foreground_
	kent_hook_mode.EnableWindow(false);
	kent_bind_mode.EnableWindow(false);
#endif
}
void Kent_gameDlg::kent_store_config()
{
	Kent_log_instance->kent_writeini(_T("kent_hook_mode"),&kent_hook_mode);
	Kent_log_instance->kent_writeini(_T("kent_bind_mode"),&kent_bind_mode);
	Kent_log_instance->kent_writeini(_T("kent_game_match_mode"),&kent_game_match_mode);
	Kent_log_instance->kent_writeini(_T("kent_reconnect_normal"),&kent_reconnect_normal);
	Kent_log_instance->kent_writeini(_T("kent_reconnect_fast"),&kent_reconnect_fast);
	Kent_log_instance->kent_writeini(_T("kent_reconnect_qq_num"),&kent_reconnect_qq_num);
	Kent_log_instance->kent_writeini(_T("kent_reconnect_qq_password"),&kent_reconnect_qq_password);
	CString tmp;
	kent_reconnect_qq_area.GetWindowText(tmp);
	Kent_log_instance->kent_writeini(_T("kent_reconnect_qq_area"),tmp);
	
}
void Kent_gameDlg::kent_return_config()
{
	CString tmp;
	Kent_log_instance->kent_hook_mode				=	(d_hook_mode)abs(kent_hook_mode.GetCurSel());
	Kent_log_instance->kent_bind_mode				=	(d_bind_mode)abs(kent_bind_mode.GetCurSel());
	Kent_log_instance->kent_game_match_mode			=	(d_match_mode)abs(kent_game_match_mode.GetCurSel());
	Kent_log_instance->kent_reconnect_normal		=	(0 == kent_reconnect_normal.GetCheck())?false:true;
	Kent_log_instance->kent_reconnect_fast			=	(0 == kent_reconnect_fast.GetCheck())?false:true;
	kent_reconnect_qq_num.GetWindowText(tmp);
	Kent_log_instance->kent_reconnect_qq_num		=	tmp;
	kent_reconnect_qq_password.GetWindowText(tmp);
	Kent_log_instance->kent_reconnect_qq_password	=	tmp;
	kent_reconnect_qq_area.GetWindowText(tmp);
	Kent_log_instance->kent_reconnect_qq_area	=	tmp;

	Kent_log_instance->kent_nextstop = (0 == kent_nextstop.GetCheck())?false:true;
	Kent_log_instance->kent_nextshutdown = (0 == kent_nextshutdown.GetCheck())?false:true;
	Kent_log_instance->kent_shutdown = (0 == kent_shutdown.GetCheck())?false:true;
	kent_shutdown_hour.GetWindowText(tmp);
	Kent_log_instance->kent_shutdown_hour	=	_ttoi(tmp);
}
