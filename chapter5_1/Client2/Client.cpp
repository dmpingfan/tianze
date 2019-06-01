// Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Client.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		CString strHello;
		strHello.LoadString(IDS_HELLO);
		cout << (LPCTSTR)strHello << endl;

        WSAData data; 
        if(!AfxSocketInit(&data))
        {
            AfxMessageBox("Windows socket initial failed!", MB_ICONSTOP); 
            return nRetCode; 
        }

        CSocket recv; 
        if(!recv.Create())
        {
            AfxMessageBox("Receive socket create failed!", MB_ICONSTOP); 
            return nRetCode; 
        }
        else 
            recv.Connect("127.0.0.1", 1025); 

        TCHAR lpszText[100]; 
        memset(lpszText, 0, 100); 
        CString strAddr; 
        UINT nPort; 
        recv.ReceiveFrom(lpszText, 100, strAddr, nPort); 
        cout<< lpszText << endl; 
        recv.Close(); 
	}

	return nRetCode;
}


