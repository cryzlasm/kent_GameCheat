// kent_reg_rechargeDlg.cpp : implementation file
//

#include "stdafx.h"


// kent_reg_rechargeDlg dialog

IMPLEMENT_DYNAMIC(kent_reg_rechargeDlg, CDialogEx)

kent_reg_rechargeDlg::kent_reg_rechargeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(kent_reg_rechargeDlg::IDD, pParent)
{

}

kent_reg_rechargeDlg::~kent_reg_rechargeDlg()
{
}

void kent_reg_rechargeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_RECHARGE_NOTICE, kent_reg_recharge_notice);
	DDX_Control(pDX, IDC_EDIT_RECHARGE_USER, kent_reg_recharge_user);
	DDX_Control(pDX, IDC_EDIT_RECHARGE_CDKEY, kent_reg_recharge_cdkey);
}


BEGIN_MESSAGE_MAP(kent_reg_rechargeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_RECHARGE, &kent_reg_rechargeDlg::OnBnClickedButtonRecharge)
END_MESSAGE_MAP()


void kent_reg_rechargeDlg::OnBnClickedButtonRecharge()
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
