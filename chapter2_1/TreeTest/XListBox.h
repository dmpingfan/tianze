#if !defined(AFX_XLISTBOX_H__49A158B7_6F9F_4962_89EE_56EC47EF4D24__INCLUDED_)
#define AFX_XLISTBOX_H__49A158B7_6F9F_4962_89EE_56EC47EF4D24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// XListBox window

class XListBox : public CListBox
{
// Construction
public:
	XListBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(XListBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~XListBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(XListBox)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XLISTBOX_H__49A158B7_6F9F_4962_89EE_56EC47EF4D24__INCLUDED_)
