// SerialDoc.h : interface of the CSerialDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERIALDOC_H__329A75BD_3B37_42DB_BB36_E55033844DDA__INCLUDED_)
#define AFX_SERIALDOC_H__329A75BD_3B37_42DB_BB36_E55033844DDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DataObject.h"

class CSerialDoc : public CDocument
{
protected: // create from serialization only
	CSerialDoc();
	DECLARE_DYNCREATE(CSerialDoc)

// Attributes
public:
    CDataObject m_obj; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerialDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSerialDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSerialDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIALDOC_H__329A75BD_3B37_42DB_BB36_E55033844DDA__INCLUDED_)
