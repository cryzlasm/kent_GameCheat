// vc6Dlg.cpp : implementation file
//
#include "stdafx.h"
#include "menuDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CmenuDlg, CDialogEx)

CmenuDlg::CmenuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmenuDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
void CmenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_KENT_TAB, kent_tab);
}

BEGIN_MESSAGE_MAP(CmenuDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_NOTIFY(TCN_SELCHANGE, IDC_KENT_TAB, &CmenuDlg::OnTcnSelchangeKentTab)
	ON_BN_CLICKED(IDC_STORE, &CmenuDlg::OnBnClickedStore)
	ON_BN_CLICKED(IDC_RESTORE, &CmenuDlg::OnBnClickedRestore)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

BOOL CmenuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	/*****************图标设置*****************/
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	/*****************选项卡设置*****************/
	//为Tab Control增加两个页面

	kent_tab.InsertItem(0, _T("用户系统"));

	CString Text;
	GetPrivateProfileString(_T("MAIN"),_T("Text"),_T(""),Text.GetBuffer(200),200,Kent_log_instance->kent_root_path+_T("\\config.ini"));
	Text.ReleaseBuffer();

	SetWindowText(Text+Kent_log_instance->kent_version);

	kent_tab.InsertItem(1, _T("英雄设置"));
	kent_tab.InsertItem(2, _T("游戏设置"));
	kent_tab.InsertItem(3, _T("高级设置"));
	//kent_tab.InsertItem(4, _T("使用说明"));

	//创建对话框
	pDialog.push_back(& kent_registerDlg);
	pDialog.push_back(& kent_herosDlg);
	pDialog.push_back(& kent_gameDlg);
	pDialog.push_back(& kent_studioDlg);
	//pDialog.push_back(& kent_helpDlg);
	pDialog.at(0)->Create(IDD_REGISTER, &kent_tab);
	pDialog.at(1)->Create(IDD_HEROS, &kent_tab);
	pDialog.at(2)->Create(IDD_GAME, &kent_tab);
	pDialog.at(3)->Create(IDD_STUDIO, &kent_tab);
	//pDialog.at(4)->Create(IDD_HELP, &kent_tab);
	//设定在Tab内显示的范围
	CRect rc;
	kent_tab.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	pDialog.at(0)->MoveWindow(&rc);
	pDialog.at(1)->MoveWindow(&rc);
	pDialog.at(2)->MoveWindow(&rc);
	pDialog.at(3)->MoveWindow(&rc);
	//pDialog.at(4)->MoveWindow(&rc);
	//显示初始页面
	pDialog.at(0)->ShowWindow(SW_SHOW);
	pDialog.at(1)->ShowWindow(SW_HIDE);
	pDialog.at(2)->ShowWindow(SW_HIDE);
	pDialog.at(3)->ShowWindow(SW_HIDE);
	//pDialog.at(4)->ShowWindow(SW_HIDE);
	//保存当前选择
	m_CurSelTab = 0;
	//Kent_log_instance->option_init();//参数初始化

	return TRUE;  // return TRUE  unless you set the focus to a control
}
void CmenuDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}
HCURSOR CmenuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
LRESULT CmenuDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if (message == WM_CLOSE)
    {
        EndDialog(0);
    }
	return CDialog::WindowProc(message, wParam, lParam);
}
void CmenuDlg::OnTcnSelchangeKentTab(NMHDR *pNMHDR, LRESULT *pResult)
{
    //把当前的页面隐藏起来
    pDialog.at(m_CurSelTab)->ShowWindow(SW_HIDE);
    //得到新的页面索引
    m_CurSelTab = kent_tab.GetCurSel();
    //把新的页面显示出来
    pDialog.at(m_CurSelTab)->ShowWindow(SW_SHOW);
	*pResult = 0;
}
void CmenuDlg::OnBnClickedStore()
{
	kent_store_config();
	kent_return_config();

	Kent_log_instance->SetAutoRun(Kent_log_instance->kent_autorun);//设置开机自启动

	CmenuDlg::OnOK();
}
void CmenuDlg::OnBnClickedRestore()
{
	Kent_log_instance->option_init();//初始化
	kent_option_update();//更新对话框
	kent_store_config();//存储设置信息
}
void CmenuDlg::kent_option_update()
{
	kent_registerDlg.kent_option_update();
	kent_herosDlg.kent_option_update();
	kent_gameDlg.kent_option_update();
	kent_helpDlg.kent_option_update();
	kent_studioDlg.kent_option_update();
}
void CmenuDlg::kent_store_config()
{
	kent_registerDlg.kent_store_config();
	kent_herosDlg.kent_store_config();
	kent_gameDlg.kent_store_config();
	kent_helpDlg.kent_store_config();
	kent_studioDlg.kent_store_config();
}
void CmenuDlg::kent_return_config()
{
	kent_registerDlg.kent_return_config();
	kent_herosDlg.kent_return_config();
	kent_gameDlg.kent_return_config();
	kent_helpDlg.kent_return_config();
	kent_studioDlg.kent_return_config();
}
void CmenuDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnClose();
}
