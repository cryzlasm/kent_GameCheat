#pragma once

class CmenuDlg : public CDialogEx
{
// Construction
	DECLARE_DYNAMIC(CmenuDlg)
public:
	CmenuDlg(CWnd* pParent = NULL);	// standard constructor
	Kent_log *Kent_log_instance;
	kent_herosDlg kent_herosDlg; 
	Kent_gameDlg kent_gameDlg;
	kent_helpDlg kent_helpDlg;
	kent_studioDlg kent_studioDlg;
	kent_registerDlg kent_registerDlg; 
	int m_CurSelTab; 
	vector<CDialog *> pDialog;//用来保存对话框对象指针
	enum { IDD = IDD_MUNU };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
protected:
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl kent_tab;
	afx_msg void OnTcnSelchangeKentTab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedstart();
	afx_msg void OnBnClickedStore();
	afx_msg void OnBnClickedRestore();
private:
	void kent_store_config();
	void kent_return_config();
	void kent_option_update();
public:
	afx_msg void OnClose();
};
