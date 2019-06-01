// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "PromptDlg.h"

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
	ON_COMMAND(ID_EDIT_PROCESS, OnEditProcess)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

//BOOL g_bCancel = FALSE; 

//ULONG WINAPI ProgressProc(LPVOID lpParam)
//{
//    //CProgressDlg* pDlg = (CProgressDlg*)lpParam; 
//    //HWND hWnd = (HWND)lpParam; 
//    //g_bCancel = FALSE; 
//    for(int i=0; i<1000; i++)
//    {
//        for(int j=0; j<1000; j++)
//        {
//            for(int k=0; k<2000; k++)
//            {
//            }
//        }

//        ////pDlg->StepIt(); 
//        //::SendMessage(hWnd, WM_STEP_PROGRESS, 0, 0); 
//        //if(g_bCancel)
//        //    break;
//    }

//    ////pDlg->DestroyWindow(); 
//    ////::DestroyWindow(hWnd); 
//    //::SendMessage(hWnd, WM_CLOSE, 0, 0); 
//    return 0; 
//}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
    //m_pDlg = NULL; 
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


void CMainFrame::OnEditProcess() 
{
	// TODO: Add your command handler code here
	
    //m_bCancel = FALSE; 
    //if(m_pDlg->GetSafeHwnd() != NULL)
    //{
    //    m_pDlg->DestroyWindow(); 
    //    m_pDlg = NULL; 
    //}

    //m_pDlg = new CProgressDlg(this); 
    //m_pDlg->Create(); 
    //m_pDlg->ShowWindow(SW_NORMAL); 
    //m_pDlg->UpdateWindow(); 
    //m_pDlg->SetProgressInfo(0, 1000, 1); 

    //for(int i=0; i<1000; i++)
    //{
    //    ; 
    //    for(int j=0; j<1000; j++)
    //    {
    //        ; 
    //        for(int k=0; k<2000; k++)
    //        {
    //            ; 
    //        }
    //    }

    //    m_pDlg->StepIt(); 
    //    if(m_bCancel)
    //        break; 
    //}

    //m_pDlg->DestroyWindow(); 
    //m_pDlg = NULL; 

	CProgressDlg* pDlg = new CProgressDlg(this); 
	pDlg->Create(); 
	pDlg->ShowWindow(SW_NORMAL); 
	pDlg->UpdateWindow(); 
	pDlg->SetProgressInfo(0, 1000, 1); 
	CreateThread(NULL, 0, CProgressDlg::StartProcess, pDlg, 0, NULL); //(LPVOID)pDlg->GetSafeHwnd(), 0, NULL); 
	
}


