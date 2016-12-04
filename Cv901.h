// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard
#pragma once
// Cv901 wrapper class

class Cv901 : public COleDispatchDriver
{
public:
	Cv901(){} // Calls COleDispatchDriver default constructor
	Cv901(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Cv901(const Cv901& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// Iv901 methods
public:
	void ks_setLicense(LPCTSTR v_licensestr)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, v_licensestr);
	}
	void ks_setExtVal(long v_language, LPCTSTR v_pcsn, LPCTSTR v_ininame, long v_contime, long v_is2svr, LPCTSTR v_rsaMod, LPCTSTR v_rsaPubKey, LPCTSTR Param8, LPCTSTR Param9, LPCTSTR v_callbackfun)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, parms, v_language, v_pcsn, v_ininame, v_contime, v_is2svr, v_rsaMod, v_rsaPubKey, Param8, Param9, v_callbackfun);
	}
	void ks_setSoftVal(long v_softcode, LPCTSTR v_softkey)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR;
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, v_softcode, v_softkey);
	}
	void ks_setUserVal(long v_clientid, LPCTSTR v_username, LPCTSTR v_password, LPCTSTR v_bdinfo)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, v_clientid, v_username, v_password, v_bdinfo);
	}
	void ks_setUpVal(long v_softHwnd, long v_softVersion, long v_chkupdate)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0xcd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, v_softHwnd, v_softVersion, v_chkupdate);
	}
	CString ks_IdCheck(LPCTSTR v_signA, long v_iscon)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_I4;
		InvokeHelper(0xce, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, v_signA, v_iscon);
		return result;
	}
	CString ks_GetData(long v_index)
	{
		CString result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xcf, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, v_index);
		return result;
	}
	CString ks_GetMsg(LPCTSTR v_index)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xd0, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, v_index);
		return result;
	}
	CString ks_advapi(LPCTSTR v_expression)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xd1, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, v_expression);
		return result;
	}
	void ks_advapifree(LPCTSTR v_expression)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xd2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, v_expression);
	}
	CString ks_reguser(long v_softcode, LPCTSTR v_username, LPCTSTR v_password, LPCTSTR v_safepassword, LPCTSTR v_keynum, LPCTSTR v_bdinfo, LPCTSTR v_puser)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0xd3, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, v_softcode, v_username, v_password, v_safepassword, v_keynum, v_bdinfo, v_puser);
		return result;
	}
	CString ks_prepaid(long v_softcode, LPCTSTR v_username, LPCTSTR v_keynum)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR;
		InvokeHelper(0xd4, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, v_softcode, v_username, v_keynum);
		return result;
	}
	CString ks_edit(long v_softcode, LPCTSTR v_username, LPCTSTR v_safepassword, LPCTSTR v_newpassword, LPCTSTR v_bdinfo)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0xd5, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, v_softcode, v_username, v_safepassword, v_newpassword, v_bdinfo);
		return result;
	}
	CString ks_viewinfo(long v_softcode, LPCTSTR v_NameOrKey)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR;
		InvokeHelper(0xd6, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, v_softcode, v_NameOrKey);
		return result;
	}
	CString ks_unbind(long v_softcode, long v_clientid, LPCTSTR v_NameOrKey, LPCTSTR v_password)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR;
		InvokeHelper(0xd7, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, v_softcode, v_clientid, v_NameOrKey, v_password);
		return result;
	}
	CString ks_exit()
	{
		CString result;
		InvokeHelper(0xd8, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long IPC_Connect(long v_sockPort)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xd9, DISPATCH_METHOD, VT_I4, (void*)&result, parms, v_sockPort);
		return result;
	}
	CString IPC_IdCheck(LPCTSTR v_signA, long v_iscon)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_I4;
		InvokeHelper(0xda, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, v_signA, v_iscon);
		return result;
	}
	CString IPC_advapi(LPCTSTR v_expression)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xdb, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, v_expression);
		return result;
	}
	void IPC_advapifree(LPCTSTR v_expression)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xdc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, v_expression);
	}
	CString IPC_GetData(long v_index)
	{
		CString result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xdd, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, v_index);
		return result;
	}
	long IPC_Start(long v_sockPort, long v_clientNum)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0xdf, DISPATCH_METHOD, VT_I4, (void*)&result, parms, v_sockPort, v_clientNum);
		return result;
	}
	CString decode_rsa(LPCTSTR v_text, LPCTSTR v_key, LPCTSTR v_modules)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0xe0, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, v_text, v_key, v_modules);
		return result;
	}
	CString decode_RC4Base64(LPCTSTR v_key, LPCTSTR v_text)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0xe2, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, v_key, v_text);
		return result;
	}
	void ks_setf(LPCTSTR f)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xde, DISPATCH_METHOD, VT_EMPTY, NULL, parms, f);
	}

	// Iv901 properties
public:

};
