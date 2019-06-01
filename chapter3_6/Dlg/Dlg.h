// Dlg.h : main header file for the DLG DLL
//

#if !defined(AFX_DLG_H__C70EABFE_B326_453E_9B7F_53927BF9C387__INCLUDED_)
#define AFX_DLG_H__C70EABFE_B326_453E_9B7F_53927BF9C387__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgApp
// See Dlg.cpp for the implementation of this class
//

class CDlgApp : public CWinApp
{
public:
	CDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

void AFX_EXT_API PASCAL ShowAboutDlg(CWnd* pParent); 


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__C70EABFE_B326_453E_9B7F_53927BF9C387__INCLUDED_)
