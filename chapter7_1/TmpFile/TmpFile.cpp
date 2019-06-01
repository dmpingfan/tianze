// TmpFile.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TmpFile.h"
#include "TmpFileDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTmpFileApp

BEGIN_MESSAGE_MAP(CTmpFileApp, CWinApp)
	//{{AFX_MSG_MAP(CTmpFileApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTmpFileApp construction

CTmpFileApp::CTmpFileApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTmpFileApp object

CTmpFileApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTmpFileApp initialization

BOOL CTmpFileApp::InitInstance()
{
	// Standard initialization

	CTmpFileDlg dlg;
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
