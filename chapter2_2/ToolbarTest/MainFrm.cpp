// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "ToolbarTest.h"

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
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_COMMAND(ID_MAKE_TOP, OnMakeTop)
	ON_UPDATE_COMMAND_UI(ID_MAKE_TOP, OnUpdateMakeTop)
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
    ON_COMMAND(IDC_BUTTON_CONTROL, OnBtnStop)
    ON_COMMAND_RANGE(ID_TOOLBTN1, ID_TOOLBTN4, OnToolBtn)
    ON_COMMAND_EX(ID_VIEW_TOOLBAR256, OnBarCheck)
    ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBAR256, OnUpdateControlBarMenu)
    //ON_UPDATE_COMMAND_UI(ID_INDICATOR_TIME, OnUpdateTime)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
    ID_INDICATOR_TIME, 
    ID_INDICATOR_PROGRESS, 
    ID_INDICATOR_BUTTON, 
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_bIsTop = FALSE; 
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	// create a view to occupy the client area of the frame
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, 
        WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | 
        CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
    m_wndToolBar.SetBorders(10, 5, 10, 5); 

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

    m_wndToolbar256.Create(this, WS_CHILD | WS_VISIBLE | CBRS_LEFT | CBRS_GRIPPER | 
        CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY, ID_VIEW_TOOLBAR256); 
    m_wndToolbar256.SetBorders(5, 5, 5, 5); 
    m_wndToolbar256.LoadToolBar(IDR_TOOLBAR256); 
    HBITMAP hbm = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_TOOLBAR256), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADMAP3DCOLORS); 
    CBitmap bm; 
    bm.Attach(hbm); 
    CImageList ilToolbar; 
    ilToolbar.Create(16, 16, ILC_COLOR8, 4, 1); 
    ilToolbar.Add(&bm, (CBitmap*)NULL); 
    m_wndToolbar256.GetToolBarCtrl().SetImageList(&ilToolbar); 
    ilToolbar.Detach(); 
    //bm.Detach(); 

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
    m_wndToolbar256.EnableDocking(CBRS_ALIGN_ANY); 
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
    //DockControlBar(&m_wndToolbar256); 
    DockControlBarLeftOf(&m_wndToolbar256, &m_wndToolBar); 

    CreateComboToolBar(); 
    CreateProgressStatusBar(); 
    SetTimer(2000, 500, TimerProc); 
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
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

BOOL CMainFrame::CreateComboToolBar()
{
    int index = 0; 
    while(m_wndToolBar.GetItemID(index) != ID_COMBO_BOX)
        index++; 

    CRect rect; 
    m_wndToolBar.SetButtonInfo(index, ID_COMBO_BOX, TBBS_SEPARATOR, COMBO_BOX_WIDTH); 
    m_wndToolBar.GetItemRect(index, &rect); 
    //rect.top += 2; 
    rect.bottom += 200; 

    if(!m_wndToolBar.m_wndCombo.Create(WS_CHILD | WS_VISIBLE | CBS_AUTOHSCROLL | CBS_DROPDOWNLIST | CBS_HASSTRINGS, 
        rect, &m_wndToolBar, IDC_COMBO_BOX_CONTROL))
        return FALSE; 

    m_wndToolBar.m_wndCombo.ShowWindow(SW_SHOW); 
    m_wndToolBar.m_wndCombo.AddString("First Select"); 
    m_wndToolBar.m_wndCombo.AddString("Second Select"); 
    m_wndToolBar.m_wndCombo.AddString("Third Select"); 
    m_wndToolBar.m_wndCombo.AddString("Forth Select"); 
    m_wndToolBar.m_wndCombo.AddString("Fifth Select"); 
    m_wndToolBar.m_wndCombo.SetCurSel(0); 

    index = 0; 
    while(m_wndToolBar.GetItemID(index) != ID_CHECK_BOX)
        index ++; 

    m_wndToolBar.SetButtonInfo(index, ID_CHECK_BOX, TBBS_SEPARATOR, CHECK_BOX_WIDTH); 
    m_wndToolBar.GetItemRect(index, &rect); 
    
    if(!m_wndToolBar.m_wndCheck.Create("One Line", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX | BS_TEXT, 
        rect, &m_wndToolBar, IDC_CHECK_BOX_CONTROL))
        return FALSE; 

    index = 0; 
    while(m_wndToolBar.GetItemID(index) != ID_RADIO_BOX)
        index ++; 

    m_wndToolBar.SetButtonInfo(index, ID_RADIO_BOX, TBBS_SEPARATOR, RADIO_BOX_WIDTH); 
    m_wndToolBar.GetItemRect(index, &rect); 

    if(!m_wndToolBar.m_wndRadio.Create("Linear", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_TEXT, 
        rect, &m_wndToolBar, IDC_RADIO_BOX_CONTROL))
        return FALSE; 

    return TRUE; 
}

BOOL CMainFrame::CreateProgressStatusBar()
{
    int index = 0; 
    while(m_wndStatusBar.GetItemID(index) != ID_INDICATOR_PROGRESS)
        index++; 

    CRect rect; 
    m_wndStatusBar.SetPaneInfo(index, ID_INDICATOR_PROGRESS, SBPS_NORMAL/*SBPS_STRETCH | SBPS_POPOUT | SBPS_NOBORDERS*/, PROGRESS_WIDTH); 
    m_wndStatusBar.GetItemRect(index, &rect); 

    if(!m_wndStatusBar.m_wndProgress.Create(WS_CHILD | WS_VISIBLE | PBS_SMOOTH, 
        rect, &m_wndStatusBar, IDC_PROGRESS_CONTROL))
        return FALSE; 

    m_wndStatusBar.ShowWindow(SW_SHOW); 
    m_wndStatusBar.m_wndProgress.SetRange(0, 60); 
    m_wndStatusBar.m_wndProgress.SetStep(1); 
    //m_wndStatusBar.m_wndProgress.SetPos(0); 
    m_wndStatusBar.m_wndProgress.SetPos(CTime::GetCurrentTime().GetSecond()); 
    SetTimer(1000, 1000, NULL); 

    index = 0; 
    while(m_wndStatusBar.GetItemID(index) != ID_INDICATOR_BUTTON)
        index ++; 

    m_wndStatusBar.SetPaneInfo(index, ID_INDICATOR_BUTTON, SBPS_NORMAL, BUTTON_WIDTH); 
    m_wndStatusBar.GetItemRect(index, &rect); 

    if(!m_wndStatusBar.m_wndBtn.Create("Stop", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_FLAT, 
        rect, &m_wndStatusBar, IDC_BUTTON_CONTROL))
        return FALSE; 

    return TRUE; 
}


void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	CFrameWnd::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	
    int index = 0; 
    while(m_wndStatusBar.GetItemID(index) != ID_INDICATOR_PROGRESS)
        index++; 

    CRect rect; 
    m_wndStatusBar.GetItemRect(index, &rect); 
    m_wndStatusBar.m_wndProgress.SetWindowPos(NULL, rect.left, rect.top, rect.Width(), rect.Height(), SWP_NOZORDER | SWP_NOACTIVATE); 

    index = 0; 
    while(m_wndStatusBar.GetItemID(index) != ID_INDICATOR_BUTTON)
        index ++; 

    m_wndStatusBar.GetItemRect(index, &rect); 
    m_wndStatusBar.m_wndBtn.MoveWindow(&rect); 
    
    CFont font; 
    font.CreatePointFont(80, "Tahoma"); 
    m_wndStatusBar.m_wndBtn.SetFont(&font); 
    font.Detach(); 
    
}

void CMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
    //m_wndStatusBar.m_wndProgress.StepIt(); 
    m_wndStatusBar.m_wndProgress.SetPos(CTime::GetCurrentTime().GetSecond()); 

	CFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::OnBtnStop()
{
    //m_wndStatusBar.m_wndProgress.SetPos(0); 
    KillTimer(1000); 
}

void CMainFrame::OnToolBtn()
{
}

void CMainFrame::DockControlBarLeftOf(CToolBar* pBar, CToolBar* pLeftOf)
{
    CRect rect; 
    //RecalcLayout(); 
    pLeftOf->GetWindowRect(&rect); 
    rect.OffsetRect(1, 0); 
    DWORD dw = pLeftOf->GetBarStyle(); 
    UINT n = 0; 
    n = (dw & CBRS_ALIGN_TOP) ? AFX_IDW_DOCKBAR_TOP : n; 
    n = (dw & CBRS_ALIGN_BOTTOM && n == 0) ? AFX_IDW_DOCKBAR_BOTTOM : n; 
    n = (dw & CBRS_ALIGN_LEFT && n == 0) ? AFX_IDW_DOCKBAR_LEFT : n; 
    n = (dw & CBRS_ALIGN_RIGHT && n == 0) ? AFX_IDW_DOCKBAR_RIGHT : n; 
    DockControlBar(pBar, n, &rect); 
}

void CMainFrame::OnMakeTop() 
{
	// TODO: Add your command handler code here
	if(m_bIsTop)
        m_wndToolbar256.SetWindowPos(&m_wndStatusBar, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE); 
    else 
        m_wndToolbar256.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE); 

    RecalcLayout(); 
    m_bIsTop = !m_bIsTop; 
}

void CMainFrame::OnUpdateMakeTop(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_bIsTop); 
}

void CMainFrame::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CControlBar* pBar = DYNAMIC_DOWNCAST(CControlBar, pWnd); 
    if(pBar != NULL)
    {
        CMenu menu; 
        if(menu.LoadMenu(IDR_MENU_TOOLBAR))
        {
            CMenu* pSubMenu = menu.GetSubMenu(0); 
            if(pSubMenu != NULL)
            {
                //pBar->ClientToScreen(&point); 
                pSubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this); 
            }
        }
    }
}

void CMainFrame::OnUpdateTime(CCmdUI* pCmdUI)
{
    CTime t = CTime::GetCurrentTime(); 
    char szTime[20]; 
    int nYear = t.GetYear(); 
    int nMonth = t.GetMonth(); 
    int nDay = t.GetDay(); 
    int nHour = t.GetHour(); 
    if(nHour > 12)
        nHour -= 12; 
    int nMinute = t.GetMinute(); 
    int nSecond = t.GetSecond(); 
    time_t tm = t.GetTime(); 
    CTime time(nYear, nMonth, nDay, nHour, nMinute, nSecond); 
    time_t tm2 = time.GetTime(); 
    int nMiliSecond = tm2 - tm; 
    wsprintf(szTime, "%i:%02i:%02i:%02i", nHour, nMinute, nSecond, nMiliSecond); 
    m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(ID_INDICATOR_TIME), szTime); 
    pCmdUI->Enable(); 
}

void CALLBACK CMainFrame::TimerProc(HWND hWnd, UINT uMsg, UINT uIDEvent, DWORD dwTime)
{
    CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd(); 
    if(uIDEvent == 2000)
    {
        CCmdUI cui; 
        cui.m_nID = ID_INDICATOR_TIME; 
        cui.m_nIndex = pMainFrame->m_wndStatusBar.CommandToIndex(ID_INDICATOR_TIME); 
        cui.m_pMenu = NULL; 
        cui.m_pOther = &(pMainFrame->m_wndStatusBar);
        pMainFrame->OnUpdateTime(&cui); 
    }
}