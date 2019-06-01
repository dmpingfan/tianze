// RubberView.h : interface of the CRubberView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RUBBERVIEW_H__149755AC_A002_4143_A22E_B65958162755__INCLUDED_)
#define AFX_RUBBERVIEW_H__149755AC_A002_4143_A22E_B65958162755__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRubberView : public CView
{
protected: // create from serialization only
	CRubberView();
	DECLARE_DYNCREATE(CRubberView)

// Attributes
public:
	CRubberDoc* GetDocument();
    CRectTracker m_tracker; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRubberView)
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
	virtual ~CRubberView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRubberView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RubberView.cpp
inline CRubberDoc* CRubberView::GetDocument()
   { return (CRubberDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RUBBERVIEW_H__149755AC_A002_4143_A22E_B65958162755__INCLUDED_)
