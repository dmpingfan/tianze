// XListBox.cpp : implementation file
//

#include "stdafx.h"
#include "TreeTest.h"
#include "XListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// XListBox

XListBox::XListBox()
{
}

XListBox::~XListBox()
{
}


BEGIN_MESSAGE_MAP(XListBox, CListBox)
	//{{AFX_MSG_MAP(XListBox)
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// XListBox message handlers

HBRUSH XListBox::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	// TODO: Change any attributes of the DC here
	
    pDC->SetBkColor(RGB(0, 0, 0)); 
    pDC->SetTextColor(RGB(0, 255, 0)); 
    
	// TODO: Return a non-NULL brush if the parent's handler should not be called
    return ::CreateSolidBrush(RGB(0, 0, 0));
}
