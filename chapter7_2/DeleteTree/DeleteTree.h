// DeleteTree.h : main header file for the DELETETREE application
//

#if !defined(AFX_DELETETREE_H__A893F87C_DFAB_4AC1_96E1_F2BB4FCA4D75__INCLUDED_)
#define AFX_DELETETREE_H__A893F87C_DFAB_4AC1_96E1_F2BB4FCA4D75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDeleteTreeApp:
// See DeleteTree.cpp for the implementation of this class
//

class CDeleteTreeApp : public CWinApp
{
public:
	CDeleteTreeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteTreeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDeleteTreeApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETETREE_H__A893F87C_DFAB_4AC1_96E1_F2BB4FCA4D75__INCLUDED_)
