// TopMostDoc.cpp : implementation of the CTopMostDoc class
//

#include "stdafx.h"
#include "TopMost.h"

#include "TopMostDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTopMostDoc

IMPLEMENT_DYNCREATE(CTopMostDoc, CDocument)

BEGIN_MESSAGE_MAP(CTopMostDoc, CDocument)
	//{{AFX_MSG_MAP(CTopMostDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTopMostDoc construction/destruction

CTopMostDoc::CTopMostDoc()
{
	// TODO: add one-time construction code here

}

CTopMostDoc::~CTopMostDoc()
{
}

BOOL CTopMostDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTopMostDoc serialization

void CTopMostDoc::Serialize(CArchive& ar)
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
// CTopMostDoc diagnostics

#ifdef _DEBUG
void CTopMostDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTopMostDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTopMostDoc commands
