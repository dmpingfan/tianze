// PropertyContainer.cpp : implementation file
//

#include "stdafx.h"
#include "PropSheet.h"
#include "PropertyContainer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropertyContainer

IMPLEMENT_DYNAMIC(CPropertyContainer, CPropertySheet)

CPropertyContainer::CPropertyContainer(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{    
}

CPropertyContainer::CPropertyContainer(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

CPropertyContainer::~CPropertyContainer()
{
}


BEGIN_MESSAGE_MAP(CPropertyContainer, CPropertySheet)
	//{{AFX_MSG_MAP(CPropertyContainer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertyContainer message handlers

BOOL CPropertyContainer::OnInitDialog() 
{
	BOOL bResult = CPropertySheet::OnInitDialog();
	// TODO: Add extra initialization here
	
    CRect rectWnd; 
    GetWindowRect(&rectWnd); 
    SetWindowPos(NULL, 0, 0, rectWnd.Width() + 100, rectWnd.Height(), SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE); 
        
    m_edit.CreateEx(WS_EX_CLIENTEDGE, _T("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, 
        rectWnd.Width(), 20, 80, 24, m_hWnd, 0, 0); 
    m_edit.SetFont(GetFont()); 
    //m_edit.Detach(); 
    CenterWindow(); 

    //m_fontEdit.CreateFont(-12, 0, 0, 0, 700, 0, 0, 0, 1, 0, 0, 0, 0, _T("MF Sans Serif")); 
    m_fontEdit.CreatePointFont(100, "Helvetica", NULL); 
    GetTabControl()->SetFont(&m_fontEdit); 

    //m_imageTab.Create(IDB_BITMAP_TAB, 16, 1, RGB(255, 255, 255)); //RGB(236, 233, 216)); 

    //HBITMAP hbm = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_TAB), 
    //    IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADMAP3DCOLORS); 
    HBITMAP hbm = LoadResourceBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_TAB)); 

    CBitmap bm; 
    bm.Attach(hbm); 

    m_imageTab.Create(16, 16, ILC_COLOR8, 4, 4); 
    m_imageTab.Add(&bm, (CBitmap*)NULL); 

    CTabCtrl* pTab = GetTabControl(); 
    pTab->SetImageList(&m_imageTab); 
    
    TC_ITEM tcItem; 
    tcItem.mask = TCIF_IMAGE; 
    for(int i=0; i<4; i++)
    {
        tcItem.iImage = i; 
        pTab->SetItem(i, &tcItem); 
    }

	return bResult;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBITMAP CPropertyContainer::LoadResourceBitmap(HINSTANCE hInstance, LPSTR lpString)
{
    HBITMAP hBitmapFinal = NULL; 
    HRSRC hRsrc = ::FindResource(hInstance, lpString, RT_BITMAP); 
    if(hRsrc != NULL)
    {
        HGLOBAL hGlobal = ::LoadResource(hInstance, hRsrc); 
        LPBITMAPINFOHEADER lpbi = (LPBITMAPINFOHEADER)LockResource(hGlobal);
        HDC hdc = ::GetDC(NULL); 
        int iNumColors; 
        HPALETTE hPalette = CreateDIBPalette((LPBITMAPINFO)lpbi, &iNumColors); 
        if(hPalette != NULL)
        {
            ::SelectPalette(hdc, hPalette, FALSE); 
            ::RealizePalette(hdc); 
        }

        hBitmapFinal = ::CreateDIBitmap(hdc, (LPBITMAPINFOHEADER)lpbi, (LONG)CBM_INIT, 
            (LPSTR)lpbi + lpbi->biSize + iNumColors * sizeof(RGBQUAD), (LPBITMAPINFO)lpbi, DIB_RGB_COLORS); 
        
        ::ReleaseDC(NULL, hdc); 
    }
    return hBitmapFinal; 
}

HPALETTE CPropertyContainer::CreateDIBPalette(LPBITMAPINFO lpbmi, LPINT lpiNumColors)
{
    HPALETTE hPal = NULL; 
    LPBITMAPINFOHEADER lpbi = (LPBITMAPINFOHEADER)lpbmi; 
    if(lpbi->biBitCount <= 8)
        *lpiNumColors = (1 << lpbi->biBitCount); 
    else 
        *lpiNumColors = 0; 

    if(lpbi->biClrUsed > 0)
        *lpiNumColors = lpbi->biClrUsed; 

    if(*lpiNumColors)
    {
        HANDLE hLogPal = GlobalAlloc(GHND, sizeof(LOGPALETTE) + sizeof(PALETTEENTRY) * (*lpiNumColors)); 
        LPLOGPALETTE lpPal = (LPLOGPALETTE)GlobalLock(hLogPal); 
        lpPal->palVersion = 0x300; 
        lpPal->palNumEntries = *lpiNumColors; 
        
        for(int i=0; i<*lpiNumColors; i++)
        {
            lpPal->palPalEntry[i].peRed = lpbmi->bmiColors[i].rgbRed; 
            lpPal->palPalEntry[i].peGreen = lpbmi->bmiColors[i].rgbGreen; 
            lpPal->palPalEntry[i].peBlue = lpbmi->bmiColors[i].rgbBlue; 
            if(i <= 10 || i >= 246)
                lpPal->palPalEntry[i].peFlags = PC_NOCOLLAPSE; 
            else 
                lpPal->palPalEntry[i].peFlags = 0; 
        }

        hPal = CreatePalette(lpPal); 
        GlobalUnlock(hLogPal); 
        GlobalFree(hLogPal);
    }

    return hPal; 
}
