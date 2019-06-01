// XButton.cpp : implementation file
//

#include "stdafx.h"
#include "ButtonTest.h"
#include "XButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// XButton

XButton::XButton()
{
    //m_clrText = GetSysColor(COLOR_BTNTEXT); 
    //m_clrTextDisabled = GetSysColor(COLOR_GRAYTEXT); 
    //m_clrBack = GetSysColor(COLOR_BTNFACE); 
    //m_clrBackDisabled = GetSysColor(COLOR_BTNFACE); 
}

XButton::~XButton()
{
}


BEGIN_MESSAGE_MAP(XButton, CButton)
	//{{AFX_MSG_MAP(XButton)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// XButton message handlers

BOOL XButton::Attach(const UINT nID, CWnd* pParent)
{
    pParent->GetDlgItem(nID)->ModifyStyle(0, BS_OWNERDRAW, 0); 
    return SubclassDlgItem(nID, pParent); 
}

void XButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
    CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC); 
    UINT nState = lpDrawItemStruct->itemState; 

    CRect rcFocus, rcButton; 
    rcButton = lpDrawItemStruct->rcItem; 
    rcFocus = lpDrawItemStruct->rcItem; 
    rcFocus.DeflateRect(4, 4); 

    //TCHAR buffer[512]; 
    //GetWindowText(buffer, 512); 

    //CBrush brBack(m_clrBack); 
    //pDC->FillRect(rcButton, &brBack); 
    //pDC->Draw3dRect(rcButton, GetSysColor(COLOR_3DLIGHT), GetSysColor(COLOR_3DSHADOW)); 

    //if(nState & ODS_DISABLED)
    //{
    //    COLORREF clrTextOld = pDC->SetTextColor(m_clrTextDisabled); 
    //    UINT nMode = pDC->SetBkMode(TRANSPARENT); 
    //    pDC->DrawText(buffer, rcButton, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
    //    pDC->SetBkMode(nMode); 
    //    pDC->SetTextColor(clrTextOld); 
    //}
    //else 
    //{
    //    COLORREF clrTextOld = pDC->SetTextColor(m_clrText); 
    //    UINT nMode = pDC->SetBkMode(TRANSPARENT); 
    //    pDC->DrawText(buffer, rcButton, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
    //    pDC->SetBkMode(nMode); 
    //    pDC->SetTextColor(clrTextOld); 
    //}

    //if(nState & ODS_FOCUS)
    //    pDC->DrawFocusRect(rcFocus); 

    if(nState & ODS_SELECTED)
        pDC->DrawFrameControl(rcButton, DFC_BUTTON, DFCS_BUTTONPUSH | DFCS_PUSHED); 
    else 
        pDC->DrawFrameControl(rcButton, DFC_BUTTON, DFCS_BUTTONPUSH);

    TCHAR buffer[512]; 
    GetWindowText(buffer, 512); 
    COLORREF clrTextOld; 
    if(nState & ODS_DISABLED)
        clrTextOld = pDC->SetTextColor(GetSysColor(COLOR_GRAYTEXT)); 
    else 
        clrTextOld = pDC->SetTextColor(GetSysColor(COLOR_BTNTEXT)); 

    UINT nMode = pDC->SetBkMode(TRANSPARENT); 
    pDC->DrawText(buffer, rcButton, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
    pDC->SetBkMode(nMode); 
    pDC->SetTextColor(clrTextOld); 

    if(nState & ODS_FOCUS)
        pDC->DrawFocusRect(rcFocus);

}
