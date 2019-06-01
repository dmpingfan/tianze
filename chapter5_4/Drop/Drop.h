// Drop.h : main header file for the DROP application
//

#if !defined(AFX_DROP_H__EB010E83_80B8_49B6_AB66_23FB2333622C__INCLUDED_)
#define AFX_DROP_H__EB010E83_80B8_49B6_AB66_23FB2333622C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDropApp:
// See Drop.cpp for the implementation of this class
//

class CDropApp : public CWinApp
{
public:
	CDropApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDropApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDropApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DROP_H__EB010E83_80B8_49B6_AB66_23FB2333622C__INCLUDED_)
