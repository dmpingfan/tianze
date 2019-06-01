// PicDoc.cpp : implementation of the CPicDoc class
//

#include "stdafx.h"
#include "Pic.h"

#include "PicDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPicDoc

IMPLEMENT_DYNCREATE(CPicDoc, CDocument)

BEGIN_MESSAGE_MAP(CPicDoc, CDocument)
	//{{AFX_MSG_MAP(CPicDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPicDoc construction/destruction

CPicDoc::CPicDoc()
{
    m_pPic = NULL; 
}

CPicDoc::~CPicDoc()
{
}

BOOL CPicDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

    m_pPic = NULL; 
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPicDoc serialization

void CPicDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPicDoc diagnostics

#ifdef _DEBUG
void CPicDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPicDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPicDoc commands

BOOL CPicDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	CFile file; 
    if(!file.Open(lpszPathName, CFile::modeRead))
    {
        AfxMessageBox("Open file failed."); 
        return FALSE; 
    }

    CFileStatus fstatus; 
    if(!file.GetStatus(lpszPathName, fstatus) || fstatus.m_size == -1)
    {
        AfxMessageBox("Get file status failed."); 
        file.Close(); 
        return FALSE; 
    }

    HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, fstatus.m_size); 
    if(hGlobal == NULL)
    {
        AfxMessageBox("Alloc memory failed."); 
        file.Close(); 
        return FALSE; 
    }

    LPVOID pData = GlobalLock(hGlobal); 
    if(pData == NULL)
    {
        AfxMessageBox("Lock memory failed"); 
        file.Close(); 
        GlobalFree(hGlobal); 
        return FALSE; 
    }

    file.ReadHuge(pData, fstatus.m_size); 
    GlobalUnlock(hGlobal); 
    IStream* pStream; 
    ::CreateStreamOnHGlobal(hGlobal, TRUE, &pStream); 
    if(FAILED(::OleLoadPicture(pStream, fstatus.m_size, TRUE, IID_IPicture, (LPVOID*)&m_pPic)))
    {
        AfxMessageBox("Load picture failed."); 
        GlobalFree(hGlobal); 
        file.Close(); 
        return FALSE; 
    }

    file.Close(); 
	return TRUE;
}

void CPicDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_pPic != NULL)
        m_pPic->Release(); 

	CDocument::DeleteContents();
}

void CPicDoc::SetModifiedFlag(BOOL bModified)
{
    CString strTitle = GetTitle(); 
    if(!IsModified() && bModified)
        SetTitle(strTitle + " *"); 
    else if(IsModified() && !bModified)
        SetTitle(strTitle.Left(strTitle.GetLength() - 2)); 

    UpdateFrameCounts(); 
    CDocument::SetModifiedFlag(bModified); 
}
