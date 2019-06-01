// BaldView.cpp : implementation of the CBaldView class
//

#include "stdafx.h"
#include "Bald.h"

#include "BaldDoc.h"
#include "BaldView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaldView

IMPLEMENT_DYNCREATE(CBaldView, CView)

BEGIN_MESSAGE_MAP(CBaldView, CView)
	//{{AFX_MSG_MAP(CBaldView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaldView construction/destruction

CBaldView::CBaldView()
{
	// TODO: add construction code here

}

CBaldView::~CBaldView()
{
}

BOOL CBaldView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBaldView drawing

void CBaldView::OnDraw(CDC* pDC)
{
	CBaldDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBaldView printing

BOOL CBaldView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBaldView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBaldView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBaldView diagnostics

#ifdef _DEBUG
void CBaldView::AssertValid() const
{
	CView::AssertValid();
}

void CBaldView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBaldDoc* CBaldView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaldDoc)));
	return (CBaldDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaldView message handlers
