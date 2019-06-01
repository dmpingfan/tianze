// Liben.h : main header file for the LIBEN application
//

#if !defined(AFX_LIBEN_H__031C54D2_F7F9_4525_BBBC_D0EBD178EA1E__INCLUDED_)
#define AFX_LIBEN_H__031C54D2_F7F9_4525_BBBC_D0EBD178EA1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLibenApp:
// See Liben.cpp for the implementation of this class
//

class CLibenApp : public CWinApp
{
public:
	CLibenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CLibenApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBEN_H__031C54D2_F7F9_4525_BBBC_D0EBD178EA1E__INCLUDED_)
