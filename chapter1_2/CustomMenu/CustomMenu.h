// CustomMenu.h : main header file for the CUSTOMMENU application
//

#if !defined(AFX_CUSTOMMENU_H__4B10B3B0_ADFE_4428_A0D8_731C21B268F4__INCLUDED_)
#define AFX_CUSTOMMENU_H__4B10B3B0_ADFE_4428_A0D8_731C21B268F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCustomMenuApp:
// See CustomMenu.cpp for the implementation of this class
//

class CCustomMenuApp : public CWinApp
{
public:
	CCustomMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCustomMenuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMMENU_H__4B10B3B0_ADFE_4428_A0D8_731C21B268F4__INCLUDED_)
