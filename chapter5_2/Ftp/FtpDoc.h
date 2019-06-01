// FtpDoc.h : interface of the CFtpDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FTPDOC_H__6BB0A1C3_A905_42C0_AA3B_62B4BEB2098C__INCLUDED_)
#define AFX_FTPDOC_H__6BB0A1C3_A905_42C0_AA3B_62B4BEB2098C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFtpDoc : public CDocument
{
protected: // create from serialization only
	CFtpDoc();
	DECLARE_DYNCREATE(CFtpDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFtpDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFtpDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFtpDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPDOC_H__6BB0A1C3_A905_42C0_AA3B_62B4BEB2098C__INCLUDED_)
