// ELISDoc.h : interface of the CELISDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELISDOC_H__68319B17_E044_46F4_B522_DF547400D914__INCLUDED_)
#define AFX_ELISDOC_H__68319B17_E044_46F4_B522_DF547400D914__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ELISSet.h"


class CELISDoc : public CDocument
{
protected: // create from serialization only
	CELISDoc();
	DECLARE_DYNCREATE(CELISDoc)

// Attributes
public:
	CELISSet m_eLISSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CELISDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CELISDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CELISDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ELISDOC_H__68319B17_E044_46F4_B522_DF547400D914__INCLUDED_)
