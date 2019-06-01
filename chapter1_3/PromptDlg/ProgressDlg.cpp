// ProgressDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PromptDlg.h"
#include "ProgressDlg.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg dialog


CProgressDlg::CProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProgressDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProgressDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_nID = CProgressDlg::IDD; 
	m_pParent = pParent; 
	m_bCancel = FALSE; 
}


void CProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgressDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProgressDlg, CDialog)
	//{{AFX_MSG_MAP(CProgressDlg)
	//ON_MESSAGE(WM_STEP_PROGRESS, StepIt)
	//ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg message handlers

BOOL CProgressDlg::Create()
{
	return CDialog::Create(m_nID, m_pParent); 
}

////extern BOOL g_bCancel; 
//void CProgressDlg::OnOK()
//{
//    // do nothing
//    //g_bCancel = TRUE; 
//}

//void CProgressDlg::OnCancel()
//{
//    ////CMainFrame* pFrame = (CMainFrame*)m_pParent; 
//    ////pFrame->m_bCancel = TRUE; 
//    //g_bCancel = TRUE; 
//}

void CProgressDlg::OnCancel()
{
	m_bCancel = TRUE; 
	CDialog::OnCancel(); 
}

void CProgressDlg::SetProgressInfo(int min, int max, int step)
{
	CProgressCtrl* pProgress = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS_MAIN); 
	if(pProgress != NULL)
	{
		pProgress->SetRange(min, max); 
		pProgress->SetStep(step); 
		pProgress->SetPos(min); 
	}
}

void CProgressDlg::StepIt()
{
	CProgressCtrl* pProgress = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS_MAIN); 
	if(pProgress != NULL)
	{
		pProgress->StepIt(); 
	}
}

void CProgressDlg::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	delete this; 
	CDialog::PostNcDestroy();
}

DWORD PASCAL CProgressDlg::StartProcess(LPVOID lpParam)
{
	return ((CProgressDlg*)lpParam)->ProcessProc(); 
}

DWORD CProgressDlg::ProcessProc()
{
    for(int i=0; i<1000; i++)
    {
        ; 
        for(int j=0; j<1000; j++)
        {
            ; 
            for(int k=0; k<2000; k++)
            {
                ; 
            }
        }

        StepIt(); 
        if(m_bCancel)
            break; 
    }

	//OnOK(); 
	SendMessage(WM_CLOSE, 0, 0); 
	return 0; 
}