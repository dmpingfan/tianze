// DesktopDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Desktop.h"
#include "DesktopDlg.h"

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
// CDesktopDlg dialog

CDesktopDlg::CDesktopDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDesktopDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDesktopDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bCancelEvent = FALSE; 
}

void CDesktopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDesktopDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDesktopDlg, CDialog)
	//{{AFX_MSG_MAP(CDesktopDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_REFRESH, OnButtonRefresh)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, OnButtonClose)
	ON_BN_CLICKED(IDC_CHECK_HIDE, OnCheckHide)
	ON_BN_CLICKED(IDC_CHECK_ENABLE, OnCheckEnable)
	ON_BN_CLICKED(IDC_BTN_ACTIVE, OnBtnActive)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_WND, OnSelchangedTreeWnd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDesktopDlg message handlers

BOOL CDesktopDlg::OnInitDialog()
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

void CDesktopDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDesktopDlg::OnPaint() 
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
HCURSOR CDesktopDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDesktopDlg::OnButtonRefresh() 
{
	// TODO: Add your control notification handler code here
	CTreeCtrl* pTree = (CTreeCtrl*)GetDlgItem(IDC_TREE_WND); 
    if(pTree != NULL)
    {
        pTree->DeleteAllItems(); 
        HWND hWnd = ::GetDesktopWindow(); 
        HTREEITEM hRoot = pTree->InsertItem("Desktop", 0, 0); 
        pTree->SetItemData(hRoot, (UINT)hWnd); 
		AddWindow(pTree, hRoot, hWnd); 

        pTree->Expand(hRoot, TVE_EXPAND); 
    }
}

void CDesktopDlg::AddWindow(CTreeCtrl* pTree, HTREEITEM hRoot, HWND hWndParent)
{
	HWND hWnd = ::GetWindow(hWndParent, GW_CHILD); 
	while(hWnd != NULL)
	{
		//if(::IsWindowEnabled(hWnd) && ::IsWindowVisible(hWnd))
		BOOL bAdd = TRUE; 
		if(!IsDlgButtonChecked(IDC_CHECK_SHOW_HIDE) && !::IsWindowVisible(hWnd) ||
			!IsDlgButtonChecked(IDC_CHECK_SHOW_DISABLE) && !::IsWindowEnabled(hWnd))
			bAdd = FALSE; 
		
		if(bAdd)
		{
			CString strWindow; 
			::GetWindowText(hWnd, strWindow.GetBuffer(256), 256); 
			strWindow.ReleaseBuffer(); 
			CString strClass; 
			::GetClassName(hWnd, strClass.GetBuffer(256), 256); 
			strClass.ReleaseBuffer(); 
			CString str; 
			str.Format("[%s] : (%s)", strWindow, strClass); 
			//if(!str.IsEmpty())
			{
				HTREEITEM hItem = pTree->InsertItem(str, 0, 0, hRoot); 
				pTree->SetItemData(hItem, (UINT)hWnd); 
				AddWindow(pTree, hItem, hWnd); 
			}
		}
		hWnd = ::GetWindow(hWnd, GW_HWNDNEXT); 
	}

}

void CDesktopDlg::OnBtnActive() 
{
	// TODO: Add your control notification handler code here
	CTreeCtrl* pTree = (CTreeCtrl*)GetDlgItem(IDC_TREE_WND); 
    if(pTree != NULL)
    {
        HTREEITEM hItem = pTree->GetSelectedItem(); 
        if(hItem != NULL)
        {
            HWND hWnd = (HWND)pTree->GetItemData(hItem); 
            if(hWnd != NULL && ::IsWindow(hWnd))
                ::SetForegroundWindow(hWnd); 
            else 
                pTree->SetItemData(hItem, NULL); 
        }
    }	
}

void CDesktopDlg::OnButtonClose() 
{
	// TODO: Add your control notification handler code here
	if(m_bCancelEvent)
		return; 
	
	CTreeCtrl* pTree = (CTreeCtrl*)GetDlgItem(IDC_TREE_WND); 
    if(pTree != NULL)
    {
        HTREEITEM hItem = pTree->GetSelectedItem(); 
        if(hItem != NULL)
        {
            HWND hWnd = (HWND)pTree->GetItemData(hItem); 
            if(hWnd != NULL && ::IsWindow(hWnd))
                ::SendMessage(hWnd, WM_CLOSE, 0, 0); 
            else 
                pTree->SetItemData(hItem, NULL); 
        }
    }
}

void CDesktopDlg::OnCheckHide() 
{
	// TODO: Add your control notification handler code here
	if(m_bCancelEvent)
		return; 

	CTreeCtrl* pTree = (CTreeCtrl*)GetDlgItem(IDC_TREE_WND); 
    if(pTree != NULL)
    {
        HTREEITEM hItem = pTree->GetSelectedItem(); 
        if(hItem != NULL)
        {
            HWND hWnd = (HWND)pTree->GetItemData(hItem); 
            if(hWnd != NULL && ::IsWindow(hWnd))
            {
                BOOL bVisible = ::IsWindowVisible(hWnd); 
                ::ShowWindow(hWnd, !bVisible);
            }
            else 
                pTree->SetItemData(hItem, NULL); 
        }
    }	
}

void CDesktopDlg::OnCheckEnable() 
{
	// TODO: Add your control notification handler code here
	CTreeCtrl* pTree = (CTreeCtrl*)GetDlgItem(IDC_TREE_WND); 
    if(pTree != NULL)
    {
        HTREEITEM hItem = pTree->GetSelectedItem(); 
        if(hItem != NULL)
        {
            HWND hWnd = (HWND)pTree->GetItemData(hItem); 
            if(hWnd != NULL && ::IsWindow(hWnd))
            {
                BOOL bEnable = ::IsWindowEnabled(hWnd); 
                ::EnableWindow(hWnd, !bEnable); 
            }
            else 
                pTree->SetItemData(hItem, NULL); 
        }
    }	
}

void CDesktopDlg::OnSelchangedTreeWnd(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	CTreeCtrl* pTree = (CTreeCtrl*)GetDlgItem(IDC_TREE_WND); 
    if(pTree != NULL)
    {
        HTREEITEM hItem = pTree->GetSelectedItem(); 
        if(hItem != NULL)
        {
            HWND hWnd = (HWND)pTree->GetItemData(hItem); 
            if(hWnd != NULL && ::IsWindow(hWnd))
            {
				m_bCancelEvent = TRUE; 
				CheckDlgButton(IDC_CHECK_HIDE, !::IsWindowVisible(hWnd)); 
				CheckDlgButton(IDC_CHECK_DISABLE, !::IsWindowEnabled(hWnd)); 
				m_bCancelEvent = FALSE; 
            }
            else 
                pTree->SetItemData(hItem, NULL); 
        }
    }

	*pResult = 0;
}
