#pragma once

#include <tchar.h>

TCHAR* now_timestr(TCHAR buf[], int bufchars, bool ymd=false);

int vaMsgBox(HWND hwnd, UINT utype, const TCHAR *szTitle, const TCHAR *szfmt, ...);
// -- utype: MB_OK|MB_ICONINFORMATION

BOOL vaSetWindowText(HWND hwnd, const TCHAR *szfmt, ...);

BOOL vaSetDlgItemText(HWND hwnd, int nIDDlgItem, const TCHAR *szfmt, ...);

void vaDbgTs(const TCHAR *fmt, ...);

void vaDbgS(const TCHAR *fmt, ...);
