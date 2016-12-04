// kent_reg_recharge_everDlg.cpp : implementation file
//

#include "stdafx.h"
#include "kent_reg_recharge_everDlg.h"
#include "afxdialogex.h"


// kent_reg_recharge_everDlg dialog

IMPLEMENT_DYNAMIC(kent_reg_recharge_everDlg, CDialogEx)

kent_reg_recharge_everDlg::kent_reg_recharge_everDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(kent_reg_recharge_everDlg::IDD, pParent)
{

}

kent_reg_recharge_everDlg::~kent_reg_recharge_everDlg()
{
}

void kent_reg_recharge_everDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_RECHARGE_NOTICE, kent_reg_recharge_notice);
	DDX_Control(pDX, IDC_EDIT_RECHARGE_USER, kent_reg_recharge_user);
	DDX_Control(pDX, IDC_EDIT_RECHARGE_CDKEY, kent_reg_recharge_cdkey);
}


BEGIN_MESSAGE_MAP(kent_reg_recharge_everDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_RECHARGE, &kent_reg_recharge_everDlg::OnBnClickedButtonRecharge)
END_MESSAGE_MAP()


// kent_reg_recharge_everDlg message handlers


void kent_reg_recharge_everDlg::OnBnClickedButtonRecharge()
{
	CString user,cdkey;
	kent_reg_recharge_user.GetWindowText(user);user.Trim();
	kent_reg_recharge_cdkey.GetWindowText(cdkey);cdkey.Trim();
	
	//³äÖµ
	CString tempstr = Kent_log_instance->kent_kss->ks_prepaid(Kent_log_instance->v_softcode,user,cdkey);
	if(Kent_log_instance->iserrno(tempstr)){
		kent_reg_recharge_notice.SetWindowText(Kent_log_instance->kent_kss->ks_GetMsg(tempstr));
	}else{
		kent_reg_recharge_notice.SetWindowText(tempstr);
	}
}
