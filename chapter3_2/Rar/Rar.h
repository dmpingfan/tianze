// Rar.h : main header file for the RAR application
//

#if !defined(AFX_RAR_H__22DE0F0D_6DAD_4FC2_A256_84B7A40A6085__INCLUDED_)
#define AFX_RAR_H__22DE0F0D_6DAD_4FC2_A256_84B7A40A6085__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRarApp:
// See Rar.cpp for the implementation of this class
//

class CRarApp : public CWinApp
{
public:
	CRarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRarApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RAR_H__22DE0F0D_6DAD_4FC2_A256_84B7A40A6085__INCLUDED_)
