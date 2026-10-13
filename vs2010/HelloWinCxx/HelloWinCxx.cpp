/*------------------------------------------------------------
HelloWinCxx.cpp skeleton program 
-- Displays "Hello, WindowsX!" in client area
				 
   Compile it with command line in Visual C++ 2010+:
   
cl /c /Od /MT /Zi /D_DEBUG /D_UNICODE /DUNICODE HelloWinCxx.cpp
rc HelloWinCxx.rc
link /debug HelloWinCxx.obj HelloWinCxx.res kernel32.lib user32.lib gdi32.lib

   Then we can load it into Visual C++ debugger.
  ------------------------------------------------------------*/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

#include "CxxRawWinBase.h"

class CAppWin : public CxxRawWinBase
{
public:
	virtual LRESULT WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	BOOL Cls_OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
	void Cls_OnPaint(HWND hwnd);
	void Cls_OnDestroy(HWND hwnd)
	{
		PostQuitMessage(44);
	}
};

int WINAPI _tWinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
					PTSTR szCmdLine, int nCmdShow)
{
	static TCHAR szAppName[] = TEXT ("HelloWinCxx") ;

	CAppWin appwin;
	BOOL succ = appwin.RegisterAndCreate(szAppName);
	assert(succ);

	MSG msg = {};
	while (GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg) ;
		DispatchMessage (&msg) ;
	}

	return (int)msg.wParam; // the value N told by PostQuitMessage(N);
}

BOOL CAppWin::Cls_OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct)
{
	assert(lpCreateStruct->lpCreateParams==(void*)this);

	return TRUE; // success, go on creation
}

void CAppWin::Cls_OnPaint(HWND hwnd)
{
	PAINTSTRUCT ps = {};
	RECT        rect ;
	HDC hdc = BeginPaint (hwnd, &ps) ;

	GetClientRect (hwnd, &rect) ;          
	Ellipse(hdc, 0,0, rect.right, rect.bottom);
	DrawText (hdc, TEXT ("Hello, WindowCxx !"), -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER) ;

	EndPaint (hwnd, &ps) ;
}


LRESULT CAppWin::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{{
		HANDLE_MSG(hwnd, WM_CREATE, Cls_OnCreate);
		HANDLE_MSG(hwnd, WM_PAINT, Cls_OnPaint);
		HANDLE_MSG(hwnd, WM_DESTROY, Cls_OnDestroy);
	}}
	
	return DefWindowProc (hwnd, message, wParam, lParam) ;
}
