// XEdit.cpp : implementation file
//

#include "stdafx.h"
#include "TreeTest.h"
#include "XEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// XEdit

XEdit::XEdit()
{
}

XEdit::~XEdit()
{
}


BEGIN_MESSAGE_MAP(XEdit, CEdit)
	//{{AFX_MSG_MAP(XEdit)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// XEdit message handlers

void XEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
    if(::IsCharAlpha(nChar))
    {
        //nChar = ::CharUpper(nChar); 
        nChar = ::toupper(nChar); 
        DefWindowProc(WM_CHAR, nChar, MAKELPARAM(nRepCnt, nFlags)); 
    }
    else 
        CEdit::OnChar(nChar, nRepCnt, nFlags);
}
