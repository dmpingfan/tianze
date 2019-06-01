// DlgOleDropTarget.cpp: implementation of the CDlgOleDropTarget class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DropFile.h"
#include "DlgOleDropTarget.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDlgOleDropTarget::CDlgOleDropTarget()
{

}

CDlgOleDropTarget::~CDlgOleDropTarget()
{

}

DROPEFFECT CDlgOleDropTarget::OnDragEnter(CWnd* pWnd, COleDataObject* pDataObject, DWORD dwKeyState, CPoint point) 
{
    TRACE("Drag enter.\n"); 
    return DROPEFFECT_MOVE; 
}

DROPEFFECT CDlgOleDropTarget::OnDragOver(CWnd* pWnd, COleDataObject* pDataObject, DWORD dwKeyState, CPoint point) 
{
    TRACE("Drag over.\n"); 
    return DROPEFFECT_LINK; //DROPEFFECT_COPY; 
}

BOOL CDlgOleDropTarget::OnDrop(CWnd* pWnd, COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point)
{
    pWnd->SetDlgItemText(IDC_EDIT_FILE_NAME, "OK"); 
    return TRUE; 
}
