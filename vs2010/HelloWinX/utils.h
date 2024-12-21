#pragma once

#include <tchar.h>

TCHAR* now_timestr(TCHAR buf[], int bufchars, bool ymd=false, bool add_millisec=true);
//
extern "C++" 
{
	template <size_t _Size> inline TCHAR*
	now_timestr(TCHAR (&buf)[_Size], bool ymd=false, bool add_millisec=true) throw() 
	{
		return now_timestr(buf, _Size, ymd, add_millisec); 
	}
}
//__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(TCHAR*, now_timestr, TCHAR, buf, bool, ymd, bool, add_millisec)
// -- This is almost OK, except that it does NOT allow C++ function's default arguments.


int vaMsgBox(HWND hwnd, UINT utype, const TCHAR *szTitle, const TCHAR *szfmt, ...);
// -- utype: MB_OK|MB_ICONINFORMATION

BOOL vaSetWindowText(HWND hwnd, const TCHAR *szfmt, ...);
BOOL vaSetDlgItemText(HWND hwnd, int nIDDlgItem, const TCHAR *szfmt, ...);

void vaDbgTs(const TCHAR *fmt, ...);

void vaDbgS(const TCHAR *fmt, ...);
