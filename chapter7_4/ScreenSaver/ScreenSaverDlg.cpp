// ScreenSaverDlg.cpp : implementation file
//

#include "stdafx.h"
//#include "ScreenSaver.h"
#include "ScreenSaverDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScreenSaverDlg dialog

CScreenSaverDlg::CScreenSaverDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScreenSaverDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScreenSaverDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CScreenSaverDlg::~CScreenSaverDlg()
{
}

void CScreenSaverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScreenSaverDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CScreenSaverDlg, CDialog)
	//{{AFX_MSG_MAP(CScreenSaverDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScreenSaverDlg message handlers

BOOL CScreenSaverDlg::OnInitDialog()
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

void CScreenSaverDlg::OnPaint() 
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

HCURSOR CScreenSaverDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

LRESULT CScreenSaverDlg::DefWindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return 0; 
}

LRESULT CScreenSaverDlg::WindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return 0; 
}
