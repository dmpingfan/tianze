// HitMoveDoc.cpp : implementation of the CHitMoveDoc class
//

#include "stdafx.h"
#include "HitMove.h"

#include "HitMoveDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHitMoveDoc

IMPLEMENT_DYNCREATE(CHitMoveDoc, CDocument)

BEGIN_MESSAGE_MAP(CHitMoveDoc, CDocument)
	//{{AFX_MSG_MAP(CHitMoveDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHitMoveDoc construction/destruction

CHitMoveDoc::CHitMoveDoc()
{
	// TODO: add one-time construction code here

}

CHitMoveDoc::~CHitMoveDoc()
{
}

BOOL CHitMoveDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHitMoveDoc serialization

void CHitMoveDoc::Serialize(CArchive& ar)
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
// CHitMoveDoc diagnostics

#ifdef _DEBUG
void CHitMoveDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHitMoveDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHitMoveDoc commands
