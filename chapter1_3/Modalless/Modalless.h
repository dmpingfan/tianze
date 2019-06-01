// Modalless.h : main header file for the MODALLESS application
//

#if !defined(AFX_MODALLESS_H__D9FE8C12_B1C4_48FB_B1C2_4CC3D51AC0EA__INCLUDED_)
#define AFX_MODALLESS_H__D9FE8C12_B1C4_48FB_B1C2_4CC3D51AC0EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CModallessApp:
// See Modalless.cpp for the implementation of this class
//

class CModallessApp : public CWinApp
{
public:
	CModallessApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModallessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CModallessApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODALLESS_H__D9FE8C12_B1C4_48FB_B1C2_4CC3D51AC0EA__INCLUDED_)
