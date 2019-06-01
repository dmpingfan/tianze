// SingleDocTemplateEx.cpp: implementation of the CSingleDocTemplateEx class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Pic.h"
#include "SingleDocTemplateEx.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSingleDocTemplateEx::CSingleDocTemplateEx(UINT nIDResource, CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass)
        : CSingleDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
{

}

CSingleDocTemplateEx::~CSingleDocTemplateEx()
{

}

CDocTemplate::Confidence CSingleDocTemplateEx::MatchDocType(LPCTSTR lpszPathName, CDocument* &rpDocMatch)
{
    Confidence match = CSingleDocTemplate::MatchDocType(lpszPathName, rpDocMatch); 
    if(match == yesAlreadyOpen)
    {
        AfxMessageBox("File already open, you are foolish!"); 
    }

    return match; 
}
