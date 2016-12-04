#include "stdafx.h"

IMPLEMENT_DYNAMIC(kent_registerDlg, CDialogEx)

kent_registerDlg::kent_registerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(kent_registerDlg::IDD, pParent)
{

}
kent_registerDlg::~kent_registerDlg()
{
}
void kent_registerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_BUY, kent_buy);
	DDX_Control(pDX, IDC_TAB_REG, kent_reg_tab);
}

BEGIN_MESSAGE_MAP(kent_registerDlg, CDialogEx)
ON_BN_CLICKED(IDC_BUTTON_BUY, &kent_registerDlg::OnBnClickedButtonBuy)
ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_REG, &kent_registerDlg::OnTcnSelchangeTabReg)
END_MESSAGE_MAP()

BOOL kent_registerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	kent_buy.SetWindowText(_T("test"));

	kent_buy.ShowWindow(SW_HIDE);
	
	kent_reg_tab.InsertItem(0, _T("用户登录"));
	kent_reg_tab.InsertItem(1, _T("用户注册"));
	kent_reg_tab.InsertItem(2, _T("用户充值"));
	kent_reg_tab.InsertItem(3, _T("密码修改"));
	
	pDialog.push_back(& kent_reg_login);
	pDialog.push_back(& kent_reg_regDlg);
	pDialog.push_back(& kent_reg_rechargeDlg);
	pDialog.push_back(& kent_reg_modifyDlg);
	
	pDialog.at(0)->Create(IDD_REGISTER_LOGIN, &kent_reg_tab);
	pDialog.at(1)->Create(IDD_REGISTER_REG, &kent_reg_tab);
	pDialog.at(2)->Create(IDD_REGISTER_RECHARGE, &kent_reg_tab);
	pDialog.at(3)->Create(IDD_REGISTER_MODIFY, &kent_reg_tab);

	//设定在Tab内显示的范围
	CRect rc;
	kent_reg_tab.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	pDialog.at(0)->MoveWindow(&rc);
	pDialog.at(1)->MoveWindow(&rc);
	pDialog.at(2)->MoveWindow(&rc);
	pDialog.at(3)->MoveWindow(&rc);
	//显示初始页面
	pDialog.at(0)->ShowWindow(SW_SHOW);
	pDialog.at(1)->ShowWindow(SW_HIDE);
	pDialog.at(2)->ShowWindow(SW_HIDE);
	pDialog.at(3)->ShowWindow(SW_HIDE);
	//保存当前选择
	m_CurSelTab = 0;

	return true;
}
void kent_registerDlg::OnBnClickedButtonBuy()
{
	Kent_log_instance->GetNewAccount();
}

void kent_registerDlg::OnTcnSelchangeTabReg(NMHDR *pNMHDR, LRESULT *pResult)
{
    //把当前的页面隐藏起来
    pDialog.at(m_CurSelTab)->ShowWindow(SW_HIDE);
    //得到新的页面索引
    m_CurSelTab = kent_reg_tab.GetCurSel();
    //把新的页面显示出来
    pDialog.at(m_CurSelTab)->ShowWindow(SW_SHOW);
	*pResult = 0;
}


void kent_registerDlg::kent_option_update()
{
	kent_reg_login.kent_option_update();
}
void kent_registerDlg::kent_store_config()
{
	kent_reg_login.kent_store_config();
}
void kent_registerDlg::kent_return_config()
{
	kent_reg_login.kent_return_config();
}