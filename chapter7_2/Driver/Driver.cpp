// Driver.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Driver.h"
#include "DriverDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDriverApp

BEGIN_MESSAGE_MAP(CDriverApp, CWinApp)
	//{{AFX_MSG_MAP(CDriverApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDriverApp construction

CDriverApp::CDriverApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDriverApp object

CDriverApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDriverApp initialization

BOOL CDriverApp::InitInstance()
{
	// Standard initialization

	CDriverDlg dlg;
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
