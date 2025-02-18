// kent_reg_modify_everDlg.cpp : implementation file
//

#include "stdafx.h"
#include "kent_reg_modify_everDlg.h"
#include "afxdialogex.h"


// kent_reg_modify_everDlg dialog

IMPLEMENT_DYNAMIC(kent_reg_modify_everDlg, CDialogEx)

kent_reg_modify_everDlg::kent_reg_modify_everDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(kent_reg_modify_everDlg::IDD, pParent)
{

}

kent_reg_modify_everDlg::~kent_reg_modify_everDlg()
{
}

void kent_reg_modify_everDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_MODIFY_USER, kent_reg_moditify_uesr);
	DDX_Control(pDX, IDC_EDIT_MODIFY_SUPER_KEY, kent_reg_moditify_super_key);
	DDX_Control(pDX, IDC_EDIT_MODIFY_LOGIN_KEY, kent_reg_moditify_login_key);
	DDX_Control(pDX, IDC_STATIC_MODIFY_NOTICE, kent_modify_notice);
}


BEGIN_MESSAGE_MAP(kent_reg_modify_everDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &kent_reg_modify_everDlg::OnBnClickedButtonModify)
END_MESSAGE_MAP()


// kent_reg_modify_everDlg message handlers


void kent_reg_modify_everDlg::OnBnClickedButtonModify()
{
	CString user,login_key,super_key;
	kent_reg_moditify_uesr.GetWindowText(user);user.Trim();
	kent_reg_moditify_super_key.GetWindowText(super_key);super_key.Trim();
	kent_reg_moditify_login_key.GetWindowText(login_key);login_key.Trim();
	//修改用户资料
	CString tempstr = Kent_log_instance->kent_kss->ks_edit(Kent_log_instance->v_softcode,user,super_key,login_key,_T(""));
	if(Kent_log_instance->iserrno(tempstr)){
		kent_modify_notice.SetWindowText(Kent_log_instance->kent_kss->ks_GetMsg(tempstr));
	}else{
		kent_modify_notice.SetWindowText(tempstr);
	}
}
