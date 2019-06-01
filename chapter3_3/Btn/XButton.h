#if !defined(AFX_XBUTTON_H__D6D33380_9EAA_4784_89B3_5B6A5A75F573__INCLUDED_)
#define AFX_XBUTTON_H__D6D33380_9EAA_4784_89B3_5B6A5A75F573__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XButton.h : header file
//

#define BTN_STATE_NORMAL 0
#define BTN_STATE_PRESSED 1
#define BTN_STATE_HOVER	2

/////////////////////////////////////////////////////////////////////////////
// XButton window

class XButton : public CButton
{
// Construction
public:
	XButton();

// Attributes
public:
	UINT m_nState; 
    //CBitmap m_bmNormal; 
    //CBitmap m_bmPressed; 
    //CBitmap m_bmHover; 
	CImageList m_ilButton; 
	BOOL m_bDown; 

// Operations
public:

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
public:
	//{{AFX_MSG(XButton)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XBUTTON_H__D6D33380_9EAA_4784_89B3_5B6A5A75F573__INCLUDED_)
