// DlgRes.h : main header file for the DLGRES application
//

#if !defined(AFX_DLGRES_H__5AC4A8B4_2297_4BF1_91CE_8A3489F14B6C__INCLUDED_)
#define AFX_DLGRES_H__5AC4A8B4_2297_4BF1_91CE_8A3489F14B6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgResApp:
// See DlgRes.cpp for the implementation of this class
//

class CDlgResApp : public CWinApp
{
public:
	CDlgResApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgResApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CDlgResApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGRES_H__5AC4A8B4_2297_4BF1_91CE_8A3489F14B6C__INCLUDED_)
