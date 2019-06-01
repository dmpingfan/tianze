// DragView.cpp : implementation of the CDragView class
//

#include "stdafx.h"
#include "Drag.h"

#include "DragDoc.h"
#include "DragView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDragView

IMPLEMENT_DYNCREATE(CDragView, CFormView)

BEGIN_MESSAGE_MAP(CDragView, CFormView)
	//{{AFX_MSG_MAP(CDragView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDragView construction/destruction

CDragView::CDragView()
	: CFormView(CDragView::IDD)
{
	//{{AFX_DATA_INIT(CDragView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CDragView::~CDragView()
{
}

void CDragView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDragView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CDragView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CFormView::PreCreateWindow(cs);
}

void CDragView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CDragView diagnostics

#ifdef _DEBUG
void CDragView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDragView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDragDoc* CDragView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDragDoc)));
	return (CDragDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDragView message handlers

void CDragView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	CDragDoc* pDoc = GetDocument(); 
    SetDlgItemText(IDC_EDIT1, pDoc->GetPathName()); 
}
