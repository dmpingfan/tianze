// PrintDoc.cpp : implementation of the CPrintDoc class
//

#include "stdafx.h"
#include "Print.h"

#include "PrintDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrintDoc

IMPLEMENT_DYNCREATE(CPrintDoc, CDocument)

BEGIN_MESSAGE_MAP(CPrintDoc, CDocument)
	//{{AFX_MSG_MAP(CPrintDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintDoc construction/destruction

CPrintDoc::CPrintDoc()
{
}

CPrintDoc::~CPrintDoc()
{
}

BOOL CPrintDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPrintDoc serialization

void CPrintDoc::Serialize(CArchive& ar)
{
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CPrintDoc diagnostics

#ifdef _DEBUG
void CPrintDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPrintDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPrintDoc commands
