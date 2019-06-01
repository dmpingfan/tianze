// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Splitter.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_RUN_WINEXEC, OnRunWinexec)
	ON_COMMAND(ID_RUN_SHELLEXEC, OnRunShellexec)
	ON_COMMAND(ID_RUN_CREATEPROC, OnRunCreateproc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

    //AfxGetApp()->m_nCmdShow = SW_HIDE; 
    //ShowWindow(SW_HIDE); 
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

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


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
    return m_SWnd.Create(this, 2, 2, CSize(20, 20), pContext); 	
    //return CFrameWnd::OnCreateClient(lpcs, pContext);
}

void CMainFrame::OnRunWinexec() 
{
	// TODO: Add your command handler code here
	WinExec("calc", SW_SHOWMINIMIZED); //SW_SHOWMAXIMIZED); 
    //WinExec("Neterm", SW_SHOWMINIMIZED); 
}

void CMainFrame::OnRunShellexec() 
{
	// TODO: Add your command handler code here
	ShellExecute(NULL, NULL, _T("Readme.txt"), NULL, NULL, SW_SHOWMAXIMIZED); 
}

void CMainFrame::OnRunCreateproc() 
{
	// TODO: Add your command handler code here
	STARTUPINFO stinfo; 
    memset(&stinfo, 0, sizeof(STARTUPINFO)); 
    PROCESS_INFORMATION procinfo; 
    CreateProcess(NULL, _T("notepad.exe"), NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &stinfo, &procinfo); 
}
