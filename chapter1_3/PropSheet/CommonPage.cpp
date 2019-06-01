// CommonPage.cpp : implementation file
//

#include "stdafx.h"
#include "PropSheet.h"
#include "CommonPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCommonPage property page

IMPLEMENT_DYNCREATE(CCommonPage, CPropertyPage)

CCommonPage::CCommonPage() : CPropertyPage(CCommonPage::IDD)
{
	//{{AFX_DATA_INIT(CCommonPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CCommonPage::~CCommonPage()
{
}

void CCommonPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommonPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCommonPage, CPropertyPage)
	//{{AFX_MSG_MAP(CCommonPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommonPage message handlers
