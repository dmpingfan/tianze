// SizeLimitDoc.h : interface of the CSizeLimitDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIZELIMITDOC_H__5E4D0C2C_74E0_414E_9647_A60F73AA234A__INCLUDED_)
#define AFX_SIZELIMITDOC_H__5E4D0C2C_74E0_414E_9647_A60F73AA234A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSizeLimitDoc : public CDocument
{
protected: // create from serialization only
	CSizeLimitDoc();
	DECLARE_DYNCREATE(CSizeLimitDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSizeLimitDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSizeLimitDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSizeLimitDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIZELIMITDOC_H__5E4D0C2C_74E0_414E_9647_A60F73AA234A__INCLUDED_)
