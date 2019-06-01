// DeleteTreeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DeleteTree.h"
#include "DeleteTreeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeleteTreeDlg dialog

CDeleteTreeDlg::CDeleteTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleteTreeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeleteTreeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDeleteTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeleteTreeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDeleteTreeDlg, CDialog)
	//{{AFX_MSG_MAP(CDeleteTreeDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_FOLDER, OnButtonFolder)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeleteTreeDlg message handlers

BOOL CDeleteTreeDlg::OnInitDialog()
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

void CDeleteTreeDlg::OnPaint() 
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

HCURSOR CDeleteTreeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDeleteTreeDlg::OnButtonFolder() 
{
	// TODO: Add your control notification handler code here
    TCHAR szDir[MAX_PATH]; 
	BROWSEINFO bi; 
    bi.hwndOwner = GetSafeHwnd(); 
    bi.pidlRoot = NULL; 
    bi.pszDisplayName = szDir; 
    bi.lpszTitle = "Selecte a directory"; 
    bi.ulFlags = BIF_RETURNONLYFSDIRS; 
    bi.lpfn = NULL; 
    bi.lParam = 0; 
    bi.iImage = 0; 
    
    ITEMIDLIST* pidl = SHBrowseForFolder(&bi); 
    if(pidl == NULL)
        szDir[0] = 0; 

    if(!SHGetPathFromIDList(pidl, szDir))
        szDir[0] = 0; 

    SetDlgItemText(IDC_EDIT_FOLDER, szDir); 	
    DlgDirListComboBox(szDir, IDC_COMBO_DRIVE, IDC_STATIC_PATH, DDL_DIRECTORY | DDL_DRIVES); 
    DlgDirList(szDir, IDC_LIST_FILE, IDC_STATIC_PATH, DDL_READWRITE | DDL_READONLY | DDL_HIDDEN | DDL_SYSTEM | DDL_ARCHIVE); 
}

void CDeleteTreeDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	CString strPath; 
    GetDlgItemText(IDC_EDIT_FOLDER, strPath); 
    DeleteTree(strPath); 
}

BOOL CDeleteTreeDlg::DeleteTree(CString strPath)
{
    return RemoveDirectory(strPath); 
}

BOOL CDeleteTreeDlg::RemoveDirectory(CString strDir)
{
    //WIN32_FIND_DATA ff; 
    //HANDLE hFileFind = FindFirstFile(strDir + "\\*.*", &ff); 
    //if(hFileFind != INVALID_HANDLE_VALUE)
    //{
    //    CString szFile; 
    //    CString szPath; 
    //    CStringList listFile; 
    //    CStringList listDir; 
    //    do
    //    {
    //        szFile = ff.cFileName; 
    //        if(szFile == "." || szFile == "..")
    //            continue; 

    //        szPath = strDir + "\\" + szFile; 
    //        if(ff.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
    //            listDir.AddTail(szPath); 
    //        else 
    //            listFile.AddTail(szPath); 

    //    }while(FindNextFile(hFileFind, &ff)); 
    //    FindClose(hFileFind); 
    
    //    POSITION pos = listFile.GetHeadPosition(); 
    //    while(pos != NULL)
    //    {
    //        DeleteFile(listFile.GetNext(pos)); 
    //        ::SHFileOperation(&fo); 
    //    }

    //    pos = listDir.GetHeadPosition(); 
    //    while(pos != NULL)
    //    {
    //        CString szPath = listDir.GetNext(pos); 
    //        RemoveDirectory(szPath); 
    //        //::RemoveDirectory(szPath); 
    //    }
    //}

    //::RemoveDirectory(strDir); 
    //return TRUE; 

    strDir += "\\*.*"; 
    SHFILEOPSTRUCT fo; 
    memset(&fo, 0, sizeof(SHFILEOPSTRUCT)); 
    fo.hwnd = GetSafeHwnd(); 
    fo.lpszProgressTitle = "Delete..."; 
    fo.wFunc = FO_DELETE ; 
    fo.fFlags = FOF_NOCONFIRMATION; 
    fo.pFrom = strDir.GetBuffer(strDir.GetLength() + 1); 
    strDir.ReleaseBuffer(); 
    SHFileOperation(&fo); 
    return TRUE; 
}