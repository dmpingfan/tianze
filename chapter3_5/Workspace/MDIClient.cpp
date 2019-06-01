// MDIClient.cpp : implementation file
//

#include "stdafx.h"
#include "Workspace.h"
#include "MDIClient.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDIClient

CMDIClient::CMDIClient()
{
	m_bmBack.LoadBitmap(IDB_XP); 
}

CMDIClient::~CMDIClient()
{
}


BEGIN_MESSAGE_MAP(CMDIClient, CWnd)
	//{{AFX_MSG_MAP(CMDIClient)
	//ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMDIClient message handlers

BOOL CMDIClient::OnEraseBkgnd(CDC* pDC) 
{
    // TODO: Add your message handler code here and/or call default
    CRect rect; 
    GetClientRect(&rect); 
    //pDC->FillSolidRect(&rect, RGB(255, 255, 255)); 
    
    //CWnd::OnEraseBkgnd(pDC); 
    if(m_bmBack.GetSafeHandle())
    {
        CBrush brush; 
        brush.CreatePatternBrush(&m_bmBack); 
        CBrush* pOldBrush = pDC->SelectObject(&brush);
        CPen* pOldPen = (CPen*)pDC->SelectStockObject(NULL_PEN); 
        pDC->Rectangle(&rect);
        pDC->SelectObject(pOldPen); 
        pDC->SelectObject(pOldBrush); 
    }
    else 
        pDC->FillSolidRect(&rect, RGB(0, 255, 0)); 
    
    return TRUE; 
    //return CWnd::OnEraseBkgnd(pDC);
}

//void CMDIClient::OnPaint() 
//{
//    CPaintDC dc(this); // device context for painting
    
//    // TODO: Add your message handler code here
//    CRect rect; 
//    GetClientRect(&rect); 
//    if(m_bmBack.GetSafeHandle())
//    {
//        CBrush brush; 
//        brush.CreatePatternBrush(&m_bmBack); 
//        CBrush* pOldBrush = dc.SelectObject(&brush);
//        CPen* pOldPen = (CPen*)dc.SelectStockObject(NULL_PEN); 
//        dc.Rectangle(&rect);
//        dc.SelectObject(pOldPen); 
//        dc.SelectObject(pOldBrush); 
//    }
//    else 
//        dc.FillSolidRect(&rect, RGB(0, 255, 0)); 
    
    
//    // Do not call CWnd::OnPaint() for painting messages
//}

//HBRUSH CMDIClient::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
//{
//    HBRUSH hbr = CWnd::OnCtlColor(pDC, pWnd, nCtlColor);
    
//    // TODO: Change any attributes of the DC here
//    CRect rect; 
//    GetClientRect(&rect); 

//    CBrush brush; 
//    brush.CreatePatternBrush(&m_bmBack); 
//    CBrush* pOldBrush = pDC->SelectObject(&brush); 
//    pDC->Rectangle(&rect); 
//    pDC->SelectObject(pOldBrush); 
//    // TODO: Return a different brush if the default is not desired
//    return hbr;

//    //HBRUSH hbr = ::CreatePatternBrush((HBITMAP)m_bmBack.GetSafeHandle()); 
//    //return hbr; 
//}

void CMDIClient::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	Invalidate(); 
}
