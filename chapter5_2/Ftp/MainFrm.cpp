// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Ftp.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_CONN, OnViewConn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_sockCtrl = NULL; 
	m_sockListen = NULL; 
	m_sockData = NULL; 
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnViewConn() 
{
	// TODO: Add your command handler code here
	m_sockCtrl = new CCtrlSocket(); 
	if(!m_sockCtrl->Create(0, SOCK_STREAM, NULL))
	{
		delete m_sockCtrl; 
		m_sockCtrl = NULL; 
		MessageBox("Socket ½¨Á¢Ê§°Ü!"); 
		return; 
	}

	if(!m_sockCtrl->AsyncSelect(FD_READ | FD_WRITE | FD_ACCEPT | FD_CONNECT | FD_CLOSE))
	{
		MessageBox("AsyncSelect Ê§°Ü!"); 
		return; 
	}

	BeginWaitCursor(); 
	if(!m_sockCtrl->Connect("anonymous", IPPORT_FTP))
	{
		delete m_sockCtrl; 
		m_sockCtrl = NULL; 
		MessageBox("Ô¶¶Ë·þÎñÆ÷Á¬½ÓÊ§°Ü!"); 
	}

	EndWaitCursor(); 

	m_sockListen = new CListenSocket(); 
	if(!m_sockListen->Create(0, SOCK_STREAM, "90.0.0.8"))
	{
		delete m_sockListen; 
		m_sockListen = NULL; 
		MessageBox("Socket ½¨Á¢Ê§°Ü!"); 
		return; 
	}

	if(!m_sockListen->AsyncSelect(FD_ACCEPT))
	{
		delete m_sockListen; 
		m_sockListen = NULL; 
		MessageBox("AsyncSelect Ê§°Ü!"); 
		return; 
	}

	if(!m_sockListen->Listen(5))
	{
		MessageBox("Listen Ê§°Ü!"); 
		return; 
	}
}

BOOL CMainFrame::ProcessFtp()
{
	return TRUE; 
}

BOOL CMainFrame::AcceptDataConn()
{
	if(m_sockData == NULL)
		m_sockData = new CDataSocket(); 

	SOCKADDR_IN addrRemote; 
	int num = sizeof(SOCKADDR_IN); 
	if(!m_sockListen->Accept(*m_sockData, (LPSOCKADDR)&addrRemote, &num))
	{
		MessageBox("Accept Ê§°Ü!"); 
		return FALSE; 
	}

	m_sockListen->Close(); 
	if(!m_sockData->AsyncSelect(FD_READ | FD_WRITE | FD_CLOSE))
	{
		MessageBox("AsyncSelect Ê§°Ü!"); 
		return FALSE; 
	}
	return TRUE; 
}

int CMainFrame::RecvData()
{
	char buf[100]; 
	int nRet = m_sockData->Receive(&buf, 100, 0); 
	//...
	return nRet; 
}

int CMainFrame::SendData()
{
	char buf[100]; 
	int nRet = m_sockData->Send(&buf, 100); 
	return nRet; 
}

void CMainFrame::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_sockCtrl != NULL)
		delete m_sockCtrl; 
	if(m_sockListen != NULL)
		delete m_sockListen; 
	if(m_sockData != NULL)
		delete m_sockData; 

	CFrameWnd::PostNcDestroy();
}
