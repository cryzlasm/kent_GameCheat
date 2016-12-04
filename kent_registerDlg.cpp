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
	
	kent_reg_tab.InsertItem(0, _T("�û���¼"));
	kent_reg_tab.InsertItem(1, _T("�û�ע��"));
	kent_reg_tab.InsertItem(2, _T("�û���ֵ"));
	kent_reg_tab.InsertItem(3, _T("�����޸�"));
	
	pDialog.push_back(& kent_reg_login);
	pDialog.push_back(& kent_reg_regDlg);
	pDialog.push_back(& kent_reg_rechargeDlg);
	pDialog.push_back(& kent_reg_modifyDlg);
	
	pDialog.at(0)->Create(IDD_REGISTER_LOGIN, &kent_reg_tab);
	pDialog.at(1)->Create(IDD_REGISTER_REG, &kent_reg_tab);
	pDialog.at(2)->Create(IDD_REGISTER_RECHARGE, &kent_reg_tab);
	pDialog.at(3)->Create(IDD_REGISTER_MODIFY, &kent_reg_tab);

	//�趨��Tab����ʾ�ķ�Χ
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
	//��ʾ��ʼҳ��
	pDialog.at(0)->ShowWindow(SW_SHOW);
	pDialog.at(1)->ShowWindow(SW_HIDE);
	pDialog.at(2)->ShowWindow(SW_HIDE);
	pDialog.at(3)->ShowWindow(SW_HIDE);
	//���浱ǰѡ��
	m_CurSelTab = 0;

	return true;
}
void kent_registerDlg::OnBnClickedButtonBuy()
{
	Kent_log_instance->GetNewAccount();
}

void kent_registerDlg::OnTcnSelchangeTabReg(NMHDR *pNMHDR, LRESULT *pResult)
{
    //�ѵ�ǰ��ҳ����������
    pDialog.at(m_CurSelTab)->ShowWindow(SW_HIDE);
    //�õ��µ�ҳ������
    m_CurSelTab = kent_reg_tab.GetCurSel();
    //���µ�ҳ����ʾ����
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