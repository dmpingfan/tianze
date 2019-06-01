// Menu.cpp: implementation of the CCustomMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomMenu.h"
#include "Menu.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomMenu::CCustomMenu()
{
	m_clrText = GetSysColor(COLOR_MENUTEXT); 
	m_clrBack = GetSysColor(COLOR_MENU); 
	m_brBackground.CreateSolidBrush(m_clrBack); 
	m_penBack.CreatePen(PS_SOLID, 0, m_clrBack); 
	m_crText = m_clrText; 
	m_bLBtnDown = FALSE; 
	m_iconX = GetSystemMetrics(SM_CXMENUCHECK); 
	m_iconY = GetSystemMetrics(SM_CYMENUCHECK); 
	m_clrHilight = GetSysColor(COLOR_HIGHLIGHT); 
	m_brSelect.CreateSolidBrush(m_clrHilight); 
	m_clrHilightText = GetSysColor(COLOR_HIGHLIGHTTEXT); 
	
	ZeroMemory(&m_lf, sizeof(LOGFONT)); 
	NONCLIENTMETRICS nm; 
	nm.cbSize = sizeof(NONCLIENTMETRICS); 
	VERIFY(SystemParametersInfo(SPI_GETNONCLIENTMETRICS, 0, &nm, 0)); 
	m_lf = nm.lfMenuFont; 
	m_iMenuHeight = nm.iMenuHeight; 
	m_fontMenu.CreateFontIndirect(&m_lf); 
}

CCustomMenu::~CCustomMenu()
{
	if(m_brBackground.GetSafeHandle() != NULL)
		m_brBackground.DeleteObject(); 
	if(m_penBack.GetSafeHandle() != NULL)
		m_penBack.DeleteObject(); 
	if(m_brSelect.GetSafeHandle() != NULL)
		m_brSelect.DeleteObject(); 
	if(m_fontMenu.GetSafeHandle() != NULL)
		m_fontMenu.DeleteObject(); 
}


void CCustomMenu::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC); 
	MENUDATA* data = (MENUDATA*)lpDrawItemStruct->itemData; 
	UINT action = lpDrawItemStruct->itemAction; 
	UINT state = lpDrawItemStruct->itemState; 
	CString strText; 
	HICON hIcon; 
	if(data != NULL)
	{
		strText = data->menuText; 
		if(data->menuIconNormal == -1)
			hIcon = NULL; 
		else if(state & ODS_SELECTED)
		{
			if(data->menuIconSelected != -1)
				hIcon = AfxGetApp()->LoadIcon(data->menuIconSelected); 
			else 
				hIcon = AfxGetApp()->LoadIcon(data->menuIconNormal); 
		}
		else 
			hIcon = AfxGetApp()->LoadIcon(data->menuIconNormal); 
	}
	else 
	{
		strText.Empty(); 
		hIcon = NULL; 
	}

	CRect rect; 
	rect.CopyRect(&lpDrawItemStruct->rcItem); 
	COLORREF crText = m_crText; 
	LOGFONT lf = m_lf;
	CFont dispFont; 

	if(state & ODS_SELECTED)
	{
		CPen* pOldPen = pDC->SelectObject(&m_penBack); 
		if(m_hilightStyle != Normal)
			pDC->FillRect(rect, &m_brBackground); 
		else 
			pDC->FillRect(rect, &m_brSelect); 
		pDC->SelectObject(pOldPen); 
		pDC->Draw3dRect(rect, GetSysColor(COLOR_3DHILIGHT), GetSysColor(COLOR_3DSHADOW)); 
		
		lf.lfWeight = FW_BOLD; 
		if(dispFont.GetSafeHandle() != NULL)
			dispFont.DeleteObject(); 
		dispFont.CreateFontIndirect(&lf); 
		crText = m_clrHilightText; 
	}
	else 
	{
		CPen* pOldPen = pDC->SelectObject(&m_penBack); 
		pDC->FillRect(rect, &m_brBackground); 
		pDC->SelectObject(pOldPen); 
		pDC->Draw3dRect(rect, m_clrBack, m_clrBack); 
		
		if(dispFont.GetSafeHandle() != NULL)
			dispFont.DeleteObject(); 
		dispFont.CreateFontIndirect(&lf); 
	}

	if(hIcon != NULL)
	{
		DrawIconEx(pDC->GetSafeHdc(), rect.left, rect.top, hIcon, max(m_iconX, 32), max(m_iconY, 32), 0, NULL, DI_NORMAL); 
	}

	rect.left += max(m_iconX, 32); 
	if(!strText.IsEmpty())
	{
		int iOldMode = pDC->GetBkMode(); 
		pDC->SetBkMode(TRANSPARENT); 
		pDC->SetTextColor(crText); 
		CFont* pOldFont = pDC->SelectObject(&dispFont); 
		pDC->DrawText(strText, rect, DT_LEFT | DT_SINGLELINE); 
		pDC->SetBkMode(iOldMode); 
		pDC->SelectObject(pOldFont); 
	}

	dispFont.DeleteObject(); 
}

void CCustomMenu::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	MENUDATA* pData = (MENUDATA*)lpMeasureItemStruct->itemData; 
	CDC* pDC = AfxGetApp()->m_pMainWnd->GetDC(); 
	CFont* pFont = pDC->SelectObject(&m_fontMenu); 
	CString strText = pData->menuText; 
	CSize size = pDC->GetTextExtent(strText); 
	//TEXTMETRIC tm; 
	//pDC->GetTextMetrics(&tm); 
	pDC->SelectObject(pFont); 
	AfxGetApp()->m_pMainWnd->ReleaseDC(pDC); 

    //lpMeasureItemStruct->itemWidth = m_iconX + tm.tmAveCharWidth * lstrlen(((MENUDATA*)(lpMeasureItemStruct->itemData))->menuText) + 10; 
    //lpMeasureItemStruct->itemHeight = max(m_iconY, m_iMenuHeight + 1); 
	lpMeasureItemStruct->itemWidth = m_iconX + size.cx + 10; 
	lpMeasureItemStruct->itemHeight = max(m_iconY, m_iMenuHeight + 1); 
}

void CCustomMenu::SetIconSize(int cx, int cy)
{
	m_iconX = cx; 
	m_iconY = cy; 
}

void CCustomMenu::SetTextColor(COLORREF clrText)
{
	m_crText = clrText; 
}

void CCustomMenu::SetBackColor(COLORREF clrBack)
{
	m_clrBack = clrBack; 
	if(m_brBackground.GetSafeHandle() != NULL)
		m_brBackground.DeleteObject(); 
	m_brBackground.CreateSolidBrush(clrBack); 
}

void CCustomMenu::SetHighlightColor(COLORREF clrHilight)
{
	m_clrHilight = clrHilight; 
	if(m_brSelect.GetSafeHandle() != NULL)
		m_brSelect.DeleteObject(); 
	m_brSelect.CreateSolidBrush(clrHilight); 
}

void CCustomMenu::SetHighlightTextColor(COLORREF clrHilightText)
{
	m_clrHilightText = clrHilightText; 
}

void CCustomMenu::SetHighlightStyle(HIGHLIGHTSTYLE hilightStyle)
{
	m_hilightStyle = hilightStyle; 
}