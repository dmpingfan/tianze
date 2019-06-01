// RubberDoc.h : interface of the CRubberDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RUBBERDOC_H__A845C915_3578_485E_BEE3_AD8A28815F96__INCLUDED_)
#define AFX_RUBBERDOC_H__A845C915_3578_485E_BEE3_AD8A28815F96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRubberDoc : public CDocument
{
protected: // create from serialization only
	CRubberDoc();
	DECLARE_DYNCREATE(CRubberDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRubberDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRubberDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRubberDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RUBBERDOC_H__A845C915_3578_485E_BEE3_AD8A28815F96__INCLUDED_)
