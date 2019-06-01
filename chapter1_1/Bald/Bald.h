// Bald.h : main header file for the BALD application
//

#if !defined(AFX_BALD_H__B1581461_7874_49B6_A054_D5F7A3156F7D__INCLUDED_)
#define AFX_BALD_H__B1581461_7874_49B6_A054_D5F7A3156F7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBaldApp:
// See Bald.cpp for the implementation of this class
//

class CBaldApp : public CWinApp
{
public:
	CBaldApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaldApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBaldApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BALD_H__B1581461_7874_49B6_A054_D5F7A3156F7D__INCLUDED_)
