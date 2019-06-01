// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__A824A577_AD77_4E37_BFD2_AE529D840F48__INCLUDED_)
#define AFX_MAINFRM_H__A824A577_AD77_4E37_BFD2_AE529D840F48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChildView.h"
#include "XToolBar.h"
#include "XStatusBar.h"


class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	XStatusBar  m_wndStatusBar;
	XToolBar    m_wndToolBar;
    CToolBar m_wndToolbar256; 
	CChildView    m_wndView;
    BOOL m_bIsTop; 

    BOOL CreateComboToolBar(); 
    BOOL CreateProgressStatusBar(); 
    void DockControlBarLeftOf(CToolBar* pBar, CToolBar* pLeftOf); 
    static void CALLBACK TimerProc(HWND hWnd, UINT uMsg, UINT uIDEvent, DWORD dwTime); 
// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMakeTop();
	afx_msg void OnUpdateMakeTop(CCmdUI* pCmdUI);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
    afx_msg void OnBtnStop(); 
    afx_msg void OnToolBtn(); 
    afx_msg void OnUpdateTime(CCmdUI* pCmdUI); 
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__A824A577_AD77_4E37_BFD2_AE529D840F48__INCLUDED_)
