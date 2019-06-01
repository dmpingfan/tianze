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
        AfxSocketInit(&data); 

        CSocket socket; 
        socket.Create(6000); 
        socket.Listen(); 
        CSocket socket2; 
        while(socket2.m_hSocket == INVALID_SOCKET)
            socket.Accept(socket2); 

        CSocketFile file(&socket2); 
        CArchive ar(&file, CArchive::load); 
        DWORD dwValue; 
        ar >> dwValue; 
        cout << dwValue << endl; 
        cin >> dwValue; 
        socket2.Close(); 
        socket.Close(); 
	}

	return nRetCode;
}


