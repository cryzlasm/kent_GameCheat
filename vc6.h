#if !defined(AFX_VC6_H__BCCAD622_EDB5_4AC7_85B3_8E2CAADB8842__INCLUDED_)
#define AFX_VC6_H__BCCAD622_EDB5_4AC7_85B3_8E2CAADB8842__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif


class CVc6App : public CWinApp
{
public:
	CVc6App();
	~CVc6App();
	//需要创建
#ifdef _kent_foreground_
	Cdm_basis *dm;
#elif defined _kent_background_new_
	CTSPlugInterFace *dm;
#elif defined _kent_background_
	Idmsoft *dm;
#endif
	ScriptInfo *script_info;
	Kent_log *Kent_log_instance;
// Overrides
	//{{AFX_VIRTUAL(CVc6App)
public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL
// Implementation
	//{{AFX_MSG(CVc6App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#endif // !defined(AFX_VC6_H__BCCAD622_EDB5_4AC7_85B3_8E2CAADB8842__INCLUDED_)
