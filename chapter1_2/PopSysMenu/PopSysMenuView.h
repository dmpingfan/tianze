// PopSysMenuView.h : interface of the CPopSysMenuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POPSYSMENUVIEW_H__555BB87B_5803_4053_B340_1117B385546B__INCLUDED_)
#define AFX_POPSYSMENUVIEW_H__555BB87B_5803_4053_B340_1117B385546B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPopSysMenuView : public CView
{
protected: // create from serialization only
	CPopSysMenuView();
	DECLARE_DYNCREATE(CPopSysMenuView)

// Attributes
public:
	CPopSysMenuDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopSysMenuView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPopSysMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPopSysMenuView)
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PopSysMenuView.cpp
inline CPopSysMenuDoc* CPopSysMenuView::GetDocument()
   { return (CPopSysMenuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPSYSMENUVIEW_H__555BB87B_5803_4053_B340_1117B385546B__INCLUDED_)
