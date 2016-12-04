#pragma once
#include "afxwin.h"


// kent_studioDlg dialog

class kent_studioDlg : public CDialogEx
{
	DECLARE_DYNAMIC(kent_studioDlg)

public:
	kent_studioDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~kent_studioDlg();

// Dialog Data
	enum { IDD = IDD_STUDIO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	Kent_log *Kent_log_instance;
	CStatic kent_studio_now_stage;
	CStatic kent_studio_now_ip;
	CEdit kent_studio_stop_ip;
	CEdit kent_studio_stop_stage;

	//连接
	CEdit kent_studio_ip_adr;
	CEdit kent_studio_port;
	CStatic kent_studio_connect_state;
	
	//答题
	CComboBox kent_identify_choose;
	CButton kent_identify_reg;
	//顺义答题
	CEdit kent_identify_sydt_code;
	//打码兔
	CEdit kent_studio_dama2_user;
	CEdit kent_studio_dama2_key;
	CStatic kent_studio_dama2_user_text;
	CStatic kent_studio_dama2_key_text;
	//UU云
	CStatic kent_studio_uuwise_user_text;
	CStatic kent_studio_uuwise_key_text;
	CEdit kent_studio_uuwise_key;
	CEdit kent_studio_uuwise_user;
	
public:
	afx_msg void OnBnClickedButtonRegIdentify();
	afx_msg void OnCbnSelchangeComboIdentify();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
	void kent_store_config();
	void kent_return_config();
	void kent_option_update();
	CButton kent_studio_finish_enable;
	CComboBox kent_game_resolution;
	CButton kent_force_downcpu;
	CButton kent_change_task;
	CEdit kent_change_task_time;
	CEdit kent_change_task_num;
	CButton kent_autorun;
};
