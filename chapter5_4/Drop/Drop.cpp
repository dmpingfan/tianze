// Drop.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Drop.h"
#include "DropDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDropApp

BEGIN_MESSAGE_MAP(CDropApp, CWinApp)
	//{{AFX_MSG_MAP(CDropApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDropApp construction

CDropApp::CDropApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDropApp object

CDropApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDropApp initialization

BOOL CDropApp::InitInstance()
{
	// Standard initialization
    ::CoInitialize(NULL); 

	CDropDlg dlg;
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

int CDropApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
    ::CoUninitialize(); 
	return CWinApp::ExitInstance();
}
