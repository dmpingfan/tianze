// DragView.h : interface of the CDragView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAGVIEW_H__03030752_C4DE_4E5E_9F66_2379F3490189__INCLUDED_)
#define AFX_DRAGVIEW_H__03030752_C4DE_4E5E_9F66_2379F3490189__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDragView : public CFormView
{
protected: // create from serialization only
	CDragView();
	DECLARE_DYNCREATE(CDragView)

public:
	//{{AFX_DATA(CDragView)
	enum{ IDD = IDD_DRAG_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CDragDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDragView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDragView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDragView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DragView.cpp
inline CDragDoc* CDragView::GetDocument()
   { return (CDragDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAGVIEW_H__03030752_C4DE_4E5E_9F66_2379F3490189__INCLUDED_)
