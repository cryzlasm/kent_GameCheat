#pragma once
#include "afxcmn.h"


class kent_registerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(kent_registerDlg)

public:
	kent_registerDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~kent_registerDlg();
	virtual BOOL OnInitDialog();
	Kent_log *Kent_log_instance;

	enum { IDD = IDD_REGISTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBuy();
	CButton kent_buy;
	CTabCtrl kent_reg_tab;
	kent_reg_login kent_reg_login;
	kent_reg_modifyDlg kent_reg_modifyDlg;
	kent_reg_rechargeDlg kent_reg_rechargeDlg;
	kent_reg_regDlg kent_reg_regDlg;
public:
	int m_CurSelTab; 
	vector<CDialog *> pDialog;//用来保存对话框对象指针
	afx_msg void OnTcnSelchangeTabReg(NMHDR *pNMHDR, LRESULT *pResult);
	void kent_store_config();
	void kent_option_update();
	void kent_return_config();
};
