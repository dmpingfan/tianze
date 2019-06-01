// TipDayView.cpp : implementation of the CTipDayView class
//

#include "stdafx.h"
#include "TipDay.h"

#include "TipDayDoc.h"
#include "TipDayView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTipDayView

IMPLEMENT_DYNCREATE(CTipDayView, CView)

BEGIN_MESSAGE_MAP(CTipDayView, CView)
	//{{AFX_MSG_MAP(CTipDayView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTipDayView construction/destruction

CTipDayView::CTipDayView()
{
}

CTipDayView::~CTipDayView()
{
}

BOOL CTipDayView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTipDayView drawing

void CTipDayView::OnDraw(CDC* pDC)
{
	CTipDayDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CTipDayView diagnostics

#ifdef _DEBUG
void CTipDayView::AssertValid() const
{
	CView::AssertValid();
}

void CTipDayView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTipDayDoc* CTipDayView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTipDayDoc)));
	return (CTipDayDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTipDayView message handlers
