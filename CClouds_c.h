// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard
#pragma once
// CClouds_c wrapper class

class CClouds_c : public COleDispatchDriver
{
public:
	CClouds_c(){} // Calls COleDispatchDriver default constructor
	CClouds_c(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CClouds_c(const CClouds_c& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// Clouds_c methods
public:
	long Initialization(LPCTSTR ������, long ��·���, LPCTSTR ��������, LPCTSTR ���������, long ʱ��Ч��ʱ��)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ������, ��·���, ��������, ���������, ʱ��Ч��ʱ��);
		return result;
	}
	long Reg(LPCTSTR ע����)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ע����);
		return result;
	}
	long Trial()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long Discount(LPCTSTR ע����, long ����)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ע����, ����);
		return result;
	}
	long Tie(LPCTSTR ע����)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ע����);
		return result;
	}
	CString JData()
	{
		CString result;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString Tips()
	{
		CString result;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString QTime()
	{
		CString result;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long ISreg()
	{
		long result;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long Areg(LPCTSTR ������, LPCTSTR �����ļ���, LPCTSTR ��������, LPCTSTR ���������, long ʱ��Ч��ʱ��)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ������, �����ļ���, ��������, ���������, ʱ��Ч��ʱ��);
		return result;
	}
	long Checktime()
	{
		long result;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long Timingbox(LPCTSTR ��ʾ��Ϣ, long �ȴ�ʱ��)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ��ʾ��Ϣ, �ȴ�ʱ��);
		return result;
	}
	CString GetInfo(long ��ȡ����)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, ��ȡ����);
		return result;
	}
	CString Inquiry(LPCTSTR ע����, long ��ȡ����)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, ע����, ��ȡ����);
		return result;
	}
	CString ApiCall(LPCTSTR �ļ���, LPCTSTR ע����, LPCTSTR ������, LPCTSTR ����һ, LPCTSTR ������, LPCTSTR ������, LPCTSTR ������, LPCTSTR ������)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, �ļ���, ע����, ������, ����һ, ������, ������, ������, ������);
		return result;
	}

	// Clouds_c properties
public:

};
