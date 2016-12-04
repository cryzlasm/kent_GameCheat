#pragma once
#include "afxwin.h"


// kent_reg_login_ever dialog

class kent_reg_login_ever : public CDialogEx
{
	DECLARE_DYNAMIC(kent_reg_login_ever)

public:
	kent_reg_login_ever(CWnd* pParent = NULL);   // standard constructor
	virtual ~kent_reg_login_ever();
	virtual BOOL OnInitDialog();
// Dialog Data
	enum { IDD = IDD_REGISTER_LOGIN_EVER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	Kent_log *Kent_log_instance;
	CEdit kent_reg_login_user;
	CEdit kent_reg_login_key;
	CStatic kent_reg_login_notice;
	afx_msg void OnBnClickedButtonLogin();
	afx_msg void OnBnClickedButtonBind();
};
