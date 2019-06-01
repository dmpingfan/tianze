// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Liben.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_SETFOCUS()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
    ON_MESSAGE(WM_LIBEN, OnLiben)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;

    //cs.style = WS_POPUP; 
    cs.style &= ~WS_VISIBLE; 
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
    cs.dwExStyle |= WS_EX_TOOLWINDOW; 
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
void CMainFrame::OnSetFocus(CWnd* pOldWnd)
{
	// forward focus to the view window
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// let the view have first crack at the command
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0,0,0,0), this, AFX_IDW_PANE_FIRST, pContext))
	{
		TRACE0("Warning: could not create view for frame.\n");
	}

	return CFrameWnd::OnCreateClient(lpcs, pContext);
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	NOTIFYICONDATA nid; 
    nid.cbSize = sizeof(NOTIFYICONDATA); 
    nid.hWnd = GetSafeHwnd(); 
    nid.uID = IDR_MAINFRAME; 
    nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP; 
    nid.uCallbackMessage = WM_LIBEN; 
    nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_CHART)); //IDR_MAINFRAME)); 
    strcpy(nid.szTip, "提示信息"); 
    Shell_NotifyIcon(NIM_ADD, &nid); 
	return 0;
}

void CMainFrame::OnLiben(WPARAM wParam, LPARAM lParam)
{
    if(lParam == WM_RBUTTONDOWN && wParam == IDR_MAINFRAME)
    {
        //SendMessage(WM_CLOSE); 
        ShowWindow(SW_SHOW); 
        SetForegroundWindow(); 
    }
}

void CMainFrame::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	NOTIFYICONDATA nid; 
    nid.cbSize = sizeof(NOTIFYICONDATA); 
    nid.hWnd = GetSafeHwnd(); 
    nid.uID = IDR_MAINFRAME; 
    Shell_NotifyIcon(NIM_DELETE, &nid); 
	CFrameWnd::PostNcDestroy();
}
