// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CtrlInfo.h"
#include "TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog


CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	EnableToolTips(); 
}


void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_WM_SETCURSOR()
	ON_NOTIFY_EX(TTN_NEEDTEXT, 0, OnTipNotify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

void CTestDlg::SetStatusText(UINT nID/*=0*/)
{
	if(nID == 0)
		nID = AFX_IDS_IDLEMESSAGE; 
	
	CWnd* pWnd = AfxGetMainWnd()->GetDescendantWindow(AFX_IDW_STATUS_BAR); 
	if(pWnd != NULL)
	{
		AfxGetMainWnd()->SendMessage(WM_SETMESSAGESTRING, nID); 
		pWnd->SendMessage(WM_IDLEUPDATECMDUI); 
		pWnd->UpdateWindow(); 
	}
}

BOOL CTestDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if(pWnd == this)
		SetStatusText(); 
	else 
	{
		TOOLTIPTEXT tip; 
		memset(&tip, 0, sizeof(TOOLTIPTEXT)); 
		tip.hdr.hwndFrom = m_hWnd; 
		tip.hdr.idFrom = pWnd->GetDlgCtrlID(); 
		tip.hdr.code = TTN_NEEDTEXT; 
		//tip.uFlags = TTF_IDISHWND; 
		SetStatusText(pWnd->GetDlgCtrlID()); 
		SendMessage(WM_NOTIFY, tip.hdr.idFrom, (LPARAM)&tip); 
		
		//CToolTipCtrl* pCtrl = new CTooTipCtrl(); 
	}

	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

void CTestDlg::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	SetStatusText(); 
	CDialog::PostNcDestroy();
}

BOOL CTestDlg::OnTipNotify(UINT id, NMHDR* pNMHDR, LRESULT* pResult)
{
	TOOLTIPTEXT* pTip = (TOOLTIPTEXT*)pNMHDR; 
	UINT nID = pNMHDR->idFrom; 
	if(pTip->uFlags & TTF_IDISHWND)
	{
		nID = ::GetDlgCtrlID((HWND)nID); 
	}

	if(nID > 0)
	{
		TCHAR szFullText[256]; 
		AfxLoadString(nID, szFullText, 256); 
		CString strTipText; 
		AfxExtractSubString(strTipText, szFullText, 1, '\n'); 
		if(!strTipText.IsEmpty())
		{
			strcpy(pTip->szText, strTipText); 
			pTip->hinst = AfxGetResourceHandle(); 
            //*pResult = 0;             
            //::SetWindowPos(pNMHDR->hwndFrom, HWND_TOP, 0, 0, 0, 0,
            //    SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOMOVE|SWP_NOOWNERZORDER);
			return TRUE; 
		}
	}

	return FALSE; 
}