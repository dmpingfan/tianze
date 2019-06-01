// SizeLimitView.cpp : implementation of the CSizeLimitView class
//

#include "stdafx.h"
#include "SizeLimit.h"

#include "SizeLimitDoc.h"
#include "SizeLimitView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSizeLimitView

IMPLEMENT_DYNCREATE(CSizeLimitView, CView)

BEGIN_MESSAGE_MAP(CSizeLimitView, CView)
	//{{AFX_MSG_MAP(CSizeLimitView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSizeLimitView construction/destruction

CSizeLimitView::CSizeLimitView()
{
	// TODO: add construction code here

}

CSizeLimitView::~CSizeLimitView()
{
}

BOOL CSizeLimitView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSizeLimitView drawing

void CSizeLimitView::OnDraw(CDC* pDC)
{
	CSizeLimitDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSizeLimitView printing

BOOL CSizeLimitView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSizeLimitView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSizeLimitView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSizeLimitView diagnostics

#ifdef _DEBUG
void CSizeLimitView::AssertValid() const
{
	CView::AssertValid();
}

void CSizeLimitView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSizeLimitDoc* CSizeLimitView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSizeLimitDoc)));
	return (CSizeLimitDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSizeLimitView message handlers
