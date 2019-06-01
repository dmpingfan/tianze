// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "UseMenu.h"
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
	pMenu = new CMenu(); 
	//pMenu->CreateMenu(); 
	pMenu->CreatePopupMenu(); 
	pMenu->AppendMenu(MF_STRING, IDM_ITEM0, "&Copy"); 
	pMenu->AppendMenu(MF_STRING, IDM_ITEM1, "&Cut"); 
	pMenu->AppendMenu(MF_STRING, IDM_ITEM2, "&Paste"); 
	pMenu->AppendMenu(MF_SEPARATOR, 0, ""); 
	pMenu->AppendMenu(MF_STRING, IDM_ITEM4, "&Select All"); 
	pMenu->AppendMenu(MF_SEPARATOR, 0, ""); 
	pMenu->AppendMenu(MF_STRING, IDM_ITEM6, "&Delete"); 
}

CChildView::~CChildView()
{
	pMenu->DestroyMenu(); 
	delete pMenu; 
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_WM_CONTEXTMENU()
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
	
	// Do not call CWnd::OnPaint() for painting messages
}


void CChildView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
    //RECT rect; 
    //GetWindowRect(&rect); 
	//pMenu->TrackPopupMenu(TPM_RIGHTALIGN, point.x + rect.left, point.y + rect.top, this, NULL); 
	pMenu->TrackPopupMenu(TPM_RIGHTALIGN, point.x, point.y, this, NULL); 
}
