// XToolBar.cpp: implementation of the XToolBar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ToolbarTest.h"
#include "XToolBar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(XToolBar, CToolBar)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

XToolBar::XToolBar()
{

}

XToolBar::~XToolBar()
{

}

void XToolBar::OnSize(UINT nType, int cx, int cy)
{
    if(m_wndCombo.GetSafeHwnd() && m_wndCheck.GetSafeHwnd() && m_wndRadio.GetSafeHwnd())
    {
        int index = 0; 
        while(GetItemID(index) != ID_COMBO_BOX)
            index++; 
    
        CRect rect; 
        GetItemRect(index, &rect); 
        rect.bottom += 200; 
        m_wndCombo.SetWindowPos(NULL, rect.left, rect.top, rect.Width(), rect.Height(), SWP_NOZORDER | SWP_NOACTIVATE); 
    
        index = 0; 
        while(GetItemID(index) != ID_CHECK_BOX)
            index ++; 
    
        GetItemRect(index, &rect);  
        m_wndCheck.SetWindowPos(NULL, rect.left, rect.top, rect.Width(), rect.Height(), SWP_NOZORDER | SWP_NOACTIVATE); 
    
        index = 0; 
        while(GetItemID(index) != ID_RADIO_BOX)
            index ++; 
    
        GetItemRect(index, &rect); 
        m_wndRadio.SetWindowPos(NULL, rect.left, rect.top, rect.Width(), rect.Height(), SWP_NOZORDER | SWP_NOACTIVATE); 
    }
}
