// Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Server.h"

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
            AfxMessageBox("Windows Socket initial failed!", MB_ICONSTOP); 
            return nRetCode; 
        }

        CSocket send, server; 
        if(!send.Create(1025))
        {
            AfxMessageBox("Send socket create failed!", MB_ICONSTOP); 
        }
        else 
        {
            send.Bind(1025, "127.0.0.1"); 
            send.Listen(); 
            send.Accept(server); 
        }

        LPTSTR lpszText = "ni hao ma? wo xiang ni xiang de shui bu zhao jiao."; 
        server.SendTo(lpszText, strlen(lpszText), 1025); 
        server.Close(); 
        send.Close(); 
	}

	return nRetCode;
}


