// ScreenSaver.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "resource.h"

//int APIENTRY WinMain(HINSTANCE hInstance,
//                     HINSTANCE hPrevInstance,
//                     LPSTR     lpCmdLine,
//                     int       nCmdShow)
//{
//     // TODO: Place code here.

//    return 0;
//}

BOOL bBlackAndWhite = TRUE; 
BOOL bErase = TRUE; 
#define szAppName "ScreenSaver"
#define szIniFile "ScreenSaver.ini"
#define szBlackAndWhite "BlackAndWhite"
#define szEraseBkgnd "EraseBkgnd"

void LoadOptions()
{
    TCHAR szStr[10]; 
    ::GetPrivateProfileString(szAppName, szBlackAndWhite, "TRUE", szStr, 10, szIniFile); 
    if(strcmp(szStr, "TRUE") == 0)
        bBlackAndWhite = TRUE; 
    else 
        bBlackAndWhite = FALSE; 

    ::GetPrivateProfileString(szAppName, szEraseBkgnd, "TRUE", szStr, 10, szIniFile); 
    if(strcmp(szStr, "TRUE") == 0)
        bErase = TRUE; 
    else 
        bErase = FALSE; 
}

void SaveOptions()
{
    ::WritePrivateProfileString(szAppName, szBlackAndWhite, bBlackAndWhite ? "TRUE" : "FALSE", szIniFile); 
    ::WritePrivateProfileString(szAppName, szEraseBkgnd, bErase ? "TRUE" : "FALSE", szIniFile); 
}

LRESULT WINAPI ScreenSaverProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
        case WM_CREATE:
            LoadOptions(); 
            srand((unsigned)time(NULL));
            SetTimer(hWnd, 1, 150, NULL); 
            break; 
        case WM_DESTROY:
            KillTimer(hWnd, 1); 
            break; 
        case WM_TIMER:
            ::InvalidateRect(hWnd, NULL, FALSE); 
            return TRUE; 
        case WM_PAINT:
        {
            PAINTSTRUCT ps; 
            ::BeginPaint(hWnd, &ps); 
            //HBRUSH hbr = ::CreateSolidBrush(RGB(150, 150, 203)); 
            //::FillRect(ps.hdc, &ps.rcPaint, hbr); 
            for(int i=0; i<65536; i++)
            {
                int x = ps.rcPaint.left + rand() % (ps.rcPaint.right - ps.rcPaint.left); 
                int y = ps.rcPaint.top + rand() % (ps.rcPaint.bottom - ps.rcPaint.top); 
                COLORREF clr = RGB(0, 0, 0); 
                if(bBlackAndWhite)
                    clr = (rand() % 2 == 0) ? RGB(0, 0, 0) : RGB(255, 255, 255); 
                else 
                    clr = RGB(rand() % 256, rand() % 256, rand() % 256); 
                ::SetPixel(ps.hdc, x, y, clr); 
            }
            ::EndPaint(hWnd, &ps); 
            return TRUE; 
        }
        case WM_ERASEBKGND:
            if(bErase)
                break; 
            else 
                return TRUE; 
    }

    return DefScreenSaverProc(hWnd, message, wParam, lParam);
}


BOOL WINAPI ScreenSaverConfigureDialog (HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    //return FALSE; 
    switch(message)
    {
        case WM_INITDIALOG:
            LoadOptions(); 
            CheckDlgButton(hDlg, IDC_CHECK_BLACK_AND_WHITE, bBlackAndWhite); 
            CheckDlgButton(hDlg, IDC_CHECK_ERASE_BKGND, bErase); 
            return TRUE; 
        case WM_CLOSE:
            ::EndDialog(hDlg, 0); 
            break; 
        case WM_COMMAND:
            switch(wParam)
            {
                case IDOK:
                    bBlackAndWhite = IsDlgButtonChecked(hDlg, IDC_CHECK_BLACK_AND_WHITE); 
                    bErase = IsDlgButtonChecked(hDlg, IDC_CHECK_ERASE_BKGND); 
                    SaveOptions(); 
                    ::EndDialog(hDlg, 1); 
                    break; 
                case IDCANCEL:
                    ::EndDialog(hDlg, 0); 
                    break; 
            }
            break; 
    }

    return DefWindowProc(hDlg,message, wParam, lParam); 
}


BOOL WINAPI RegisterDialogClasses (HANDLE hInst)
{
    return TRUE; 
}


