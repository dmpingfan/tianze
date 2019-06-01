// CtrlSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Ftp.h"
#include "CtrlSocket.h"
#include "mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCtrlSocket

CCtrlSocket::CCtrlSocket()
{
}

CCtrlSocket::~CCtrlSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CCtrlSocket, CSocket)
	//{{AFX_MSG_MAP(CCtrlSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CCtrlSocket member functions

void CCtrlSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CSocket::OnReceive(nErrorCode);
	((CMainFrame*)AfxGetMainWnd())->ProcessFtp(); 
}
