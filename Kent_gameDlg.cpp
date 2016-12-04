
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
	kent_hook_mode.AddString(_T("��̨"));
	kent_hook_mode.AddString(_T("ǰ̨"));
	//
	kent_bind_mode.AddString(_T("�Զ�ѡ��"));
	kent_bind_mode.AddString(_T("ģʽһ"));
	kent_bind_mode.AddString(_T("ģʽ��"));
	//
	kent_game_match_mode.AddString(_T("ͳ��ս��ƥ��"));
	kent_game_match_mode.AddString(_T("ͳ��ս���˻�"));
	kent_game_match_mode.AddString(_T("�ٻ�ʦϿ�ȼ��˻�"));
	kent_game_match_mode.AddString(_T("�ٻ�ʦϿ��һ���˻�"));
	kent_game_match_mode.AddString(_T("�Զ�ѡ��(7����ͳ��)"));
	kent_game_match_mode.AddString(_T("Ť������ƥ��"));
	kent_game_match_mode.AddString(_T("���ش��Ҷ�ƥ��"));
	kent_game_match_mode.AddString(_T("�����ͼ"));

	kent_reconnect_qq_area.AddString(_T("�ϴε�¼����"));

	kent_reconnect_qq_area.AddString(_T("��ŷ����"));
	kent_reconnect_qq_area.AddString(_T("�氲"));
	kent_reconnect_qq_area.AddString(_T("ŵ����˹"));
	kent_reconnect_qq_area.AddString(_T("��¶���"));
	kent_reconnect_qq_area.AddString(_T("Ƥ��������"));
	
	kent_reconnect_qq_area.AddString(_T("ս��ѧԺ"));
	kent_reconnect_qq_area.AddString(_T("�����"));
	kent_reconnect_qq_area.AddString(_T("��ɪ�ر�"));
	kent_reconnect_qq_area.AddString(_T("��������"));
	kent_reconnect_qq_area.AddString(_T("�þ�֮��"));

	kent_reconnect_qq_area.AddString(_T("��ɫõ��"));
	kent_reconnect_qq_area.AddString(_T("��Ӱ��"));
	kent_reconnect_qq_area.AddString(_T("�������"));
	kent_reconnect_qq_area.AddString(_T("ˮ��֮��"));
	kent_reconnect_qq_area.AddString(_T("Ӱ��"));

	kent_reconnect_qq_area.AddString(_T("����֮��"));
	kent_reconnect_qq_area.AddString(_T("����֮��"));
	kent_reconnect_qq_area.AddString(_T("��������"));
	kent_reconnect_qq_area.AddString(_T("Ƥ�ǽ䱸"));
	kent_reconnect_qq_area.AddString(_T("Ƥ��������"));

	kent_reconnect_qq_area.AddString(_T("�ȶ�������"));
	kent_reconnect_qq_area.AddString(_T("��������"));
	kent_reconnect_qq_area.AddString(_T("���׶�׿��"));
	kent_reconnect_qq_area.AddString(_T("��η�ȷ�"));
	kent_reconnect_qq_area.AddString(_T("ˡ����"));
	
	kent_reconnect_qq_area.AddString(_T("Ť������"));
	kent_reconnect_qq_area.AddString(_T("����֮��"));
	kent_reconnect_qq_area.AddString(_T("������ר��"));

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
