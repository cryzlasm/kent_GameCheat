#pragma once
#include "afxwin.h"

class kent_herosDlg : public CDialogEx
{
	DECLARE_DYNAMIC(kent_herosDlg)

public:
	kent_herosDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~kent_herosDlg();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_HEROS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	Kent_log *Kent_log_instance;
	CEdit kent_hero_select1;
	CEdit kent_hero_select2;
	CEdit kent_hero_select3;
	CComboBox kent_skill_hero_select1;
	CComboBox kent_skill_hero_select2;
	CComboBox kent_skill_hero_select3;
	CButton kent_hero_rand;
	CButton kent_hero_allrand;
	CComboBox kent_hero_occupy_mode;
	CButton kent_hero_occupy_rand_start;
	CButton kent_hero_occupy_rand_die;
	CEdit kent_hero_die_call;
	CComboBox kent_hero_die_call_chance;
public:
	void kent_store_config();
	void kent_return_config();
	void kent_option_update();
	CButton kent_hero_ruizi;
};
