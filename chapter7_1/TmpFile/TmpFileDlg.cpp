// TmpFileDlg.cpp : implementation file
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
// CTmpFileDlg dialog

CTmpFileDlg::CTmpFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTmpFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTmpFileDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTmpFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTmpFileDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTmpFileDlg, CDialog)
	//{{AFX_MSG_MAP(CTmpFileDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CREATE, OnButtonCreate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTmpFileDlg message handlers

BOOL CTmpFileDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTmpFileDlg::OnPaint() 
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

HCURSOR CTmpFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTmpFileDlg::OnButtonCreate() 
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_EDIT_TMP_FILE, GetUniqueTmpFileName()); 
}

CString CTmpFileDlg::GetUniqueTmpFileName()
{
	TCHAR szTempPath[_MAX_PATH]; 
	DWORD dwResult = ::GetTempPath(_MAX_PATH, szTempPath); 
	TCHAR szTempFile[_MAX_PATH]; 
	UINT nResult = ::GetTempFileName(szTempPath, _T("ex"), 0, szTempFile); 
	CString strTempFile = szTempFile; 
	return strTempFile; 
}
