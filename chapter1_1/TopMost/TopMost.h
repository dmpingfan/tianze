// TopMost.h : main header file for the TOPMOST application
//

#if !defined(AFX_TOPMOST_H__96D54C29_7406_4CBB_BBD5_4CC01599F129__INCLUDED_)
#define AFX_TOPMOST_H__96D54C29_7406_4CBB_BBD5_4CC01599F129__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTopMostApp:
// See TopMost.cpp for the implementation of this class
//

class CTopMostApp : public CWinApp
{
public:
	CTopMostApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTopMostApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTopMostApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOPMOST_H__96D54C29_7406_4CBB_BBD5_4CC01599F129__INCLUDED_)
