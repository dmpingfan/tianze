
#define CN_SEND (WM_USER + 100)
typedef struct tagGPSINFO
{
    BOOL fConnected; 
    BYTE bPort; 
    BYTE bByteSize; 
    BYTE bParity; 
    BYTE bStopBits; 
    DWORD dwBaudRate; 
    HANDLE idComDev; 
    HANDLE hPostEvent; 
    HANDLE hWatchThread; 
    HANDLE hWatchEvent; 
    HWND hTermWnd; 
    DWORD dwThreadID; 
    OVERLAPPED osWrite; 
    OVERLAPPED osRead; 
} GPSINFO, *PGPSINFO; 

LRESULT CreateGPSInfo(HWND hWnd, BYTE nPort = 1); 
BOOL DestroyGPSInfo(); 
BOOL OpenConnection(); 
BOOL CloseConnection(); 
DWORD PASCAL CommWatchProc(LPVOID lpParam); 
int ReadCommBlock(LPSTR lpszBlock, int nMaxLength); 
BOOL WriteCommBlock(LPSTR lpszBuffer, DWORD nLength); 