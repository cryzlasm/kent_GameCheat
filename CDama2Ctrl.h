// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#pragma once
// CDama2Ctrl wrapper class

class CDama2Ctrl : public COleDispatchDriver
{
public:
	CDama2Ctrl(){} // Calls COleDispatchDriver default constructor
	CDama2Ctrl(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDama2Ctrl(const CDama2Ctrl& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IDama2Ctrl methods
public:
	CString get_SoftwareName()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_SoftwareName(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_SoftwareID()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_SoftwareID(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_OrigError()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString get_SysAnnouncementURL()
	{
		CString result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_AppAnnouncementURL()
	{
		CString result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long Login(LPCTSTR szUserName, LPCTSTR szUserPassword, LPCTSTR szDyncVerifyCode)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szUserName, szUserPassword, szDyncVerifyCode);
		return result;
	}
	long Logoff()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long Register(LPCTSTR szUserName, LPCTSTR szUserPassword, LPCTSTR szQQ, LPCTSTR szTelNo, LPCTSTR szEmail, long lDyncVCodeSendMode)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szUserName, szUserPassword, szQQ, szTelNo, szEmail, lDyncVCodeSendMode);
		return result;
	}
	long Recharge(LPCTSTR szUserName, LPCTSTR szCardNo, long * ulBalance)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szUserName, szCardNo, ulBalance);
		return result;
	}
	long QueryBalance(long * ulBalance)
	{
		long result;
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ulBalance);
		return result;
	}
	long ReadInfo(BSTR * szUserName, BSTR * szQQ, BSTR * szTelNo, BSTR * szEmail, long * lDyncVCodeSendMode)
	{
		long result;
		static BYTE parms[] = VTS_PBSTR VTS_PBSTR VTS_PBSTR VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szUserName, szQQ, szTelNo, szEmail, lDyncVCodeSendMode);
		return result;
	}
	long ChangeInfo(LPCTSTR szUserOldPassword, LPCTSTR szUserNewPassword, LPCTSTR szQQ, LPCTSTR szTelNo, LPCTSTR szEmail, long lDyncVCodeSendMode, LPCTSTR szDyncVerifyCode)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_BSTR ;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szUserOldPassword, szUserNewPassword, szQQ, szTelNo, szEmail, lDyncVCodeSendMode, szDyncVerifyCode);
		return result;
	}
	long Decode(LPCTSTR szURL, LPCTSTR szCookie, LPCTSTR szReferer, unsigned char byVCodeLen, short usTimeout, long ulVCodeTypeID, BOOL bDownloadFromLocalMachine, long * RequestID)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_UI1 VTS_I2 VTS_I4 VTS_BOOL VTS_PI4 ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szURL, szCookie, szReferer, byVCodeLen, usTimeout, ulVCodeTypeID, bDownloadFromLocalMachine, RequestID);
		return result;
	}
	long DecodeBuf(long lpDataAddress, long ulDataLen, LPCTSTR szExtName, unsigned char byVCodeLen, short usTimeout, long ulVCodeTypeID, long * RequestID)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_UI1 VTS_I2 VTS_I4 VTS_PI4 ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lpDataAddress, ulDataLen, szExtName, byVCodeLen, usTimeout, ulVCodeTypeID, RequestID);
		return result;
	}
	long DecodeWnd(LPCTSTR szWndDef, long x, long y, long cx, long cy, unsigned char byVCodeLen, short usTimeout, long ulVCodeTypeID, long * RequestID)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_UI1 VTS_I2 VTS_I4 VTS_PI4 ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szWndDef, x, y, cx, cy, byVCodeLen, usTimeout, ulVCodeTypeID, RequestID);
		return result;
	}
	long GetResult(long ulRequestID, long ulWaitTimeout, BSTR * szVerifyCode, long * ulVCodeID, BSTR * szReturnCookie)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ulRequestID, ulWaitTimeout, szVerifyCode, ulVCodeID, szReturnCookie);
		return result;
	}
	long ReportResult(long ulVCodeID, BOOL bCorrect)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BOOL ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ulVCodeID, bCorrect);
		return result;
	}
	long Init()
	{
		long result;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void Uninit()
	{
		InvokeHelper(0x13, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long DecodeSync(LPCTSTR szURL, LPCTSTR szCookie, LPCTSTR szReferer, short usTimeout, long ulVCodeTypeID, BSTR * pszVCodeText, BSTR * pszRetCookie)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_I2 VTS_I4 VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szURL, szCookie, szReferer, usTimeout, ulVCodeTypeID, pszVCodeText, pszRetCookie);
		return result;
	}
	long DecodeBufSync(long lpDataAddress, long ulDataLen, LPCTSTR szExtName, short usTimeout, long ulVCodeTypeID, BSTR * pszVCodeText)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_I2 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lpDataAddress, ulDataLen, szExtName, usTimeout, ulVCodeTypeID, pszVCodeText);
		return result;
	}
	long DecodeWndSync(LPCTSTR szWndDef, long x, long y, long cx, long cy, short usTimeout, long ulVCodeTypeID, BSTR * pszVCodeText)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I2 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szWndDef, x, y, cx, cy, usTimeout, ulVCodeTypeID, pszVCodeText);
		return result;
	}
	long DecodeWndHandle(long lHandle, long x, long y, long cx, long cy, unsigned char byVCodeLen, short usTimeout, long ulVCodeTypeID, long * RequestID)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_UI1 VTS_I2 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lHandle, x, y, cx, cy, byVCodeLen, usTimeout, ulVCodeTypeID, RequestID);
		return result;
	}
	long DecodeWndHandleSync(long lHandle, long x, long y, long cx, long cy, short usTimeout, long ulVCodeTypeID, BSTR * pszVCodeText)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I2 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lHandle, x, y, cx, cy, usTimeout, ulVCodeTypeID, pszVCodeText);
		return result;
	}
	long DecodeFileSync(LPCTSTR szFileName, short usTimeout, long ulVCodeTypeID, BSTR * pszVCodeText)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I2 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szFileName, usTimeout, ulVCodeTypeID, pszVCodeText);
		return result;
	}
	CString DecodeFileSync2(LPCTSTR szFileName, short usTimeout, long ulVCodeTypeID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_I2 VTS_I4 ;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, szFileName, usTimeout, ulVCodeTypeID);
		return result;
	}
	long D2File(LPCTSTR szUserName, LPCTSTR szUserPassword, LPCTSTR szFileName, short usTimeout, long ulVCodeTypeID, BSTR * pszVCodeText)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_I2 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szUserName, szUserPassword, szFileName, usTimeout, ulVCodeTypeID, pszVCodeText);
		return result;
	}
	long D2Buf(LPCTSTR szUserName, LPCTSTR szUserPassword, long lpDataAddress, long ulDataLen, short usTimeout, long ulVCodeTypeID, BSTR * pszVCodeText)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I2 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, szUserName, szUserPassword, lpDataAddress, ulDataLen, usTimeout, ulVCodeTypeID, pszVCodeText);
		return result;
	}
	CString D2File2(LPCTSTR szUserName, LPCTSTR szUserPassword, LPCTSTR szFileName, short usTimeout, long ulVCodeTypeID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_I2 VTS_I4 ;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, szUserName, szUserPassword, szFileName, usTimeout, ulVCodeTypeID);
		return result;
	}
	CString D2Buf2(LPCTSTR szUserName, LPCTSTR szUserPassword, long lpDataAddress, long ulDataLen, short usTimeout, long ulVCodeTypeID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I2 VTS_I4 ;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, szUserName, szUserPassword, lpDataAddress, ulDataLen, usTimeout, ulVCodeTypeID);
		return result;
	}
	long QueryBalance2()
	{
		long result;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long D2WndHandle(LPCTSTR pszSoftwareId, LPCTSTR pszUserName, LPCTSTR pszUserPassword, long hHandle, long x, long y, long cx, long cy, short usTimeout, long ulVCodeTypeID, BSTR * pszVCodeText)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I2 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pszSoftwareId, pszUserName, pszUserPassword, hHandle, x, y, cx, cy, usTimeout, ulVCodeTypeID, pszVCodeText);
		return result;
	}
	long D2Wnd(LPCTSTR pszSoftwareId, LPCTSTR pszUserName, LPCTSTR pszUserPassword, LPCTSTR pszWndDef, long x, long y, long cx, long cy, short usTimeout, long ulVCodeTypeID, BSTR * pszVCodeText)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I2 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pszSoftwareId, pszUserName, pszUserPassword, pszWndDef, x, y, cx, cy, usTimeout, ulVCodeTypeID, pszVCodeText);
		return result;
	}
	long D2ReportError(long ulVCodeID)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ulVCodeID);
		return result;
	}
	long D2Balance(LPCTSTR pszSoftwareId, LPCTSTR pszUserName, LPCTSTR pszUserPassword)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pszSoftwareId, pszUserName, pszUserPassword);
		return result;
	}
	long D2Recharge(LPCTSTR pszSoftwareId, LPCTSTR pszUserName, LPCTSTR pszCardNo)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pszSoftwareId, pszUserName, pszCardNo);
		return result;
	}
	long D2Register(LPCTSTR pszSoftwareId, LPCTSTR pszUserName, LPCTSTR pszUserPassword, LPCTSTR pszQQ, LPCTSTR pszTelNo, LPCTSTR pszEmail, long nDyncSendMode)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pszSoftwareId, pszUserName, pszUserPassword, pszQQ, pszTelNo, pszEmail, nDyncSendMode);
		return result;
	}
	CString D2File3(LPCTSTR pszSoftwareId, LPCTSTR szUserName, LPCTSTR szUserPassword, LPCTSTR szFileName, short usTimeout, long ulVCodeTypeID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I2 VTS_I4 ;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, pszSoftwareId, szUserName, szUserPassword, szFileName, usTimeout, ulVCodeTypeID);
		return result;
	}
	CString D2Buf3(LPCTSTR pszSoftwareId, LPCTSTR szUserName, LPCTSTR szUserPassword, long lpDataAddress, long ulDataLen, short usTimeout, long ulVCodeTypeID)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I2 VTS_I4 ;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, pszSoftwareId, szUserName, szUserPassword, lpDataAddress, ulDataLen, usTimeout, ulVCodeTypeID);
		return result;
	}

	// IDama2Ctrl properties
public:

};
