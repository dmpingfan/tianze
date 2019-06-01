// SnapDoc.cpp : implementation of the CSnapDoc class
//

#include "stdafx.h"
#include "Snap.h"

#include "SnapDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnapDoc

IMPLEMENT_DYNCREATE(CSnapDoc, CDocument)

BEGIN_MESSAGE_MAP(CSnapDoc, CDocument)
	//{{AFX_MSG_MAP(CSnapDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnapDoc construction/destruction

CSnapDoc::CSnapDoc()
{
}

CSnapDoc::~CSnapDoc()
{
}

BOOL CSnapDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSnapDoc serialization

void CSnapDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSnapDoc diagnostics

#ifdef _DEBUG
void CSnapDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSnapDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSnapDoc commands
