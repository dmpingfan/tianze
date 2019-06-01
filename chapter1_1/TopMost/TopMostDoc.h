// TopMostDoc.h : interface of the CTopMostDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOPMOSTDOC_H__62D29A6C_E2B0_4790_B301_11E004CD5E91__INCLUDED_)
#define AFX_TOPMOSTDOC_H__62D29A6C_E2B0_4790_B301_11E004CD5E91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTopMostDoc : public CDocument
{
protected: // create from serialization only
	CTopMostDoc();
	DECLARE_DYNCREATE(CTopMostDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTopMostDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTopMostDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTopMostDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOPMOSTDOC_H__62D29A6C_E2B0_4790_B301_11E004CD5E91__INCLUDED_)
