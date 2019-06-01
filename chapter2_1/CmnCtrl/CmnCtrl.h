// CmnCtrl.h : main header file for the CMNCTRL application
//

#if !defined(AFX_CMNCTRL_H__E2477C07_2648_4923_ACB9_A6B42A69E191__INCLUDED_)
#define AFX_CMNCTRL_H__E2477C07_2648_4923_ACB9_A6B42A69E191__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCmnCtrlApp:
// See CmnCtrl.cpp for the implementation of this class
//

class CCmnCtrlApp : public CWinApp
{
public:
	CCmnCtrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCmnCtrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCmnCtrlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMNCTRL_H__E2477C07_2648_4923_ACB9_A6B42A69E191__INCLUDED_)
