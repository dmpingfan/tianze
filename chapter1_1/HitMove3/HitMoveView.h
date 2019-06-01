// HitMoveView.h : interface of the CHitMoveView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HITMOVEVIEW_H__7E933B27_6002_4BB6_9EC3_DB85AFE0EA01__INCLUDED_)
#define AFX_HITMOVEVIEW_H__7E933B27_6002_4BB6_9EC3_DB85AFE0EA01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHitMoveView : public CView
{
protected: // create from serialization only
	CHitMoveView();
	DECLARE_DYNCREATE(CHitMoveView)

// Attributes
public:
	CHitMoveDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHitMoveView)
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
	virtual ~CHitMoveView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHitMoveView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HitMoveView.cpp
inline CHitMoveDoc* CHitMoveView::GetDocument()
   { return (CHitMoveDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HITMOVEVIEW_H__7E933B27_6002_4BB6_9EC3_DB85AFE0EA01__INCLUDED_)
