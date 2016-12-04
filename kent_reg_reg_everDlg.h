#pragma once
#include "afxwin.h"


// kent_reg_reg_everDlg dialog

class kent_reg_reg_everDlg : public CDialogEx
{
	DECLARE_DYNAMIC(kent_reg_reg_everDlg)

public:
	kent_reg_reg_everDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~kent_reg_reg_everDlg();

// Dialog Data
	enum { IDD = IDD_REGISTER_REG_EVER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	Kent_log *Kent_log_instance;
	CEdit kent_reg_reg_user;
	CEdit kent_reg_reg_login_key;
	CEdit kent_reg_reg_super_key;
	CEdit kent_reg_reg_cdkey;
	CStatic kent_reg_reg_notice;
	afx_msg void OnBnClickedButtonReg();
};
