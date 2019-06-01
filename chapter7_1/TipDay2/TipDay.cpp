// TipDay.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TipDay.h"
#include "TipDayDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTipDayApp

BEGIN_MESSAGE_MAP(CTipDayApp, CWinApp)
	ON_COMMAND(CG_IDS_TIPOFTHEDAY, ShowTipOfTheDay)
	//{{AFX_MSG_MAP(CTipDayApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTipDayApp construction

CTipDayApp::CTipDayApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTipDayApp object

CTipDayApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTipDayApp initialization

BOOL CTipDayApp::InitInstance()
{
	// CG: This line inserted by 'Tip of the Day' component.

	// Standard initialization
	ShowTipAtStartup();

	CTipDayDlg dlg;
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

void CTipDayApp::ShowTipAtStartup(void)
{
	// CG: This function added by 'Tip of the Day' component.

	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	if (cmdInfo.m_bShowSplash)
	{
        //CTipDlg dlg;
        //if (dlg.m_bStartup)
        //    dlg.DoModal();
		CTipDlg* pDlg = new CTipDlg(); 
		pDlg->Create(MAKEINTRESOURCE(IDD_TIP)); 
		pDlg->ShowWindow(SW_SHOW); 
	}

}

void CTipDayApp::ShowTipOfTheDay(void)
{
	// CG: This function added by 'Tip of the Day' component.

	CTipDlg dlg;
	dlg.DoModal();

}
