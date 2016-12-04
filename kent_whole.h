#pragma once
class kent_whole
{
public:
	//创建时初始化
	CString kent_root_path;
	CString kent_res_path;
	//外部传入
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
	//释放资源文件
	BOOL kent_release(void);
	//注册组件
	BOOL RegDll(LPCTSTR file);
	//系统检查
	BOOL Kent_SysCheck(void);
private:
	BOOL Kent_FolderExists(CString s);
	BOOL Kent_CreateDir(CString P);
	BOOL Kent_ExtraceRes_res(DWORD res_id,CString path);
	BOOL Kent_ExtraceRes_bitmap(DWORD res_id,CString path);
};

