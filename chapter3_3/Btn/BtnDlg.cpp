// BtnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Btn.h"
#include "BtnDlg.h"

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
// CBtnDlg dialog

CBtnDlg::CBtnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBtnDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBtnDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBtnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBtnDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBtnDlg, CDialog)
	//{{AFX_MSG_MAP(CBtnDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_NCPAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBtnDlg message handlers

BOOL CBtnDlg::OnInitDialog()
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
    m_btnOK.SubclassDlgItem(IDC_BUTTON_OK, this); 
    m_btnCancel.SubclassDlgItem(IDC_BUTTON_CANCEL, this); 

	HBITMAP hbm = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BTNOK), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADMAP3DCOLORS); 
	CBitmap bmp; 
	bmp.Attach(hbm); 

	m_btnOK.m_ilButton.Create(32, 32, ILC_COLOR8, 3, 1); 
	m_btnOK.m_ilButton.Add(&bmp, (CBitmap*)NULL); 
	bmp.Detach(); 

	hbm = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BTNCANCEL), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADMAP3DCOLORS); 
	bmp.Attach(hbm); 
	m_btnCancel.m_ilButton.Create(32, 32, ILC_COLOR8, 3, 1); 
	m_btnCancel.m_ilButton.Add(&bmp, (CBitmap*)NULL); 
	bmp.Detach(); 
		
    //CImageList ilButton; 
    //ilButton.Create(32, 32, ILC_COLOR8, 6, 1); 
    //ilButton.Add(&bmp, (CBitmap*)NULL); 
    //m_btnOK.m_bmNormal.Attach((HBITMAP)ilButton.ExtractIcon(0)); 
    //m_btnOK.m_bmPressed.Attach((HBITMAP)ilButton.ExtractIcon(1)); 
    //m_btnOK.m_bmHover.Attach((HBITMAP)ilButton.ExtractIcon(2)); 
    //m_btnCancel.m_bmNormal.Attach((HBITMAP)ilButton.ExtractIcon(3)); 
    //m_btnCancel.m_bmPressed.Attach((HBITMAP)ilButton.ExtractIcon(4)); 
    //m_btnCancel.m_bmHover.Attach((HBITMAP)ilButton.ExtractIcon(5)); 
    //ilButton.Detach(); 
    
    //HBITMAP hbm = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BTN1_NORMAL), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADMAP3DCOLORS ); 
    //m_btnOK.m_bmNormal.Attach(hbm); 
    //hbm = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BTN1_PRESS), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION); 
    //m_btnOK.m_bmPressed.Attach(hbm); 
    //hbm = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BTN1_HOVER), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION); 
    //m_btnOK.m_bmHover.Attach(hbm); 

    //hbm = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BTN2_NORMAL), IMAGE_BITMAP, 0, 0, 0); 
    //m_btnCancel.m_bmNormal.Attach(hbm); 
    //hbm = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BTN2_PRESS), IMAGE_BITMAP, 0, 0, 0); 
    //m_btnCancel.m_bmPressed.Attach(hbm); 
    //hbm = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BTN2_HOVER), IMAGE_BITMAP, 0, 0, 0); 
    //m_btnCancel.m_bmHover.Attach(hbm); 

    //m_btnOK.m_bmNormal.LoadBitmap(IDB_BTN1_NORMAL); 
    //m_btnOK.m_bmPressed.LoadBitmap(IDB_BTN1_PRESS); 
    //m_btnOK.m_bmHover.LoadBitmap(IDB_BTN1_HOVER); 
    //m_btnCancel.m_bmNormal.LoadBitmap(IDB_BTN2_NORMAL); 
    //m_btnCancel.m_bmPressed.LoadBitmap(IDB_BTN2_PRESS); 
    //m_btnCancel.m_bmHover.LoadBitmap(IDB_BTN2_HOVER); 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBtnDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBtnDlg::OnPaint() 
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
HCURSOR CBtnDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBtnDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CPoint pt = point; 
	ClientToScreen(&pt); 
	m_btnOK.ScreenToClient(&pt); 
	m_btnOK.OnMouseMove(nFlags, pt); 

	pt = point; 
	ClientToScreen(&pt); 
	m_btnCancel.ScreenToClient(&pt); 
	m_btnCancel.OnMouseMove(nFlags, pt); 
	CDialog::OnMouseMove(nFlags, point);
}

void CBtnDlg::OnNcPaint() 
{
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnNcPaint() for painting messages
	CDialog::OnNcPaint(); 

	CString strPath; 
	::GetWindowsDirectory(strPath.GetBuffer(_MAX_PATH), _MAX_PATH); 
	strPath.ReleaseBuffer();
	strPath += "\\notepad.exe"; //"C:\\WINDOWS\\SYSTEM32\\notepad.exe"
	
	SHFILEINFO finfo; 
	::SHGetFileInfo(strPath, 0, &finfo, sizeof(SHFILEINFOA), SHGFI_ICON); 
	
	CWindowDC dc(this); 
	dc.DrawIcon(30, 0, finfo.hIcon); 
	::DestroyIcon(finfo.hIcon); 

	HICON hIcon = ::ExtractIcon(AfxGetInstanceHandle(), "spider.exe", 0); 
	dc.DrawIcon(80, 0, hIcon); 
	::DestroyIcon(hIcon); 
}
