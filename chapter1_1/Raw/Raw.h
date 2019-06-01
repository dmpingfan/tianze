// Raw.h : main header file for the RAW application
//

#if !defined(AFX_RAW_H__D7C02D32_0390_4F3C_86D2_8AFC1A0E0C80__INCLUDED_)
#define AFX_RAW_H__D7C02D32_0390_4F3C_86D2_8AFC1A0E0C80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRawApp:
// See Raw.cpp for the implementation of this class
//

class CRawApp : public CWinApp
{
public:
	CRawApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRawApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRawApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RAW_H__D7C02D32_0390_4F3C_86D2_8AFC1A0E0C80__INCLUDED_)
