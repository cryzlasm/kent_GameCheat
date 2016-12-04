// kent_reg_login.cpp : implementation file
//

#include "stdafx.h"

IMPLEMENT_DYNAMIC(kent_reg_login, CDialogEx)

kent_reg_login::kent_reg_login(CWnd* pParent /*=NULL*/)
	: CDialogEx(kent_reg_login::IDD, pParent)
{

}

kent_reg_login::~kent_reg_login()
{
}

void kent_reg_login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_LOGIN_USER, kent_reg_login_user);
	DDX_Control(pDX, IDC_EDIT_LOGIN_KEY, kent_reg_login_key);
	DDX_Control(pDX, IDC_STATIC_LOGIN_NOTICE, kent_reg_login_notice);
}

BEGIN_MESSAGE_MAP(kent_reg_login, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &kent_reg_login::OnBnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_BIND, &kent_reg_login::OnBnClickedButtonBind)
END_MESSAGE_MAP()

BOOL kent_reg_login::OnInitDialog()
{
	CDialog::OnInitDialog();
	kent_option_update();
	return true;
}
void kent_reg_login::kent_option_update()
{
	kent_reg_login_user.SetWindowText(Kent_log_instance->kent_reg_login_user);
	kent_reg_login_key.SetWindowText(Kent_log_instance->kent_reg_login_key);
}
void kent_reg_login::kent_store_config()
{

}
void kent_reg_login::kent_return_config()
{

}

void kent_reg_login::OnBnClickedButtonLogin()
{
	//kent_reg_login_notice.SetWindowText(_T("过度期间请直接点开始运行"));
	//return;
VMProtectBeginUltra("OnBnClickedButtonLogin");
	kent_reg_login_user.GetWindowText(Kent_log_instance->kent_reg_login_user);
	kent_reg_login_key.GetWindowText(Kent_log_instance->kent_reg_login_key);

	Kent_log_instance->kent_kss->ks_setUserVal(1,Kent_log_instance->kent_reg_login_user,Kent_log_instance->kent_reg_login_key,_T(""));
	Kent_log_instance->kent_writeini(_T("kent_reg_login_user"),Kent_log_instance->kent_reg_login_user);
	Kent_log_instance->kent_writeini(_T("kent_reg_login_key"),Kent_log_instance->kent_reg_login_key);
	//验证信息
	//无用户名则尝试获取
	if(Kent_log_instance->kent_studio_can_connect && 0 == Kent_log_instance->kent_reg_login_user.GetLength()){
		Kent_log_instance->GetNewAccount();
	}

	Sleep(100);
	int i_rnd = (int)(49 * rand() / (RAND_MAX + 1.0));
	CString v_msgstr = Kent_log_instance->kent_kss->ks_IdCheck(Kent_log_instance->signData.Mid(i_rnd*8, 8), 1);
	if(Kent_log_instance->iserrno(v_msgstr)){
		kent_reg_login_notice.SetWindowText(Kent_log_instance->kent_kss->ks_GetMsg(v_msgstr));
	}else if(Kent_log_instance->signData.Mid(i_rnd * 8 + 400, 8) != v_msgstr){
		MessageBox(_T("软件验证失败，将关闭程序"));
		ExitProcess(0);
	}else{
		CString toview;
		toview.Format(_T("登录成功,剩余天数:%.2f(显示时间可能会有延时)"),(double)_ttoi(Kent_log_instance->kent_kss->ks_GetData(5))/60/60/24);
		kent_reg_login_notice.SetWindowText(toview);
	}
VMProtectEnd();
}
void kent_reg_login::OnBnClickedButtonBind()
{
//VMProtectBegin("OnBnClickedButtonBind");
//	kent_reg_login_user.GetWindowText(Kent_log_instance->kent_reg_login_user);Kent_log_instance->kent_reg_login_user.Trim();
//	kent_reg_login_key.GetWindowText(Kent_log_instance->kent_reg_login_key);Kent_log_instance->kent_reg_login_key.Trim();
//	
//	Kent_log_instance->kent_kss->ks_setUserVal(1,Kent_log_instance->kent_reg_login_user,Kent_log_instance->kent_reg_login_key,_T(""));
//	Kent_log_instance->kent_writeini(_T("kent_reg_login_user"),Kent_log_instance->kent_reg_login_user);
//	Kent_log_instance->kent_writeini(_T("kent_reg_login_key"),Kent_log_instance->kent_reg_login_key);
//	Kent_log_instance->kent_kss->ks_exit();
//	CString v_msgstr = Kent_log_instance->kent_kss->ks_unbind(Kent_log_instance->v_softcode,1,Kent_log_instance->kent_reg_login_user,Kent_log_instance->kent_reg_login_key);
//	if(Kent_log_instance->iserrno(v_msgstr)){
//		kent_reg_login_notice.SetWindowText(Kent_log_instance->kent_kss->ks_GetMsg(v_msgstr));
//	}else{
//		kent_reg_login_notice.SetWindowText(v_msgstr);
//	}
//VMProtectEnd();
kent_reg_login_notice.SetWindowText(_T("自动解绑模式：3小时不使用辅助，将自动解绑，可以更换电脑！"));
}
