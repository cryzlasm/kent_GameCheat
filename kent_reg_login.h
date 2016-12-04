#pragma once
#include "afxwin.h"


// kent_reg_login dialog

class kent_reg_login : public CDialogEx
{
	DECLARE_DYNAMIC(kent_reg_login)

public:
	kent_reg_login(CWnd* pParent = NULL);   // standard constructor
	virtual ~kent_reg_login();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_REGISTER_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	Kent_log *Kent_log_instance;
	
	void kent_store_config();
	void kent_return_config();
	void kent_option_update();

	CEdit kent_reg_login_user;
	CEdit kent_reg_login_key;
	CStatic kent_reg_login_notice;
	afx_msg void OnBnClickedButtonLogin();
	afx_msg void OnBnClickedButtonBind();
};
