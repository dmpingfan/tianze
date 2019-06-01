// FormerView.h : interface of the CFormerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FORMERVIEW_H__1D79609D_FE74_4535_832B_1AF0B62AD01D__INCLUDED_)
#define AFX_FORMERVIEW_H__1D79609D_FE74_4535_832B_1AF0B62AD01D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XButton.h"

class CFormerView : public CFormView
{
protected: // create from serialization only
	CFormerView();
	DECLARE_DYNCREATE(CFormerView)

public:
	//{{AFX_DATA(CFormerView)
	enum{ IDD = IDD_FORM_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CFormDoc* GetDocument();
    XButton m_btn; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormerView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFormerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFormerView)
	afx_msg void OnOK();
    afx_msg void OnCancel(); 
	afx_msg void OnButtonNum();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FormerView.cpp
inline CFormDoc* CFormerView::GetDocument()
   { return (CFormDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORMERVIEW_H__1D79609D_FE74_4535_832B_1AF0B62AD01D__INCLUDED_)
