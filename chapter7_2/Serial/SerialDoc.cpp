// SerialDoc.cpp : implementation of the CSerialDoc class
//

#include "stdafx.h"
#include "Serial.h"

#include "SerialDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSerialDoc

IMPLEMENT_DYNCREATE(CSerialDoc, CDocument)

BEGIN_MESSAGE_MAP(CSerialDoc, CDocument)
	//{{AFX_MSG_MAP(CSerialDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSerialDoc construction/destruction

CSerialDoc::CSerialDoc()
{
}

CSerialDoc::~CSerialDoc()
{
}

BOOL CSerialDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSerialDoc serialization

void CSerialDoc::Serialize(CArchive& ar)
{
    m_obj.Serialize(ar); 
}

/////////////////////////////////////////////////////////////////////////////
// CSerialDoc diagnostics

#ifdef _DEBUG
void CSerialDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSerialDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSerialDoc commands
