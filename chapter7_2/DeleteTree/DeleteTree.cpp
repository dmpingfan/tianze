// DeleteTree.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "DeleteTree.h"
#include "DeleteTreeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeleteTreeApp

BEGIN_MESSAGE_MAP(CDeleteTreeApp, CWinApp)
	//{{AFX_MSG_MAP(CDeleteTreeApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeleteTreeApp construction

CDeleteTreeApp::CDeleteTreeApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDeleteTreeApp object

CDeleteTreeApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDeleteTreeApp initialization

BOOL CDeleteTreeApp::InitInstance()
{
	// Standard initialization

	CDeleteTreeDlg dlg;
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
