// Rubber.h : main header file for the RUBBER application
//

#if !defined(AFX_RUBBER_H__6ADAE234_201B_42B6_BF8F_7FEFEA3CF524__INCLUDED_)
#define AFX_RUBBER_H__6ADAE234_201B_42B6_BF8F_7FEFEA3CF524__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRubberApp:
// See Rubber.cpp for the implementation of this class
//

class CRubberApp : public CWinApp
{
public:
	CRubberApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRubberApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRubberApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RUBBER_H__6ADAE234_201B_42B6_BF8F_7FEFEA3CF524__INCLUDED_)
