// RarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Rar.h"
#include "RarDlg.h"

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
// CRarDlg dialog

CRarDlg::CRarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRarDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRarDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRarDlg, CDialog)
	//{{AFX_MSG_MAP(CRarDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_BROWSE_INPUT, OnButtonBrowseInput)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE_OUTPUT, OnButtonBrowseOutput)
	ON_BN_CLICKED(IDC_BUTTON_RUN, OnButtonRun)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRarDlg message handlers

BOOL CRarDlg::OnInitDialog()
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

void CRarDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRarDlg::OnPaint() 
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
HCURSOR CRarDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRarDlg::OnButtonBrowseInput() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE); ; 
	if(dlg.DoModal() == IDOK)
		SetDlgItemText(IDC_EDIT_INPUT, dlg.GetPathName()); 
}



void CRarDlg::OnButtonBrowseOutput() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(FALSE); 
	if(dlg.DoModal() == IDOK)
		SetDlgItemText(IDC_EDIT_OUTPUT, dlg.GetPathName()); 
}

void CRarDlg::OnButtonRun() 
{
	// TODO: Add your control notification handler code here
	CString strBatch; 
	CString strInputFile; 
	GetDlgItemText(IDC_EDIT_INPUT, strInputFile); 
	CString strOutputFile; 
	GetDlgItemText(IDC_EDIT_OUTPUT, strOutputFile); 
	if(CreateBatchFile(strInputFile, strOutputFile, strBatch))
	{
		RunBatch(strBatch); 
		DeleteFile(strBatch); 
	}
}

BOOL CRarDlg::CreateBatchFile(CString strInputFile, CString strOutputFile, CString& strBatch)
{
	TCHAR dir[_MAX_PATH]; 
	GetModuleFileName(AfxGetInstanceHandle(), dir, _MAX_PATH); 
	strBatch = dir; 
	strBatch = strBatch.Left(strBatch.ReverseFind('\\')); 
	strBatch += "\\rar_file.bat"; 

	CStdioFile file; 
	CFileException e; 
	if(!file.Open(strBatch, CFile::modeCreate | CFile::modeRead | CFile::modeWrite, &e))
	{
		e.ReportError(); 
		return FALSE; 
	}

	CString str; 
	str = "\"C:\\Program Files\\WinRAR\\rar.exe\" a -r "; 
	str += strOutputFile + ".rar ";
	str += strInputFile + "\n"; 
	file.WriteString(str); 
	file.Close(); 
	return TRUE; 
}

BOOL CRarDlg::RunBatch(CString strBatch)
{
	STARTUPINFO sinfo; 
	memset(&sinfo, 0, sizeof(STARTUPINFO)); 
	PROCESS_INFORMATION pinfo; 
	BOOL bOK = CreateProcess(NULL, strBatch.GetBuffer(strBatch.GetLength()), NULL, NULL, FALSE, CREATE_DEFAULT_ERROR_MODE, NULL, NULL, &sinfo, &pinfo); 
	if(bOK && WaitForSingleObject(pinfo.hProcess, INFINITE) == WAIT_OBJECT_0)
	{
    	CString str; 
    	str.Format("Create process [0x%x] successfully.", pinfo.dwProcessId); 
    	MessageBox(str); 
		CloseHandle(pinfo.hProcess); 
		CloseHandle(pinfo.hThread);
	}

	strBatch.ReleaseBuffer(); 
	return bOK; 
}
