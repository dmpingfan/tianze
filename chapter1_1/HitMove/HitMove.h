// HitMove.h : main header file for the HITMOVE application
//

#if !defined(AFX_HITMOVE_H__31F1C06D_9D3F_4B18_8FA2_13ED189A4A50__INCLUDED_)
#define AFX_HITMOVE_H__31F1C06D_9D3F_4B18_8FA2_13ED189A4A50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHitMoveApp:
// See HitMove.cpp for the implementation of this class
//

class CHitMoveApp : public CWinApp
{
public:
	CHitMoveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHitMoveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHitMoveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HITMOVE_H__31F1C06D_9D3F_4B18_8FA2_13ED189A4A50__INCLUDED_)
