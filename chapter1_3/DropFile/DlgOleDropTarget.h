// DlgOleDropTarget.h: interface for the CDlgOleDropTarget class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLGOLEDROPTARGET_H__F8AB9680_40C3_4898_A546_64E82156E5FC__INCLUDED_)
#define AFX_DLGOLEDROPTARGET_H__F8AB9680_40C3_4898_A546_64E82156E5FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDlgOleDropTarget : public COleDropTarget  
{
public:
	CDlgOleDropTarget();
	virtual ~CDlgOleDropTarget();

protected:
    virtual DROPEFFECT OnDragEnter(CWnd* pWnd, COleDataObject* pDataObject, DWORD dwKeyState, CPoint point); 
    virtual DROPEFFECT OnDragOver(CWnd* pWnd, COleDataObject* pDataObject, DWORD dwKeyState, CPoint point); 
    virtual BOOL OnDrop(CWnd* pWnd, COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point); 
};

#endif // !defined(AFX_DLGOLEDROPTARGET_H__F8AB9680_40C3_4898_A546_64E82156E5FC__INCLUDED_)
