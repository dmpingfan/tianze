// TopMostView.h : interface of the CTopMostView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOPMOSTVIEW_H__D272A0D7_8A98_44F4_93D6_3C17477D3745__INCLUDED_)
#define AFX_TOPMOSTVIEW_H__D272A0D7_8A98_44F4_93D6_3C17477D3745__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTopMostView : public CView
{
protected: // create from serialization only
	CTopMostView();
	DECLARE_DYNCREATE(CTopMostView)

// Attributes
public:
	CTopMostDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTopMostView)
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
	virtual ~CTopMostView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTopMostView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TopMostView.cpp
inline CTopMostDoc* CTopMostView::GetDocument()
   { return (CTopMostDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOPMOSTVIEW_H__D272A0D7_8A98_44F4_93D6_3C17477D3745__INCLUDED_)
