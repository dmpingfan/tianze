// ELISDoc.cpp : implementation of the CELISDoc class
//

#include "stdafx.h"
#include "ELIS.h"

#include "ELISSet.h"
#include "ELISDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CELISDoc

IMPLEMENT_DYNCREATE(CELISDoc, CDocument)

BEGIN_MESSAGE_MAP(CELISDoc, CDocument)
	//{{AFX_MSG_MAP(CELISDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CELISDoc construction/destruction

CELISDoc::CELISDoc()
{
}

CELISDoc::~CELISDoc()
{
}

BOOL CELISDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CELISDoc diagnostics

#ifdef _DEBUG
void CELISDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CELISDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CELISDoc commands
