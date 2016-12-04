// Kent_forever.cpp : implementation file
//

#include "stdafx.h"
#include "Kent_forever.h"
#include "afxdialogex.h"

#define WM_SHOWTASK_EVER (WM_USER+1001)

// Kent_forever dialog

IMPLEMENT_DYNAMIC(Kent_forever, CDialogEx)
Kent_forever::Kent_forever(CWnd* pParent /*=NULL*/)
	: CDialogEx(Kent_forever::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_EVER);
}
Kent_forever::~Kent_forever()
{
}
void Kent_forever::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_REG, m_EverReg);
	DDX_Control(pDX, IDC_EDIT_QQ_NUM_EVER, kent_reconnect_qq_num);
	DDX_Control(pDX, IDC_EDIT_QQ_KEY_EVER, kent_reconnect_qq_password);
	DDX_Control(pDX, IDC_COMBO_QQ_AREA_EVER, kent_reconnect_qq_area);
	DDX_Control(pDX, IDC_CHECK_RECONNECT_EVER, kent_reconnect_normal);
	DDX_Control(pDX, IDC_EDIT_HERO_SELECT_EVER1, kent_hero_select1);
	DDX_Control(pDX, IDC_EDIT_HERO_SELECT_EVER2, kent_hero_select2);
	DDX_Control(pDX, IDC_EDIT_HERO_SELECT_EVER3, kent_hero_select3);
	DDX_Control(pDX, IDC_HERO_RND_EVER, kent_hero_rand);
	DDX_Control(pDX, IDC_HERO_RUIZI_EVER, kent_hero_ruizi);
	DDX_Control(pDX, IDC_COMBOIDC_MATCH_MODE_EVER, kent_game_match_mode);
}

BEGIN_MESSAGE_MAP(Kent_forever, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_REG, &Kent_forever::OnTcnSelchangeTabReg)
	ON_BN_CLICKED(IDC_BUTTON_HELP, &Kent_forever::OnBnClickedButtonHelp)
	ON_BN_CLICKED(IDC_BUTTON_STORE_EVER, &Kent_forever::OnBnClickedButtonStoreEver)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL_EVER, &Kent_forever::OnBnClickedButtonCancelEver)
	ON_WM_CLOSE()
END_MESSAGE_MAP()
// Kent_forever message handlers
BOOL Kent_forever::OnInitDialog()
{
	CDialog::OnInitDialog();
	/*****************图标设置*****************/
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	/*****************标题设置*****************/

	CString Text;
	GetPrivateProfileString(_T("MAIN"),_T("Text"),_T(""),Text.GetBuffer(200),200,Kent_log_instance->kent_root_path+_T("\\config.ini"));
	Text.ReleaseBuffer();

	SetWindowText(Text+Kent_log_instance->kent_version);

	m_EverReg.InsertItem(0, _T("用户登录"));
	m_EverReg.InsertItem(1, _T("用户注册"));
	m_EverReg.InsertItem(2, _T("密码修改"));

	pDialog.push_back(& kent_reg_login_ever);
	pDialog.push_back(& kent_reg_reg_everDlg);
	//pDialog.push_back(& kent_reg_recharge_everDlg);
	pDialog.push_back(& kent_reg_modify_everDlg);

	pDialog.at(0)->Create(IDD_REGISTER_LOGIN_EVER, &m_EverReg);
	pDialog.at(1)->Create(IDD_REGISTER_REG_EVER, &m_EverReg);
	//pDialog.at(2)->Create(IDD_REGISTER_RECHARGE_EVER, &m_EverReg);
	pDialog.at(2)->Create(IDD_REGISTER_MODIFY_EVER, &m_EverReg);

	//设定在Tab内显示的范围
	CRect rc;
	m_EverReg.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	pDialog.at(0)->MoveWindow(&rc);
	pDialog.at(1)->MoveWindow(&rc);
	pDialog.at(2)->MoveWindow(&rc);
	//显示初始页面
	pDialog.at(0)->ShowWindow(SW_SHOW);
	pDialog.at(1)->ShowWindow(SW_HIDE);
	pDialog.at(2)->ShowWindow(SW_HIDE);
	//保存当前选择
	m_CurSelTab = 0;

	kent_game_match_mode.AddString(_T("统治战场匹配(0-7级召唤师峡谷)"));
#ifdef Distort_forever
	kent_game_match_mode.AddString(_T("扭曲丛林(0-7级召唤师峡谷)"));
#elif defined Dominate_forever

#else
	kent_game_match_mode.AddString(_T("召唤师峡谷简单人机"));
	kent_game_match_mode.AddString(_T("召唤师峡谷一般人机"));
	kent_game_match_mode.AddString(_T("扭曲丛林匹配"));
	kent_game_match_mode.AddString(_T("极地大乱斗匹配"));
	kent_game_match_mode.AddString(_T("随机选择(不包括大乱斗)"));
#endif

	kent_reconnect_qq_area.AddString(_T("上次登录大区"));

	kent_reconnect_qq_area.AddString(_T("艾欧尼亚"));
	kent_reconnect_qq_area.AddString(_T("祖安"));
	kent_reconnect_qq_area.AddString(_T("诺克萨斯"));
	kent_reconnect_qq_area.AddString(_T("班德尔城"));
	kent_reconnect_qq_area.AddString(_T("皮尔特若夫"));
	
	kent_reconnect_qq_area.AddString(_T("战争学院"));
	kent_reconnect_qq_area.AddString(_T("巨神峰"));
	kent_reconnect_qq_area.AddString(_T("雷瑟守备"));
	kent_reconnect_qq_area.AddString(_T("钢铁烈阳"));
	kent_reconnect_qq_area.AddString(_T("裁决之地"));

	kent_reconnect_qq_area.AddString(_T("黑色玫瑰"));
	kent_reconnect_qq_area.AddString(_T("暗影岛"));
	kent_reconnect_qq_area.AddString(_T("均衡教派"));
	kent_reconnect_qq_area.AddString(_T("水晶之痕"));
	kent_reconnect_qq_area.AddString(_T("影流"));

	kent_reconnect_qq_area.AddString(_T("守望之海"));
	kent_reconnect_qq_area.AddString(_T("征服之海"));
	kent_reconnect_qq_area.AddString(_T("卡拉曼达"));
	kent_reconnect_qq_area.AddString(_T("皮城戒备"));
	kent_reconnect_qq_area.AddString(_T("皮尔特若夫"));

	kent_reconnect_qq_area.AddString(_T("比尔吉沃特"));
	kent_reconnect_qq_area.AddString(_T("德玛西亚"));
	kent_reconnect_qq_area.AddString(_T("弗雷尔卓德"));
	kent_reconnect_qq_area.AddString(_T("无畏先锋"));
	kent_reconnect_qq_area.AddString(_T("恕瑞玛"));
	
	kent_reconnect_qq_area.AddString(_T("扭曲丛林"));
	kent_reconnect_qq_area.AddString(_T("巨龙之巢"));
	kent_reconnect_qq_area.AddString(_T("教育网专区"));

	kent_reconnect_qq_area.SetCurSel(0);

	kent_option_update();//显示设置
	return TRUE;  // return TRUE  unless you set the focus to a control
}
void Kent_forever::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}
HCURSOR Kent_forever::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void Kent_forever::OnDestroy()
{
	CDialog::OnDestroy();
}
void Kent_forever::OnTcnSelchangeTabReg(NMHDR *pNMHDR, LRESULT *pResult)
{
    //把当前的页面隐藏起来
    pDialog.at(m_CurSelTab)->ShowWindow(SW_HIDE);
    //得到新的页面索引
    m_CurSelTab = m_EverReg.GetCurSel();
    //把新的页面显示出来
    pDialog.at(m_CurSelTab)->ShowWindow(SW_SHOW);
	*pResult = 0;
}
void Kent_forever::kent_store_config()
{
	Kent_log_instance->kent_writeini(_T("kent_game_match_mode"),match_mode_EverToNormal(kent_game_match_mode.GetCurSel()));
	Kent_log_instance->kent_writeini(_T("kent_hero_rand"),&kent_hero_rand);
	Kent_log_instance->kent_writeini(_T("kent_hero_ruizi"),&kent_hero_ruizi);
	Kent_log_instance->kent_writeini(_T("kent_hero_select1"),&kent_hero_select1);
	Kent_log_instance->kent_writeini(_T("kent_hero_select2"),&kent_hero_select2);
	Kent_log_instance->kent_writeini(_T("kent_hero_select3"),&kent_hero_select3);
	Kent_log_instance->kent_writeini(_T("kent_reconnect_normal"),&kent_reconnect_normal);
	Kent_log_instance->kent_writeini(_T("kent_reconnect_qq_num"),&kent_reconnect_qq_num);
	Kent_log_instance->kent_writeini(_T("kent_reconnect_qq_password"),&kent_reconnect_qq_password);
	CString tmp;
	kent_reconnect_qq_area.GetWindowText(tmp);
	Kent_log_instance->kent_writeini(_T("kent_reconnect_qq_area"),tmp);

}
void Kent_forever::kent_return_config()
{
	CString tmp;
	Kent_log_instance->kent_game_match_mode		=	(d_match_mode)abs(match_mode_EverToNormal(kent_game_match_mode.GetCurSel()));
	Kent_log_instance->kent_hero_rand				=	(0 == kent_hero_rand.GetCheck())?false:true;
	Kent_log_instance->kent_hero_ruizi				=	(0 == kent_hero_ruizi.GetCheck())?false:true;
	kent_hero_select1.GetWindowText(tmp);
	Kent_log_instance->kent_hero_select.at(0)		=	tmp;
	kent_hero_select2.GetWindowText(tmp);
	Kent_log_instance->kent_hero_select.at(1)		=	tmp;
	kent_hero_select3.GetWindowText(tmp);
	Kent_log_instance->kent_hero_select.at(2)		=	tmp;
	Kent_log_instance->kent_reconnect_normal		=	(0 == kent_reconnect_normal.GetCheck())?false:true;
	kent_reconnect_qq_num.GetWindowText(tmp);
	Kent_log_instance->kent_reconnect_qq_num		=	tmp;
	kent_reconnect_qq_password.GetWindowText(tmp);
	Kent_log_instance->kent_reconnect_qq_password	=	tmp;
	kent_reconnect_qq_area.GetWindowText(tmp);
	Kent_log_instance->kent_reconnect_qq_area	=	tmp;
}
void Kent_forever::kent_option_update()
{
	kent_game_match_mode.SetCurSel(match_mode_NormalToEver(Kent_log_instance->kent_game_match_mode));
	//随机英雄
	kent_hero_rand.SetCheck(Kent_log_instance->kent_hero_rand);
	//瑞兹
	kent_hero_ruizi.SetCheck(Kent_log_instance->kent_hero_ruizi);
	//英雄设置
	kent_hero_select1.SetWindowText(Kent_log_instance->kent_hero_select.at(0));
	kent_hero_select2.SetWindowText(Kent_log_instance->kent_hero_select.at(1));
	kent_hero_select3.SetWindowText(Kent_log_instance->kent_hero_select.at(2));

	kent_reconnect_normal.SetCheck(Kent_log_instance->kent_reconnect_normal);
	kent_reconnect_qq_num.SetWindowText(Kent_log_instance->kent_reconnect_qq_num);
	kent_reconnect_qq_password.SetWindowText(Kent_log_instance->kent_reconnect_qq_password);
	kent_reconnect_qq_area.SetWindowText(Kent_log_instance->kent_reconnect_qq_area);

	
	kent_reg_login_ever.kent_reg_login_user.SetWindowText(Kent_log_instance->kent_reg_login_user);
	kent_reg_login_ever.kent_reg_login_key.SetWindowText(Kent_log_instance->kent_reg_login_key);
}
d_match_mode Kent_forever::match_mode_EverToNormal(int Ever)
{
#ifdef Distort_forever
	switch(Ever){
	case 0:return match_mode_common;//
	case 1:return match_mode_Distort;//
	default:return match_mode_Distort;
	}
#elif defined Dominate_forever
	return match_mode_common;//
#else
	switch(Ever){
	case 0:return match_mode_common;//
	case 1:return match_mode_normal_machine;//
	case 2:return match_mode_normal_machine_hard;//
	case 3:return match_mode_Distort;//
	case 4:return match_mode_Colosseum;//
	case 5:return match_mode_Random;//
	default:return match_mode_Random;
	}
#endif
}
int Kent_forever::match_mode_NormalToEver(d_match_mode Normal)
{
#ifdef Distort_forever
	switch(Normal){
	case match_mode_common:return 0;//
	case match_mode_Distort:return 1;//
	default:return 1;
	}
#elif defined Dominate_forever
	return 0;//
#else
	switch(Normal){
	case match_mode_common:return 0;//
	case match_mode_normal_machine:return 1;//
	case match_mode_normal_machine_hard:return 2;//
	case match_mode_Distort:return 3;//
	case match_mode_Colosseum:return 4;//
	case match_mode_Random:return 5;//
	default:return 5;
	}
#endif
}
void Kent_forever::OnBnClickedButtonHelp()
{
	ShellExecute(NULL,_T("open"),_T("使用前必读.txt"),NULL,NULL,SW_SHOWNORMAL);
}
void Kent_forever::OnBnClickedButtonStoreEver()
{
	// TODO: Add your control notification handler code here
	kent_store_config();
	kent_return_config();
	CDialogEx::OnOK();
}
void Kent_forever::OnBnClickedButtonCancelEver()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
void Kent_forever::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	kent_store_config();
	kent_return_config();

	CDialogEx::OnClose();
}
