// RubberDoc.cpp : implementation of the CRubberDoc class
//

#include "stdafx.h"
#include "Rubber.h"

#include "RubberDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRubberDoc

IMPLEMENT_DYNCREATE(CRubberDoc, CDocument)

BEGIN_MESSAGE_MAP(CRubberDoc, CDocument)
	//{{AFX_MSG_MAP(CRubberDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRubberDoc construction/destruction

CRubberDoc::CRubberDoc()
{
	// TODO: add one-time construction code here

}

CRubberDoc::~CRubberDoc()
{
}

BOOL CRubberDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRubberDoc serialization

void CRubberDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRubberDoc diagnostics

#ifdef _DEBUG
void CRubberDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRubberDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRubberDoc commands
