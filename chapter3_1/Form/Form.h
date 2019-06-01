// Form.h : main header file for the FORM application
//

#if !defined(AFX_FORM_H__97AA8559_AE8C_401E_A403_49B0113EFFFD__INCLUDED_)
#define AFX_FORM_H__97AA8559_AE8C_401E_A403_49B0113EFFFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFormApp:
// See Form.cpp for the implementation of this class
//

class CFormApp : public CWinApp
{
public:
	CFormApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFormApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORM_H__97AA8559_AE8C_401E_A403_49B0113EFFFD__INCLUDED_)
