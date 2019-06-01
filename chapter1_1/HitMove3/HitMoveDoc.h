// HitMoveDoc.h : interface of the CHitMoveDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HITMOVEDOC_H__C5C1CC8E_43A1_4FE3_9AB0_08EC00F7236B__INCLUDED_)
#define AFX_HITMOVEDOC_H__C5C1CC8E_43A1_4FE3_9AB0_08EC00F7236B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHitMoveDoc : public CDocument
{
protected: // create from serialization only
	CHitMoveDoc();
	DECLARE_DYNCREATE(CHitMoveDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHitMoveDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHitMoveDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHitMoveDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HITMOVEDOC_H__C5C1CC8E_43A1_4FE3_9AB0_08EC00F7236B__INCLUDED_)
