#pragma once


// kent_reg_rechargeDlg dialog

class kent_reg_rechargeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(kent_reg_rechargeDlg)

public:
	kent_reg_rechargeDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~kent_reg_rechargeDlg();

// Dialog Data
	enum { IDD = IDD_REGISTER_RECHARGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	Kent_log *Kent_log_instance;

	CStatic kent_reg_recharge_notice;
	CEdit kent_reg_recharge_user;
	CEdit kent_reg_recharge_cdkey;
	afx_msg void OnBnClickedButtonRecharge();
};
