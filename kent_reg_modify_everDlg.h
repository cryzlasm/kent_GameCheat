#pragma once
#include "afxwin.h"


// kent_reg_modify_everDlg dialog

class kent_reg_modify_everDlg : public CDialogEx
{
	DECLARE_DYNAMIC(kent_reg_modify_everDlg)

public:
	kent_reg_modify_everDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~kent_reg_modify_everDlg();

// Dialog Data
	enum { IDD = IDD_REGISTER_MODIFY_EVER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	Kent_log *Kent_log_instance;
	CEdit kent_reg_moditify_uesr;
	CEdit kent_reg_moditify_super_key;
	CEdit kent_reg_moditify_login_key;
	CStatic kent_modify_notice;
	afx_msg void OnBnClickedButtonModify();
};
