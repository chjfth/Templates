#pragma once

#include <tchar.h>

TCHAR* now_timestr(TCHAR buf[], int bufchars, bool ymd=false);

int vaMsgBox(HWND hwnd, UINT utype, const TCHAR *szTitle, const TCHAR *szfmt, ...);
// -- utype: MB_OK|MB_ICONINFORMATION

void vaDbgTs(const TCHAR *fmt, ...);

void vaDbgS(const TCHAR *fmt, ...);
