// PicView.cpp : implementation of the CPicView class
//

#include "stdafx.h"
#include "Pic.h"

#include "PicDoc.h"
#include "PicView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPicView

IMPLEMENT_DYNCREATE(CPicView, CView)

BEGIN_MESSAGE_MAP(CPicView, CView)
	//{{AFX_MSG_MAP(CPicView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPicView construction/destruction

CPicView::CPicView()
{
}

CPicView::~CPicView()
{
}

BOOL CPicView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPicView drawing

void CPicView::OnDraw(CDC* pDC)
{
	CPicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

    if(pDoc->m_pPic != NULL)
    {
        OLE_XSIZE_HIMETRIC hmWidth; 
        OLE_YSIZE_HIMETRIC hmHeight; 
        pDoc->m_pPic->get_Width(&hmWidth); 
        pDoc->m_pPic->get_Height(&hmHeight); 

        double fX, fY; 
        fX = (double)pDC->GetDeviceCaps(HORZRES) * (double)hmWidth / ((double)pDC->GetDeviceCaps(HORZSIZE) * 100.0); 
        fY = (double)pDC->GetDeviceCaps(VERTRES) * (double)hmHeight / ((double)pDC->GetDeviceCaps(VERTSIZE) * 100.0); 

        pDoc->m_pPic->Render(pDC->GetSafeHdc(), 0, 0, (DWORD)fX, (DWORD)fY, 0, hmHeight - 1, hmWidth, -hmHeight, NULL); 
    }
}

/////////////////////////////////////////////////////////////////////////////
// CPicView diagnostics

#ifdef _DEBUG
void CPicView::AssertValid() const
{
	CView::AssertValid();
}

void CPicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPicDoc* CPicView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPicDoc)));
	return (CPicDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPicView message handlers
