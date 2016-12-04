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
	long Initialization(LPCTSTR 软件编号, long 线路编号, LPCTSTR 传输密码, LPCTSTR 定义机器码, long 时钟效验时间)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_I4, (void*)&result, parms, 软件编号, 线路编号, 传输密码, 定义机器码, 时钟效验时间);
		return result;
	}
	long Reg(LPCTSTR 注册码)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_I4, (void*)&result, parms, 注册码);
		return result;
	}
	long Trial()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long Discount(LPCTSTR 注册码, long 点数)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_I4, (void*)&result, parms, 注册码, 点数);
		return result;
	}
	long Tie(LPCTSTR 注册码)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_I4, (void*)&result, parms, 注册码);
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
	long Areg(LPCTSTR 软件编号, LPCTSTR 配置文件名, LPCTSTR 传输密码, LPCTSTR 定义机器码, long 时钟效验时间)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_I4, (void*)&result, parms, 软件编号, 配置文件名, 传输密码, 定义机器码, 时钟效验时间);
		return result;
	}
	long Checktime()
	{
		long result;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long Timingbox(LPCTSTR 提示信息, long 等待时长)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_I4, (void*)&result, parms, 提示信息, 等待时长);
		return result;
	}
	CString GetInfo(long 获取类型)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, 获取类型);
		return result;
	}
	CString Inquiry(LPCTSTR 注册码, long 获取类型)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, 注册码, 获取类型);
		return result;
	}
	CString ApiCall(LPCTSTR 文件名, LPCTSTR 注册码, LPCTSTR 函数名, LPCTSTR 参数一, LPCTSTR 参数二, LPCTSTR 参数三, LPCTSTR 参数四, LPCTSTR 参数五)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, 文件名, 注册码, 函数名, 参数一, 参数二, 参数三, 参数四, 参数五);
		return result;
	}

	// Clouds_c properties
public:

};
