// PopSysMenu.h : main header file for the POPSYSMENU application
//

#if !defined(AFX_POPSYSMENU_H__83EF71CF_48E5_4F42_A175_C75F916E0495__INCLUDED_)
#define AFX_POPSYSMENU_H__83EF71CF_48E5_4F42_A175_C75F916E0495__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPopSysMenuApp:
// See PopSysMenu.cpp for the implementation of this class
//

class CPopSysMenuApp : public CWinApp
{
public:
	CPopSysMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopSysMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPopSysMenuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPSYSMENU_H__83EF71CF_48E5_4F42_A175_C75F916E0495__INCLUDED_)