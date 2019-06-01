// Timer.h : main header file for the TIMER application
//

#if !defined(AFX_TIMER_H__44E71B0A_6021_4D4F_9FC2_9ED02EC4DBF0__INCLUDED_)
#define AFX_TIMER_H__44E71B0A_6021_4D4F_9FC2_9ED02EC4DBF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include <fstream.h>

/////////////////////////////////////////////////////////////////////////////
// CTimerApp:
// See Timer.cpp for the implementation of this class
//

class CTimerApp : public CWinApp
{
public:
	CTimerApp();
	~CTimerApp(); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	void InitializeTimer(); 
	UINT m_nAccuracy; 
	UINT m_nTimerID1; 
	UINT m_nTimerID2; 
	ofstream fout; 

	static void PASCAL Timer1Proc(UINT nTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD dw2); 
	static void PASCAL Timer2Proc(UINT nTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD dw2); 

	//{{AFX_MSG(CTimerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMER_H__44E71B0A_6021_4D4F_9FC2_9ED02EC4DBF0__INCLUDED_)
