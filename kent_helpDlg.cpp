
#include "stdafx.h"


IMPLEMENT_DYNAMIC(kent_helpDlg, CDialogEx)

kent_helpDlg::kent_helpDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(kent_helpDlg::IDD, pParent)
{
}
kent_helpDlg::~kent_helpDlg()
{
}
void kent_helpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, kent_help_str);
}
BEGIN_MESSAGE_MAP(kent_helpDlg, CDialogEx)

END_MESSAGE_MAP()
BOOL kent_helpDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CString str_help;

#ifdef lol_home_background
	str_help=_T("TIMO������ǿ�棨֧�ֺ�̨��\r\n");
	str_help+=_T("TIMO�����������Ⱥ��127559445\r\n");
	str_help+=_T("TIMO����VIP�ۺ�2Ⱥ��231965630�����������Ǻ�������ע�Ա����ּ�Ⱥ������ܾ���\r\n");
	str_help+=_T("���ڲ���ʱ�����ۺ�Ⱥ���汾���±���ţ�������ге���\r\n");
#endif
#ifdef lol_home_foreground
	str_help=_T("TIMO���������棨��֧�ֺ�̨��\r\n");
	str_help+=_T("TIMO�����������Ⱥ��127559445\r\n");
	str_help+=_T("TIMO����VIP�ۺ�2Ⱥ��231965630�����������Ǻ�������ע�Ա����ּ�Ⱥ������ܾ���\r\n");
	str_help+=_T("���ڲ���ʱ�����ۺ�Ⱥ���汾���±���ţ�������ге���\r\n");
#endif
#if defined lol_home_foreground || defined lol_home_background
	str_help+=_T("ȫ�²���C++ƽ̨�����������ȶ���ȫ.\r\n");
	str_help+=_T("�Ӵ��������Ӧ�ã����ⱻ��Ϊ���.\r\n");
	str_help+=_T("��ǿ�����ȫ�º�̨�һ������ÿ���ĵȴ���\r\n\r\n");
#endif
#ifdef kent_background
	str_help=_T("kent����(��ǿ�棬���Ժ�̨)\r\n");
	str_help+=_T("�ۺ�Ⱥ��361989735(��ע���Լ��������˺��Լ��Ƿ����������ܾ���)\r\n");
	str_help+=_T("kent����Ⱥ4��109555078\r\n\r\n");
#endif

#ifdef kent_foreground
	str_help=_T("kent����(�����棬���ܺ�̨)\r\n");
	str_help+=_T("�ۺ�Ⱥ��361989735(��ע���Լ��������˺��Լ��Ƿ����������ܾ���)\r\n");
	str_help+=_T("kent����Ⱥ4��109555078\r\n\r\n");
#endif
	str_help+=_T("��ǿ��ͻ����������:\r\n");
	str_help+=_T("1����ǿ���ȡ�����ں˼���������������Ӱ�ȫ��\r\n");
	str_help+=_T("2�������ṩ��̨����֧�֣������ڵ���Ϸ���棬���������£�\r\n\r\n");
	
	str_help+=_T("ʹ�÷���:\r\n");
	str_help+=_T("1��ע���˺ţ���ע���˺ż���1Сʱ���ã�\r\n");
	str_help+=_T("2����¼�˺�\r\n");
	str_help+=_T("3������Ϸ������Ϸ����\r\n");
	str_help+=_T("4�������ʼ\r\n");
	str_help+=_T("5�������ֵ�����������˻���ֵ��Ӧ������\r\n");


#ifdef kent_han
	str_help = _T("");
#endif

	kent_help_str.SetWindowText(str_help);
	kent_option_update();
	return true;
}
void kent_helpDlg::kent_option_update()
{
	return;
}
void kent_helpDlg::kent_store_config()
{
	return;
}
void kent_helpDlg::kent_return_config()
{
	return;
}
