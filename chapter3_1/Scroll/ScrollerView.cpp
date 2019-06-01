// ScrollerView.cpp : implementation of the CScrollerView class
//

#include "stdafx.h"
#include "Scroll.h"

#include "ScrollDoc.h"
#include "ScrollerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScrollerView

IMPLEMENT_DYNCREATE(CScrollerView, CScrollView)

BEGIN_MESSAGE_MAP(CScrollerView, CScrollView)
	//{{AFX_MSG_MAP(CScrollerView)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScrollerView construction/destruction

CScrollerView::CScrollerView()
{
	// TODO: add construction code here

}

CScrollerView::~CScrollerView()
{
}

BOOL CScrollerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CScrollerView drawing

void CScrollerView::OnDraw(CDC* pDC)
{
	CScrollDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

    if(pDoc->m_file.m_pStream != NULL)
    {
        CString str; 
        int x = 20; 
        int y = 0; 
        pDoc->m_file.SeekToBegin(); 
        while(pDoc->m_file.ReadString(str))
        {
            //pDC->TextOut(x, y, str); 
            pDC->TabbedTextOut(x, y, str, 0, NULL, 0); 
            y += 20; 
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// CScrollerView printing

BOOL CScrollerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CScrollerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CScrollerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CScrollerView diagnostics

#ifdef _DEBUG
void CScrollerView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CScrollerView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CScrollDoc* CScrollerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CScrollDoc)));
	return (CScrollDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CScrollerView message handlers

void CScrollerView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
    CSize m_sizeTotal(800, 5000); 
	SetScrollSizes(MM_TEXT, m_sizeTotal); 
}

void CScrollerView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(!KeyScroll(nChar))
        CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CScrollerView::KeyScroll(UINT nChar)
{
    CScrollBar* pBar = GetScrollBarCtrl(SB_VERT); 
    CScrollBar* pBar2 = GetScrollBarCtrl(SB_HORZ); 
    switch(nChar)
    {
        case VK_UP:
            OnVScroll(SB_LINEUP, 0, pBar); 
            break; 
        case VK_DOWN:
            OnVScroll(SB_LINEDOWN, 0, pBar); 
            break; 
        case VK_LEFT:
            OnHScroll(SB_LINELEFT, 0, pBar2); 
            break; 
        case VK_RIGHT:
            OnHScroll(SB_LINERIGHT, 0, pBar2); 
            break; 
        case VK_HOME:
            OnVScroll(SB_TOP, 0, pBar); 
            break; 
        case VK_END:
            OnVScroll(SB_BOTTOM, 0, pBar); 
            break; 
        case VK_PRIOR:
            OnVScroll(SB_PAGEUP, 0, pBar); 
            break; 
        case VK_NEXT:
            OnVScroll(SB_PAGEDOWN, 0, pBar); 
            break; 
        default:
            return FALSE; 
    }

    GetDocument()->UpdateAllViews(this); 
    return TRUE; 
}

