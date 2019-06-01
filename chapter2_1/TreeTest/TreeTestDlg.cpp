// TreeTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TreeTest.h"
#include "TreeTestDlg.h"

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
// CTreeTestDlg dialog

CTreeTestDlg::CTreeTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTreeTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTreeTestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    m_nTop = -1; 
}

void CTreeTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTreeTestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTreeTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTreeTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_REFRESH, OnRefresh)
	ON_WM_CTLCOLOR()
	ON_EN_KILLFOCUS(IDC_EDIT_TEST, OnKillfocusEditTest)
	ON_LBN_KILLFOCUS(IDC_LIST_TEST, OnKillfocusListTest)
	ON_NOTIFY(NM_KILLFOCUS, IDC_TREE_TEST, OnKillfocusTreeTest)
	ON_NOTIFY(NM_KILLFOCUS, IDC_TREE_TEST2, OnKillfocusTreeTest2)
	//}}AFX_MSG_MAP
    ON_MESSAGE(WM_VALIDATE_PARAMS, OnValidateParams)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeTestDlg message handlers

BOOL CTreeTestDlg::OnInitDialog()
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
	m_tree.SubclassDlgItem(IDC_TREE_TEST, this); 
    CString strPath = "E:\\code\\mfc\\msdn\\C++ Q&A"; 
    HTREEITEM hRoot = m_tree.InsertItem(strPath); 
    AddTreeNode(&m_tree, hRoot, strPath); 
    m_tree.Expand(hRoot, TVE_EXPAND); 

    CTreeCtrl* pCtrl = (CTreeCtrl*)GetDlgItem(IDC_TREE_TEST2); 
    hRoot = pCtrl->InsertItem(strPath); 
    AddTreeNode(pCtrl, hRoot, strPath); 
    pCtrl->Expand(hRoot, TVE_EXPAND); 

    m_listbox.SubclassDlgItem(IDC_LIST_TEST, this); 
    //AddListItem((CListBox*)GetDlgItem(IDC_LIST_TEST), strPath); 
    OnRefresh(); 

    m_edit.SubclassDlgItem(IDC_EDIT_TEST, this); 

    CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_TEST); 
    pSpin->SetRange(0, 10000); 

    CButton* pBtn = (CButton*)GetDlgItem(ID_REFRESH); 
    pBtn->SetIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME)); //AfxGetApp()->LoadStandardIcon(IDI_APPLICATION)); 

    pBtn = (CButton*)GetDlgItem(IDOK); 
    pBtn->SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BUTTON))); 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTreeTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTreeTestDlg::OnPaint() 
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
HCURSOR CTreeTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTreeTestDlg::AddTreeNode(CTreeCtrl* pTree, HTREEITEM hParent, CString strPath)
{
    CFileFind ff; 
    ff.FindFile(strPath + "\\*.*"); 
    while(ff.FindNextFile())
    {
        if(ff.IsDots())
            continue; 
        
        CString strFileName = ff.GetFileName(); 
        HTREEITEM hItem = pTree->InsertItem(strFileName, hParent); 
        if(ff.IsDirectory())
            AddTreeNode(pTree, hItem, strPath + "\\" + strFileName); 
    }
    ff.Close(); 

    pTree->Expand(hParent, TVE_EXPAND); 
}

void CTreeTestDlg::AddListItem(CListBox* pList, CString strPath)
{
    CFileFind ff; 
    ff.FindFile(strPath + "\\*.*"); 
    while(ff.FindNextFile())
    {
        if(ff.IsDots())
            continue; 
        
        CString strFileName = ff.GetFileName(); 
        pList->AddString(strFileName); 
        if(ff.IsDirectory())
            AddListItem(pList, strPath + "\\" + strFileName); 
    }
    ff.Close(); 

}

void CTreeTestDlg::OnRefresh() 
{
	// TODO: Add your control notification handler code here
    CString strPath = "E:\\code\\mfc\\msdn\\C++ Q&A"; 
    CListBox* pList = (CListBox*)GetDlgItem(IDC_LIST_TEST); 
    pList->SetRedraw(FALSE); 
    int nCount = pList->GetCount(); 
    while(nCount--)
        pList->DeleteString(nCount); 
	AddListItem(pList, strPath); 
    pList->SetRedraw(TRUE); 
    
    CRect rect; 
    pList->GetWindowRect(&rect); 
    InvalidateRect(&rect); 
}

HBRUSH CTreeTestDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr; 
	
	// TODO: Change any attributes of the DC here
	if(nCtlColor == CTLCOLOR_EDIT)
    {
        pDC->SetTextColor(RGB(0, 255, 0)); 
        pDC->SetBkColor(RGB(0, 0, 0)); 
    }
    else
        hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

    if(nCtlColor == CTLCOLOR_LISTBOX && pWnd->GetDlgCtrlID() == IDC_LIST_TEST)
    {
        CListBox* pList = (CListBox*)pWnd; 
        int nTop = pList->GetTopIndex(); 
        if(nTop != m_nTop)
        {
            m_nTop = nTop; 
            if(m_nTop >= 0)
            {
                CString strText; 
                pList->GetText(m_nTop, strText); 
                SetDlgItemText(IDC_EDIT_TEST, strText); 
            }
        }
    }

	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CTreeTestDlg::OnKillfocusEditTest() 
{
	// TODO: Add your control notification handler code here
	PostMessage(WM_VALIDATE_PARAMS, IDC_EDIT_TEST); 
}

void CTreeTestDlg::OnKillfocusListTest() 
{
	// TODO: Add your control notification handler code here
	PostMessage(WM_VALIDATE_PARAMS, IDC_LIST_TEST); 
}

void CTreeTestDlg::OnKillfocusTreeTest(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	PostMessage(WM_VALIDATE_PARAMS, IDC_TREE_TEST); 
	*pResult = 0;
}

void CTreeTestDlg::OnKillfocusTreeTest2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	PostMessage(WM_VALIDATE_PARAMS, IDC_TREE_TEST2); 
	*pResult = 0;
}

BOOL CTreeTestDlg::OnValidateParams(WPARAM wParam, LPARAM lParam)
{
    BOOL bWrong = rand() % 2; 
    switch(wParam)
    {
        case IDC_EDIT_TEST:
        case IDC_LIST_TEST:
        case IDC_TREE_TEST:
        case IDC_TREE_TEST2:
            if(bWrong)
            {
                CString str; 
                str.Format("Wrong parameter for %d", wParam); 
                MessageBox(str); 
                GetDlgItem(wParam)->SetFocus(); 
            }
            break; 
    }

    return TRUE; 
}
