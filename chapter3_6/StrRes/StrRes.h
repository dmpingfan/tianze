// StrRes.h : main header file for the STRRES application
//

#if !defined(AFX_STRRES_H__DD2AFCDB_52D4_404A_BF89_2F419A04ECBB__INCLUDED_)
#define AFX_STRRES_H__DD2AFCDB_52D4_404A_BF89_2F419A04ECBB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStrResApp:
// See StrRes.cpp for the implementation of this class
//

class CStrResApp : public CWinApp
{
public:
	CStrResApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStrResApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CStrResApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STRRES_H__DD2AFCDB_52D4_404A_BF89_2F419A04ECBB__INCLUDED_)
