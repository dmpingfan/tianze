// PropSheet.h : main header file for the PROPSHEET application
//

#if !defined(AFX_PROPSHEET_H__9247830D_0204_460E_83C7_F02AEB7531BA__INCLUDED_)
#define AFX_PROPSHEET_H__9247830D_0204_460E_83C7_F02AEB7531BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPropSheetApp:
// See PropSheet.cpp for the implementation of this class
//

class CPropSheetApp : public CWinApp
{
public:
	CPropSheetApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropSheetApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CPropSheetApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPSHEET_H__9247830D_0204_460E_83C7_F02AEB7531BA__INCLUDED_)
