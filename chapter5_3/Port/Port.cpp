// Port.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Port.h"
#include "PortDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPortApp

BEGIN_MESSAGE_MAP(CPortApp, CWinApp)
	//{{AFX_MSG_MAP(CPortApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPortApp construction

CPortApp::CPortApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPortApp object

CPortApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPortApp initialization

BOOL CPortApp::InitInstance()
{
	// Standard initialization

	CPortDlg dlg;
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
