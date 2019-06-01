// TipDay.h : main header file for the TIPDAY application
//

#if !defined(AFX_TIPDAY_H__745FD04E_3967_4882_94D5_B6DA3448CE51__INCLUDED_)
#define AFX_TIPDAY_H__745FD04E_3967_4882_94D5_B6DA3448CE51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTipDayApp:
// See TipDay.cpp for the implementation of this class
//

class CTipDayApp : public CWinApp
{
public:
	CTipDayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTipDayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTipDayApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ShowTipAtStartup(void);
private:
	void ShowTipOfTheDay(void);
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIPDAY_H__745FD04E_3967_4882_94D5_B6DA3448CE51__INCLUDED_)
