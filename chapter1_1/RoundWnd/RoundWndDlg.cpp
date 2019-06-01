// RoundWndDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RoundWnd.h"
#include "RoundWndDlg.h"

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
// CRoundWndDlg dialog

CRoundWndDlg::CRoundWndDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRoundWndDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRoundWndDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRoundWndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRoundWndDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRoundWndDlg, CDialog)
	//{{AFX_MSG_MAP(CRoundWndDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_NCHITTEST()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoundWndDlg message handlers

BOOL CRoundWndDlg::OnInitDialog()
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
    CRect rect; 
    GetClientRect(rect); 
	m_rgn.CreateEllipticRgn(0, 0, rect.Width(), rect.Height()); 
    SetWindowRgn(m_rgn, TRUE); 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRoundWndDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRoundWndDlg::OnPaint() 
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
		//CDialog::OnPaint();
        CPaintDC dc(this);
        dc.SelectStockObject(NULL_PEN); 
        COLORREF color = RGB(255, 255, 255); 
        BYTE byRed = GetRValue(color); 
        BYTE byGreen = GetGValue(color); 
        BYTE byBlue = GetBValue(color); 

        CRect rect; 
        GetClientRect(rect); 
        int nUnits = min(rect.right, rect.bottom); 
        float fStepHorz = (float)rect.right / nUnits; 
        float fStepVert = (float)rect.bottom / nUnits; 
        int nEllipse = nUnits / 3; 

        CBrush brush; 
        for(int i = 0; i < nEllipse;  i ++)
        {
            brush.CreateSolidBrush(RGB(i * byRed / nEllipse, i * byGreen / nEllipse, i * byBlue / nEllipse)); 
            dc.SelectObject(&brush); 
            dc.Ellipse(
                (int)fStepHorz * i, //(int)fStepHorz * 2
                (int)fStepVert * i, 
                rect.right - (int)fStepHorz * i + 1, 
                rect.bottom - (int)fStepVert * i + 1); 
            brush.DeleteObject(); 
        }
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRoundWndDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

UINT CRoundWndDlg::OnNcHitTest(CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	UINT nHitTest = CDialog::OnNcHitTest(point);
    return (nHitTest == HTCLIENT) ? HTCAPTION : nHitTest; 
}
