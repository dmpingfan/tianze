// NoneView.cpp : implementation of the CNoneView class
//

#include "stdafx.h"
#include "None.h"

#include "NoneDoc.h"
#include "NoneView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNoneView

IMPLEMENT_DYNCREATE(CNoneView, CView)

BEGIN_MESSAGE_MAP(CNoneView, CView)
	//{{AFX_MSG_MAP(CNoneView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoneView construction/destruction

CNoneView::CNoneView()
{
	// TODO: add construction code here

}

CNoneView::~CNoneView()
{
}

BOOL CNoneView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CNoneView drawing

void CNoneView::OnDraw(CDC* pDC)
{
	CNoneDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CNoneView printing

BOOL CNoneView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNoneView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNoneView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CNoneView diagnostics

#ifdef _DEBUG
void CNoneView::AssertValid() const
{
	CView::AssertValid();
}

void CNoneView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNoneDoc* CNoneView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNoneDoc)));
	return (CNoneDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNoneView message handlers
