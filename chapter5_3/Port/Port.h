// Port.h : main header file for the PORT application
//

#if !defined(AFX_PORT_H__CAE6AAD7_576A_41DC_BBB5_7F925AF2DE8C__INCLUDED_)
#define AFX_PORT_H__CAE6AAD7_576A_41DC_BBB5_7F925AF2DE8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPortApp:
// See Port.cpp for the implementation of this class
//

class CPortApp : public CWinApp
{
public:
	CPortApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPortApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPortApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PORT_H__CAE6AAD7_576A_41DC_BBB5_7F925AF2DE8C__INCLUDED_)
