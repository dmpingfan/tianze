// FtpView.h : interface of the CFtpView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FTPVIEW_H__BB7A9A72_3EA6_40ED_893D_D542EDDE3151__INCLUDED_)
#define AFX_FTPVIEW_H__BB7A9A72_3EA6_40ED_893D_D542EDDE3151__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFtpView : public CView
{
protected: // create from serialization only
	CFtpView();
	DECLARE_DYNCREATE(CFtpView)

// Attributes
public:
	CFtpDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFtpView)
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
	virtual ~CFtpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFtpView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FtpView.cpp
inline CFtpDoc* CFtpView::GetDocument()
   { return (CFtpDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPVIEW_H__BB7A9A72_3EA6_40ED_893D_D542EDDE3151__INCLUDED_)
