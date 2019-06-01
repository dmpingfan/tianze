// RawDoc.cpp : implementation of the CRawDoc class
//

#include "stdafx.h"
#include "Raw.h"

#include "RawDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRawDoc

IMPLEMENT_DYNCREATE(CRawDoc, CDocument)

BEGIN_MESSAGE_MAP(CRawDoc, CDocument)
	//{{AFX_MSG_MAP(CRawDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRawDoc construction/destruction

CRawDoc::CRawDoc()
{
	// TODO: add one-time construction code here

}

CRawDoc::~CRawDoc()
{
}

BOOL CRawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRawDoc serialization

void CRawDoc::Serialize(CArchive& ar)
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
// CRawDoc diagnostics

#ifdef _DEBUG
void CRawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRawDoc commands
