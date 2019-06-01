// Wait.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Wait.h"
#include "WaitDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWaitApp

BEGIN_MESSAGE_MAP(CWaitApp, CWinApp)
	//{{AFX_MSG_MAP(CWaitApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWaitApp construction

CWaitApp::CWaitApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CWaitApp object

CWaitApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CWaitApp initialization

BOOL CWaitApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

    PROCESS_INFORMATION pinfo; 
    memset(&pinfo, 0, sizeof(PROCESS_INFORMATION));     
    STARTUPINFO sinfo; 
    memset(&sinfo, 0, sizeof(STARTUPINFO)); 
    sinfo.cb = sizeof(STARTUPINFO); 
    sinfo.dwFlags = STARTF_USESHOWWINDOW; 
    sinfo.wShowWindow = SW_SHOWDEFAULT; 
    CreateProcess(NULL, "freecell.exe", NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &sinfo, &pinfo); 
    DWORD nIndex = WaitForSingleObject(pinfo.hProcess, INFINITE); 
    CloseHandle(pinfo.hThread); 
    CloseHandle(pinfo.hProcess);

	CWaitDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
