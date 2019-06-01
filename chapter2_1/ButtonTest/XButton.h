#if !defined(AFX_XBUTTON_H__3C549DDD_E2C2_4527_9F51_D84521C8AC1B__INCLUDED_)
#define AFX_XBUTTON_H__3C549DDD_E2C2_4527_9F51_D84521C8AC1B__INCLUDED_

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
    //COLORREF m_clrText; 
    //COLORREF m_clrTextDisabled; 
    //COLORREF m_clrBack; 
    //COLORREF m_clrBackDisabled; 

// Operations
public:
    BOOL XButton::Attach(const UINT nID, CWnd* pParent); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(XButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~XButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(XButton)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XBUTTON_H__3C549DDD_E2C2_4527_9F51_D84521C8AC1B__INCLUDED_)
