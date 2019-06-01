#if !defined(AFX_XBUTTON_H__D14B0510_A43B_4DE9_8174_2A6B848C0F03__INCLUDED_)
#define AFX_XBUTTON_H__D14B0510_A43B_4DE9_8174_2A6B848C0F03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// XButton window

class XButton : public CButton
{
// Construction
public:
	XButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(XButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~XButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(XButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XBUTTON_H__D14B0510_A43B_4DE9_8174_2A6B848C0F03__INCLUDED_)
