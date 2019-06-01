// TipDayDoc.cpp : implementation of the CTipDayDoc class
//

#include "stdafx.h"
#include "TipDay.h"

#include "TipDayDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTipDayDoc

IMPLEMENT_DYNCREATE(CTipDayDoc, CDocument)

BEGIN_MESSAGE_MAP(CTipDayDoc, CDocument)
	//{{AFX_MSG_MAP(CTipDayDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTipDayDoc construction/destruction

CTipDayDoc::CTipDayDoc()
{
}

CTipDayDoc::~CTipDayDoc()
{
}

BOOL CTipDayDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTipDayDoc serialization

void CTipDayDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTipDayDoc diagnostics

#ifdef _DEBUG
void CTipDayDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTipDayDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTipDayDoc commands
