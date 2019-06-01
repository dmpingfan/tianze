// PicView.h : interface of the CPicView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PICVIEW_H__0B896AD0_E320_400E_800F_DBE778996649__INCLUDED_)
#define AFX_PICVIEW_H__0B896AD0_E320_400E_800F_DBE778996649__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPicView : public CView
{
protected: // create from serialization only
	CPicView();
	DECLARE_DYNCREATE(CPicView)

// Attributes
public:
	CPicDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPicView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PicView.cpp
inline CPicDoc* CPicView::GetDocument()
   { return (CPicDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICVIEW_H__0B896AD0_E320_400E_800F_DBE778996649__INCLUDED_)
