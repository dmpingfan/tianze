// FormerView.cpp : implementation of the CFormerView class
//

#include "stdafx.h"
#include "Form.h"

#include "FormDoc.h"
#include "FormerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFormerView

IMPLEMENT_DYNCREATE(CFormerView, CFormView)

BEGIN_MESSAGE_MAP(CFormerView, CFormView)
	//{{AFX_MSG_MAP(CFormerView)
	ON_BN_CLICKED(IDC_BUTTON_NUM, OnButtonNum)
	//}}AFX_MSG_MAP
	// Standard printing commands
    ON_COMMAND(IDOK, OnOK)
    ON_COMMAND(IDCANCEL, OnCancel)
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFormerView construction/destruction

CFormerView::CFormerView()
	: CFormView(CFormerView::IDD)
{
	//{{AFX_DATA_INIT(CFormerView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CFormerView::~CFormerView()
{
}

void CFormerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFormerView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CFormerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CFormerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

    m_btn.SubclassDlgItem(IDC_BUTTON_NUM, this); 
}

/////////////////////////////////////////////////////////////////////////////
// CFormerView printing

BOOL CFormerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFormerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFormerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CFormerView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CFormerView diagnostics

#ifdef _DEBUG
void CFormerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFormerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFormDoc* CFormerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFormDoc)));
	return (CFormDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFormerView message handlers

void CFormerView::OnOK() 
{
	// TODO: Add your control notification handler code here
	CAnimateCtrl* pCtrl = (CAnimateCtrl*)GetDlgItem(IDC_ANIMATE_TEST); 
    pCtrl->Open(IDR_ANIMATE_MFC); 
    //pCtrl->Open(IDR_ANIMATE_BORING); 
    pCtrl->Play(0, -1, 10); 
}

void CFormerView::OnCancel()
{
	CAnimateCtrl* pCtrl = (CAnimateCtrl*)GetDlgItem(IDC_ANIMATE_TEST); 
    pCtrl->Stop(); 
    pCtrl->Close(); 
}

void CFormerView::OnButtonNum() 
{
	// TODO: Add your control notification handler code here
	static int i = 0; 
    SetDlgItemInt(IDC_EDIT_NUM, i++); 
}
