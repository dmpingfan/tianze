#if !defined(AFX_XEDIT_H__EAAFC509_0632_41C5_A851_23AF3D0C2FDA__INCLUDED_)
#define AFX_XEDIT_H__EAAFC509_0632_41C5_A851_23AF3D0C2FDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// XEdit window

class XEdit : public CEdit
{
// Construction
public:
	XEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(XEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~XEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(XEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XEDIT_H__EAAFC509_0632_41C5_A851_23AF3D0C2FDA__INCLUDED_)
