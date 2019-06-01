// SnapView.h : interface of the CSnapView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SNAPVIEW_H__355A31C1_52A0_481E_A802_BC1571FA5B66__INCLUDED_)
#define AFX_SNAPVIEW_H__355A31C1_52A0_481E_A802_BC1571FA5B66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSnapView : public CView
{
protected: // create from serialization only
	CSnapView();
	DECLARE_DYNCREATE(CSnapView)

// Attributes
public:
	CSnapDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnapView)
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
	virtual ~CSnapView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSnapView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SnapView.cpp
inline CSnapDoc* CSnapView::GetDocument()
   { return (CSnapDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAPVIEW_H__355A31C1_52A0_481E_A802_BC1571FA5B66__INCLUDED_)
