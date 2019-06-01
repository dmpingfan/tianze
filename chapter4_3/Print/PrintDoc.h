// PrintDoc.h : interface of the CPrintDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRINTDOC_H__BE793C94_4FB9_40B2_A04B_7D45B8A26418__INCLUDED_)
#define AFX_PRINTDOC_H__BE793C94_4FB9_40B2_A04B_7D45B8A26418__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPrintDoc : public CDocument
{
protected: // create from serialization only
	CPrintDoc();
	DECLARE_DYNCREATE(CPrintDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPrintDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPrintDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTDOC_H__BE793C94_4FB9_40B2_A04B_7D45B8A26418__INCLUDED_)
