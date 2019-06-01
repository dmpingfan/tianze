// Ticket.h : main header file for the TICKET application
//

#if !defined(AFX_TICKET_H__D0276DED_3AE9_4A45_9D1F_7E87C99C1905__INCLUDED_)
#define AFX_TICKET_H__D0276DED_3AE9_4A45_9D1F_7E87C99C1905__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTicketApp:
// See Ticket.cpp for the implementation of this class
//

class CTicketApp : public CWinApp
{
public:
	CTicketApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTicketApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTicketApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TICKET_H__D0276DED_3AE9_4A45_9D1F_7E87C99C1905__INCLUDED_)
