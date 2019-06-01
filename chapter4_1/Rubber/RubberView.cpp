// RubberView.cpp : implementation of the CRubberView class
//

#include "stdafx.h"
#include "Rubber.h"

#include "RubberDoc.h"
#include "RubberView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRubberView

IMPLEMENT_DYNCREATE(CRubberView, CView)

BEGIN_MESSAGE_MAP(CRubberView, CView)
	//{{AFX_MSG_MAP(CRubberView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRubberView construction/destruction

CRubberView::CRubberView()
{
	// TODO: add construction code here
    m_tracker.m_rect.SetRect(0, 0, 100, 100); 
    m_tracker.m_nStyle = CRectTracker::resizeInside | CRectTracker::dottedLine; 
}

CRubberView::~CRubberView()
{
}

BOOL CRubberView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRubberView drawing

void CRubberView::OnDraw(CDC* pDC)
{
	CRubberDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

    CBrush brush(RGB(0, 0, 255)); 
    CBrush* pOldBrush = pDC->SelectObject(&brush); 

    CRect rcEllipse; 
    m_tracker.GetTrueRect(&rcEllipse); 
    pDC->Rectangle(rcEllipse); 
    m_tracker.Draw(pDC); 
    pDC->SelectObject(pOldBrush); 

    int nTabStop = 20; 
    CString str("Cathy\tNorman\tOliver"); 
    pDC->SetBkMode(TRANSPARENT); 
    COLORREF clrOld = pDC->SetTextColor(RGB(255, 255, 0)); 
    pDC->TabbedTextOut(rcEllipse.left, rcEllipse.top, str, 1, &nTabStop, 0); 

    pDC->DrawText(str, rcEllipse, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_EXPANDTABS); 
    pDC->SetTextColor(clrOld); 
}

/////////////////////////////////////////////////////////////////////////////
// CRubberView printing

BOOL CRubberView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRubberView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRubberView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRubberView diagnostics

#ifdef _DEBUG
void CRubberView::AssertValid() const
{
	CView::AssertValid();
}

void CRubberView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRubberDoc* CRubberView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRubberDoc)));
	return (CRubberDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRubberView message handlers

void CRubberView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    if(m_tracker.HitTest(point) != CRectTracker::hitNothing)
    {
        m_tracker.Track(this, point, TRUE); 
    }
    else 
    {
        m_tracker.TrackRubberBand(this, point, TRUE); 
    }

    Invalidate(); 
	CView::OnLButtonDown(nFlags, point);
}
