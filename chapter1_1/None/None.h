// None.h : main header file for the NONE application
//

#if !defined(AFX_NONE_H__3AC368D9_861C_4106_BDD2_805554BD1026__INCLUDED_)
#define AFX_NONE_H__3AC368D9_861C_4106_BDD2_805554BD1026__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CNoneApp:
// See None.cpp for the implementation of this class
//

class CNoneApp : public CWinApp
{
public:
	CNoneApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoneApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CNoneApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NONE_H__3AC368D9_861C_4106_BDD2_805554BD1026__INCLUDED_)
