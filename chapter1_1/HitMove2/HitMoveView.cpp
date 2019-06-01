// HitMoveView.cpp : implementation of the CHitMoveView class
//

#include "stdafx.h"
#include "HitMove.h"

#include "HitMoveDoc.h"
#include "HitMoveView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHitMoveView

IMPLEMENT_DYNCREATE(CHitMoveView, CView)

BEGIN_MESSAGE_MAP(CHitMoveView, CView)
	//{{AFX_MSG_MAP(CHitMoveView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHitMoveView construction/destruction

CHitMoveView::CHitMoveView()
{
	// TODO: add construction code here

}

CHitMoveView::~CHitMoveView()
{
}

BOOL CHitMoveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHitMoveView drawing

void CHitMoveView::OnDraw(CDC* pDC)
{
	CHitMoveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CHitMoveView printing

BOOL CHitMoveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHitMoveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHitMoveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHitMoveView diagnostics

#ifdef _DEBUG
void CHitMoveView::AssertValid() const
{
	CView::AssertValid();
}

void CHitMoveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHitMoveDoc* CHitMoveView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHitMoveDoc)));
	return (CHitMoveDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHitMoveView message handlers

void CHitMoveView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CView::OnLButtonDown(nFlags, point);
    GetParentFrame()->PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y)); 
    //GetParentFrame()->PostMessage(WM_NCLBUTTONDOWN, HTCLOSE, MAKELPARAM(point.x, point.y)); 
    //GetParentFrame()->PostMessage(WM_NCLBUTTONDOWN, HTSIZE, MAKELPARAM(point.x, point.y)); 
    //GetParentFrame()->PostMessage(WM_NCLBUTTONDOWN, HTMINBUTTON, MAKELPARAM(point.x, point.y)); 
}
