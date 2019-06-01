// CtrlInfoView.cpp : implementation of the CCtrlInfoView class
//

#include "stdafx.h"
#include "CtrlInfo.h"

#include "CtrlInfoDoc.h"
#include "CtrlInfoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCtrlInfoView

IMPLEMENT_DYNCREATE(CCtrlInfoView, CView)

BEGIN_MESSAGE_MAP(CCtrlInfoView, CView)
	//{{AFX_MSG_MAP(CCtrlInfoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCtrlInfoView construction/destruction

CCtrlInfoView::CCtrlInfoView()
{
	// TODO: add construction code here

}

CCtrlInfoView::~CCtrlInfoView()
{
}

BOOL CCtrlInfoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCtrlInfoView drawing

void CCtrlInfoView::OnDraw(CDC* pDC)
{
	CCtrlInfoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CCtrlInfoView printing

BOOL CCtrlInfoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCtrlInfoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCtrlInfoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCtrlInfoView diagnostics

#ifdef _DEBUG
void CCtrlInfoView::AssertValid() const
{
	CView::AssertValid();
}

void CCtrlInfoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCtrlInfoDoc* CCtrlInfoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCtrlInfoDoc)));
	return (CCtrlInfoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCtrlInfoView message handlers
