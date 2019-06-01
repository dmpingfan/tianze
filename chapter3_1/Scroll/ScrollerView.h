// ScrollerView.h : interface of the CScrollerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCROLLERVIEW_H__0BA4B40F_55E2_4F05_80CB_6E64EE5240CE__INCLUDED_)
#define AFX_SCROLLERVIEW_H__0BA4B40F_55E2_4F05_80CB_6E64EE5240CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CScrollerView : public CScrollView
{
protected: // create from serialization only
	CScrollerView();
	DECLARE_DYNCREATE(CScrollerView)

// Attributes
public:
	CScrollDoc* GetDocument();

// Operations
public:
    BOOL KeyScroll(UINT nChar); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CScrollerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CScrollerView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ScrollerView.cpp
inline CScrollDoc* CScrollerView::GetDocument()
   { return (CScrollDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLLERVIEW_H__0BA4B40F_55E2_4F05_80CB_6E64EE5240CE__INCLUDED_)
