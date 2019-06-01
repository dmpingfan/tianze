// BaldDoc.cpp : implementation of the CBaldDoc class
//

#include "stdafx.h"
#include "Bald.h"

#include "BaldDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaldDoc

IMPLEMENT_DYNCREATE(CBaldDoc, CDocument)

BEGIN_MESSAGE_MAP(CBaldDoc, CDocument)
	//{{AFX_MSG_MAP(CBaldDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaldDoc construction/destruction

CBaldDoc::CBaldDoc()
{
	// TODO: add one-time construction code here

}

CBaldDoc::~CBaldDoc()
{
}

BOOL CBaldDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBaldDoc serialization

void CBaldDoc::Serialize(CArchive& ar)
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
// CBaldDoc diagnostics

#ifdef _DEBUG
void CBaldDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBaldDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaldDoc commands
