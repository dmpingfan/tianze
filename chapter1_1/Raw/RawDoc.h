// RawDoc.h : interface of the CRawDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RAWDOC_H__59AFC78E_1DD0_4CEB_A309_3C7E097F9E1C__INCLUDED_)
#define AFX_RAWDOC_H__59AFC78E_1DD0_4CEB_A309_3C7E097F9E1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRawDoc : public CDocument
{
protected: // create from serialization only
	CRawDoc();
	DECLARE_DYNCREATE(CRawDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRawDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRawDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RAWDOC_H__59AFC78E_1DD0_4CEB_A309_3C7E097F9E1C__INCLUDED_)
