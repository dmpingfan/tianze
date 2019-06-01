// XTree.cpp : implementation file
//

#include "stdafx.h"
#include "TreeTest.h"
#include "XTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// XTree

XTree::XTree()
{
}

XTree::~XTree()
{
}


BEGIN_MESSAGE_MAP(XTree, CTreeCtrl)
	//{{AFX_MSG_MAP(XTree)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// XTree message handlers

void XTree::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
    HTREEITEM hItem = NULL; 
    DRAWITEMSTRUCT dis; 
    CRect rc; 
    
    CFont* pOldFont = (CFont*)dc.SelectObject(GetFont()); 
    UINT nMode = dc.SetBkMode(TRANSPARENT); 

    for(hItem = GetFirstVisibleItem(); hItem != NULL; hItem = GetNextVisibleItem(hItem))
    {
        if(!GetItemRect(hItem, rc, TRUE)) //FALSE); 
            continue; 

        CRect rect = dc.m_ps.rcPaint; 
        if(rc.left > rect.right || rc.right < rect.left ||
            rc.top > rect.bottom || rc.bottom < rect.top)
            continue; 

        dis.hwndItem = (HWND)hItem; 
        dis.rcItem = rc; 
        OnDrawItem(0, &dis, &dc); 
    }

    dc.SetBkMode(nMode); 
    dc.SelectObject(pOldFont); 

	// Do not call CTreeCtrl::OnPaint() for painting messages
}

void XTree::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDIS, CDC* pDC)
{
    //pDC->Rectangle(&lpDIS->rcItem); 
    CString strText; 
    TVITEM item; 
    item.hItem = (HTREEITEM)lpDIS->hwndItem; 
    item.pszText = strText.GetBuffer(128); 
    item.cchTextMax = 128; 
    item.mask = TVIF_TEXT | TVIF_STATE; 
    GetItem(&item); 

    COLORREF clrText = GetSysColor(COLOR_BTNTEXT); 
    if(item.state & TVIS_SELECTED)
    {
        pDC->FillSolidRect(&lpDIS->rcItem, GetSysColor(COLOR_HIGHLIGHT)); 
        //pDC->InvertRect(&lpDIS->rcItem); 
        pDC->DrawFocusRect(&lpDIS->rcItem); 
        clrText = GetSysColor(COLOR_BTNFACE); 
    }
    else 
    {
        //pDC->InvertRect(&lpDIS->rcItem); 
        pDC->FillSolidRect(&lpDIS->rcItem, RGB(255, 255, 255)); 
    }

    COLORREF clrOldText = pDC->SetTextColor(clrText); 
    pDC->DrawText(item.pszText, &lpDIS->rcItem, DT_LEFT | DT_VCENTER | DT_SINGLELINE); 
    pDC->SetTextColor(clrOldText); 
}
