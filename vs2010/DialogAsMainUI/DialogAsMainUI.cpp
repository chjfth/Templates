﻿#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <stdio.h>
#include "resource.h"
#include "iversion.h"

#include "CmnHdr-Jeffrey.h"

#define JULAYOUT_IMPL
#include "JULayout2.h"

#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

HINSTANCE g_hinstExe;

struct DlgPrivate_st
{
	const TCHAR *mystr;
	int clicks;
};


void Dlg_OnCommand(HWND hdlg, int id, HWND hwndCtl, UINT codeNotify) 
{
	DlgPrivate_st *prdata = (DlgPrivate_st*)GetWindowLongPtr(hdlg, DWLP_USER);
	TCHAR textbuf[200];

	switch (id) 
	{{
	case IDC_BUTTON1:
	{
		++(prdata->clicks);
		_sntprintf_s(textbuf, _TRUNCATE, _T("Clicks: %d"), prdata->clicks);
		SetDlgItemText(hdlg, IDC_EDIT1, textbuf);

		InvalidateRect(GetDlgItem(hdlg, IDC_LABEL1), NULL, TRUE);
		break;
	}
	case IDOK:
	case IDCANCEL:
	{
		EndDialog(hdlg, id);
		break;
	}
	}}
}

BOOL Dlg_OnInitDialog(HWND hdlg, HWND hwndFocus, LPARAM lParam) 
{
	DlgPrivate_st *prdata = (DlgPrivate_st*)lParam;
	SetWindowLongPtr(hdlg, DWLP_USER, (LONG_PTR)prdata);
	
	chSETDLGICONS(hdlg, IDI_WINMAIN);

	TCHAR textbuf[200];
	_sntprintf_s(textbuf, _TRUNCATE, _T("version: %d.%d.%d"), 
		DialogAsMainUI_VMAJOR, DialogAsMainUI_VMINOR, DialogAsMainUI_VPATCH);
	SetDlgItemText(hdlg, IDC_LABEL1, textbuf);
	
	SetDlgItemText(hdlg, IDC_EDIT1, prdata->mystr);

	JULayout *jul = JULayout::EnableJULayout(hdlg);

	jul->AnchorControl(0,0, 100,0, IDC_LABEL1);
	jul->AnchorControl(0,0, 100,100, IDC_EDIT1);
	jul->AnchorControl(50,100, 50,100, IDC_BUTTON1);

	SetFocus(GetDlgItem(hdlg, IDC_BUTTON1));
	
	return 0; // Let Dlg-manager respect SetFocus().
}

INT_PTR WINAPI Dlg_Proc(HWND hdlg, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
	switch (uMsg) 
	{
		chHANDLE_DLGMSG(hdlg, WM_INITDIALOG,    Dlg_OnInitDialog);
		chHANDLE_DLGMSG(hdlg, WM_COMMAND,       Dlg_OnCommand);
	}
	return FALSE;
}


int WINAPI _tWinMain(HINSTANCE hinstExe, HINSTANCE, PTSTR pszCmdLine, int) 
{
	g_hinstExe = hinstExe;

	DlgPrivate_st dlgdata = { _T("Hello.\r\nPrivate string here.") };
	DialogBoxParam(hinstExe, MAKEINTRESOURCE(IDD_WINMAIN), NULL, Dlg_Proc, (LPARAM)&dlgdata);

	return 0;
}
