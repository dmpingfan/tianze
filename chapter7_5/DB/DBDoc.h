// DBDoc.h : interface of the CDBDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBDOC_H__099AA13B_7031_438A_BEE3_75E8FF2D1A0A__INCLUDED_)
#define AFX_DBDOC_H__099AA13B_7031_438A_BEE3_75E8FF2D1A0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "DBSet.h"


class CDBDoc : public CDocument
{
protected: // create from serialization only
	CDBDoc();
	DECLARE_DYNCREATE(CDBDoc)

// Attributes
public:
	CDBSet m_dBSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDBDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDBDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBDOC_H__099AA13B_7031_438A_BEE3_75E8FF2D1A0A__INCLUDED_)
