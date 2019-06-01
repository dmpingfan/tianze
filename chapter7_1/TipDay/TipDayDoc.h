// TipDayDoc.h : interface of the CTipDayDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIPDAYDOC_H__B2AB50D9_D115_45CC_9915_FCA61EFC239E__INCLUDED_)
#define AFX_TIPDAYDOC_H__B2AB50D9_D115_45CC_9915_FCA61EFC239E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTipDayDoc : public CDocument
{
protected: // create from serialization only
	CTipDayDoc();
	DECLARE_DYNCREATE(CTipDayDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTipDayDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTipDayDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTipDayDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIPDAYDOC_H__B2AB50D9_D115_45CC_9915_FCA61EFC239E__INCLUDED_)
