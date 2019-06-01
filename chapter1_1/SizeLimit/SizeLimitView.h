// SizeLimitView.h : interface of the CSizeLimitView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIZELIMITVIEW_H__262CEDE2_CDB5_42E9_8945_4FDE23327846__INCLUDED_)
#define AFX_SIZELIMITVIEW_H__262CEDE2_CDB5_42E9_8945_4FDE23327846__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSizeLimitView : public CView
{
protected: // create from serialization only
	CSizeLimitView();
	DECLARE_DYNCREATE(CSizeLimitView)

// Attributes
public:
	CSizeLimitDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSizeLimitView)
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
	virtual ~CSizeLimitView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSizeLimitView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SizeLimitView.cpp
inline CSizeLimitDoc* CSizeLimitView::GetDocument()
   { return (CSizeLimitDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIZELIMITVIEW_H__262CEDE2_CDB5_42E9_8945_4FDE23327846__INCLUDED_)
