// FontDlg.cpp : implementation file
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
// CFontDlg dialog

CFontDlg::CFontDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFontDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFontDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFontDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFontDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFontDlg, CDialog)
	//{{AFX_MSG_MAP(CFontDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnBtnFont)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontDlg message handlers

BOOL CFontDlg::OnInitDialog()
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

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetDlgItemText(IDC_EDIT1, "How are you(你好吗)?"); 
    SetDlgItemText(IDC_BUTTON1, "Fine(很好)"); 
    SendDlgItemMessage(IDC_COMBO1, CB_ADDSTRING, 0, (WPARAM)"One(一)"); 
    SendDlgItemMessage(IDC_COMBO1, CB_ADDSTRING, 0, (WPARAM)"Two(二)"); 
    SendDlgItemMessage(IDC_COMBO1, CB_ADDSTRING, 0, (WPARAM)"Three(三)"); 
    SendDlgItemMessage(IDC_COMBO1, CB_ADDSTRING, 0, (WPARAM)"Four(四)"); 
    SendDlgItemMessage(IDC_COMBO1, CB_SETCURSEL, 0, 0); 
    SendDlgItemMessage(IDC_COMBO2, CB_ADDSTRING, 0, (WPARAM)"One(一)"); 
    SendDlgItemMessage(IDC_COMBO2, CB_ADDSTRING, 0, (WPARAM)"Two(二)"); 
    SendDlgItemMessage(IDC_COMBO2, CB_ADDSTRING, 0, (WPARAM)"Three(三)"); 
    SendDlgItemMessage(IDC_COMBO2, CB_ADDSTRING, 0, (WPARAM)"Four(四)"); 
    SendDlgItemMessage(IDC_COMBO2, CB_SETCURSEL, 0, 0); 
    SendDlgItemMessage(IDC_COMBO3, CB_ADDSTRING, 0, (WPARAM)"One(一)"); 
    SendDlgItemMessage(IDC_COMBO3, CB_ADDSTRING, 0, (WPARAM)"Two(二)"); 
    SendDlgItemMessage(IDC_COMBO3, CB_ADDSTRING, 0, (WPARAM)"Three(三)"); 
    SendDlgItemMessage(IDC_COMBO3, CB_ADDSTRING, 0, (WPARAM)"Four(四)"); 
    SendDlgItemMessage(IDC_COMBO3, CB_SETCURSEL, 0, 0); 
    SendDlgItemMessage(IDC_LIST1, LB_ADDSTRING, 0, (WPARAM)"One(一)"); 
    SendDlgItemMessage(IDC_LIST1, LB_ADDSTRING, 0, (WPARAM)"Two(二)"); 
    SendDlgItemMessage(IDC_LIST1, LB_ADDSTRING, 0, (WPARAM)"Three(三)"); 
    SendDlgItemMessage(IDC_LIST1, LB_ADDSTRING, 0, (WPARAM)"Four(四)"); 
    SendDlgItemMessage(IDC_LIST1, LB_SETCURSEL, 0, 0); 

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFontDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFontDlg::OnPaint() 
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

HCURSOR CFontDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFontDlg::OnBtnFont() 
{
	// TODO: Add your control notification handler code here
    LOGFONT lf; 
    CFont* pFont = GetFont(); 
    pFont->GetLogFont(&lf); 
	CFontDialog dlg(&lf); 
    if(dlg.DoModal())
    {
        dlg.GetCurrentFont(&lf); 
        CFont font; 
        font.CreateFontIndirect(&lf); 
        //SetFont(&font); 
        //font.Detach(); 
        ChangeDlgFont(&font); 
        font.Detach(); 
    }
}

void CFontDlg::ChangeDlgFont(CFont* pFont)
{
    CDC* pDC = GetDC(); 
    TEXTMETRIC tmOld, tmNew; 
    CFont* pFont2 = pDC->SelectObject(GetFont()); 
    pDC->GetTextMetrics(&tmOld); 
    pDC->SelectObject(pFont); 
    pDC->GetTextMetrics(&tmNew); 
    pDC->SelectObject(pFont2); 
    ReleaseDC(pDC); 

    CRect rect, rect2; 
    GetClientRect(&rect);
    GetWindowRect(&rect2);  
    int xDiff = rect2.Width() - rect.Width(); 
    int yDiff = rect2.Height() - rect.Height(); 
    int nOldHeight = tmOld.tmHeight + tmOld.tmExternalLeading; 
    int nNewHeight = tmNew.tmHeight + tmNew.tmExternalLeading; 

    CRect rectNew; 
    rectNew.left = rectNew.top = 0; 
    rectNew.right = ::MulDiv(rect.right, tmNew.tmAveCharWidth, tmOld.tmAveCharWidth); 
    rectNew.bottom = ::MulDiv(rect.bottom, nNewHeight, nOldHeight); 

    CRect rectNew2; 
    //rectNew2.left = rect2.left; 
    //rectNew2.top = rect2.top; 
    //rectNew2.right = rect2.left + rectNew.right + xDiff; 
    //rectNew2.bottom = rect2.top + rectNew.bottom + yDiff; 
    rectNew2.left = rect2.left + (rect.right - rectNew.right) / 2; 
    rectNew2.top = rect2.top + (rect.bottom - rectNew.bottom) / 2; 
    rectNew2.right = rectNew2.left + rectNew.right + xDiff; 
    rectNew2.bottom = rectNew2.top + rectNew.bottom + yDiff; 

    MoveWindow(rectNew2); 
    SetFont(pFont); 

    CWnd* pChildWnd = GetWindow(GW_CHILD); 
    while(pChildWnd)
    {
        pChildWnd->SetFont(pFont); 
        pChildWnd->GetWindowRect(rect2); 

        CString strClass; 
        ::GetClassName(pChildWnd->GetSafeHwnd(), strClass.GetBufferSetLength(32), 31); 
        strClass.MakeUpper(); 
        if(strClass == _T("COMBOBOX"))
        {
            pChildWnd->SendMessage(CB_GETDROPPEDCONTROLRECT, 0, (LPARAM)&rect); 
            rect2.right = rect.right; 
            rect2.bottom = rect.bottom; 
        }

        ScreenToClient(&rect2); 
        rect2.left = MulDiv(rect2.left, tmNew.tmAveCharWidth, tmOld.tmAveCharWidth); 
        rect2.right = MulDiv(rect2.right, tmNew.tmAveCharWidth, tmOld.tmAveCharWidth); 
        rect2.top = MulDiv(rect2.top, nNewHeight, nOldHeight); 
        rect2.bottom = MulDiv(rect2.bottom, nNewHeight, nOldHeight); 
        pChildWnd->MoveWindow(&rect2); 

        pChildWnd = pChildWnd->GetNextWindow(GW_HWNDNEXT); 
    }
}
