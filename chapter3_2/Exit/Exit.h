// Exit.h : main header file for the EXIT application
//

#if !defined(AFX_EXIT_H__C53F1316_C0D0_4CBC_9DD8_17F73E0B17A7__INCLUDED_)
#define AFX_EXIT_H__C53F1316_C0D0_4CBC_9DD8_17F73E0B17A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CExitApp:
// See Exit.cpp for the implementation of this class
//

class CExitApp : public CWinApp
{
public:
	CExitApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExitApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CExitApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXIT_H__C53F1316_C0D0_4CBC_9DD8_17F73E0B17A7__INCLUDED_)
