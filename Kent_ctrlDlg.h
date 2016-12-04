#pragma once

class Kent_ctrlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(Kent_ctrlDlg)
public:
	Kent_ctrlDlg(CWnd* pParent = NULL);   // standard constructor
	~Kent_ctrlDlg(void);
	//外部传入
	ScriptInfo *script_info;
	Kent_log *Kent_log_instance;
// Dialog Data
	enum { IDD = IDD_DIALOG_CTRL };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	HICON m_hIcon;
	NOTIFYICONDATA m_nid;
	LRESULT OnShowTask(WPARAM wParam, LPARAM lParam);//托盘消息声明
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnCancel();
	afx_msg void OnClose();
	afx_msg void OnOK();
	afx_msg void OnBnClickedButtonMenu();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
	afx_msg LRESULT OnHotKey(WPARAM wParam,LPARAM lParam);//快捷键
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void kent_tips(CString Info);//托盘提示

	afx_msg void OnTimer(UINT_PTR nIDEvent);

};
