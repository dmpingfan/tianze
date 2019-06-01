// Serial.h : main header file for the SERIAL application
//

#if !defined(AFX_SERIAL_H__8E44D082_2369_461D_A6B4_D2168735398A__INCLUDED_)
#define AFX_SERIAL_H__8E44D082_2369_461D_A6B4_D2168735398A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSerialApp:
// See Serial.cpp for the implementation of this class
//

class CSerialApp : public CWinApp
{
public:
	CSerialApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerialApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSerialApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIAL_H__8E44D082_2369_461D_A6B4_D2168735398A__INCLUDED_)
