// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard
#pragma once
// Csydtdll wrapper class

class Csydtdll : public COleDispatchDriver
{
public:
	Csydtdll(){} // Calls COleDispatchDriver default constructor
	Csydtdll(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Csydtdll(const Csydtdll& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// Isydtdll methods
public:
	CString Send(LPCTSTR c1, LPCTSTR c2)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, c1, c2);
		return result;
	}
	long CaptureGif(long x1, long y1, long x2, long y2, LPCTSTR path)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_I4, (void*)&result, parms, x1, y1, x2, y2, path);
		return result;
	}
	CString Ver()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	// Isydtdll properties
public:

};
