// ELISView.cpp : implementation of the CELISView class
//

#include "stdafx.h"
#include "ELIS.h"

#include "ELISSet.h"
#include "ELISDoc.h"
#include "ELISView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CELISView

IMPLEMENT_DYNCREATE(CELISView, CRecordView)

BEGIN_MESSAGE_MAP(CELISView, CRecordView)
	//{{AFX_MSG_MAP(CELISView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CELISView construction/destruction

CELISView::CELISView()
	: CRecordView(CELISView::IDD)
{
	//{{AFX_DATA_INIT(CELISView)
		// NOTE: the ClassWizard will add member initialization here
	m_pSet = NULL;
	//}}AFX_DATA_INIT
}

CELISView::~CELISView()
{
}

void CELISView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CELISView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
    
    SetDlgItemInt(IDC_EDIT_ID, m_pSet->m_ID); 
    SetDlgItemText(IDC_EDIT_NAME, m_pSet->m_Name); 
    SetDlgItemText(IDC_EDIT_REMARK, m_pSet->m_Remark); 
    SetDlgItemText(IDC_EDIT_IMAGE_PATH, m_pSet->m_ImagePath); 
    SetDlgItemText(IDC_EDIT_SN, m_pSet->m_SN); 
    SetDlgItemInt(IDC_EDIT_LENGTH, (int)m_pSet->m_Length); 
    SetDlgItemText(IDC_EDIT_LENGTH_UNIT, m_pSet->m_LengthUnit); 
    SetDlgItemInt(IDC_EDIT_WEIGHT, (int)m_pSet->m_Weight); 
    SetDlgItemText(IDC_EDIT_WEIGHT_UNIT, m_pSet->m_WeightUnit); 
    SetDlgItemInt(IDC_EDIT_OUTTER_DIAMETER, (int)m_pSet->m_OutterDiameter); 
    SetDlgItemText(IDC_EDIT_OUTTER_DIAMETER_UNIT, m_pSet->m_OutterDiameterUnit); 
    SetDlgItemInt(IDC_EDIT_INNER_DIAMETER, (int)m_pSet->m_InnerDiameter); 
    SetDlgItemText(IDC_EDIT_INNER_DIAMETER_UNIT, m_pSet->m_InnerDiameterUnit); 
    SetDlgItemInt(IDC_EDIT_TEMPERATURE_ENDURE, (int)m_pSet->m_TemperatureEndure); 
    SetDlgItemText(IDC_EDIT_TEMPERATURE_ENDURE_UNIT, m_pSet->m_TemperatureEndureUnit); 
    SetDlgItemInt(IDC_EDIT_PRESSURE_ENDURE, (int)m_pSet->m_PressureEndure); 
    SetDlgItemText(IDC_EDIT_PRESSURE_ENDURE_UNIT, m_pSet->m_PressureEndureUnit); 
    SetDlgItemInt(IDC_EDIT_MAX_SPEED, (int)m_pSet->m_MaxSpeed); 
    SetDlgItemText(IDC_EDIT_MAX_SPEED_UNIT, m_pSet->m_MaxSpeedUnit); 

    CString str; 
    str.Format("0x%x", m_pSet->m_DisplayMask); 
    SetDlgItemText(IDC_EDIT_DISPLAY_MASK, str); 
    SetDlgItemText(IDC_EDIT_TOP_TRANSFORMER, m_pSet->m_TopTransformer); 
    SetDlgItemText(IDC_EDIT_BOTTOM_TRANSFORMER, m_pSet->m_BottomTransformer); 
}

BOOL CELISView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CRecordView::PreCreateWindow(cs);
}

void CELISView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_eLISSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CELISView diagnostics

#ifdef _DEBUG
void CELISView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CELISView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CELISDoc* CELISView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CELISDoc)));
	return (CELISDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CELISView database support
CRecordset* CELISView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CELISView message handlers

void CELISView::Go(CString strFilter)
{
    //GetDlgItemText(IDC_EDIT_NAME_LIKE, m_pSet->m_strNameLike); 
    m_pSet->m_strNameLike = strFilter; 
    m_pSet->Requery(); 
}