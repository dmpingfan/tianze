// RoundWnd.h : main header file for the ROUNDWND application
//

#if !defined(AFX_ROUNDWND_H__13432388_5C0A_4D65_9630_D08E874E5D0A__INCLUDED_)
#define AFX_ROUNDWND_H__13432388_5C0A_4D65_9630_D08E874E5D0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRoundWndApp:
// See RoundWnd.cpp for the implementation of this class
//

class CRoundWndApp : public CWinApp
{
public:
	CRoundWndApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoundWndApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRoundWndApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROUNDWND_H__13432388_5C0A_4D65_9630_D08E874E5D0A__INCLUDED_)
