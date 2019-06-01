// TopMostView.cpp : implementation of the CTopMostView class
//

#include "stdafx.h"
#include "TopMost.h"

#include "TopMostDoc.h"
#include "TopMostView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTopMostView

IMPLEMENT_DYNCREATE(CTopMostView, CView)

BEGIN_MESSAGE_MAP(CTopMostView, CView)
	//{{AFX_MSG_MAP(CTopMostView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTopMostView construction/destruction

CTopMostView::CTopMostView()
{
	// TODO: add construction code here

}

CTopMostView::~CTopMostView()
{
}

BOOL CTopMostView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTopMostView drawing

void CTopMostView::OnDraw(CDC* pDC)
{
	CTopMostDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTopMostView printing

BOOL CTopMostView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTopMostView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTopMostView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTopMostView diagnostics

#ifdef _DEBUG
void CTopMostView::AssertValid() const
{
	CView::AssertValid();
}

void CTopMostView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTopMostDoc* CTopMostView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTopMostDoc)));
	return (CTopMostDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTopMostView message handlers
