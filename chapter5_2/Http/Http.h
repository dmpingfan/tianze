// Http.h : main header file for the HTTP application
//

#if !defined(AFX_HTTP_H__D045873D_9871_43DB_B10E_166F6E592DE5__INCLUDED_)
#define AFX_HTTP_H__D045873D_9871_43DB_B10E_166F6E592DE5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHttpApp:
// See Http.cpp for the implementation of this class
//

class CHttpApp : public CWinApp
{
public:
	CHttpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHttpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHttpApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTTP_H__D045873D_9871_43DB_B10E_166F6E592DE5__INCLUDED_)
