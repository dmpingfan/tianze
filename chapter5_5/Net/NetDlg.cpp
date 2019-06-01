// NetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Net.h"
#include "NetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNetDlg dialog

CNetDlg::CNetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNetDlg, CDialog)
	//{{AFX_MSG_MAP(CNetDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_HANG_UP, OnButtonHangUp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetDlg message handlers

BOOL CNetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CString str = GetBIOS(); 
    SetDlgItemText(IDC_EDIT_BIOS, str); 

    str = GetIP();
    SetDlgItemText(IDC_EDIT_IP, str); 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNetDlg::OnPaint() 
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

HCURSOR CNetDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNetDlg::OnButtonHangUp() 
{
	// TODO: Add your control notification handler code here
	BOOL bOK = FALSE; 
    RASCONN ras[20]; 
    ras[0].dwSize = sizeof(RASCONN); 
    DWORD dwSize = sizeof(ras); 
    DWORD dwNumber = 0; 
    if(RasEnumConnections(ras, &dwSize, &dwNumber) == 0)
    {
        bOK = TRUE; 
        for(int i=0; i<dwNumber; i++)
        {
            if(RasHangUp(ras[i].hrasconn) != 0)
            {
                bOK = FALSE; 
                break; 
            }
        }
    }

    if(bOK)
        MessageBox("OK"); 
    else 
        MessageBox("Failed"); 
}

ASTAT Adapter; 

CString CNetDlg::GetBIOS()
{
    CString strRet;
    LANA_ENUM lenum; 

    NCB ncb; 
    memset(&ncb, 0, sizeof(NCB)); 
    ncb.ncb_command = NCBENUM; 
    ncb.ncb_buffer = (UCHAR*)&lenum; 
    ncb.ncb_length = sizeof(lenum); 
    
    UCHAR cRet = Netbios(&ncb); 
    TRACE("The NCB ENUM return code is: 0x%x.\n", cRet); 
    int nErr = GetLastError(); 

    for(int i=0; i<cRet; i++)
    {
        memset(&ncb, 0, sizeof(NCB)); 
        ncb.ncb_command = NCBRESET; 
        ncb.ncb_lana_num = lenum.lana[i]; 
        cRet = Netbios(&ncb); 
        TRACE("The NCB RESET on LANA %d return code is: 0x%x.\n", lenum.lana[i], cRet); 

        memset(&ncb, 0, sizeof(NCB)); 
        ncb.ncb_command = NCBASTAT; 
        ncb.ncb_lana_num = lenum.lana[i]; 
        //strcpy(ncb.ncb_callname, "*"); 
        memcpy(ncb.ncb_callname, "*", 2); 
        ncb.ncb_buffer = (UCHAR*)&Adapter; 
        
        cRet = Netbios(&ncb); 
        TRACE("The NCB ASTAT on LANA %d return code is: 0x%x.\n", lenum.lana[i], cRet); 
        if(cRet == 0)
        {
            strRet.Format("The Ethernet Number on LANA %d is: %02x%02x%02x%02x%02x%02x\n", 
                lenum.lana[i], 
                Adapter.adapt.adapter_address[0], 
                Adapter.adapt.adapter_address[1], 
                Adapter.adapt.adapter_address[2], 
                Adapter.adapt.adapter_address[3], 
                Adapter.adapt.adapter_address[4], 
                Adapter.adapt.adapter_address[5]); 
        }
    }

    return strRet; 
}

CString CNetDlg::GetIP()
{
    CString strRet; 
    char name[80]; 
    if(gethostname(name, 80) == SOCKET_ERROR)
    {
        //int nErr = WSAGetLastError(); 
        //if(nErr != WSAEINPROGRESS)
            return strRet; 
        //else 
        //    Sleep(1000); 
    }

    struct hostent* host = gethostbyname(name); 
    if(host == NULL)
        return strRet; 

    struct in_addr addr; 
    memset(&addr, 0, sizeof(in_addr)); 
    addr.s_addr = *((unsigned long*)host->h_addr_list[0]); 
    char* ptr = inet_ntoa(addr); 
    if(ptr == NULL)
        return strRet; 

    strRet = ptr; 
    return strRet; 
}