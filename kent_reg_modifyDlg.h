#pragma once

// kent_reg_modifyDlg dialog

class kent_reg_modifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(kent_reg_modifyDlg)

public:
	kent_reg_modifyDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~kent_reg_modifyDlg();

// Dialog Data
	enum { IDD = IDD_REGISTER_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	Kent_log *Kent_log_instance;

	CStatic kent_modify_notice;
	afx_msg void OnBnClickedButtonModify();
	CEdit kent_reg_moditify_uesr;
	CEdit kent_reg_moditify_super_key;
	CEdit kent_reg_moditify_login_key;
};
