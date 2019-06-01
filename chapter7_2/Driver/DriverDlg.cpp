// DriverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Driver.h"
#include "DriverDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDriverDlg dialog

CDriverDlg::CDriverDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDriverDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDriverDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDriverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDriverDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDriverDlg, CDialog)
	//{{AFX_MSG_MAP(CDriverDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_DRIVER, OnSelchangeComboDriver)
	ON_BN_CLICKED(IDC_BUTTON_SET_LABEL, OnButtonSetLabel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDriverDlg message handlers

BOOL CDriverDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO_DRIVER); 
    CRect rect; 
    pCombo->GetWindowRect(&rect); 
    pCombo->SetDroppedWidth(rect.Width() * 2); 

    DWORD nLen = GetLogicalDriveStrings(0, NULL) * sizeof(TCHAR); 
    if(nLen > 0)
    {
        LPTSTR lpsz = new TCHAR[nLen]; 
        LPTSTR lpszOld = lpsz; 
        GetLogicalDriveStrings(nLen, lpsz); 
        while(*lpsz != 0)
        {
            pCombo->AddString(lpsz); 
            lpsz = _tcschr(lpsz, 0) + 1; 
        }

        delete[] lpszOld; 
    }

    if(pCombo->GetCount() > 0)
        pCombo->SetCurSel(0); 

    pCombo->SetFocus(); 
    OnSelchangeComboDriver(); 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDriverDlg::OnPaint() 
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

HCURSOR CDriverDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDriverDlg::OnSelchangeComboDriver() 
{
	// TODO: Add your control notification handler code here
	CString str, str2; 
    CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO_DRIVER); 
    int nSel = pCombo->GetCurSel(); 
    if(nSel >= 0)
    {
        pCombo->GetLBText(nSel, str); 
        int nType = GetDriveType(str); 
        switch(nType)
        {
            case DRIVE_UNKNOWN:
                str2 = "UNKNOWN"; 
                break; 
            case DRIVE_NO_ROOT_DIR:
                str2 = "NO ROOT DIR"; 
                break; 
            case DRIVE_REMOVABLE:
                str2 = "REMOVABLE"; 
                break; 
            case DRIVE_FIXED:
                str2 = "FIXED"; 
                break; 
            case DRIVE_REMOTE:
                str2 = "REMOTE"; 
                break; 
            case DRIVE_CDROM:
                str2 = "CDROM"; 
                break; 
            case DRIVE_RAMDISK:
                str2 = "RAMDISK"; 
                break; 
        }

        SetDlgItemText(IDC_EDIT_TYPE, str2); 
        DWORD dwSize, spc, bps, nfc, tnc; 
        GetDiskFreeSpace(str, &spc, &bps, &nfc, &tnc); 
        dwSize = tnc / 1024 * spc * bps / 1024; 
        SetDlgItemInt(IDC_EDIT_TOTAL_SPACE, dwSize); 
        dwSize = nfc / 1024 * spc * bps / 1024; 
        SetDlgItemInt(IDC_EDIT_FREE_SPACE, dwSize); 

        LPTSTR szVolume = new TCHAR[12]; 
        szVolume[0] = 0; 
        LPTSTR szFileSystem = new TCHAR[12]; 
        szFileSystem[0] = 0; 
        DWORD dwSerial, dwMaxLen, dwFlag; 
        dwSerial = dwMaxLen = dwFlag = 0; 
        GetVolumeInformation(str, szVolume, 12, &dwSerial, &dwMaxLen, &dwFlag, szFileSystem, 12); 
        LPTSTR szSerial = new TCHAR[30]; 
        sprintf(szSerial, "%X", dwSerial); 
        SetDlgItemText(IDC_EDIT_SERIAL_NO, szSerial); 
        SetDlgItemText(IDC_EDIT_VOLUME_LABEL, szVolume); 
        SetDlgItemText(IDC_EDIT_FILE_SYSTEM, szFileSystem); 
        delete[] szSerial; 
        delete[] szVolume; 
        delete[] szFileSystem; 
    }
}

void CDriverDlg::OnButtonSetLabel() 
{
	// TODO: Add your control notification handler code here
	CString str, str2; 
    CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO_DRIVER); 
    int nSel = pCombo->GetCurSel(); 
    if(nSel >= 0)
    {
        pCombo->GetLBText(nSel, str); 
        GetDlgItemText(IDC_EDIT_VOLUME_LABEL, str2); 
        SetVolumeLabel(str, str2); 
    }	
}
