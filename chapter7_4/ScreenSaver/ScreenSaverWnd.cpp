// ScreenSaverWnd.cpp : implementation file
//

#include "stdafx.h"
//#include "ScreenSaver.h"
#include "ScreenSaverWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScreenSaverWnd

CScreenSaverWnd::CScreenSaverWnd()
{
}

CScreenSaverWnd::~CScreenSaverWnd()
{
}


BEGIN_MESSAGE_MAP(CScreenSaverWnd, CWnd)
	//{{AFX_MSG_MAP(CScreenSaverWnd)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CScreenSaverWnd message handlers

void CScreenSaverWnd::OnDraw(CDC* pDC)
{
}

void CScreenSaverWnd::OnInitialUpdate()
{
}

LRESULT CScreenSaverWnd::DefWindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return 0; 
}

LRESULT CScreenSaverWnd::WindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return 0; 
}