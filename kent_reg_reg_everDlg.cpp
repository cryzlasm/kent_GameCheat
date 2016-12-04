// kent_reg_reg_everDlg.cpp : implementation file
//

#include "stdafx.h"
#include "kent_reg_reg_everDlg.h"
#include "afxdialogex.h"


// kent_reg_reg_everDlg dialog

IMPLEMENT_DYNAMIC(kent_reg_reg_everDlg, CDialogEx)

kent_reg_reg_everDlg::kent_reg_reg_everDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(kent_reg_reg_everDlg::IDD, pParent)
{

}

kent_reg_reg_everDlg::~kent_reg_reg_everDlg()
{
}

void kent_reg_reg_everDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_REG_USER, kent_reg_reg_user);
	DDX_Control(pDX, IDC_EDIT_REG_LOGIN_KEY, kent_reg_reg_login_key);
	DDX_Control(pDX, IDC_EDIT_REG_SUPER_KEY, kent_reg_reg_super_key);
	DDX_Control(pDX, IDC_EDIT_REG_CDKEY, kent_reg_reg_cdkey);
	DDX_Control(pDX, IDC_STATIC_REG_NOTICE, kent_reg_reg_notice);
}


BEGIN_MESSAGE_MAP(kent_reg_reg_everDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_REG, &kent_reg_reg_everDlg::OnBnClickedButtonReg)
END_MESSAGE_MAP()


// kent_reg_reg_everDlg message handlers


void kent_reg_reg_everDlg::OnBnClickedButtonReg()
{
	CString user,login_key,super_key,cdkey;
	kent_reg_reg_user.GetWindowText(user);user.Trim();
	kent_reg_reg_login_key.GetWindowText(login_key);login_key.Trim();
	kent_reg_reg_super_key.GetWindowText(super_key);super_key.Trim();
	kent_reg_reg_cdkey.GetWindowText(cdkey);cdkey.Trim();
	
	EnableWindow(false);
	//³äÖµ
	CString tempstr = Kent_log_instance->kent_kss->ks_reguser(Kent_log_instance->v_softcode,user,login_key,super_key,cdkey,_T(""),_T(""));
	if(Kent_log_instance->iserrno(tempstr)){
		kent_reg_reg_notice.SetWindowText(Kent_log_instance->kent_kss->ks_GetMsg(tempstr));
	}else{
		kent_reg_reg_notice.SetWindowText(tempstr);
		MessageBox(tempstr);
	}
	EnableWindow(true);
}
