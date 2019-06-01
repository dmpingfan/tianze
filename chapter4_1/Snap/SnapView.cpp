// SnapView.cpp : implementation of the CSnapView class
//

#include "stdafx.h"
#include "Snap.h"

#include "SnapDoc.h"
#include "SnapView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnapView

IMPLEMENT_DYNCREATE(CSnapView, CView)

BEGIN_MESSAGE_MAP(CSnapView, CView)
	//{{AFX_MSG_MAP(CSnapView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnapView construction/destruction

CSnapView::CSnapView()
{
}

CSnapView::~CSnapView()
{
}

BOOL CSnapView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSnapView drawing

void CSnapView::OnDraw(CDC* pDC)
{
	CSnapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CSnapView printing

BOOL CSnapView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSnapView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CSnapView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// CSnapView diagnostics

#ifdef _DEBUG
void CSnapView::AssertValid() const
{
	CView::AssertValid();
}

void CSnapView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSnapDoc* CSnapView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnapDoc)));
	return (CSnapDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSnapView message handlers
