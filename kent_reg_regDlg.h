#pragma once

class kent_reg_regDlg : public CDialogEx
{
	DECLARE_DYNAMIC(kent_reg_regDlg)

public:
	kent_reg_regDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~kent_reg_regDlg();

// Dialog Data
	enum { IDD = IDD_REGISTER_REG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	Kent_log *Kent_log_instance;

	CEdit kent_reg_reg_user;
	CEdit kent_reg_reg_login_key;
	CEdit kent_reg_reg_super_key;
	CEdit kent_reg_reg_cdkey;
	afx_msg void OnBnClickedButtonReg();
	CStatic kent_reg_reg_notice;
};
