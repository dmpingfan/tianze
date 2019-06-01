// ProgramGroup.h : main header file for the PROGRAMGROUP application
//

#if !defined(AFX_PROGRAMGROUP_H__911FABA8_2289_4677_BD8A_905C42BDE6C5__INCLUDED_)
#define AFX_PROGRAMGROUP_H__911FABA8_2289_4677_BD8A_905C42BDE6C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CProgramGroupApp:
// See ProgramGroup.cpp for the implementation of this class
//

class CProgramGroupApp : public CWinApp
{
public:
	CProgramGroupApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgramGroupApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

    DWORD dwDDEInst; 

    BOOL AddProgramGroup(CString strGroup, CString strItem, CString strFile); 
// Implementation

	//{{AFX_MSG(CProgramGroupApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRAMGROUP_H__911FABA8_2289_4677_BD8A_905C42BDE6C5__INCLUDED_)
