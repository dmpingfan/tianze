// TicketDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ticket.h"
#include "TicketDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTicketDlg dialog

CTicketDlg::CTicketDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTicketDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTicketDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTicketDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTicketDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTicketDlg, CDialog)
	//{{AFX_MSG_MAP(CTicketDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SELL, OnButtonSell)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTicketDlg message handlers

BOOL CTicketDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTicketDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTicketDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTicketDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTicketDlg::OnButtonSell() 
{
	// TODO: Add your control notification handler code here
	m_nTicket = 1000; 
	InitializeCriticalSection(&m_cs); 
	for(int i=0; i<10; i++)
	{
		m_hThreadArray[i] = CreateThread(NULL, 0, CTicketDlg::StartThreadProc, this, CREATE_SUSPENDED, NULL); 
	}

	for(i=0; i<10; i++)
		::ResumeThread(m_hThreadArray[i]); 

	int nCount = 10; 
	DWORD dwExit; 
	CString str; 
	while(nCount > 0)
	{
		DWORD dwWait = ::WaitForMultipleObjects(nCount, m_hThreadArray, FALSE, INFINITE);
		if(dwWait >= WAIT_OBJECT_0 && dwWait < WAIT_OBJECT_0 + nCount)
		{
			GetExitCodeThread(m_hThreadArray[dwWait], &dwExit); 
			str.Format("Thread [0x%x] sold tickets [%d]", m_hThreadArray[dwWait], dwExit); 
			MessageBox(str); 
			
			if(dwWait != nCount -1)
				m_hThreadArray[dwWait] = m_hThreadArray[nCount -1]; 
			nCount --; 
		}
	}

	::DeleteCriticalSection(&m_cs); 
}

DWORD PASCAL CTicketDlg::StartThreadProc(LPVOID pParam)
{
	return ((CTicketDlg*)pParam)->SellTicketProc(); 
}

DWORD CTicketDlg::SellTicketProc()
{
	int nCount = 0; 
	while(m_nTicket> 0)
	{
		::EnterCriticalSection(&m_cs); 
		if(m_nTicket > 0)
		{
			m_nTicket --; 
			nCount ++; 
		}
		::LeaveCriticalSection(&m_cs); 
		//Sleep(1); 
	}

	return nCount; 
}