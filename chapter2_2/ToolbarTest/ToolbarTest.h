// ToolbarTest.h : main header file for the TOOLBARTEST application
//

#if !defined(AFX_TOOLBARTEST_H__9ACC58C7_818D_44A6_AEA7_E1D42C280410__INCLUDED_)
#define AFX_TOOLBARTEST_H__9ACC58C7_818D_44A6_AEA7_E1D42C280410__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CToolbarTestApp:
// See ToolbarTest.cpp for the implementation of this class
//

class CToolbarTestApp : public CWinApp
{
public:
	CToolbarTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolbarTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CToolbarTestApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLBARTEST_H__9ACC58C7_818D_44A6_AEA7_E1D42C280410__INCLUDED_)
