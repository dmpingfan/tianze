// ProgramGroup.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ProgramGroup.h"
#include "ProgramGroupDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgramGroupApp

BEGIN_MESSAGE_MAP(CProgramGroupApp, CWinApp)
	//{{AFX_MSG_MAP(CProgramGroupApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgramGroupApp construction

CProgramGroupApp::CProgramGroupApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CProgramGroupApp object

CProgramGroupApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CProgramGroupApp initialization

BOOL CProgramGroupApp::InitInstance()
{
	// Standard initialization
    DdeInitialize(&dwDDEInst, NULL, APPCMD_CLIENTONLY, 0); 

	CProgramGroupDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{        
        if(!AddProgramGroup(dlg.m_strGroup, dlg.m_strItem, dlg.m_strFile))
        {
            ::MessageBox(NULL, "Error adding group and item", "ProgramGroup: DDE Error", MB_OK | MB_ICONHAND); 
        }
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CProgramGroupApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	DdeUninitialize(dwDDEInst); 
	return CWinApp::ExitInstance();
}

//[ShowGroup(GroupName, 1)]
//[DeleteGroup(GroupName)]
//[ReloadGroup(GroupName)]
//[AddItem(ItemName.exe, ItemName)]
//[ReplaceItem(ItemName)]
//[DeleteItem(ItemName)]
//[ExitProgMan(1)]
BOOL CProgramGroupApp::AddProgramGroup(CString strGroup, CString strItem, CString strFile)
{
    HSZ hszService = DdeCreateStringHandle(dwDDEInst, _T("PROGMAN"), CP_WINANSI); 
    HSZ hszTopic = DdeCreateStringHandle(dwDDEInst, _T("PROGMAN"), CP_WINANSI); 
    HCONV hConv = DdeConnect(dwDDEInst, hszService, hszTopic, NULL); 
    DdeFreeStringHandle(dwDDEInst, hszService); 
    DdeFreeStringHandle(dwDDEInst, hszTopic); 
    if(hConv == NULL)
        return FALSE; 

    CString szCmd; 
    szCmd.Format("[CreateGroup(%s)]", strGroup); 
    DWORD dwResult; 
    DdeClientTransaction((LPBYTE)(LPCTSTR)szCmd, szCmd.GetLength()+1, hConv, NULL, CF_TEXT, XTYP_EXECUTE, 1000, &dwResult); 
    
    szCmd.Format("[AddItem(%s, %s)]", strFile, strItem); 
    DdeClientTransaction((LPBYTE)(LPCTSTR)szCmd, szCmd.GetLength()+1, hConv, NULL, CF_TEXT, XTYP_EXECUTE, 1000, &dwResult); 

    return TRUE; 
}