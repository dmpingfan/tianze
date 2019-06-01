// Btn.h : main header file for the BTN application
//

#if !defined(AFX_BTN_H__FFB429FC_8EB0_4A23_8CC4_88B42DBB9813__INCLUDED_)
#define AFX_BTN_H__FFB429FC_8EB0_4A23_8CC4_88B42DBB9813__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBtnApp:
// See Btn.cpp for the implementation of this class
//

class CBtnApp : public CWinApp
{
public:
	CBtnApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBtnApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBtnApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BTN_H__FFB429FC_8EB0_4A23_8CC4_88B42DBB9813__INCLUDED_)
