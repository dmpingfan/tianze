// NoneDoc.cpp : implementation of the CNoneDoc class
//

#include "stdafx.h"
#include "None.h"

#include "NoneDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNoneDoc

IMPLEMENT_DYNCREATE(CNoneDoc, CDocument)

BEGIN_MESSAGE_MAP(CNoneDoc, CDocument)
	//{{AFX_MSG_MAP(CNoneDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoneDoc construction/destruction

CNoneDoc::CNoneDoc()
{
	// TODO: add one-time construction code here

}

CNoneDoc::~CNoneDoc()
{
}

BOOL CNoneDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CNoneDoc serialization

void CNoneDoc::Serialize(CArchive& ar)
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
// CNoneDoc diagnostics

#ifdef _DEBUG
void CNoneDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNoneDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNoneDoc commands
