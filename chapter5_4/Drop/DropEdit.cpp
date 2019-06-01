// DropEdit.cpp : implementation file
//

#include "stdafx.h"
#include "Drop.h"
#include "DropEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDropEdit

CDropEdit::CDropEdit()
{
}

CDropEdit::~CDropEdit()
{
}


BEGIN_MESSAGE_MAP(CDropEdit, CEdit)
	//{{AFX_MSG_MAP(CDropEdit)
	ON_WM_DROPFILES()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDropEdit message handlers

void CDropEdit::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class	
	DragAcceptFiles(); 
	CEdit::PreSubclassWindow();
}


void CDropEdit::OnDropFiles(HDROP hDropInfo) 
{
	// TODO: Add your message handler code here and/or call default
	int nNum = DragQueryFile(hDropInfo, -1, NULL, 0); 
    CStringList listFiles; 
    for(int i=0; i<nNum; i++)
    {
        int nSize = DragQueryFile(hDropInfo, i, NULL, 0) + 1; 
        char* lpszName = (char*)LocalAlloc(LPTR, nSize); 
        if(lpszName == NULL)
            continue; 

        DragQueryFile(hDropInfo, i, lpszName, nSize); 
        listFiles.AddTail(lpszName); 
        LocalFree(lpszName); 
    }

    CString szFiles; 
    DragFinish(hDropInfo); 
    POSITION pos = listFiles.GetHeadPosition(); 
    while(pos != NULL)
    {
        CString strFile = listFiles.GetNext(pos); 
        szFiles += ExpandShortcut(strFile) + "; "; 
    }

    SetWindowText(szFiles); 
	CEdit::OnDropFiles(hDropInfo);
}

CString CDropEdit::ExpandShortcut(CString strFile)
{
    CString strRet = strFile; 
    LPTSTR lpsz = strFile.GetBuffer(_MAX_PATH); 
    IShellLink* psl; 
    HRESULT hRes = ::CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (LPVOID*)&psl); 
    if(SUCCEEDED(hRes))
    {
        IPersistFile* ppf; 
        hRes = psl->QueryInterface(IID_IPersistFile, (LPVOID*)&ppf); 
        if(SUCCEEDED(hRes))
        {
            WORD wsz[_MAX_PATH]; 
            ::MultiByteToWideChar(CP_ACP, 0, lpsz, -1, wsz, _MAX_PATH); 
            hRes = ppf->Load(wsz, STGM_READ); 
            if(SUCCEEDED(hRes))
            {
                WIN32_FIND_DATA wfd; 
                hRes = psl->GetPath(strRet.GetBuffer(_MAX_PATH), _MAX_PATH, &wfd, SLGP_UNCPRIORITY); 
                strRet.ReleaseBuffer(); 
            }
            ppf->Release(); 
        }
        psl->Release(); 
    }

    strFile.ReleaseBuffer(); 
    return strRet; 
}