// CtrlInfoDoc.h : interface of the CCtrlInfoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CTRLINFODOC_H__41D21DB1_7C8F_4974_A9CC_817A1D7A0ABD__INCLUDED_)
#define AFX_CTRLINFODOC_H__41D21DB1_7C8F_4974_A9CC_817A1D7A0ABD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCtrlInfoDoc : public CDocument
{
protected: // create from serialization only
	CCtrlInfoDoc();
	DECLARE_DYNCREATE(CCtrlInfoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtrlInfoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCtrlInfoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCtrlInfoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTRLINFODOC_H__41D21DB1_7C8F_4974_A9CC_817A1D7A0ABD__INCLUDED_)
