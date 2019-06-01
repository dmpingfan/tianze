// OpenGL.h : main header file for the OPENGL application
//

#if !defined(AFX_OPENGL_H__E258E125_A8C4_4497_922C_35861688A910__INCLUDED_)
#define AFX_OPENGL_H__E258E125_A8C4_4497_922C_35861688A910__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COpenGLApp:
// See OpenGL.cpp for the implementation of this class
//

class COpenGLApp : public CWinApp
{
public:
	COpenGLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGLApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(COpenGLApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGL_H__E258E125_A8C4_4497_922C_35861688A910__INCLUDED_)
