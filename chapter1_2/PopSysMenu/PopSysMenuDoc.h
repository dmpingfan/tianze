// PopSysMenuDoc.h : interface of the CPopSysMenuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POPSYSMENUDOC_H__D3326A41_DD9E_4B1B_9E0B_43B735975086__INCLUDED_)
#define AFX_POPSYSMENUDOC_H__D3326A41_DD9E_4B1B_9E0B_43B735975086__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPopSysMenuDoc : public CDocument
{
protected: // create from serialization only
	CPopSysMenuDoc();
	DECLARE_DYNCREATE(CPopSysMenuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopSysMenuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPopSysMenuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPopSysMenuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPSYSMENUDOC_H__D3326A41_DD9E_4B1B_9E0B_43B735975086__INCLUDED_)
