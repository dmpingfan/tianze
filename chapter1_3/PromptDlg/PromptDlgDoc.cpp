// PromptDlgDoc.cpp : implementation of the CPromptDlgDoc class
//

#include "stdafx.h"
#include "PromptDlg.h"

#include "PromptDlgDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPromptDlgDoc

IMPLEMENT_DYNCREATE(CPromptDlgDoc, CDocument)

BEGIN_MESSAGE_MAP(CPromptDlgDoc, CDocument)
	//{{AFX_MSG_MAP(CPromptDlgDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPromptDlgDoc construction/destruction

CPromptDlgDoc::CPromptDlgDoc()
{
	// TODO: add one-time construction code here

}

CPromptDlgDoc::~CPromptDlgDoc()
{
}

BOOL CPromptDlgDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPromptDlgDoc serialization

void CPromptDlgDoc::Serialize(CArchive& ar)
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
// CPromptDlgDoc diagnostics

#ifdef _DEBUG
void CPromptDlgDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPromptDlgDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPromptDlgDoc commands
