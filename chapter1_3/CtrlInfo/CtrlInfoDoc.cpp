// CtrlInfoDoc.cpp : implementation of the CCtrlInfoDoc class
//

#include "stdafx.h"
#include "CtrlInfo.h"

#include "CtrlInfoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCtrlInfoDoc

IMPLEMENT_DYNCREATE(CCtrlInfoDoc, CDocument)

BEGIN_MESSAGE_MAP(CCtrlInfoDoc, CDocument)
	//{{AFX_MSG_MAP(CCtrlInfoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCtrlInfoDoc construction/destruction

CCtrlInfoDoc::CCtrlInfoDoc()
{
	// TODO: add one-time construction code here

}

CCtrlInfoDoc::~CCtrlInfoDoc()
{
}

BOOL CCtrlInfoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCtrlInfoDoc serialization

void CCtrlInfoDoc::Serialize(CArchive& ar)
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
// CCtrlInfoDoc diagnostics

#ifdef _DEBUG
void CCtrlInfoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCtrlInfoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCtrlInfoDoc commands
