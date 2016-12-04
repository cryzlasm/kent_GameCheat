// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#pragma once

class CTSPlugInterFace : public COleDispatchDriver
{
public:
	CTSPlugInterFace(){} // Calls COleDispatchDriver default constructor
	CTSPlugInterFace(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTSPlugInterFace(const CTSPlugInterFace& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:
	
	long IsFileExist(LPCTSTR file){
		WIN32_FIND_DATA FindFileData;
		HANDLE hFind;

		hFind = FindFirstFile(file, &FindFileData);

		if (hFind == INVALID_HANDLE_VALUE) {
			return 0;
		}
		else {
			return 1;
			FindClose(hFind);
		}
	}


	// ITSPlugInterFace methods
public:
	long BindWindow(long hwnd, LPCTSTR display, LPCTSTR mouse, LPCTSTR keypad, long mode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, display, mouse, keypad, mode);
		return result;
	}
	long BindWindowEx(long hwnd, LPCTSTR display, LPCTSTR mouse, LPCTSTR keypad, LPCTSTR publics, long mode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, display, mouse, keypad, publics, mode);
		return result;
	}
	long UnBindWindow()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long KeyDown(long vk_code)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_I4, (void*)&result, parms, vk_code);
		return result;
	}
	long KeyUp(long vk_code)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_I4, (void*)&result, parms, vk_code);
		return result;
	}
	long KeyPress(long vk_code)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_I4, (void*)&result, parms, vk_code);
		return result;
	}
	long LeftDown()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long LeftUp()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long LeftClick()
	{
		long result;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MoveTo(long x, long y)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_I4, (void*)&result, parms, x, y);
		return result;
	}
	long FindPic(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir, VARIANT * intX, VARIANT * intY)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_R8 VTS_I4 VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_I4, (void*)&result, parms, x1, y1, x2, y2, pic_name, delta_color, sim, dir, intX, intY);
		return result;
	}
	long RightClick()
	{
		long result;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long RightDown()
	{
		long result;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long FindColor(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long dir, VARIANT * intX, VARIANT * intY)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_R8 VTS_I4 VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_I4, (void*)&result, parms, x1, y1, x2, y2, color, sim, dir, intX, intY);
		return result;
	}
	long RightUp()
	{
		long result;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString GetColor(long x, long y)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x, y);
		return result;
	}
	CString GetCursorShape()
	{
		CString result;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long SetPath(LPCTSTR path)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_I4, (void*)&result, parms, path);
		return result;
	}
	long TSGuardProtect(long enable, LPCTSTR type)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_I4, (void*)&result, parms, enable, type);
		return result;
	}
	long KeyPressStr(LPCTSTR key_str, long delay)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_I4, (void*)&result, parms, key_str, delay);
		return result;
	}
	long SendString(long hwnd, LPCTSTR str)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, str);
		return result;
	}
	long SendString2(long hwnd, LPCTSTR str)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, str);
		return result;
	}
	long KeyPressChar(LPCTSTR key_str)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_I4, (void*)&result, parms, key_str);
		return result;
	}
	long KeyDownChar(LPCTSTR key_str)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, key_str);
		return result;
	}
	long KeyUpChar(LPCTSTR key_str)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, key_str);
		return result;
	}
	long GetCursorPos(VARIANT * x, VARIANT * y)
	{
		long result;
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, x, y);
		return result;
	}
	long MoveR(long rx, long ry)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_I4, (void*)&result, parms, rx, ry);
		return result;
	}
	CString Ver()
	{
		CString result;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetPath()
	{
		CString result;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long MiddleClick()
	{
		long result;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long WheelDown()
	{
		long result;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long WheelUp()
	{
		long result;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long Capture(long x1, long y1, long x2, long y2, LPCTSTR file)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_I4, (void*)&result, parms, x1, y1, x2, y2, file);
		return result;
	}
	long CaptureJpg(long x1, long y1, long x2, long y2, LPCTSTR file)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_I4, (void*)&result, parms, x1, y1, x2, y2, file);
		return result;
	}
	long CapturePng(long x1, long y1, long x2, long y2, LPCTSTR file)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_I4, (void*)&result, parms, x1, y1, x2, y2, file);
		return result;
	}
	long LockInput(long lock)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lock);
		return result;
	}
	CString Ocr(long x1, long y1, long x2, long y2, LPCTSTR color_format, float sim)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_R4 ;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x1, y1, x2, y2, color_format, sim);
		return result;
	}
	long SetDict(long index, LPCTSTR file)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_I4, (void*)&result, parms, index, file);
		return result;
	}
	long UseDict(long index)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_I4, (void*)&result, parms, index);
		return result;
	}
	long ClearDict(long index)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, index);
		return result;
	}
	long FindStr(long x1, long y1, long x2, long y2, LPCTSTR string, LPCTSTR color_format, float sim, VARIANT * intX, VARIANT * intY)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_R4 VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x2b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, x1, y1, x2, y2, string, color_format, sim, intX, intY);
		return result;
	}
	long FindStrFast(long x1, long y1, long x2, long y2, LPCTSTR string, LPCTSTR color_format, float sim, VARIANT * intX, VARIANT * intY)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_R4 VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x2c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, x1, y1, x2, y2, string, color_format, sim, intX, intY);
		return result;
	}
	long GetNowDict()
	{
		long result;
		InvokeHelper(0x2d, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString GetBasePath()
	{
		CString result;
		InvokeHelper(0x2e, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long IsDisplayDead(long x1, long y1, long x2, long y2, long t)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x2f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, x1, y1, x2, y2, t);
		return result;
	}
	CString FindPicEx(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_R8 VTS_I4 ;
		InvokeHelper(0x30, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x1, y1, x2, y2, pic_name, delta_color, sim, dir);
		return result;
	}
	CString FindStrEx(long x1, long y1, long x2, long y2, LPCTSTR string, LPCTSTR color_format, double sim)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_R8 ;
		InvokeHelper(0x31, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x1, y1, x2, y2, string, color_format, sim);
		return result;
	}
	CString FindStrFastEx(long x1, long y1, long x2, long y2, LPCTSTR string, LPCTSTR color_format, double sim)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_R8 ;
		InvokeHelper(0x32, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x1, y1, x2, y2, string, color_format, sim);
		return result;
	}
	long CaptureGif(long x1, long y1, long x2, long y2, LPCTSTR file, long delay, long time)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_I4 VTS_I4 ;
		InvokeHelper(0x33, DISPATCH_METHOD, VT_I4, (void*)&result, parms, x1, y1, x2, y2, file, delay, time);
		return result;
	}
	long DownCpu(long rate)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x34, DISPATCH_METHOD, VT_I4, (void*)&result, parms, rate);
		return result;
	}
	long SetKeypadDelay(LPCTSTR type, long delay)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x35, DISPATCH_METHOD, VT_I4, (void*)&result, parms, type, delay);
		return result;
	}
	long SetMouseDelay(LPCTSTR type, long delay)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x36, DISPATCH_METHOD, VT_I4, (void*)&result, parms, type, delay);
		return result;
	}
	long CmpColor(long x, long y, LPCTSTR color, double sim)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_R8 ;
		InvokeHelper(0x37, DISPATCH_METHOD, VT_I4, (void*)&result, parms, x, y, color, sim);
		return result;
	}
	long SendStringIme(LPCTSTR str)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x38, DISPATCH_METHOD, VT_I4, (void*)&result, parms, str);
		return result;
	}
	CString FindColorEx(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long dir)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_R8 VTS_I4 ;
		InvokeHelper(0x39, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x1, y1, x2, y2, color, sim, dir);
		return result;
	}
	CString EnumWindow(long parent, LPCTSTR title, LPCTSTR class_name, long filter)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0x3a, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, parent, title, class_name, filter);
		return result;
	}
	CString EnumWindowByProcess(LPCTSTR process_name, LPCTSTR title, LPCTSTR class_name, long filter)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0x3b, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, process_name, title, class_name, filter);
		return result;
	}
	CString EnumProcess(LPCTSTR name)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x3c, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, name);
		return result;
	}
	long ClientToScreen(long ClientToScreen, VARIANT * x, VARIANT * y)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x3d, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ClientToScreen, x, y);
		return result;
	}
	long FindWindow(LPCTSTR class_name, LPCTSTR title)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x3e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, class_name, title);
		return result;
	}
	long FindWindowByProcess(LPCTSTR process_name, LPCTSTR class_name, LPCTSTR title)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x3f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, process_name, class_name, title);
		return result;
	}
	long FindWindowByProcessId(long process_id, LPCTSTR class_name, LPCTSTR title)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x40, DISPATCH_METHOD, VT_I4, (void*)&result, parms, process_id, class_name, title);
		return result;
	}
	long FindWindowEx(long parent, LPCTSTR class_name, LPCTSTR title)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x41, DISPATCH_METHOD, VT_I4, (void*)&result, parms, parent, class_name, title);
		return result;
	}
	long GetClientRect(long hwnd, VARIANT * x1, VARIANT * y1, VARIANT * x2, VARIANT * y2)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x42, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, x1, y1, x2, y2);
		return result;
	}
	long GetClientSize(long hwnd, VARIANT * width, VARIANT * height)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x43, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, width, height);
		return result;
	}
	long GetForegroundFocus()
	{
		long result;
		InvokeHelper(0x44, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GetForegroundWindow()
	{
		long result;
		InvokeHelper(0x45, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GetMousePointWindow()
	{
		long result;
		InvokeHelper(0x46, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GetPointWindow(long x, long y)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x47, DISPATCH_METHOD, VT_I4, (void*)&result, parms, x, y);
		return result;
	}
	CString GetProcessInfo(long pid)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x48, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, pid);
		return result;
	}
	long GetSpecialWindow(long flag)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x49, DISPATCH_METHOD, VT_I4, (void*)&result, parms, flag);
		return result;
	}
	long GetWindow(long hwnd, long flag)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x4a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, flag);
		return result;
	}
	CString GetWindowClass(long hwnd)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x4b, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd);
		return result;
	}
	long GetWindowProcessId(long hwnd)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x4c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd);
		return result;
	}
	CString GetWindowProcessPath(long hwnd)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x4d, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd);
		return result;
	}
	long GetWindowRect(long hwnd, VARIANT * x1, VARIANT * y1, VARIANT * x2, VARIANT * y2)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x4e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, x1, y1, x2, y2);
		return result;
	}
	long GetWindowState(long hwnd, long flag)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x4f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, flag);
		return result;
	}
	CString GetWindowTitle(long hwnd)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x50, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd);
		return result;
	}
	long MoveWindow(long hwnd, long x, long y)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x51, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, x, y);
		return result;
	}
	long ScreenToClient(long hwnd, VARIANT * x, VARIANT * y)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x52, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, x, y);
		return result;
	}
	long SendPaste(long hwnd)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x53, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd);
		return result;
	}
	long SetClientSize(long hwnd, long width, long hight)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x54, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, width, hight);
		return result;
	}
	long SetWindowState(long hwnd, long flag)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x55, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, flag);
		return result;
	}
	long SetWindowSize(long hwnd, long width, long height)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x56, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, width, height);
		return result;
	}
	long SetWindowText(long hwnd, LPCTSTR title)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x57, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, title);
		return result;
	}
	long SetWindowTransparent(long hwnd, long trans)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x58, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, trans);
		return result;
	}
	long SetClipboard(LPCTSTR value)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x59, DISPATCH_METHOD, VT_I4, (void*)&result, parms, value);
		return result;
	}
	CString GetClipboard()
	{
		CString result;
		InvokeHelper(0x5a, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString DoubleToData(double value)
	{
		CString result;
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x5b, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, value);
		return result;
	}
	CString FloatToData(float value)
	{
		CString result;
		static BYTE parms[] = VTS_R4 ;
		InvokeHelper(0x5c, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, value);
		return result;
	}
	CString IntToData(long value, long type)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x5d, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, value, type);
		return result;
	}
	CString StringToData(LPCTSTR value, long type)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x5e, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, value, type);
		return result;
	}
	CString FindData(long hwnd, LPCTSTR addr_range, LPCTSTR data)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x5f, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd, addr_range, data);
		return result;
	}
	CString FindDouble(long hwnd, LPCTSTR addr_range, double double_value_min, double double_value_max)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_R8 VTS_R8 ;
		InvokeHelper(0x60, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd, addr_range, double_value_min, double_value_max);
		return result;
	}
	CString FindFloat(long hwnd, LPCTSTR addr_range, float float_value_min, float float_value_max)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_R4 VTS_R4 ;
		InvokeHelper(0x61, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd, addr_range, float_value_min, float_value_max);
		return result;
	}
	CString FindInt(long hwnd, LPCTSTR addr_range, long int_value_min, long int_value_max, long type)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x62, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd, addr_range, int_value_min, int_value_max, type);
		return result;
	}
	CString FindString(long hwnd, LPCTSTR addr_range, LPCTSTR string_value, long type)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0x63, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd, addr_range, string_value, type);
		return result;
	}
	CString ReadData(long hwnd, LPCTSTR addr, long len)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd, addr, len);
		return result;
	}
	CString OcrEx(long x1, long y1, long x2, long y2, LPCTSTR color_format, double sim)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_R8 ;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x1, y1, x2, y2, color_format, sim);
		return result;
	}
	double ReadDouble(long hwnd, LPCTSTR addr)
	{
		double result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_R8, (void*)&result, parms, hwnd, addr);
		return result;
	}
	float ReadFloat(long hwnd, LPCTSTR addr)
	{
		float result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_R4, (void*)&result, parms, hwnd, addr);
		return result;
	}
	long ReadInt(long hwnd, LPCTSTR addr, long type)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, addr, type);
		return result;
	}
	CString ReadString(long hwnd, LPCTSTR addr, long type, long len)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 ;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd, addr, type, len);
		return result;
	}
	long TerminateProcess(long pid)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pid);
		return result;
	}
	long VirtualAllocEx(long hwnd, long addr, long size, long type)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, addr, size, type);
		return result;
	}
	long VirtualFreeEx(long hwnd, long addr)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x6c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, addr);
		return result;
	}
	long WriteDouble(long hwnd, LPCTSTR addr, double v)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_R8 ;
		InvokeHelper(0x6d, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, addr, v);
		return result;
	}
	long WriteFloat(long hwnd, LPCTSTR addr, float v)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_R4 ;
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, addr, v);
		return result;
	}
	long WriteInt(long hwnd, LPCTSTR addr, long type, long v)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 ;
		InvokeHelper(0x6f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, addr, type, v);
		return result;
	}
	long WriteString(long hwnd, LPCTSTR addr, long type, LPCTSTR v)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_BSTR ;
		InvokeHelper(0x70, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, addr, type, v);
		return result;
	}
	long WriteData(long hwnd, LPCTSTR addr, LPCTSTR data)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x71, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, addr, data);
		return result;
	}
	long IsBind(long hwnd)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x72, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd);
		return result;
	}
	CString FindFloatEx(long hwnd, LPCTSTR addr_range, float float_value_min, float float_value_max, long step, long multi_thread, long mode)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_R4 VTS_R4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x73, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd, addr_range, float_value_min, float_value_max, step, multi_thread, mode);
		return result;
	}
	CString FindDoubleEx(long hwnd, LPCTSTR addr_range, double double_value_min, double double_value_max, long step, long multi_thread, long mode)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_R8 VTS_R8 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x74, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd, addr_range, double_value_min, double_value_max, step, multi_thread, mode);
		return result;
	}
	CString FindIntEx(long hwnd, LPCTSTR addr_range, long int_value_min, long int_value_max, long type, long step, long multi_thread, long mode)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x75, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd, addr_range, int_value_min, int_value_max, type, step, multi_thread, mode);
		return result;
	}
	CString FindDataEx(long hwnd, LPCTSTR addr_range, LPCTSTR data, long step, long multi_thread, long mode)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x76, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd, addr_range, data, step, multi_thread, mode);
		return result;
	}
	CString FindStringEx(long hwnd, LPCTSTR addr_range, LPCTSTR string_value, long type, long step, long multi_thread, long mode)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x77, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd, addr_range, string_value, type, step, multi_thread, mode);
		return result;
	}
	long GetModuleBaseAddr(long hwnd, LPCTSTR modulename)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x78, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, modulename);
		return result;
	}
	CString GetCommandLine(long hwnd)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x79, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, hwnd);
		return result;
	}
	long AsmAdd(LPCTSTR asm_ins)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x7a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, asm_ins);
		return result;
	}
	long AsmCall(long hwnd, long mode)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x7b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd, mode);
		return result;
	}
	long AsmClear()
	{
		long result;
		InvokeHelper(0x7c, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString AsmCode(long base_addr)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x7d, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, base_addr);
		return result;
	}
	CString Assemble(LPCTSTR asm_code, long base_addr, long is_upper)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 ;
		InvokeHelper(0x7e, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, asm_code, base_addr, is_upper);
		return result;
	}
	CString MatchPicName(LPCTSTR pic_name)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x7f, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, pic_name);
		return result;
	}
	long SetShowErrorMsg(long show)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x80, DISPATCH_METHOD, VT_I4, (void*)&result, parms, show);
		return result;
	}
	long Reg(LPCTSTR reg_code, long type)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x81, DISPATCH_METHOD, VT_I4, (void*)&result, parms, reg_code, type);
		return result;
	}
	CString GetMachineCode()
	{
		CString result;
		InvokeHelper(0x82, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long TSGuardProtectToHide(long enble)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x83, DISPATCH_METHOD, VT_I4, (void*)&result, parms, enble);
		return result;
	}
	long TSGuardProtectToHide2(long enable)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x84, DISPATCH_METHOD, VT_I4, (void*)&result, parms, enable);
		return result;
	}
	long TSGuardProtectToNP(long enable)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x85, DISPATCH_METHOD, VT_I4, (void*)&result, parms, enable);
		return result;
	}
	long delay(long mis)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x86, DISPATCH_METHOD, VT_I4, (void*)&result, parms, mis);
		return result;
	}
	CString FindStrS(long x1, long y1, long x2, long y2, LPCTSTR string, LPCTSTR color_format, double sim, VARIANT * intX, VARIANT * intY)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_R8 VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x87, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x1, y1, x2, y2, string, color_format, sim, intX, intY);
		return result;
	}
	CString FindStrFastS(long x1, long y1, long x2, long y2, LPCTSTR string, LPCTSTR color_format, double sim, VARIANT * intX, VARIANT * intY)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_R8 VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x88, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x1, y1, x2, y2, string, color_format, sim, intX, intY);
		return result;
	}
	CString FindStrExS(long x1, long y1, long x2, long y2, LPCTSTR string, LPCTSTR color_format, double sim)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_R8 ;
		InvokeHelper(0x89, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x1, y1, x2, y2, string, color_format, sim);
		return result;
	}
	CString FindStrFastExS(long x1, long y1, long x2, long y2, LPCTSTR string, LPCTSTR color_format, double sim)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_R8 ;
		InvokeHelper(0x8a, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x1, y1, x2, y2, string, color_format, sim);
		return result;
	}
	CString FindPicS(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir, VARIANT * intX, VARIANT * intY)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_R8 VTS_I4 VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x8b, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x1, y1, x2, y2, pic_name, delta_color, sim, dir, intX, intY);
		return result;
	}
	CString FindPicExS(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_R8 VTS_I4 ;
		InvokeHelper(0x8c, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x1, y1, x2, y2, pic_name, delta_color, sim, dir);
		return result;
	}
	long SetDictPwd(LPCTSTR pwd)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x8d, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pwd);
		return result;
	}
	long SetPicPwd(LPCTSTR pwd)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x8e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pwd);
		return result;
	}
	long LeftDoubleClick()
	{
		long result;
		InvokeHelper(0x8f, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long FreeProcessMemory(long hwnd)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x90, DISPATCH_METHOD, VT_I4, (void*)&result, parms, hwnd);
		return result;
	}
	long TSDXGraphicProtect(long enable)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x91, DISPATCH_METHOD, VT_I4, (void*)&result, parms, enable);
		return result;
	}
	long TSDXKmProtect(long enable, LPCTSTR type)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x92, DISPATCH_METHOD, VT_I4, (void*)&result, parms, enable, type);
		return result;
	}
	long CheckFontSmooth()
	{
		long result;
		InvokeHelper(0x93, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long DisableFontSmooth()
	{
		long result;
		InvokeHelper(0x94, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GetScreenData(long x1, long y1, long x2, long y2)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x95, DISPATCH_METHOD, VT_I4, (void*)&result, parms, x1, y1, x2, y2);
		return result;
	}
	unsigned long EnableRealMouse(unsigned long enable, unsigned long mousedelay, unsigned long mousestep)
	{
		unsigned long result;
		static BYTE parms[] = VTS_UI4 VTS_UI4 VTS_UI4 ;
		InvokeHelper(0x96, DISPATCH_METHOD, VT_UI4, (void*)&result, parms, enable, mousedelay, mousestep);
		return result;
	}
	unsigned long EnableRealKeypad(unsigned long enable)
	{
		unsigned long result;
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(0x97, DISPATCH_METHOD, VT_UI4, (void*)&result, parms, enable);
		return result;
	}
	CString MoveToEx(unsigned long x, unsigned long y, unsigned long w, unsigned long h)
	{
		CString result;
		static BYTE parms[] = VTS_UI4 VTS_UI4 VTS_UI4 VTS_UI4 ;
		InvokeHelper(0x98, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x, y, w, h);
		return result;
	}
	unsigned long CheckUAC()
	{
		unsigned long result;
		InvokeHelper(0x99, DISPATCH_METHOD, VT_UI4, (void*)&result, NULL);
		return result;
	}
	unsigned long SetUAC(unsigned long enable)
	{
		unsigned long result;
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(0x9a, DISPATCH_METHOD, VT_UI4, (void*)&result, parms, enable);
		return result;
	}
	unsigned long WaitKey(unsigned long vk_code, unsigned long time_out)
	{
		unsigned long result;
		static BYTE parms[] = VTS_UI4 VTS_UI4 ;
		InvokeHelper(0x9b, DISPATCH_METHOD, VT_UI4, (void*)&result, parms, vk_code, time_out);
		return result;
	}
	unsigned long FindMultiColor(unsigned long x1, unsigned long y1, unsigned long x2, unsigned long y2, LPCTSTR first_color, LPCTSTR offset_color, double sim, unsigned long dir, VARIANT * intX, VARIANT * intY)
	{
		unsigned long result;
		static BYTE parms[] = VTS_UI4 VTS_UI4 VTS_UI4 VTS_UI4 VTS_BSTR VTS_BSTR VTS_R8 VTS_UI4 VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x9c, DISPATCH_METHOD, VT_UI4, (void*)&result, parms, x1, y1, x2, y2, first_color, offset_color, sim, dir, intX, intY);
		return result;
	}
	CString FindMultiColorEx(unsigned long x1, unsigned long y1, unsigned long x2, unsigned long y2, LPCTSTR first_color, LPCTSTR offset_color, double sim, unsigned long dir)
	{
		CString result;
		static BYTE parms[] = VTS_UI4 VTS_UI4 VTS_UI4 VTS_UI4 VTS_BSTR VTS_BSTR VTS_R8 VTS_UI4 ;
		InvokeHelper(0x9d, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x1, y1, x2, y2, first_color, offset_color, sim, dir);
		return result;
	}
	unsigned long SetSimMode(unsigned long mode)
	{
		unsigned long result;
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(0x9e, DISPATCH_METHOD, VT_UI4, (void*)&result, parms, mode);
		return result;
	}

	// ITSPlugInterFace properties
public:

};
