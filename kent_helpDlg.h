#pragma once


class kent_helpDlg : public CDialogEx
{
	DECLARE_DYNAMIC(kent_helpDlg)

public:
	kent_helpDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~kent_helpDlg();
	virtual BOOL OnInitDialog();
// Dialog Data
	enum { IDD = IDD_HELP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	Kent_log *Kent_log_instance;
	CEdit kent_help_str;
public:
	void kent_store_config();
	void kent_return_config();
	void kent_option_update();
};
