// DragDoc.cpp : implementation of the CDragDoc class
//

#include "stdafx.h"
#include "Drag.h"

#include "DragDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDragDoc

IMPLEMENT_DYNCREATE(CDragDoc, CDocument)

BEGIN_MESSAGE_MAP(CDragDoc, CDocument)
	//{{AFX_MSG_MAP(CDragDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDragDoc construction/destruction

CDragDoc::CDragDoc()
{
}

CDragDoc::~CDragDoc()
{
}

BOOL CDragDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDragDoc serialization

void CDragDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDragDoc diagnostics

#ifdef _DEBUG
void CDragDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDragDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDragDoc commands
