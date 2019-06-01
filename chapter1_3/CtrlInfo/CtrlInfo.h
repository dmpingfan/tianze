// CtrlInfo.h : main header file for the CTRLINFO application
//

#if !defined(AFX_CTRLINFO_H__2DF1E648_19AC_4E20_A169_67A5A2C9C028__INCLUDED_)
#define AFX_CTRLINFO_H__2DF1E648_19AC_4E20_A169_67A5A2C9C028__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCtrlInfoApp:
// See CtrlInfo.cpp for the implementation of this class
//

class CCtrlInfoApp : public CWinApp
{
public:
	CCtrlInfoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtrlInfoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCtrlInfoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTRLINFO_H__2DF1E648_19AC_4E20_A169_67A5A2C9C028__INCLUDED_)
