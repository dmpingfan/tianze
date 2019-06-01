// ELISView.h : interface of the CELISView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELISVIEW_H__B96F017C_98DF_4616_9CBD_0E89E570569B__INCLUDED_)
#define AFX_ELISVIEW_H__B96F017C_98DF_4616_9CBD_0E89E570569B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CELISSet;
#include "ELISDoc.h"

class CELISView : public CRecordView
{
protected: // create from serialization only
	CELISView();
	DECLARE_DYNCREATE(CELISView)

public:
	//{{AFX_DATA(CELISView)
	enum{ IDD = IDD_ELIS_FORM };
	CELISSet* m_pSet;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CELISDoc* GetDocument();

// Operations
public:
    void Go(CString strFilter); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CELISView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CELISView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CELISView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ELISView.cpp
inline CELISDoc* CELISView::GetDocument()
   { return (CELISDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ELISVIEW_H__B96F017C_98DF_4616_9CBD_0E89E570569B__INCLUDED_)
