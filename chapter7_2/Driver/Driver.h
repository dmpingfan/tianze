// Driver.h : main header file for the DRIVER application
//

#if !defined(AFX_DRIVER_H__4023104A_42F5_46E7_A8F9_562B74742ED9__INCLUDED_)
#define AFX_DRIVER_H__4023104A_42F5_46E7_A8F9_562B74742ED9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDriverApp:
// See Driver.cpp for the implementation of this class
//

class CDriverApp : public CWinApp
{
public:
	CDriverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDriverApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDriverApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRIVER_H__4023104A_42F5_46E7_A8F9_562B74742ED9__INCLUDED_)
