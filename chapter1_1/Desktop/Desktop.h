// Desktop.h : main header file for the DESKTOP application
//

#if !defined(AFX_DESKTOP_H__8A95D963_C706_496C_80D4_E342E50BD997__INCLUDED_)
#define AFX_DESKTOP_H__8A95D963_C706_496C_80D4_E342E50BD997__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDesktopApp:
// See Desktop.cpp for the implementation of this class
//

class CDesktopApp : public CWinApp
{
public:
	CDesktopApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDesktopApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDesktopApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESKTOP_H__8A95D963_C706_496C_80D4_E342E50BD997__INCLUDED_)
