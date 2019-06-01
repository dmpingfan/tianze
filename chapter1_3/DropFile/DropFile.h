// DropFile.h : main header file for the DROPFILE application
//

#if !defined(AFX_DROPFILE_H__89742F57_775C_4826_88DB_56B3B60993D0__INCLUDED_)
#define AFX_DROPFILE_H__89742F57_775C_4826_88DB_56B3B60993D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDropFileApp:
// See DropFile.cpp for the implementation of this class
//

class CDropFileApp : public CWinApp
{
public:
	CDropFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDropFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDropFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DROPFILE_H__89742F57_775C_4826_88DB_56B3B60993D0__INCLUDED_)
