// kent_reg_login_ever.cpp : implementation file
//

#include "stdafx.h"
#include "kent_reg_login_ever.h"
#include "afxdialogex.h"


// kent_reg_login_ever dialog

IMPLEMENT_DYNAMIC(kent_reg_login_ever, CDialogEx)

kent_reg_login_ever::kent_reg_login_ever(CWnd* pParent /*=NULL*/)
	: CDialogEx(kent_reg_login_ever::IDD, pParent)
{

}

kent_reg_login_ever::~kent_reg_login_ever()
{
}

void kent_reg_login_ever::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_LOGIN_USER, kent_reg_login_user);
	DDX_Control(pDX, IDC_EDIT_LOGIN_KEY, kent_reg_login_key);
	DDX_Control(pDX, IDC_STATIC_LOGIN_NOTICE, kent_reg_login_notice);
}


BEGIN_MESSAGE_MAP(kent_reg_login_ever, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &kent_reg_login_ever::OnBnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_BIND, &kent_reg_login_ever::OnBnClickedButtonBind)
END_MESSAGE_MAP()


// kent_reg_login_ever message handlers
BOOL kent_reg_login_ever::OnInitDialog()
{
	CDialog::OnInitDialog();

#if defined kent_forever ||defined kent_forever_background
	kent_reg_login_notice.SetWindowText(_T("试用账号:lol123密码:lol123\n购买后请使用注册码注册自己的账号。"));
#endif
	return true;
}

void kent_reg_login_ever::OnBnClickedButtonLogin()
{
	//kent_reg_login_notice.SetWindowText(_T("过度期间请直接点开始运行"));
	//return;
VMProtectBeginUltra("kent_reg_login_ever::OnBnClickedButtonLogin");
	kent_reg_login_user.GetWindowText(Kent_log_instance->kent_reg_login_user);
	kent_reg_login_key.GetWindowText(Kent_log_instance->kent_reg_login_key);

	Kent_log_instance->kent_kss->ks_setUserVal(1,Kent_log_instance->kent_reg_login_user,Kent_log_instance->kent_reg_login_key,_T(""));
	Kent_log_instance->kent_writeini(_T("kent_reg_login_user"),Kent_log_instance->kent_reg_login_user);
	Kent_log_instance->kent_writeini(_T("kent_reg_login_key"),Kent_log_instance->kent_reg_login_key);
	//验证信息
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
		toview.Format(_T("登录成功,剩余天数:%.2f(时间显示有延时，如果时间不正确，请重启辅助再试！"),(double)_ttoi(Kent_log_instance->kent_kss->ks_GetData(5))/60/60/24);
		kent_reg_login_notice.SetWindowText(toview);
	}
VMProtectEnd();
}


void kent_reg_login_ever::OnBnClickedButtonBind()
{
	kent_reg_login_notice.SetWindowText(_T("解绑成功！"));
}
