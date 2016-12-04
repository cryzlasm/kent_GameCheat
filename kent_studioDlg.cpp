// kent_studioDlg.cpp : implementation file
//

#include "stdafx.h"
#include "kent_studioDlg.h"
#include "afxdialogex.h"


// kent_studioDlg dialog

IMPLEMENT_DYNAMIC(kent_studioDlg, CDialogEx)

kent_studioDlg::kent_studioDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(kent_studioDlg::IDD, pParent)
{

}
kent_studioDlg::~kent_studioDlg()
{
}
void kent_studioDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_IDENTIFY, kent_identify_choose);
	DDX_Control(pDX, IDC_BUTTON_REG_IDENTIFY, kent_identify_reg);
	DDX_Control(pDX, IDC_EDIT_IDENTIFY_CODE_SYDT, kent_identify_sydt_code);
	DDX_Control(pDX, IDC_EDIT_IP, kent_studio_ip_adr);
	DDX_Control(pDX, IDC_EDIT_PORT, kent_studio_port);
	DDX_Control(pDX, IDC_STATIC_CONNECT_STATE, kent_studio_connect_state);
	DDX_Control(pDX, IDC_EDIT_QQ_STOPIP, kent_studio_stop_ip);
	DDX_Control(pDX, IDC_EDIT_QQ_STOPSTAGE, kent_studio_stop_stage);
	DDX_Control(pDX, IDC_STATIC_NOW_STAGE, kent_studio_now_stage);
	DDX_Control(pDX, IDC_STATIC_NOW_IP, kent_studio_now_ip);
	DDX_Control(pDX, IDC_CHECK_FINSIH_ENABLE, kent_studio_finish_enable);
	DDX_Control(pDX, IDC_EDIT_IDENTIFY_DAMA2_USER, kent_studio_dama2_user);
	DDX_Control(pDX, IDC_EDIT_IDENTIFY_DAMA2_KEY, kent_studio_dama2_key);
	DDX_Control(pDX, IDC_STATIC_DAMA2_USER, kent_studio_dama2_user_text);
	DDX_Control(pDX, IDC_STATIC_DAMA2_KEY, kent_studio_dama2_key_text);
	DDX_Control(pDX, IDC_STATIC_UUWISE_USER, kent_studio_uuwise_user_text);
	DDX_Control(pDX, IDC_STATIC_UUWISE_KEY, kent_studio_uuwise_key_text);
	DDX_Control(pDX, IDC_EDIT_IDENTIFY_UUWISE_KEY, kent_studio_uuwise_key);
	DDX_Control(pDX, IDC_EDIT_IDENTIFY_UUWISE_USER, kent_studio_uuwise_user);
	DDX_Control(pDX, IDC_COMBO_RESOLUTION, kent_game_resolution);
	DDX_Control(pDX, IDC_CHECK_FORCE_DOWNCPU, kent_force_downcpu);
	DDX_Control(pDX, IDC_CHECK_CHANGE_TASK, kent_change_task);
	DDX_Control(pDX, IDC_EDIT_CHANGE_TIME, kent_change_task_time);
	DDX_Control(pDX, IDC_EDIT_CHANGE_TASK_NUM, kent_change_task_num);
	DDX_Control(pDX, IDC_CHECK_AUTORUN, kent_autorun);
}
BEGIN_MESSAGE_MAP(kent_studioDlg, CDialogEx)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_REG_IDENTIFY, &kent_studioDlg::OnBnClickedButtonRegIdentify)
	ON_CBN_SELCHANGE(IDC_COMBO_IDENTIFY, &kent_studioDlg::OnCbnSelchangeComboIdentify)
END_MESSAGE_MAP()
BOOL kent_studioDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	kent_identify_choose.AddString(_T("不使用"));
	kent_identify_choose.AddString(_T("顺逸代答"));
	kent_identify_choose.AddString(_T("打码兔"));
	kent_identify_choose.AddString(_T("UU云"));
	kent_identify_choose.SetCurSel(0);

	kent_game_resolution.AddString(_T("1280*720"));
	kent_game_resolution.AddString(_T("1024*768"));
	kent_game_resolution.SetCurSel(0);

	kent_option_update();//更新参数
	SetTimer(2, (int)(3000.0), NULL);//1秒检测一次注册状态
	return true;
}
void kent_studioDlg::kent_option_update()
{
	CString tmp;
	//kent_identify_sydt_code
	kent_identify_sydt_code.SetWindowTextW(Kent_log_instance->kent_identify_sydt_code);
	//kent_studio_now_stage
	tmp.Format(_T("当前等级:%d"),Kent_log_instance->kent_studio_now_stage);
	kent_studio_now_stage.SetWindowTextW(tmp);
	//kent_studio_now_ip
	tmp.Format(_T("当前金币:%d"),Kent_log_instance->kent_studio_now_ip);
	kent_studio_now_ip.SetWindowTextW(tmp);
	//kent_studio_stop_ip
	tmp.Format(_T("%d"),Kent_log_instance->kent_studio_stop_ip);
	kent_studio_stop_ip.SetWindowTextW(tmp);
	//kent_studio_stop_stage
	tmp.Format(_T("%d"),Kent_log_instance->kent_studio_stop_stage);
	kent_studio_stop_stage.SetWindowTextW(tmp);
	//kent_studio_finish_enable
	kent_studio_finish_enable.SetCheck(Kent_log_instance->kent_studio_finish_enable);
	//kent_autorun
	if(Kent_log_instance->IsAutoRun()){
		Kent_log_instance->kent_autorun = true;
	}else{
		Kent_log_instance->kent_autorun = false;
	}
	kent_autorun.SetCheck(Kent_log_instance->kent_autorun);

	//kent_studio_ip_adr
	kent_studio_ip_adr.SetWindowTextW(Kent_log_instance->kent_studio_ip_adr);
	//kent_studio_port
	tmp.Format(_T("%d"),Kent_log_instance->kent_studio_port);
	kent_studio_port.SetWindowTextW(tmp);
	//kent_identify_choose
	kent_identify_choose.SetWindowTextW(Kent_log_instance->kent_identify_choose);//特例存储文字
	if(0 == Kent_log_instance->kent_identify_choose.Compare(_T("顺逸代答"))){
		kent_identify_choose.SetCurSel(1);
	}else if(0 == Kent_log_instance->kent_identify_choose.Compare(_T("打码兔"))){
		kent_identify_choose.SetCurSel(2);
	}else if(0 == Kent_log_instance->kent_identify_choose.Compare(_T("UU云"))){
		kent_identify_choose.SetCurSel(3);
	}else{
		kent_identify_choose.SetCurSel(0);
	}

	kent_game_resolution.SetCurSel(Kent_log_instance->kent_game_resolution);

	OnCbnSelchangeComboIdentify();
	//kent_studio_dama2_key
	kent_studio_dama2_key.SetWindowTextW(Kent_log_instance->kent_studio_dama2_key);
	//kent_studio_dama2_user
	kent_studio_dama2_user.SetWindowTextW(Kent_log_instance->kent_studio_dama2_user);
	//kent_studio_uuwise_key
	kent_studio_uuwise_key.SetWindowTextW(Kent_log_instance->kent_studio_uuwise_key);
	//kent_studio_uuwise_user
	kent_studio_uuwise_user.SetWindowTextW(Kent_log_instance->kent_studio_uuwise_user);
	//kent_force_downcpu
	kent_force_downcpu.SetCheck(Kent_log_instance->kent_force_downcpu);
	//kent_change_task
	kent_change_task.SetCheck(Kent_log_instance->kent_change_task);
	//kent_change_task_time
	tmp.Format(_T("%d"),Kent_log_instance->kent_change_task_time);
	kent_change_task_time.SetWindowTextW(tmp);
	//kent_change_task_num
	tmp.Format(_T("%d"),Kent_log_instance->kent_change_task_num);
	kent_change_task_num.SetWindowTextW(tmp);
}
void kent_studioDlg::kent_store_config()
{
	CString tmp;
	Kent_log_instance->kent_writeini(_T("kent_identify_sydt_code"),&kent_identify_sydt_code);
	Kent_log_instance->kent_writeini(_T("kent_studio_stop_ip"),&kent_studio_stop_ip);
	Kent_log_instance->kent_writeini(_T("kent_studio_stop_stage"),&kent_studio_stop_stage);
	Kent_log_instance->kent_writeini(_T("kent_studio_finish_enable"),&kent_studio_finish_enable);
	Kent_log_instance->kent_writeini(_T("kent_autorun"),&kent_autorun);
	Kent_log_instance->kent_writeini(_T("kent_studio_ip_adr"),&kent_studio_ip_adr);
	Kent_log_instance->kent_writeini(_T("kent_studio_port"),&kent_studio_port);
	kent_identify_choose.GetWindowText(tmp);
	Kent_log_instance->kent_writeini(_T("kent_identify_choose"),tmp);//特例存储文字
	Kent_log_instance->kent_writeini(_T("kent_game_resolution"),kent_game_resolution.GetCurSel());//存储数字
	kent_studio_dama2_key.GetWindowText(tmp);
	Kent_log_instance->kent_writeini(_T("kent_studio_dama2_key"),tmp);
	kent_studio_dama2_user.GetWindowText(tmp);
	Kent_log_instance->kent_writeini(_T("kent_studio_dama2_user"),tmp);
	kent_studio_uuwise_key.GetWindowText(tmp);
	Kent_log_instance->kent_writeini(_T("kent_studio_uuwise_key"),tmp);
	kent_studio_uuwise_user.GetWindowText(tmp);
	Kent_log_instance->kent_writeini(_T("kent_studio_uuwise_user"),tmp);
	Kent_log_instance->kent_writeini(_T("kent_force_downcpu"),&kent_force_downcpu);
	Kent_log_instance->kent_writeini(_T("kent_change_task"),&kent_change_task);
	Kent_log_instance->kent_writeini(_T("kent_change_task_time"),&kent_change_task_time);
	Kent_log_instance->kent_writeini(_T("kent_change_task_num"),&kent_change_task_num);
}
void kent_studioDlg::kent_return_config()
{
	CString tmp;
	//kent_identify_sydt_code
	kent_identify_sydt_code.GetWindowTextW(tmp);
	Kent_log_instance->kent_identify_sydt_code = tmp;
	//kent_studio_stop_ip
	kent_studio_stop_ip.GetWindowText(tmp);
	Kent_log_instance->kent_studio_stop_ip = _ttoi(tmp);
	//kent_studio_stop_stage
	kent_studio_stop_stage.GetWindowText(tmp);
	Kent_log_instance->kent_studio_stop_stage = _ttoi(tmp);
	//kent_studio_finish_enable
	Kent_log_instance->kent_studio_finish_enable	=	(0 == kent_studio_finish_enable.GetCheck())?false:true;
	//kent_autorun
	Kent_log_instance->kent_autorun	=	(0 == kent_autorun.GetCheck())?false:true;
	//kent_studio_ip_adr
	kent_studio_ip_adr.GetWindowTextW(tmp);
	Kent_log_instance->kent_studio_ip_adr = tmp;
	//kent_studio_port
	kent_studio_port.GetWindowText(tmp);
	Kent_log_instance->kent_studio_port = _ttoi(tmp);
	//kent_identify_choose
	kent_identify_choose.GetWindowText(tmp);
	Kent_log_instance->kent_identify_choose = tmp;//特例存储文字
	//kent_game_resolution
	Kent_log_instance->kent_game_resolution = kent_game_resolution.GetCurSel();//存储数字
	//kent_studio_dama2_key
	kent_studio_dama2_key.GetWindowText(tmp);
	Kent_log_instance->kent_studio_dama2_key = tmp;
	//kent_studio_dama2_user
	kent_studio_dama2_user.GetWindowText(tmp);
	Kent_log_instance->kent_studio_dama2_user = tmp;
	//kent_studio_uuwise_user
	kent_studio_uuwise_user.GetWindowText(tmp);
	Kent_log_instance->kent_studio_uuwise_user = tmp;
	//kent_studio_uuwise_key
	kent_studio_uuwise_key.GetWindowText(tmp);
	Kent_log_instance->kent_studio_uuwise_key = tmp;
	//kent_force_downcpu
	Kent_log_instance->kent_force_downcpu	=	(0 == kent_force_downcpu.GetCheck())?false:true;
	//kent_change_task
	Kent_log_instance->kent_change_task	=	(0 == kent_change_task.GetCheck())?false:true;
	//kent_change_task_time
	kent_change_task_time.GetWindowText(tmp);
	Kent_log_instance->kent_change_task_time = _ttoi(tmp);
	//kent_change_task_num
	kent_change_task_num.GetWindowText(tmp);
	Kent_log_instance->kent_change_task_num = _ttoi(tmp);
}
void kent_studioDlg::OnBnClickedButtonRegIdentify()
{
	CString tmp;
	kent_identify_choose.GetWindowText(tmp);
	if(0 == tmp.Compare(_T("顺逸代答"))){
		ShellExecute(NULL,_T("open"),_T("http://sy.softsf.com/index.php/index/regist/referees/xuguruogu"),NULL,NULL,SW_SHOWNORMAL);
	}else if(0 == tmp.Compare(_T("打码兔"))){
		ShellExecute(NULL,_T("open"),_T("http://www.dama2.com/index/ureg?tj=465337&vali=1ca68cd08f5e9a5eebff156de34a9a5c"),NULL,NULL,SW_SHOWNORMAL);
	}else if(0 == tmp.Compare(_T("UU云"))){
		ShellExecute(NULL,_T("open"),_T("http://www.uuwise.com/userReg.html"),NULL,NULL,SW_SHOWNORMAL);
	}
}
void kent_studioDlg::OnCbnSelchangeComboIdentify()
{
	CString tmp;
	kent_identify_choose.GetWindowText(tmp);
	if(0 == tmp.Compare(_T("顺逸代答"))){
		kent_identify_sydt_code.ShowWindow(SW_SHOW);
		kent_studio_dama2_user.ShowWindow(SW_HIDE);
		kent_studio_dama2_key.ShowWindow(SW_HIDE);
		kent_studio_dama2_user_text.ShowWindow(SW_HIDE);
		kent_studio_dama2_key_text.ShowWindow(SW_HIDE);
		kent_studio_uuwise_user_text.ShowWindow(SW_HIDE);
		kent_studio_uuwise_key_text.ShowWindow(SW_HIDE);
		kent_studio_uuwise_key.ShowWindow(SW_HIDE);
		kent_studio_uuwise_user.ShowWindow(SW_HIDE);
		kent_identify_reg.ShowWindow(SW_SHOW);
		
	}else if(0 == tmp.Compare(_T("打码兔"))){
		kent_identify_sydt_code.ShowWindow(SW_HIDE);
		kent_studio_dama2_user.ShowWindow(SW_SHOW);
		kent_studio_dama2_key.ShowWindow(SW_SHOW);
		kent_studio_dama2_user_text.ShowWindow(SW_SHOW);
		kent_studio_dama2_key_text.ShowWindow(SW_SHOW);
		kent_studio_uuwise_user_text.ShowWindow(SW_HIDE);
		kent_studio_uuwise_key_text.ShowWindow(SW_HIDE);
		kent_studio_uuwise_key.ShowWindow(SW_HIDE);
		kent_studio_uuwise_user.ShowWindow(SW_HIDE);
		kent_identify_reg.ShowWindow(SW_SHOW);
	}else if(0 == tmp.Compare(_T("UU云"))){
		kent_identify_sydt_code.ShowWindow(SW_HIDE);
		kent_studio_dama2_user.ShowWindow(SW_HIDE);
		kent_studio_dama2_key.ShowWindow(SW_HIDE);
		kent_studio_dama2_user_text.ShowWindow(SW_HIDE);
		kent_studio_dama2_key_text.ShowWindow(SW_HIDE);
		kent_studio_uuwise_user_text.ShowWindow(SW_SHOW);
		kent_studio_uuwise_key_text.ShowWindow(SW_SHOW);
		kent_studio_uuwise_key.ShowWindow(SW_SHOW);
		kent_studio_uuwise_user.ShowWindow(SW_SHOW);
		kent_identify_reg.ShowWindow(SW_SHOW);
	}else{
		kent_identify_sydt_code.ShowWindow(SW_HIDE);
		kent_studio_dama2_user.ShowWindow(SW_HIDE);
		kent_studio_dama2_key.ShowWindow(SW_HIDE);
		kent_studio_dama2_user_text.ShowWindow(SW_HIDE);
		kent_studio_dama2_key_text.ShowWindow(SW_HIDE);
		kent_studio_uuwise_user_text.ShowWindow(SW_HIDE);
		kent_studio_uuwise_key_text.ShowWindow(SW_HIDE);
		kent_studio_uuwise_key.ShowWindow(SW_HIDE);
		kent_studio_uuwise_user.ShowWindow(SW_HIDE);
		kent_identify_reg.ShowWindow(SW_HIDE);
	}

}
void kent_studioDlg::OnTimer(UINT_PTR nIDEvent)
{	
	if(2 == nIDEvent)
	{
		KillTimer(nIDEvent);

		if(Kent_log_instance->kent_studio_can_connect){
			kent_studio_connect_state.SetWindowText(_T("状态:连接成功"));
		}else{
			kent_studio_connect_state.SetWindowText(_T("状态:连接失败"));
		}
		CString tmp;
		tmp.Format(_T("当前等级:%d"),Kent_log_instance->kent_studio_now_stage);
		kent_studio_now_stage.SetWindowText(tmp);
	
		tmp.Format(_T("当前金币:%d"),Kent_log_instance->kent_studio_now_ip);
		kent_studio_now_ip.SetWindowText(tmp);

		CDialog::OnTimer(nIDEvent);
		SetTimer(nIDEvent, (int)(3000.0), NULL);
	}
}
