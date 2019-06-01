
#include <afxwin.h>         // MFC core and standard components
#include "resource.h"

class CEmptyApp : public CWinApp
{
public:
	virtual BOOL InitInstance(); 
}; 

class CEmptyWnd : public CWnd
{
public:
	DECLARE_MESSAGE_MAP()
	afx_msg OnCreate(LPCREATESTRUCT lpCreateStruct); 
}; 


CEmptyApp theApp; 

BEGIN_MESSAGE_MAP(CEmptyWnd, CWnd)
ON_WM_CREATE()
END_MESSAGE_MAP()

BOOL CEmptyApp::InitInstance()
{
	RECT rect = {30, 30, 400, 300}; 
	CEmptyWnd* pWnd = new CEmptyWnd; 
	m_pMainWnd = pWnd; 
	LPCTSTR lpszClassName = AfxRegisterWndClass(0, 0, (HBRUSH)::GetStockObject(WHITE_BRUSH), 0); 
	pWnd->CreateEx(0, lpszClassName, "Test Window", WS_OVERLAPPEDWINDOW, rect, NULL, 0, NULL); 
	pWnd->ShowWindow(m_nCmdShow);
	pWnd->UpdateWindow(); 
	return TRUE; 
}

int CEmptyWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CMenu menu; 
	menu.LoadMenu(IDR_MENU1); 
	SetMenu(&menu); 
	menu.Detach(); 
	return 0; 
}

