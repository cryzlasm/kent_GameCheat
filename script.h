#pragma once

class ScriptInfo
{
public:
	kent_windows *kent_windows_instance;
	HANDLE thread_handle;    // �߳̾��
	bool  is_run;           // �߳̽�����־
	//�ⲿ����
#ifdef _kent_foreground_
	Cdm_basis *dm;
#elif defined _kent_background_new_
	CTSPlugInterFace *dm;
#elif defined _kent_background_
	Idmsoft *dm;
#endif
	Kent_log *Kent_log_instance;
	ScriptInfo(void);
	~ScriptInfo(void);
	bool StartScript(void);
	bool StopScript(void);
	void script_main(void);
	bool Kent_SysCheck(void);
	void open_dmguard();
	bool is_dmguard;
};