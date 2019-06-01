#if !defined(AFX_XTREE_H__97AB999F_1FBA_4D5A_B8AC_3372FB71A5ED__INCLUDED_)
#define AFX_XTREE_H__97AB999F_1FBA_4D5A_B8AC_3372FB71A5ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XTree.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// XTree window

class XTree : public CTreeCtrl
{
// Construction
public:
	XTree();

// Attributes
public:

// Operations
public:
    void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDIS, CDC* pDC); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(XTree)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~XTree();

	// Generated message map functions
protected:
	//{{AFX_MSG(XTree)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XTREE_H__97AB999F_1FBA_4D5A_B8AC_3372FB71A5ED__INCLUDED_)
