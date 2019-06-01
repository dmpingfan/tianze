// DBView.h : interface of the CDBView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBVIEW_H__C068FB75_DCA2_4FB4_AA11_2C07FB187688__INCLUDED_)
#define AFX_DBVIEW_H__C068FB75_DCA2_4FB4_AA11_2C07FB187688__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDBSet;

class CDBView : public CRecordView
{
protected: // create from serialization only
	CDBView();
	DECLARE_DYNCREATE(CDBView)

public:
	//{{AFX_DATA(CDBView)
	enum{ IDD = IDD_DB_FORM };
	CDBSet* m_pSet;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CDBDoc* GetDocument();
    CListCtrl* m_pList; 
    CListBox* m_pBox; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDBView)
	afx_msg void OnButtonQuery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DBView.cpp
inline CDBDoc* CDBView::GetDocument()
   { return (CDBDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBVIEW_H__C068FB75_DCA2_4FB4_AA11_2C07FB187688__INCLUDED_)
