// XCheckTree.cpp : implementation file
//

#include "stdafx.h"
#include "CmnCtrl.h"
#include "XCheckTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// XCheckTree

XCheckTree::XCheckTree()
{
}

XCheckTree::~XCheckTree()
{
}


BEGIN_MESSAGE_MAP(XCheckTree, CTreeCtrl)
	//{{AFX_MSG_MAP(XCheckTree)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// XCheckTree message handlers

//HTREEITEM XCheckTree::InsertItem(LPTV_INSERTSTRUCT lpInsertStruct)
//{
//    lpInsertStruct->item.mask |= TVIF_STATE; 
//    lpInsertStruct->item.state = INDEXTOSTATEIMAGEMASK(1); 
//    lpInsertStruct->item.stateMask = TVIS_STATEIMAGEMASK; 
//    return CTreeCtrl::InsertItem(lpInsertStruct); 
//}

//HTREEITEM XCheckTree::InsertItem(LPCTSTR lpszItem)
//{
//    return CTreeCtrl::InsertItem(lpszItem); 
//}

void XCheckTree::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	UINT nFlag = 0;
    HTREEITEM hItem = HitTest(point, &nFlag); 
    if(nFlag & TVHT_ONITEMSTATEICON)
    {
        int iImage = GetItemState(hItem, TVIS_STATEIMAGEMASK) >> 12; 
        SetItemState(hItem, INDEXTOSTATEIMAGEMASK(iImage == 1 ? 2 : 1), TVIS_STATEIMAGEMASK); 
    }

	CTreeCtrl::OnLButtonDown(nFlags, point);
}

void XCheckTree::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar == VK_SPACE)
    {
        HTREEITEM hItem = GetSelectedItem(); 
        int iImage = GetItemState(hItem, TVIS_STATEIMAGEMASK) >> 12; 
        SetItemState(hItem, INDEXTOSTATEIMAGEMASK(iImage == 1 ? 2 : 1), TVIS_STATEIMAGEMASK); 
    }

	CTreeCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL XCheckTree::IsItemChecked(HTREEITEM hItem)
{
    return GetItemState(hItem, TVIS_STATEIMAGEMASK) >> 12 == 2; 
}

HTREEITEM XCheckTree::GetFirstCheckedItem()
{
    for(HTREEITEM hItem = GetRootItem(); hItem != NULL; hItem = GetNextItem(hItem, TVGN_NEXT))
    {
        if(IsItemChecked(hItem))
            return hItem; 
    }

    return NULL; 
}

HTREEITEM XCheckTree::GetNextCheckedItem(HTREEITEM hItem)
{
    for(hItem = GetNextItem(hItem, TVGN_NEXT); hItem != NULL; hItem = GetNextItem(hItem, TVGN_NEXT))
    {
        if(IsItemChecked(hItem))
            return hItem; 
    }

    return NULL; 
}

HTREEITEM XCheckTree::GetPrevCheckedItem(HTREEITEM hItem)
{
    for(hItem = GetNextItem(hItem, TVGN_PREVIOUS); hItem != NULL; hItem = GetNextItem(hItem, TVGN_PREVIOUS))
    {
        if(IsItemChecked(hItem))
            return hItem; 
    }

    return NULL; 
}
