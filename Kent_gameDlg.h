#pragma once
#include "afxwin.h"

class Kent_gameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(Kent_gameDlg)

public:
	Kent_gameDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~Kent_gameDlg();
	virtual BOOL OnInitDialog();
	enum { IDD = IDD_GAME };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	Kent_log *Kent_log_instance;
	CComboBox kent_game_match_mode;
	CComboBox kent_hook_mode;
	CComboBox kent_bind_mode;
	CButton kent_reconnect_normal;
	CButton kent_reconnect_fast;
	CEdit kent_reconnect_qq_num;
	CEdit kent_reconnect_qq_password;
public:
	void kent_store_config();
	void kent_return_config();
	void kent_option_update();
	CEdit kent_shutdown_hour;
	CButton kent_shutdown;
	CComboBox kent_reconnect_qq_area;
	CButton kent_nextstop;
	CButton kent_nextshutdown;
	CStatic kent_reconnect_qq_area_text;
};
