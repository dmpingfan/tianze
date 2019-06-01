// FtpView.cpp : implementation of the CFtpView class
//

#include "stdafx.h"
#include "Ftp.h"

#include "FtpDoc.h"
#include "FtpView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFtpView

IMPLEMENT_DYNCREATE(CFtpView, CView)

BEGIN_MESSAGE_MAP(CFtpView, CView)
	//{{AFX_MSG_MAP(CFtpView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFtpView construction/destruction

CFtpView::CFtpView()
{
	// TODO: add construction code here

}

CFtpView::~CFtpView()
{
}

BOOL CFtpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFtpView drawing

void CFtpView::OnDraw(CDC* pDC)
{
	CFtpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFtpView printing

BOOL CFtpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFtpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFtpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFtpView diagnostics

#ifdef _DEBUG
void CFtpView::AssertValid() const
{
	CView::AssertValid();
}

void CFtpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFtpDoc* CFtpView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFtpDoc)));
	return (CFtpDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFtpView message handlers
