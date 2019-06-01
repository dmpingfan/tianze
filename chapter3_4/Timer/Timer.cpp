// Timer.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Timer.h"
#include "TimerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimerApp

BEGIN_MESSAGE_MAP(CTimerApp, CWinApp)
	//{{AFX_MSG_MAP(CTimerApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimerApp construction

CTimerApp::CTimerApp() : fout("timer.txt", ios::out)
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_nAccuracy = 1; 
	m_nTimerID1 = 0; 
	m_nTimerID2 = 0; 

	TIMECAPS tc; 
	if(timeGetDevCaps(&tc, sizeof(TIMECAPS)) == TIMERR_NOERROR)
	{
		m_nAccuracy = min(max(tc.wPeriodMin, TIMER_ACCURACY), tc.wPeriodMax); 
		timeBeginPeriod(m_nAccuracy); 
		InitializeTimer(); 
	}
}

CTimerApp::~CTimerApp()
{
	fout << "end timer." << endl; 
	timeKillEvent(m_nTimerID1); 
	timeKillEvent(m_nTimerID2); 
	timeEndPeriod(m_nAccuracy); 
}

void CTimerApp::InitializeTimer()
{
	m_nTimerID1 = timeSetEvent(TIMER1, m_nAccuracy, (LPTIMECALLBACK)Timer1Proc, (DWORD)this, TIME_PERIODIC); 
	if(m_nTimerID1 == 0)
		AfxMessageBox("不能计时", MB_OK); 
	else 
		fout << "start 1ms." << endl; 

	m_nTimerID2 = timeSetEvent(TIMER2, m_nAccuracy, (LPTIMECALLBACK)Timer2Proc, (DWORD)this, TIME_PERIODIC); 
	if(m_nTimerID2 == 0)
		AfxMessageBox("不能计时"); 
	else 
		fout << "start 2s." << endl; 
}

void PASCAL CTimerApp::Timer1Proc(UINT nTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
	static int i = 0; 
	CTimerApp* pApp = (CTimerApp*)dwUser; 
	DWORD dwTime = GetTickCount(); 
	pApp->fout << "1ms: " << dwTime << ", " << ++i << endl; 
}

void PASCAL CTimerApp::Timer2Proc(UINT nTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
	static int i = 0; 
	CTimerApp* pApp = (CTimerApp*)dwUser; 
	DWORD dwTime = GetTickCount(); 
	pApp->fout << "2s: " << dwTime << ", " << ++i << endl; 
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTimerApp object

CTimerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTimerApp initialization

BOOL CTimerApp::InitInstance()
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

	CTimerDlg dlg;
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
