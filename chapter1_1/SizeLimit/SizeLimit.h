// SizeLimit.h : main header file for the SIZELIMIT application
//

#if !defined(AFX_SIZELIMIT_H__D6973BAE_CC55_4DEE_B9B2_A4E715680605__INCLUDED_)
#define AFX_SIZELIMIT_H__D6973BAE_CC55_4DEE_B9B2_A4E715680605__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSizeLimitApp:
// See SizeLimit.cpp for the implementation of this class
//

class CSizeLimitApp : public CWinApp
{
public:
	CSizeLimitApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSizeLimitApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSizeLimitApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIZELIMIT_H__D6973BAE_CC55_4DEE_B9B2_A4E715680605__INCLUDED_)
