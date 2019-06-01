// Tray.cpp : Defines the entry point for the application.
//

#include "tray.h"

HINSTANCE g_hInstance = NULL; 
BOOL g_bExist = FALSE; 
BOOL CALLBACK DlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam); 
LRESULT IconDrawItem(LPDRAWITEMSTRUCT lpdi); 
void IconAdd(HWND hDlg); 
void IconDelete(HWND hDlg); 
void IconChange(HWND hDlg); 
void IconMessage(HWND hDlg, UINT nMessage, UINT nID, UINT nFlag, HICON hIcon, LPSTR szTip); 

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
    g_hInstance = hInstance;  
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_DEMO), NULL, DlgProc); 
	return 0;
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_INITDIALOG:
            break; 
        case WM_DRAWITEM:
            return IconDrawItem((LPDRAWITEMSTRUCT)lParam); 
            break; 
        case WM_CLOSE:
            EndDialog(hDlg, TRUE); 
            break; 
        case WM_DESTROY:
            IconDelete(hDlg); 
            break; 
        case WM_COMMAND:
            switch(GET_WM_COMMAND_ID(wParam, lParam))
            {
                case IDCANCEL:
                    EndDialog(hDlg, TRUE); 
                    break; 
                case IDC_BUTTON_LOAD:
                    if(!g_bExist)
                        IconAdd(hDlg); 
                    else 
                        IconChange(hDlg); 
                    ShowWindow(hDlg, SW_HIDE); 
                    break; 
                case IDC_BUTTON_UNLOAD:
                    IconDelete(hDlg); 
                    break; 
                default:
                    return FALSE; 
            }
            break; 
        case WM_TRAY:
            switch(lParam)
            {
                case WM_LBUTTONDBLCLK:
                    ShowWindow(hDlg, SW_SHOW); 
                    SetForegroundWindow(hDlg); 
                    break; 
                default:
                    return FALSE; 
            }
            break; 
        default:
            return FALSE; 
    }
    return TRUE; 
}

LRESULT IconDrawItem(LPDRAWITEMSTRUCT lpdi)
{
    HICON hIcon = (HICON)LoadImage(g_hInstance, MAKEINTRESOURCE(lpdi->CtlID), IMAGE_ICON, 16, 16, 0); 
    if(!hIcon)
        return FALSE; 

    DrawIconEx(lpdi->hDC, lpdi->rcItem.left, lpdi->rcItem.top, hIcon, 16, 16, 0, NULL, DI_NORMAL); 
    return TRUE; 
}

void IconAdd(HWND hDlg)
{
    g_bExist = TRUE; 
    char szIconFileName[128]; 
    char szTip[64]; 
    GetDlgItemText(hDlg, IDC_ICONFILENAME, szIconFileName, 128); 
    GetDlgItemText(hDlg, IDC_TIP, szTip, 64); 
    HICON hIcon = (HICON)LoadImage(g_hInstance, szIconFileName, IMAGE_ICON, 16, 16, LR_LOADFROMFILE); 
    IconMessage(hDlg, NIM_ADD, 0, NIF_MESSAGE | NIF_ICON | NIF_TIP, hIcon, szTip); 
    DestroyIcon(hIcon); 
}

void IconDelete(HWND hDlg)
{
    g_bExist = FALSE; 
    IconMessage(hDlg, NIM_DELETE, 0, 0, NULL, NULL); 
}

void IconChange(HWND hDlg)
{
    char szIconFileName[128]; 
    char szTip[64]; 
    GetDlgItemText(hDlg, IDC_ICONFILENAME, szIconFileName, 128); 
    GetDlgItemText(hDlg, IDC_TIP, szTip, 64); 
    HICON hIcon = (HICON)LoadImage(g_hInstance, szIconFileName, IMAGE_ICON, 16, 16, LR_LOADFROMFILE); 
    IconMessage(hDlg, NIM_MODIFY, 0, NIF_ICON | NIF_TIP, hIcon, szTip); 
    DestroyIcon(hIcon); 
}

void IconMessage(HWND hDlg, UINT nMessage, UINT nID, UINT nFlag, HICON hIcon, LPSTR szTip)
{
    NOTIFYICONDATA nid; 
    nid.cbSize = sizeof(NOTIFYICONDATA); 
    nid.hWnd = hDlg; 
    nid.uID = nID; 
    nid.uFlags = nFlag; 
    nid.uCallbackMessage = WM_TRAY; 
    nid.hIcon = hIcon; 
    if(szTip != NULL)
        strcpy(nid.szTip, szTip); 
    Shell_NotifyIcon(nMessage, &nid); 
}



