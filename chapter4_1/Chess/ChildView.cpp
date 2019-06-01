// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Chess.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
{
    m_bmBlack.LoadBitmap(IDB_CHESSBLACK); 
    m_bmWhite.LoadBitmap(IDB_CHESSWHITE); 
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CDC dcMem; 
    dcMem.CreateCompatibleDC(&dc); 
    CBitmap* pBitmap = dcMem.SelectObject(&m_bmBlack);
    
    BITMAP bmp; 
    m_bmBlack.GetBitmap(&bmp); 
    CBrush brush(RGB(0, 0, 0)); 
    CPen pen(PS_SOLID, 1, RGB(0, 0, 0)); 
    CPen* pOldPen = dc.SelectObject(&pen); 
    CBrush* pOldBrush = dc.SelectObject(&brush); 
    dc.Ellipse(100, 100, 100 + bmp.bmWidth, 100 + bmp.bmHeight); 
    dc.StretchBlt(100, 100, bmp.bmWidth, bmp.bmHeight, &dcMem, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCPAINT); 
    dc.SelectObject(pOldBrush); 
    dc.SelectObject(pOldPen); 

    dc.StretchBlt(100, 200, bmp.bmWidth, bmp.bmHeight, &dcMem, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY); 

    dcMem.SelectObject(&m_bmWhite); 
    m_bmWhite.GetBitmap(&bmp); 
    //brush.DeleteObject(); 
    //brush.CreateSolidBrush(RGB(255, 255, 255)); 
    //pen.DeleteObject(); 
    //pen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255)); 
    pOldPen = dc.SelectObject(&pen); 
    pOldBrush = dc.SelectObject(&brush); 
    dc.Ellipse(500, 100, 500 + bmp.bmWidth, 100 + bmp.bmHeight); 
    dc.StretchBlt(500, 100, bmp.bmWidth, bmp.bmHeight, &dcMem, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCPAINT); 
    dc.SelectObject(pOldPen); 
    dc.SelectObject(pOldBrush); 

    dc.StretchBlt(500, 200, bmp.bmWidth, bmp.bmHeight, &dcMem, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY); 

    dcMem.SelectObject(pBitmap); 
	// Do not call CWnd::OnPaint() for painting messages
}

