// Startup.h : main header file for the STARTUP application
//

#if !defined(AFX_STARTUP_H__3E20ABE1_68CF_4DBE_94C2_6BFA98F76B9E__INCLUDED_)
#define AFX_STARTUP_H__3E20ABE1_68CF_4DBE_94C2_6BFA98F76B9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStartupApp:
// See Startup.cpp for the implementation of this class
//

class CStartupApp : public CWinApp
{
public:
	CStartupApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStartupApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//{{AFX_MSG(CStartupApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARTUP_H__3E20ABE1_68CF_4DBE_94C2_6BFA98F76B9E__INCLUDED_)
