
#include <afxwin.h>
#include <afxext.h>
//#include <afxcmn.h>
#include "resource.h"

class CToolbarApp : public CWinApp
{
public:
    virtual BOOL InitInstance(); 
}; 

class CToolbarWnd : public CFrameWnd
{
public:
    CToolbarWnd(); 

    CToolBar m_wndToolBar; 
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct); 
    afx_msg void OnButtonCmd(); 
    afx_msg void OnUpdateBtnCmdUI(CCmdUI* pCmdUI); 
    DECLARE_MESSAGE_MAP()
}; 

CToolbarApp theApp; 

BEGIN_MESSAGE_MAP(CToolbarWnd, CFrameWnd)
ON_WM_CREATE()
ON_COMMAND_RANGE(ID_TOOLBTN1, ID_TOOLBTN4, OnButtonCmd)
ON_UPDATE_COMMAND_UI_RANGE(ID_TOOLBTN1, ID_TOOLBTN4, OnUpdateBtnCmdUI)
END_MESSAGE_MAP()

BOOL CToolbarApp::InitInstance()
{
    CToolbarWnd* pWnd = new CToolbarWnd(); 
    m_pMainWnd = pWnd; 
    pWnd->LoadFrame(IDR_MAINMENU); 
    pWnd->ShowWindow(SW_SHOW); 
    pWnd->UpdateWindow(); 
    return TRUE; 
}

CToolbarWnd::CToolbarWnd()
{
}

int CToolbarWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    CFrameWnd::OnCreate(lpCreateStruct); 
    m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, // | TBSTYLE_LIST, 
        WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER
        | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC); 
    m_wndToolBar.LoadToolBar(IDR_TOOLBAR_MAIN); 
    m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY); 
    EnableDocking(CBRS_ALIGN_ANY); 
    DockControlBar(&m_wndToolBar);     
    return 0; 
}

void CToolbarWnd::OnButtonCmd()
{
}

void CToolbarWnd::OnUpdateBtnCmdUI(CCmdUI* pCmdUI)
{
    pCmdUI->Enable(TRUE); 
    if(pCmdUI->m_nID % 2 == 0)
        pCmdUI->SetCheck(); 
    else 
        pCmdUI->SetRadio(); 
}