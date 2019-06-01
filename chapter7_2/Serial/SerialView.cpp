// SerialView.cpp : implementation of the CSerialView class
//

#include "stdafx.h"
#include "Serial.h"

#include "SerialDoc.h"
#include "SerialView.h"
#include "DataObject.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSerialView

IMPLEMENT_DYNCREATE(CSerialView, CView)

BEGIN_MESSAGE_MAP(CSerialView, CView)
	//{{AFX_MSG_MAP(CSerialView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSerialView construction/destruction

CSerialView::CSerialView()
{
}

CSerialView::~CSerialView()
{
}

BOOL CSerialView::PreCreateWindow(CREATESTRUCT& cs)
{
	if(!CView::PreCreateWindow(cs))
        return FALSE; 

    cs.dwExStyle &= ~WS_EX_CLIENTEDGE; 
    cs.dwExStyle |= WS_EX_STATICEDGE; 
    return TRUE; 
}

/////////////////////////////////////////////////////////////////////////////
// CSerialView drawing

void CSerialView::OnDraw(CDC* pDC)
{
	CSerialDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

    CString str; 
    str.Format("%d", pDoc->m_obj.m_nNumber); 
    pDC->TextOut(20, 10, str); 
    pDC->TextOut(20, 30, pDoc->m_obj.m_strName); 
}

/////////////////////////////////////////////////////////////////////////////
// CSerialView diagnostics

#ifdef _DEBUG
void CSerialView::AssertValid() const
{
	CView::AssertValid();
}

void CSerialView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSerialDoc* CSerialView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSerialDoc)));
	return (CSerialDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSerialView message handlers
