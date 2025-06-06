#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>
#include <CommCtrl.h>
#include <tchar.h>
#include <stdio.h>

#include <MyAPI1.h>
#include <MyAPI2.h>

#include "resource.h"

#include "iversion.h"

#include "utils.h"

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
	DlgPrivate_st &prdata = *(DlgPrivate_st*)GetWindowLongPtr(hdlg, DWLP_USER);
	TCHAR textbuf[200];

	switch (id) 
	{{
	case IDC_BUTTON1:
	{
		++(prdata.clicks);
		_sntprintf_s(textbuf, _TRUNCATE, _T("Clicks: %d"), prdata.clicks);
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

static void Dlg_EnableJULayout(HWND hdlg)
{
	JULayout *jul = JULayout::EnableJULayout(hdlg);

	jul->AnchorControl(0,0, 100,0, IDC_LABEL1);
	jul->AnchorControl(0,0, 100,100, IDC_EDIT1);
	jul->AnchorControl(50,100, 50,100, IDC_BUTTON1);

	// If you add more controls(IDC_xxx) to the dialog, adjust them here.
}

void Do_InitWork(HWND hdlg)
{
	HWND hedit = GetDlgItem(hdlg, IDC_EDIT1);

	MyAPI1_version_st vst1 = {};
	MyAPI1_getversion(&vst1);

	vaAppendText_mled(hedit, _T("Using MyAPI1 version: %d.%d.%d.%d\n"), 
		vst1.major, vst1.minor, vst1.patch, vst1.extra);

	MyAPI2_version_st vst2 = {};
	MyAPI2_getversion(&vst2);

	vaAppendText_mled(hedit, _T("Using MyAPI2 version: %d.%d.%d.%d\n"), 
		vst2.major, vst2.minor, vst2.patch, vst2.extra);
}

BOOL Dlg_OnInitDialog(HWND hdlg, HWND hwndFocus, LPARAM lParam) 
{
	SNDMSG(hdlg, WM_SETICON, TRUE, (LPARAM)LoadIcon(GetWindowInstance(hdlg), MAKEINTRESOURCE(IDI_WINMAIN)));

	DlgPrivate_st &prdata = *(DlgPrivate_st*)lParam;
	SetWindowLongPtr(hdlg, DWLP_USER, (LONG_PTR)&prdata);
	
	TCHAR textbuf[200];
	_sntprintf_s(textbuf, _TRUNCATE, _T("version: %d.%d.%d"), 
		MyEXE_VMAJOR, MyEXE_VMINOR, MyEXE_VPATCH);
	SetDlgItemText(hdlg, IDC_LABEL1, textbuf);
	
//	SetDlgItemText(hdlg, IDC_EDIT1, prdata.mystr);

	Dlg_EnableJULayout(hdlg);

	Do_InitWork(hdlg);

	SetFocus(GetDlgItem(hdlg, IDC_BUTTON1));
	return FALSE; // FALSE to let Dlg-manager respect our SetFocus().
}

INT_PTR WINAPI UserDlgProc(HWND hdlg, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
	switch (uMsg) 
	{
		HANDLE_dlgMSG(hdlg, WM_INITDIALOG,    Dlg_OnInitDialog);
		HANDLE_dlgMSG(hdlg, WM_COMMAND,       Dlg_OnCommand);
	}
	return FALSE;
}


int WINAPI _tWinMain(HINSTANCE hinstExe, HINSTANCE, PTSTR szParams, int) 
{
	g_hinstExe = hinstExe;

	InitCommonControls(); // WinXP requires this, to work with Visual-style manifest

	const TCHAR *szfullcmdline = GetCommandLine();
	vaDbgTs(_T("GetCommandLine() = %s"), szfullcmdline);

	DlgPrivate_st dlgdata = { _T("Hello.\r\nPrivate string here.") };
	DialogBoxParam(hinstExe, MAKEINTRESOURCE(IDD_WINMAIN), NULL, UserDlgProc, (LPARAM)&dlgdata);

	return 0;
}
