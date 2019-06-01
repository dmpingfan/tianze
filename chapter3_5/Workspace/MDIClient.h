#if !defined(AFX_MDICLIENT_H__ADF6AAE7_BD59_4A90_ACD0_689C0368F56E__INCLUDED_)
#define AFX_MDICLIENT_H__ADF6AAE7_BD59_4A90_ACD0_689C0368F56E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MDIClient.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMDIClient window

class CMDIClient : public CWnd
{
// Construction
public:
	CMDIClient();

// Attributes
public:
	CBitmap m_bmBack; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDIClient)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMDIClient();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMDIClient)
	//afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC); 
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDICLIENT_H__ADF6AAE7_BD59_4A90_ACD0_689C0368F56E__INCLUDED_)
