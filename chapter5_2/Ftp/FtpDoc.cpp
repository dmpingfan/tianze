// FtpDoc.cpp : implementation of the CFtpDoc class
//

#include "stdafx.h"
#include "Ftp.h"

#include "FtpDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFtpDoc

IMPLEMENT_DYNCREATE(CFtpDoc, CDocument)

BEGIN_MESSAGE_MAP(CFtpDoc, CDocument)
	//{{AFX_MSG_MAP(CFtpDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFtpDoc construction/destruction

CFtpDoc::CFtpDoc()
{
	// TODO: add one-time construction code here

}

CFtpDoc::~CFtpDoc()
{
}

BOOL CFtpDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFtpDoc serialization

void CFtpDoc::Serialize(CArchive& ar)
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
// CFtpDoc diagnostics

#ifdef _DEBUG
void CFtpDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFtpDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFtpDoc commands
