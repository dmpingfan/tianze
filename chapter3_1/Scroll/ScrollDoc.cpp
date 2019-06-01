// ScrollDoc.cpp : implementation of the CScrollDoc class
//

#include "stdafx.h"
#include "Scroll.h"

#include "ScrollDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScrollDoc

IMPLEMENT_DYNCREATE(CScrollDoc, CDocument)

BEGIN_MESSAGE_MAP(CScrollDoc, CDocument)
	//{{AFX_MSG_MAP(CScrollDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScrollDoc construction/destruction

CScrollDoc::CScrollDoc()
{
	// TODO: add one-time construction code here

}

CScrollDoc::~CScrollDoc()
{
}

BOOL CScrollDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CScrollDoc serialization

void CScrollDoc::Serialize(CArchive& ar)
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
// CScrollDoc diagnostics

#ifdef _DEBUG
void CScrollDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CScrollDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CScrollDoc commands

BOOL CScrollDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
    BOOL bOpen = m_file.Open(lpszPathName, CFile::modeRead | CFile::shareDenyNone | CFile::typeText, NULL); 
    //int nLine = 0; 
    //CString str; 
    //while(m_file.ReadString(str))
    //    nLine ++; 

    //CSize sizeTotal(1000, nLine * 20); 
    //POSITION pos = GetFirstViewPosition(); 
    //CView* pView = GetNextView(pos); 
    //while(pView != NULL)
    //{
    //    CScrollView* pScroll = DYNAMIC_DOWNCAST(CScrollView, pView); 
    //    if(pScroll != NULL)
    //        pScroll->SetScrollSizes(MM_TEXT, sizeTotal); 
    //    pView = GetNextView(pos); 
    //}

	return bOpen;
}

void CScrollDoc::OnCloseDocument() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_file.m_pStream != NULL)
        m_file.Close(); 
	CDocument::OnCloseDocument();
}