// BaldView.h : interface of the CBaldView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BALDVIEW_H__2F281199_5A9C_4FEA_885B_706CC1559312__INCLUDED_)
#define AFX_BALDVIEW_H__2F281199_5A9C_4FEA_885B_706CC1559312__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBaldView : public CView
{
protected: // create from serialization only
	CBaldView();
	DECLARE_DYNCREATE(CBaldView)

// Attributes
public:
	CBaldDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaldView)
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
	virtual ~CBaldView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBaldView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BaldView.cpp
inline CBaldDoc* CBaldView::GetDocument()
   { return (CBaldDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BALDVIEW_H__2F281199_5A9C_4FEA_885B_706CC1559312__INCLUDED_)
