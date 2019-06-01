// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Text.h"
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
	CRect rect; 
    GetClientRect(&rect); 
    CString str(_T("…………旋转文本!")); 
    
    CFont font; 
    LOGFONT lf; 
    memset(&lf, 0, sizeof(LOGFONT)); 
    lf.lfHeight = -14; 
    lf.lfWeight = FW_NORMAL; 
    lf.lfClipPrecision = CLIP_LH_ANGLES; // doesn't matter.
    strcpy(lf.lfFaceName, "宋体"); 

    UINT nMode = dc.SetBkMode(TRANSPARENT); 
    for(int i=0; i<3600; i+=150)
    {
        lf.lfEscapement = i;
        font.CreateFontIndirect(&lf); 
        CFont* pOldFont = dc.SelectObject(&font); 
        dc.TextOut(rect.Width() / 2, rect.Height() / 2, str); 
        dc.SelectObject(pOldFont); 
        font.DeleteObject(); 
    }
    dc.SetBkMode(nMode); 

	// Do not call CWnd::OnPaint() for painting messages
}

