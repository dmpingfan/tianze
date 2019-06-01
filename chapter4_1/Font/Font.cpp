// Font.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Font.h"
#include "FontDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFontApp

BEGIN_MESSAGE_MAP(CFontApp, CWinApp)
	//{{AFX_MSG_MAP(CFontApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontApp construction

CFontApp::CFontApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CFontApp object

CFontApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CFontApp initialization

BOOL CFontApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CFontDlg dlg;
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
