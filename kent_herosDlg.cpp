
#include "stdafx.h"

IMPLEMENT_DYNAMIC(kent_herosDlg, CDialogEx)

kent_herosDlg::kent_herosDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(kent_herosDlg::IDD, pParent)
{

}
kent_herosDlg::~kent_herosDlg()
{
}
void kent_herosDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_HERO_SELECT1, kent_hero_select1);
	DDX_Control(pDX, IDC_EDIT_HERO_SELECT2, kent_hero_select2);
	DDX_Control(pDX, IDC_EDIT_HERO_SELECT3, kent_hero_select3);
	DDX_Control(pDX, IDC_COMBOIDC_HERO_SELECT1, kent_skill_hero_select1);
	DDX_Control(pDX, IDC_COMBOIDC_HERO_SELECT2, kent_skill_hero_select2);
	DDX_Control(pDX, IDC_COMBOIDC_HERO_SELECT3, kent_skill_hero_select3);
	DDX_Control(pDX, IDC_HERO_RND, kent_hero_rand);
	DDX_Control(pDX, IDC_HERO_ALLRND, kent_hero_allrand);
	DDX_Control(pDX, IDC_COMBOIDC_OCCUPY_MODE, kent_hero_occupy_mode);
	DDX_Control(pDX, IDC_CHECK3, kent_hero_occupy_rand_start);
	DDX_Control(pDX, IDC_CHECK4, kent_hero_occupy_rand_die);
	DDX_Control(pDX, IDC_EDIT_DIE_CALL, kent_hero_die_call);
	DDX_Control(pDX, IDC_COMBOIDC_DIE_CALL_CHANCE, kent_hero_die_call_chance);
	DDX_Control(pDX, IDC_HERO_RUIZI, kent_hero_ruizi);
}

BEGIN_MESSAGE_MAP(kent_herosDlg, CDialogEx)

END_MESSAGE_MAP()
BOOL kent_herosDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	kent_hero_occupy_mode.AddString(_T("随机"));
	kent_hero_occupy_mode.AddString(_T("顺时针"));
	kent_hero_occupy_mode.AddString(_T("逆时针"));
	kent_hero_occupy_mode.AddString(_T("守对方塔"));
	kent_hero_die_call_chance.AddString(_T("0%"));
	kent_hero_die_call_chance.AddString(_T("10%"));
	kent_hero_die_call_chance.AddString(_T("20%"));
	kent_hero_die_call_chance.AddString(_T("40%"));
	kent_option_update();
	return true;
}
void kent_herosDlg::kent_option_update()
{
	kent_hero_occupy_mode.SetCurSel(Kent_log_instance->kent_hero_occupy_mode);
	//死后随机模式
	kent_hero_occupy_rand_die.SetCheck(Kent_log_instance->kent_hero_occupy_rand_die);
	//每局随机模式
	kent_hero_occupy_rand_start.SetCheck(Kent_log_instance->kent_hero_occupy_rand_start);
	//随机英雄
	kent_hero_rand.SetCheck(Kent_log_instance->kent_hero_rand);
	kent_hero_allrand.SetCheck(Kent_log_instance->kent_hero_allrand);
	//瑞兹
	kent_hero_ruizi.SetCheck(Kent_log_instance->kent_hero_ruizi);
	//技能设置
	kent_skill_hero_select1.SetCurSel(Kent_log_instance->kent_skill_hero_select.at(0));
	kent_skill_hero_select2.SetCurSel(Kent_log_instance->kent_skill_hero_select.at(1));
	kent_skill_hero_select3.SetCurSel(Kent_log_instance->kent_skill_hero_select.at(2));
	//英雄设置
	kent_hero_select1.SetWindowText(Kent_log_instance->kent_hero_select.at(0));
	kent_hero_select2.SetWindowText(Kent_log_instance->kent_hero_select.at(1));
	kent_hero_select3.SetWindowText(Kent_log_instance->kent_hero_select.at(2));
	//死亡喊话
	kent_hero_die_call_chance.SetCurSel(Kent_log_instance->kent_hero_die_call_chance);
	vector<CString> tmp = Kent_log_instance->kent_split(Kent_log_instance->kent_hero_die_call,_T("|"));
	CString kent_hero_die_call_display=_T("");
	if(tmp.size()){
		vector<CString>::iterator iter = tmp.begin();
		kent_hero_die_call_display += *iter;
		for(iter++;iter != tmp.end(); ++iter)
		{
			kent_hero_die_call_display += _T("\r\n");
			kent_hero_die_call_display += *iter;
		}
	}
	kent_hero_die_call.SetWindowText(kent_hero_die_call_display);//显示多行
}
void kent_herosDlg::kent_store_config()
{
	Kent_log_instance->kent_writeini(_T("kent_hero_occupy_mode"),&kent_hero_occupy_mode);
	Kent_log_instance->kent_writeini(_T("kent_hero_occupy_rand_die"),&kent_hero_occupy_rand_die);
	Kent_log_instance->kent_writeini(_T("kent_hero_occupy_rand_start"),&kent_hero_occupy_rand_start);
	Kent_log_instance->kent_writeini(_T("kent_hero_rand"),&kent_hero_rand);
	Kent_log_instance->kent_writeini(_T("kent_hero_allrand"),&kent_hero_allrand);
	Kent_log_instance->kent_writeini(_T("kent_hero_ruizi"),&kent_hero_ruizi);
	Kent_log_instance->kent_writeini(_T("kent_skill_hero_select1"),&kent_skill_hero_select1);
	Kent_log_instance->kent_writeini(_T("kent_skill_hero_select2"),&kent_skill_hero_select2);
	Kent_log_instance->kent_writeini(_T("kent_skill_hero_select3"),&kent_skill_hero_select3);
	Kent_log_instance->kent_writeini(_T("kent_hero_select1"),&kent_hero_select1);
	Kent_log_instance->kent_writeini(_T("kent_hero_select2"),&kent_hero_select2);
	Kent_log_instance->kent_writeini(_T("kent_hero_select3"),&kent_hero_select3);
	Kent_log_instance->kent_writeini(_T("kent_hero_die_call"),&kent_hero_die_call);
	Kent_log_instance->kent_writeini(_T("kent_hero_die_call_chance"),&kent_hero_die_call_chance);
}
void kent_herosDlg::kent_return_config()
{
	CString tmp;
	Kent_log_instance->kent_hero_occupy_mode		=	(d_occupy_mode)abs(kent_hero_occupy_mode.GetCurSel());
	Kent_log_instance->kent_hero_occupy_rand_die	=	(0 == kent_hero_occupy_rand_die.GetCheck())?false:true;
	Kent_log_instance->kent_hero_occupy_rand_start	=	(0 == kent_hero_occupy_rand_start.GetCheck())?false:true;
	Kent_log_instance->kent_hero_rand				=	(0 == kent_hero_rand.GetCheck())?false:true;
	Kent_log_instance->kent_hero_allrand			=	(0 == kent_hero_allrand.GetCheck())?false:true;
	Kent_log_instance->kent_hero_ruizi				=	(0 == kent_hero_ruizi.GetCheck())?false:true;
	Kent_log_instance->kent_skill_hero_select.at(0)	=	abs(kent_skill_hero_select1.GetCurSel());
	Kent_log_instance->kent_skill_hero_select.at(1)	=	abs(kent_skill_hero_select2.GetCurSel());
	Kent_log_instance->kent_skill_hero_select.at(2)	=	abs(kent_skill_hero_select3.GetCurSel());
	kent_hero_select1.GetWindowText(tmp);
	Kent_log_instance->kent_hero_select.at(0)		=	tmp;
	kent_hero_select2.GetWindowText(tmp);
	Kent_log_instance->kent_hero_select.at(1)		=	tmp;
	kent_hero_select3.GetWindowText(tmp);
	Kent_log_instance->kent_hero_select.at(2)		=	tmp;
	kent_hero_die_call.GetWindowText(tmp);
	vector<CString> get_tmp = Kent_log_instance->kent_split(tmp,_T("\r\n"));
	CString out_str = _T("");
	if(get_tmp.size()){
		vector<CString>::iterator iter = get_tmp.begin();
		out_str = *iter;
		for(iter++;iter != get_tmp.end();iter++)
		{
			out_str += _T("|");
			out_str += *iter;
		}
	}
	Kent_log_instance->kent_hero_die_call			=	out_str;
	Kent_log_instance->kent_hero_die_call_chance	=	(d_die_call_chance)abs(kent_hero_die_call_chance.GetCurSel());
}