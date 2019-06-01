// UseMenu.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "UseMenu.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUseMenuApp

BEGIN_MESSAGE_MAP(CUseMenuApp, CWinApp)
	//{{AFX_MSG_MAP(CUseMenuApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUseMenuApp construction

CUseMenuApp::CUseMenuApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CUseMenuApp object

CUseMenuApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CUseMenuApp initialization

BOOL CUseMenuApp::InitInstance()
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

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));


	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object.

	CMainFrame* pFrame = new CMainFrame;
	m_pMainWnd = pFrame;

	// create and load the frame with its resources

	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);




	// The one and only window has been initialized, so show and update it.
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CUseMenuApp message handlers





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
	virtual BOOL OnInitDialog();
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
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
	ON_WM_MEASUREITEM()
	ON_WM_DRAWITEM()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CUseMenuApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();

	// calculate menu row count
	CRect rcFrame, rcClient; 
	m_pMainWnd->GetWindowRect(&rcFrame); 
	m_pMainWnd->GetClientRect(&rcClient); 
	int caption  = ::GetSystemMetrics(SM_CYCAPTION); 
	int border = ::GetSystemMetrics(SM_CYFRAME); 
	int menu = ::GetSystemMetrics(SM_CYMENU); 
	int rows = (rcFrame.Height() - rcClient.Height() - caption - 2 * border) / menu; 
	CString str; 
	str.Format("Menu take rows : %d", rows); 
	AfxMessageBox(str); 
}

/////////////////////////////////////////////////////////////////////////////
// CUseMenuApp message handlers


BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
    
    //CMenu menu; 
    //menu.CreateMenu(); 
    //menu.AppendMenu(MF_STRING, IDM_MENU0, "&File"); 
    //menu.AppendMenu(MF_STRING, IDM_MENU1, "&Edit"); 
    //menu.AppendMenu(MF_STRING, IDM_MENU2, "&View"); 
    //menu.AppendMenu(MF_STRING, IDM_MENU3, "&Help"); 
    //menu.InsertMenu(IDM_MENU2, MF_BYCOMMAND, IDM_ITEM0, "&About"); 
    //SetMenu(&menu); 
    //menu.Detach(); 

	CMenu menu0, menu1; 
	menu1.CreateMenu(); 
	//menu1.CreatePopupMenu(); 
	menu1.AppendMenu(MF_STRING | MF_OWNERDRAW, IDM_ITEM0, "&Copy"); 
	menu1.AppendMenu(MF_STRING | MF_OWNERDRAW, IDM_ITEM1, "&Cut"); 
	menu1.AppendMenu(MF_STRING | MF_OWNERDRAW, IDM_ITEM2, "&Paste"); 
	menu1.AppendMenu(MF_SEPARATOR | MF_OWNERDRAW, IDM_ITEM3, ""); 
	menu1.AppendMenu(MF_STRING | MF_OWNERDRAW, IDM_ITEM4, "&Select All"); 
	menu1.AppendMenu(MF_SEPARATOR | MF_OWNERDRAW, IDM_ITEM5, ""); 
	menu1.AppendMenu(MF_STRING | MF_OWNERDRAW, IDM_ITEM6, "&Delete"); 

	CString strText; 
	menu1.GetMenuString(IDM_ITEM6, strText, MF_BYCOMMAND); 

	menu0.CreateMenu(); 
	//menu0.CreatePopupMenu(); 
	menu0.AppendMenu(MF_POPUP, (UINT)menu1.m_hMenu, "&Edit"); 
	SetMenu(&menu0); 

	menu0.Detach(); 
	menu1.Detach(); 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAboutDlg::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	// TODO: Add your message handler code here and/or call default
	
	if(nIDCtl == 0)
	{
		NONCLIENTMETRICS ncm; 
		memset(&ncm, 0, sizeof(NONCLIENTMETRICS)); 
		ncm.cbSize = sizeof(NONCLIENTMETRICS); 

		SIZE size; 
		size.cx  = size.cy = 0; 
		if(SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(NONCLIENTMETRICS), &ncm, 0))
		{
			HFONT hFontMenu = CreateFontIndirect(&ncm.lfMenuFont); 
			//char szText[_MAX_PATH]; 
			//CMenu* pMenu = GetMenu(); 
			//pMenu = pMenu->GetSubMenu(0); 
			//pMenu->GetMenuString(lpMeasureItemStruct->itemID, szText, _MAX_PATH, MF_BYCOMMAND); //MF_BYPOSITION); 
			//::GetMenuString((HMENU)lpMeasureItemStruct->itemID, , szText, _MAX_PATH, MF_BYPOSITION); 

			char* szText = "Ni Hao Ma? Wo Hen Xiang Ni."; 

			HFONT hFontOld; 
			HDC hDC = ::GetDC(NULL); 
			hFontOld = (HFONT)::SelectObject(hDC, hFontMenu); 
			GetTextExtentPoint32(hDC, szText, lstrlen(szText), &size); 
			::SelectObject(hDC, hFontOld); 
			::ReleaseDC(NULL, hDC); 
		}

		lpMeasureItemStruct->itemWidth = size.cx; 
		lpMeasureItemStruct->itemHeight = size.cy; 
	}

	CDialog::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}

void CAboutDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your message handler code here and/or call default
	
	if(nIDCtl == 0)
	{
		CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC); 
		HMENU hMenu = (HMENU)lpDrawItemStruct->hwndItem; 
		//char szText[_MAX_PATH]; 
		//::GetMenuString(hMenu, 0, szText, _MAX_PATH, MF_BYPOSITION); 
		char* szText = "Ni Hao Ma? Wo Hen Xiang Ni."; 
		pDC->DrawText(szText, &lpDrawItemStruct->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
		//::GetMenuItemInfo(hMenu, 0, TRUE, NULL); 
	}

	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
