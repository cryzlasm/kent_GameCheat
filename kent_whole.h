#pragma once
class kent_whole
{
public:
	//����ʱ��ʼ��
	CString kent_root_path;
	CString kent_res_path;
	//�ⲿ����
#ifdef _kent_foreground_
	Cdm_basis *dm;
#elif defined _kent_background_new_
	CTSPlugInterFace *dm;
#elif defined _kent_background_
	Idmsoft *dm;
#endif

public:
	kent_whole(void);
	~kent_whole(void);
	//�ͷ���Դ�ļ�
	BOOL kent_release(void);
	//ע�����
	BOOL RegDll(LPCTSTR file);
	//ϵͳ���
	BOOL Kent_SysCheck(void);
private:
	BOOL Kent_FolderExists(CString s);
	BOOL Kent_CreateDir(CString P);
	BOOL Kent_ExtraceRes_res(DWORD res_id,CString path);
	BOOL Kent_ExtraceRes_bitmap(DWORD res_id,CString path);
};

