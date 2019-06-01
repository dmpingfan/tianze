// FormDoc.h : interface of the CFormDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FORMDOC_H__B06EE90C_9E8A_4B88_9869_B29BA0D63BA1__INCLUDED_)
#define AFX_FORMDOC_H__B06EE90C_9E8A_4B88_9869_B29BA0D63BA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFormDoc : public CDocument
{
protected: // create from serialization only
	CFormDoc();
	DECLARE_DYNCREATE(CFormDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFormDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFormDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORMDOC_H__B06EE90C_9E8A_4B88_9869_B29BA0D63BA1__INCLUDED_)
