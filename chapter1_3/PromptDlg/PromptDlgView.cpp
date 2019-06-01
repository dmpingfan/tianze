// PromptDlgView.cpp : implementation of the CPromptDlgView class
//

#include "stdafx.h"
#include "PromptDlg.h"

#include "PromptDlgDoc.h"
#include "PromptDlgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPromptDlgView

IMPLEMENT_DYNCREATE(CPromptDlgView, CView)

BEGIN_MESSAGE_MAP(CPromptDlgView, CView)
	//{{AFX_MSG_MAP(CPromptDlgView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPromptDlgView construction/destruction

CPromptDlgView::CPromptDlgView()
{
	// TODO: add construction code here

}

CPromptDlgView::~CPromptDlgView()
{
}

BOOL CPromptDlgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPromptDlgView drawing

void CPromptDlgView::OnDraw(CDC* pDC)
{
	CPromptDlgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPromptDlgView printing

BOOL CPromptDlgView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPromptDlgView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPromptDlgView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPromptDlgView diagnostics

#ifdef _DEBUG
void CPromptDlgView::AssertValid() const
{
	CView::AssertValid();
}

void CPromptDlgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPromptDlgDoc* CPromptDlgView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPromptDlgDoc)));
	return (CPromptDlgDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPromptDlgView message handlers
