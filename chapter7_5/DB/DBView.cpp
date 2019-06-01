// DBView.cpp : implementation of the CDBView class
//

#include "stdafx.h"
#include "DB.h"

#include "DBSet.h"
#include "DBDoc.h"
#include "DBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBView

IMPLEMENT_DYNCREATE(CDBView, CRecordView)

BEGIN_MESSAGE_MAP(CDBView, CRecordView)
	//{{AFX_MSG_MAP(CDBView)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, OnButtonQuery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDBView construction/destruction

CDBView::CDBView()
	: CRecordView(CDBView::IDD)
{
	//{{AFX_DATA_INIT(CDBView)
		// NOTE: the ClassWizard will add member initialization here
	m_pSet = NULL;
	//}}AFX_DATA_INIT

    m_pList = NULL; 
    m_pBox = NULL; 
}

CDBView::~CDBView()
{
}

void CDBView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDBView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CDBView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CRecordView::PreCreateWindow(cs);
}

void CDBView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_dBSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

    //m_pSet->Open(AFX_DB_USE_DEFAULT_TYPE, "select * from [ToolInformation]"); 
    m_pBox = (CListBox*)GetDlgItem(IDC_LIST_COLUMN); 
    m_pBox->ResetContent(); 
    int nCount = m_pSet->GetODBCFieldCount(); 
    for(int i=0; i<nCount; i++)
    {
        CODBCFieldInfo fi; 
        m_pSet->GetODBCFieldInfo(i, fi); 
        m_pBox->AddString(fi.m_strName); 
    }
}

/////////////////////////////////////////////////////////////////////////////
// CDBView diagnostics

#ifdef _DEBUG
void CDBView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDBView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDBDoc* CDBView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBDoc)));
	return (CDBDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDBView database support
CRecordset* CDBView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CDBView message handlers

void CDBView::OnButtonQuery() 
{
	// TODO: Add your control notification handler code here
    m_pBox = (CListBox*)GetDlgItem(IDC_LIST_COLUMN); 
	int nCount = m_pBox->GetSelCount(); 
    if(nCount == 0)
        return; 

    m_pList = (CListCtrl*)GetDlgItem(IDC_LIST_RECORD); 
    m_pList->DeleteAllItems(); 
    while(m_pList->DeleteColumn(0))
        ; 

    int* pItems = new int[nCount]; 
    m_pBox->GetSelItems(nCount, pItems); 
    for(int i=0; i<nCount; i++)
    {
        CString str; 
        m_pBox->GetText(pItems[i], str); 
        m_pList->InsertColumn(i, str, LVCFMT_CENTER, m_pList->GetStringWidth(str) + 20); 
    }

    m_pSet->Requery(); 
    m_pSet->MoveFirst(); 
    for(i=0; i<m_pSet->GetRecordCount(); i++)
    {
        for(int j=0; j<nCount; j++)
        {
            int nIndex = pItems[j]; 
            if(j==0)
                m_pList->InsertItem(i, m_pSet->m_arrValues[nIndex]); 
            else 
                m_pList->SetItem(i, j, LVIF_TEXT, m_pSet->m_arrValues[nIndex], 0, 0, 0, 0); 
        }
        m_pSet->MoveNext(); 
    }

    delete[] pItems; 
}
