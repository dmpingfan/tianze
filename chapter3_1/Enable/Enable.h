// Enable.h : main header file for the ENABLE application
//

#if !defined(AFX_ENABLE_H__DEE478A6_3BDE_42E9_954D_73E226414AA3__INCLUDED_)
#define AFX_ENABLE_H__DEE478A6_3BDE_42E9_954D_73E226414AA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEnableApp:
// See Enable.cpp for the implementation of this class
//

class CEnableApp : public CWinApp
{
public:
	CEnableApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnableApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEnableApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENABLE_H__DEE478A6_3BDE_42E9_954D_73E226414AA3__INCLUDED_)
