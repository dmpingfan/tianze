// XButton.cpp : implementation file
//

#include "stdafx.h"
#include "Btn.h"
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
	m_nState = BTN_STATE_NORMAL; 
	m_bDown = FALSE; 
}

XButton::~XButton()
{
}


BEGIN_MESSAGE_MAP(XButton, CButton)
	//{{AFX_MSG_MAP(XButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// XButton message handlers

//void XButton::OnPaint() 
//{
//    CPaintDC dc(this); // device context for painting
    
//    // TODO: Add your message handler code here
//    CBitmap* pBitmap; 
//    if(m_nState == BTN_STATE_NORMAL)
//        pBitmap = &m_bmNormal; 
//    else if(m_nState == BTN_STATE_PRESSED)
//        pBitmap = &m_bmPressed; 
//    else 
//        pBitmap = &m_bmHover; 

//    BITMAP bmp; 
//    pBitmap->GetBitmap(&bmp); 
//    CDC memDC; 
//    memDC.CreateCompatibleDC(&dc); 
//    memDC.SelectObject(pBitmap); 

//    CRect rect; 
//    GetClientRect(&rect); 
//    dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY); 
//    //dc.BitBlt(0, 0, bmp.bmWidth, bmp.bmHeight, &memDC, 0, 0, SRCCOPY); 
//    // Do not call CButton::OnPaint() for painting messages
//}

void XButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bDown = TRUE; 
	m_nState = BTN_STATE_PRESSED; 
	SetCapture(); 
	Invalidate(); 
	CButton::OnLButtonDown(nFlags, point);
}

void XButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bDown = FALSE; 
	m_nState = BTN_STATE_NORMAL; 
	ReleaseCapture(); 
	Invalidate(); 
	CButton::OnLButtonUp(nFlags, point);
}

void XButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	UINT nState; 
	CRect rect; 
	GetClientRect(&rect); 
	if(rect.PtInRect(point))
	{
		if(m_bDown)
			nState = BTN_STATE_PRESSED; 
		else 
			nState = BTN_STATE_HOVER; 
	}
	else
		nState = BTN_STATE_NORMAL; 

	if(m_nState != nState)
	{
		m_nState = nState; 
		Invalidate(); 
	}

	CButton::OnMouseMove(nFlags, point);
}

void XButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC); 
	
	// TODO: Add your message handler code here
    //CBitmap* pBitmap; 
    //if(m_nState == BTN_STATE_NORMAL)
    //    pBitmap = &m_bmNormal; 
    //else if(m_nState == BTN_STATE_PRESSED)
    //    pBitmap = &m_bmPressed; 
    //else 
    //    pBitmap = &m_bmHover; 

    //BITMAP bmp; 
    //pBitmap->GetBitmap(&bmp); 
    //CDC memDC; 
    //memDC.CreateCompatibleDC(pDC); 
    //memDC.SelectObject(pBitmap); 

    //CRect rect; 
    //GetClientRect(&rect); 
    //pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY); 
    ////dc.BitBlt(0, 0, bmp.bmWidth, bmp.bmHeight, &memDC, 0, 0, SRCCOPY); 

	CRect rect; 
	GetClientRect(&rect); 
	m_ilButton.Draw(pDC, m_nState, rect.TopLeft(), ILD_NORMAL); 
	//m_ilButton.DrawIndirect(pDC, m_nState, rect.TopLeft(), rect.Size(), CPoint(0, 0)); 
}