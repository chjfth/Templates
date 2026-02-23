#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>
#include <CommCtrl.h>
#include <tchar.h>
#include <stdio.h>
#include "resource.h"

#include "iversion.h"

#if 10000
// For standalone use
#include "utils.h"

#define JULAYOUT_IMPL
#include "JULayout2.h"

#else
// For use in chj git-repo dir-tree
#define CHHI_ALL_IMPL
#include <mswin/JULayout2.h>

#include <vaDbgTs.h>
#include <mswin/utils_env.h>
#include <mswin/utils_wingui.h>

#endif // 10000


#include "CxxDialog.h"

#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")


HINSTANCE g_hinstExe;

class MainDialog : public CxxDialog
{
public:
	MainDialog(LPCTSTR mystr);

	virtual INT_PTR DialogProc(HWND hdlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	void OnCommand(HWND hdlg, int id, HWND hwndCtl, UINT codeNotify);
	BOOL OnInitDialog(HWND hdlg, HWND hwndFocus, LPARAM lParam);

private:
	const TCHAR *m_mystr;
	int m_clicks;
};

MainDialog::MainDialog(LPCTSTR mystr)
{
	m_mystr = mystr;
	m_clicks = 0;
}

void MainDialog::OnCommand(HWND hdlg, int id, HWND hwndCtl, UINT codeNotify) 
{
	switch (id) 
	{{
	case IDC_BUTTON1:
	{
		++m_clicks;
		vaSetDlgItemText(hdlg, IDC_EDIT_LOGMSG, _T("Clicks: %d"), m_clicks);

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
	jul->AnchorControl(0,0, 100,100, IDC_EDIT_LOGMSG);
	jul->AnchorControl(50,100, 50,100, IDC_BUTTON1);

	// If you add more controls(IDC_xxx) to the dialog, adjust them here.
}

BOOL MainDialog::OnInitDialog(HWND hdlg, HWND hwndFocus, LPARAM lParam) 
{
	SNDMSG(hdlg, WM_SETICON, TRUE, (LPARAM)LoadIcon(GetWindowInstance(hdlg), MAKEINTRESOURCE(IDI_WINMAIN)));

	vaSetDlgItemText(hdlg, IDC_LABEL1, _T("version: %d.%d.%d"), 
		DialogAsMainUICxx_VMAJOR, DialogAsMainUICxx_VMINOR, DialogAsMainUICxx_VPATCH);
	
	SetDlgItemText(hdlg, IDC_EDIT_LOGMSG, m_mystr);

	Dlg_EnableJULayout(hdlg);

	SetFocus(GetDlgItem(hdlg, IDC_BUTTON1));
	return FALSE; // FALSE to let Dlg-manager respect our SetFocus().
}

INT_PTR MainDialog::DialogProc(HWND hdlg, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
	switch (uMsg) 
	{
		HANDLE_dlgMSG(hdlg, WM_INITDIALOG,    OnInitDialog);
		HANDLE_dlgMSG(hdlg, WM_COMMAND,       OnCommand);
	}
	return FALSE;
}


int WINAPI _tWinMain(HINSTANCE hinstExe, HINSTANCE, PTSTR szParams, int) 
{
	g_hinstExe = hinstExe;

	InitCommonControls(); // WinXP requires this, to work with Visual-style manifest

	const TCHAR *szfullcmdline = GetCommandLine();
	vaDbgTs(_T("GetCommandLine() = %s"), szfullcmdline);

	MainDialog dlg(_T("Hello.\r\nPrivate string here."));
	dlg.DialogBoxParam(hinstExe, MAKEINTRESOURCE(IDD_WINMAIN), NULL);

	return 0;
}
