// XButton.cpp : implementation file
//

#include "stdafx.h"
#include "Form.h"
#include "XButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// XButton

XButton::XButton()
{
}

XButton::~XButton()
{
}


BEGIN_MESSAGE_MAP(XButton, CButton)
	//{{AFX_MSG_MAP(XButton)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// XButton message handlers

void XButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    GetParent()->PostMessage(WM_COMMAND, GetDlgCtrlID(), (LPARAM)GetSafeHwnd()); 
	CButton::OnMouseMove(nFlags, point);
}
