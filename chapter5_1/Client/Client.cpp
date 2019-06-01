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
        AfxSocketInit(&data); 

        CSocket socket; 
        socket.Create(); 
        //SOCKADDR_IN addr; 
        //memset(&addr, 0, sizeof(SOCKADDR_IN)); 
        //addr.sin_family = AF_INET; 
        //addr.sin_port = htons(6000); 
        //addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); 
        //socket.Connect((SOCKADDR*)&addr, sizeof(SOCKADDR)); 
        socket.Connect("127.0.0.1", 6000); 

        if(socket.m_hSocket != INVALID_SOCKET)
        {
            CSocketFile file(&socket); 
            CArchive ar(&file, CArchive::store); 
            DWORD dwValue = 1000; 
            cout << "Please input an integer:" << endl; 
            cin >> dwValue; 
            ar << dwValue; 
        }
        socket.Close(); 
	}

	return nRetCode;
}


