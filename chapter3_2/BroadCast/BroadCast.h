// BroadCast.h : main header file for the BROADCAST application
//

#if !defined(AFX_BROADCAST_H__7E017A19_FFB0_41EC_BF79_7ECE837A4E8F__INCLUDED_)
#define AFX_BROADCAST_H__7E017A19_FFB0_41EC_BF79_7ECE837A4E8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBroadCastApp:
// See BroadCast.cpp for the implementation of this class
//

class CBroadCastApp : public CWinApp
{
public:
	CBroadCastApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBroadCastApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBroadCastApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROADCAST_H__7E017A19_FFB0_41EC_BF79_7ECE837A4E8F__INCLUDED_)
