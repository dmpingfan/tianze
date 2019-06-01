// Net.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Net.h"
#include "NetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNetApp

BEGIN_MESSAGE_MAP(CNetApp, CWinApp)
	//{{AFX_MSG_MAP(CNetApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetApp construction

CNetApp::CNetApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CNetApp object

CNetApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CNetApp initialization

BOOL CNetApp::InitInstance()
{
	// Standard initialization
    WSADATA wsa; 
    AfxSocketInit(&wsa); 

	CNetDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
