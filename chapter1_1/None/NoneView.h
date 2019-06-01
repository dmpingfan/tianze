// NoneView.h : interface of the CNoneView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NONEVIEW_H__5A44ACF4_7433_4721_854E_8B1912EDCD1B__INCLUDED_)
#define AFX_NONEVIEW_H__5A44ACF4_7433_4721_854E_8B1912EDCD1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNoneView : public CView
{
protected: // create from serialization only
	CNoneView();
	DECLARE_DYNCREATE(CNoneView)

// Attributes
public:
	CNoneDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoneView)
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
	virtual ~CNoneView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNoneView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in NoneView.cpp
inline CNoneDoc* CNoneView::GetDocument()
   { return (CNoneDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NONEVIEW_H__5A44ACF4_7433_4721_854E_8B1912EDCD1B__INCLUDED_)
