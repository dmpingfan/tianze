
#include "stdafx.h"
#include "Comm.h"

HWND g_hWnd = NULL; 
PGPSINFO g_pInfo = NULL; 

LRESULT CreateGPSInfo(HWND hWnd, BYTE nPort /*=1*/)
{
    g_pInfo = (PGPSINFO)LocalAlloc(LPTR, sizeof(GPSINFO)); 
    if(g_pInfo == NULL)
        return -1; 

    g_hWnd = hWnd; 
    g_pInfo->idComDev = 0; 
    g_pInfo->fConnected = FALSE; 
    g_pInfo->bPort = nPort; 
    g_pInfo->dwBaudRate = CBR_9600; 
    g_pInfo->bByteSize = 8; 
    g_pInfo->bParity = NOPARITY; 
    g_pInfo->bStopBits = ONESTOPBIT; 
    g_pInfo->osWrite.Offset = 0; 
    g_pInfo->osWrite.OffsetHigh = 0; 
    g_pInfo->osRead.Offset = 0; 
    g_pInfo->osRead.OffsetHigh = 0; 

    g_pInfo->osRead.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL); 
    if(g_pInfo->osRead.hEvent == NULL)
    {
        LocalFree(g_pInfo); 
        return -1; 
    }

    g_pInfo->osWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL); 
    if(g_pInfo->osWrite.hEvent == NULL)
    {
        CloseHandle(g_pInfo->osRead.hEvent); 
        LocalFree(g_pInfo); 
        return -1; 
    }

    return TRUE; 
}

BOOL DestroyGPSInfo()
{
    if(g_pInfo == NULL)
        return FALSE; 

    if(g_pInfo->fConnected)
        CloseConnection(); 

    CloseHandle(g_pInfo->osRead.hEvent); 
    CloseHandle(g_pInfo->osWrite.hEvent); 
    CloseHandle(g_pInfo->hPostEvent); 
    LocalFree(g_pInfo); 
    g_pInfo = NULL; 
    return TRUE; 
}

BOOL OpenConnection()
{
    if(g_pInfo == NULL)
        return FALSE; 

    HCURSOR hWaitCursor = LoadCursor(NULL, IDC_WAIT); 
    HCURSOR hOldCursor = SetCursor(hWaitCursor); 

    char szPort[15]; 
    wsprintf(szPort, "COM%d", g_pInfo->bPort); 
    g_pInfo->idComDev = CreateFile(szPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL); 
    if(g_pInfo->idComDev == (HANDLE)-1)
    {
        SetCursor(hOldCursor); 
        return FALSE; 
    }

    SetCommMask(g_pInfo->idComDev, EV_RXCHAR); 
    SetupComm(g_pInfo->idComDev, 4096, 4096); 
    PurgeComm(g_pInfo->idComDev, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR); 

    COMMTIMEOUTS CommTimeOuts; 
    CommTimeOuts.ReadIntervalTimeout = 0xFFFFFFFF; 
    CommTimeOuts.ReadTotalTimeoutMultiplier = 0; 
    CommTimeOuts.ReadTotalTimeoutConstant = 1000; 
    CommTimeOuts.WriteTotalTimeoutMultiplier = 0; 
    CommTimeOuts.WriteTotalTimeoutConstant = 1000; 
    SetCommTimeouts(g_pInfo->idComDev, &CommTimeOuts); 

    DCB dcb; 
    dcb.DCBlength = sizeof(DCB); 
    GetCommState(g_pInfo->idComDev, &dcb); 
    dcb.BaudRate = g_pInfo->dwBaudRate; 
    dcb.ByteSize = g_pInfo->bByteSize; 
    dcb.Parity = g_pInfo->bParity; 
    dcb.StopBits = g_pInfo->bStopBits; 
    dcb.fOutxDsrFlow = FALSE; 
    dcb.fDtrControl = DTR_CONTROL_ENABLE; 
    dcb.fOutxCtsFlow = FALSE; 
    dcb.fRtsControl = RTS_CONTROL_ENABLE; 
    dcb.fInX = dcb.fOutX = FALSE; 
    dcb.fBinary = TRUE; 
    dcb.fParity = TRUE; 
    if(!SetCommState(g_pInfo->idComDev, &dcb))
    {
        g_pInfo->fConnected = FALSE; 
        CloseHandle(g_pInfo->idComDev); 
        SetCursor(hOldCursor); 
        return FALSE; 
    }

    g_pInfo->fConnected = TRUE; 
    DWORD dwThreadID; 
    HANDLE hCommWatchThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CommWatchProc, NULL, 0, &dwThreadID); 
    if(hCommWatchThread == NULL)
    {
        g_pInfo->fConnected = FALSE;
        CloseHandle(g_pInfo->idComDev); 
        SetCursor(hOldCursor); 
        return FALSE; 
    }

    g_pInfo->dwThreadID = dwThreadID; 
    g_pInfo->hWatchThread = hCommWatchThread; 
    EscapeCommFunction(g_pInfo->idComDev, SETDTR); 

    SetCursor(hOldCursor); 
    return TRUE; 
}

BOOL CloseConnection()
{
    if(g_pInfo == NULL)
        return FALSE; 

    g_pInfo->fConnected = FALSE; 
    SetCommMask(g_pInfo->idComDev, 0); 
    while(g_pInfo->dwThreadID != 0)
        ; 

    EscapeCommFunction(g_pInfo->idComDev, CLRDTR); 
    PurgeComm(g_pInfo->idComDev, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR); 
    CloseHandle(g_pInfo->idComDev); 
    return TRUE; 
}

DWORD PASCAL CommWatchProc(LPVOID lpParam)
{
    OVERLAPPED os; 
    memset(&os, 0, sizeof(OVERLAPPED)); 
    os.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL); 
    if(os.hEvent == NULL)
    {
        ::MessageBox(NULL, "Failed to create event for thread!", "GPS Error!", MB_OK | MB_ICONEXCLAMATION); 
        return FALSE; 
    }

    if(!SetCommMask(g_pInfo->idComDev, EV_RXCHAR))
        return FALSE; 

    BYTE abIn[1024]; 
    int nLength = 0; 
    while(g_pInfo->fConnected)
    {
        DWORD dwEvtMask = 0; 
        WaitCommEvent(g_pInfo->idComDev, &dwEvtMask, NULL); 
        if((dwEvtMask & EV_RXCHAR) == EV_RXCHAR)
        {
            do
            {
                nLength = ReadCommBlock((LPSTR)abIn, 1024); 
                if(nLength > 0)
                {
                    *(abIn + nLength) = 0; 
                    ::SendMessage(g_hWnd, CN_SEND, nLength, (LONG)(LPSTR)abIn); 
                }
            }while(nLength > 0 && g_pInfo->fConnected); 
        }
    }

    CloseHandle(os.hEvent); 
    g_pInfo->dwThreadID = 0; 
    g_pInfo->hWatchThread = NULL; 
    return TRUE; 
}

int ReadCommBlock(LPSTR lpszBlock, int nMaxLength)
{
    if(g_pInfo == NULL)
        return FALSE; 

    COMSTAT ComState; 
    DWORD dwErrorFlags; 
    ClearCommError(g_pInfo->idComDev, &dwErrorFlags, &ComState); 
    DWORD dwLength = min((DWORD)nMaxLength, ComState.cbInQue); 
    if(dwLength > 0)
    {
        BOOL fReadState = ReadFile(g_pInfo->idComDev, lpszBlock, dwLength, &dwLength, &g_pInfo->osRead); 
        if(!fReadState)
        {
            if(GetLastError() == ERROR_IO_PENDING)
            {
                OutputDebugString("IO Pending.\r\n"); 
                while(!GetOverlappedResult(g_pInfo->idComDev, &g_pInfo->osRead, &dwLength, TRUE))
                {
                    if(GetLastError() == ERROR_IO_INCOMPLETE)
                        continue; 
                }
            }
            else 
            {
                dwLength = 0; 
                ClearCommError(g_pInfo->idComDev, &dwErrorFlags, &ComState); 
            }
        }
    }

    return dwLength; 
}

BOOL WriteCommBlock(LPSTR lpBuffer, DWORD dwLength)
{
    if(g_pInfo == NULL)
        return FALSE; 

    DWORD dwErrorFlags; 
    COMSTAT ComState; 
    DWORD dwWritten; 
    BOOL fWriteState = WriteFile(g_pInfo->idComDev, lpBuffer, dwLength, &dwWritten, &g_pInfo->osWrite); 
    if(!fWriteState)
    {
        if(GetLastError() == ERROR_IO_PENDING)
        {
            while(!GetOverlappedResult(g_pInfo->idComDev, &g_pInfo->osWrite, &dwWritten, TRUE))
            {
                if(GetLastError() == ERROR_IO_INCOMPLETE)
                    continue; 
                else 
                {
                    ClearCommError(g_pInfo->idComDev, &dwErrorFlags, &ComState); 
                    break; 
                }
            }
        }
        else 
        {
            ClearCommError(g_pInfo->idComDev, &dwErrorFlags, &ComState); 
            return FALSE; 
        }
    }

    return TRUE; 
}