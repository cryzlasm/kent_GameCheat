#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// Kent_forever dialog

class Kent_forever : public CDialogEx
{
	DECLARE_DYNAMIC(Kent_forever)

public:
	Kent_forever(CWnd* pParent = NULL);   // standard constructor
	virtual ~Kent_forever();
	
	ScriptInfo *script_info;
	Kent_log *Kent_log_instance;
// Dialog Data
	enum { IDD = IDD_DIALOG_FOREVER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	HICON m_hIcon;
	NOTIFYICONDATA m_nid;
	LRESULT OnShowTask(WPARAM wParam, LPARAM lParam);//托盘消息声明
	virtual BOOL OnInitDialog();

	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();

	CTabCtrl m_EverReg;
	int m_CurSelTab;
	vector<CDialog *> pDialog;//用来保存对话框对象指针
	kent_reg_login_ever kent_reg_login_ever;
	kent_reg_modify_everDlg kent_reg_modify_everDlg;
	kent_reg_recharge_everDlg kent_reg_recharge_everDlg;
	kent_reg_reg_everDlg kent_reg_reg_everDlg;
	afx_msg void OnTcnSelchangeTabReg(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit kent_reconnect_qq_num;
	CEdit kent_reconnect_qq_password;
	CComboBox kent_reconnect_qq_area;
	CButton kent_reconnect_normal;
	CEdit kent_hero_select1;
	CEdit kent_hero_select2;
	CEdit kent_hero_select3;
	CButton kent_hero_rand;
	CButton kent_hero_ruizi;
	CComboBox kent_game_match_mode;
	
	void kent_store_config();
	void kent_return_config();
	void kent_option_update();
	int match_mode_NormalToEver(d_match_mode Normal);
	d_match_mode match_mode_EverToNormal(int Ever);
	afx_msg void OnBnClickedButtonHelp();
	afx_msg void OnBnClickedButtonStoreEver();
	afx_msg void OnBnClickedButtonCancelEver();
	afx_msg void OnClose();
};
