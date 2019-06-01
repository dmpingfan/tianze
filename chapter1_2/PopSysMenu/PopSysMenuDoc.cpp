// PopSysMenuDoc.cpp : implementation of the CPopSysMenuDoc class
//

#include "stdafx.h"
#include "PopSysMenu.h"

#include "PopSysMenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPopSysMenuDoc

IMPLEMENT_DYNCREATE(CPopSysMenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CPopSysMenuDoc, CDocument)
	//{{AFX_MSG_MAP(CPopSysMenuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopSysMenuDoc construction/destruction

CPopSysMenuDoc::CPopSysMenuDoc()
{
	// TODO: add one-time construction code here

}

CPopSysMenuDoc::~CPopSysMenuDoc()
{
}

BOOL CPopSysMenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPopSysMenuDoc serialization

void CPopSysMenuDoc::Serialize(CArchive& ar)
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
// CPopSysMenuDoc diagnostics

#ifdef _DEBUG
void CPopSysMenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPopSysMenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPopSysMenuDoc commands
