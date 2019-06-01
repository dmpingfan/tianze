// NoneDoc.h : interface of the CNoneDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NONEDOC_H__359BCC40_9AD6_4D41_9062_796BA0586146__INCLUDED_)
#define AFX_NONEDOC_H__359BCC40_9AD6_4D41_9062_796BA0586146__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNoneDoc : public CDocument
{
protected: // create from serialization only
	CNoneDoc();
	DECLARE_DYNCREATE(CNoneDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoneDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNoneDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNoneDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NONEDOC_H__359BCC40_9AD6_4D41_9062_796BA0586146__INCLUDED_)
