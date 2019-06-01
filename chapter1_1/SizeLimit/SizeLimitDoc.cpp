// SizeLimitDoc.cpp : implementation of the CSizeLimitDoc class
//

#include "stdafx.h"
#include "SizeLimit.h"

#include "SizeLimitDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSizeLimitDoc

IMPLEMENT_DYNCREATE(CSizeLimitDoc, CDocument)

BEGIN_MESSAGE_MAP(CSizeLimitDoc, CDocument)
	//{{AFX_MSG_MAP(CSizeLimitDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSizeLimitDoc construction/destruction

CSizeLimitDoc::CSizeLimitDoc()
{
	// TODO: add one-time construction code here

}

CSizeLimitDoc::~CSizeLimitDoc()
{
}

BOOL CSizeLimitDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSizeLimitDoc serialization

void CSizeLimitDoc::Serialize(CArchive& ar)
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
// CSizeLimitDoc diagnostics

#ifdef _DEBUG
void CSizeLimitDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSizeLimitDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSizeLimitDoc commands
