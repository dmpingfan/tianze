// PromptDlgDoc.h : interface of the CPromptDlgDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROMPTDLGDOC_H__8F8ECD2D_A6E4_4CD2_BCB8_F12F95C82657__INCLUDED_)
#define AFX_PROMPTDLGDOC_H__8F8ECD2D_A6E4_4CD2_BCB8_F12F95C82657__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPromptDlgDoc : public CDocument
{
protected: // create from serialization only
	CPromptDlgDoc();
	DECLARE_DYNCREATE(CPromptDlgDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPromptDlgDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPromptDlgDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPromptDlgDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROMPTDLGDOC_H__8F8ECD2D_A6E4_4CD2_BCB8_F12F95C82657__INCLUDED_)
