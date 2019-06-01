// PopSysMenuView.cpp : implementation of the CPopSysMenuView class
//

#include "stdafx.h"
#include "PopSysMenu.h"

#include "PopSysMenuDoc.h"
#include "PopSysMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPopSysMenuView

IMPLEMENT_DYNCREATE(CPopSysMenuView, CView)

BEGIN_MESSAGE_MAP(CPopSysMenuView, CView)
	//{{AFX_MSG_MAP(CPopSysMenuView)
	ON_WM_CONTEXTMENU()
	ON_WM_SYSCOMMAND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopSysMenuView construction/destruction

CPopSysMenuView::CPopSysMenuView()
{
	// TODO: add construction code here

}

CPopSysMenuView::~CPopSysMenuView()
{
}

BOOL CPopSysMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPopSysMenuView drawing

void CPopSysMenuView::OnDraw(CDC* pDC)
{
	CPopSysMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPopSysMenuView printing

BOOL CPopSysMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPopSysMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPopSysMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPopSysMenuView diagnostics

#ifdef _DEBUG
void CPopSysMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CPopSysMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPopSysMenuDoc* CPopSysMenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPopSysMenuDoc)));
	return (CPopSysMenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPopSysMenuView message handlers

void CPopSysMenuView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu* pMenu = GetParentFrame()->GetSystemMenu(FALSE); 
	if(pMenu != NULL)
	{
		//ClientToScreen(&point); 
		if(point.x == -1 && point.y == -1)
		{
			CRect rect; 
			GetClientRect(&rect); 
			ClientToScreen(&rect); 
			point = rect.TopLeft();  
		}

		pMenu->EnableMenuItem(6, MF_BYPOSITION | MF_GRAYED); //ID_FILE_CLOSE, MF_BYCOMMAND | MF_GRAYED); 
		pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, GetParentFrame()); 
	}
}

void CPopSysMenuView::OnSysCommand(UINT nID, LPARAM lParam) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnSysCommand(nID, lParam);
}
