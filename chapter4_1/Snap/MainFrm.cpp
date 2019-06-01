// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Snap.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_EDIT_SNAP, OnEditSnap)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_CANCELMODE()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
    m_bSnap = FALSE; 
    m_bTrack = FALSE; 
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnEditSnap() 
{
	// TODO: Add your command handler code here
    m_bSnap = TRUE;  
	SetCapture();     
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bSnap)
    {
        m_bSnap = FALSE; 
        m_bTrack = TRUE; 
        m_ptStart = point; 
        ClientToScreen(&m_ptStart); 
    }
    else 
        CFrameWnd::OnLButtonDown(nFlags, point);
}

void CMainFrame::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bTrack)
    {
        m_bTrack = FALSE; 
        ReleaseCapture(); 

        ClientToScreen(&point); 
        m_rect.SetRect(m_ptStart, point); 
        m_rect.NormalizeRect(); 
        if(m_rect.IsRectEmpty())
        {
            m_rect.right = m_rect.left + 100; 
            m_rect.bottom = m_rect.top + 100; 
        }

        HBITMAP hbm = CopyScreenToBitmap(&m_rect); 
        if(hbm != NULL && OpenClipboard())
        {
            EmptyClipboard(); 
            SetClipboardData(CF_BITMAP, hbm); 
            CloseClipboard(); 
        }

        if(hbm != NULL)
        {
            HDC hDC = CreateDC("DISPLAY", NULL, NULL, NULL); 
            int iBits = GetDeviceCaps(hDC, BITSPIXEL) * GetDeviceCaps(hDC, PLANES); 
            DeleteDC(hDC); 

            WORD wBitCount = 8; 
            if(iBits <= 1)
                wBitCount = 1; 
            else if(iBits <= 4)
                wBitCount = 4; 
            else if(iBits <= 8)
                wBitCount = 8; 
            else if(iBits <= 24)
                wBitCount = 24; 

            DWORD dwPaletteSize = 0; 
            if(wBitCount <= 8)
                dwPaletteSize = (1 << wBitCount) * sizeof(RGBQUAD); 

            BITMAP bm; 
            GetObject(hbm, sizeof(BITMAP), (LPSTR)&bm); 

            BITMAPINFOHEADER bi; 
            bi.biSize = sizeof(BITMAPINFOHEADER); 
            bi.biWidth = bm.bmWidth; 
            bi.biHeight = bm.bmHeight; 
            bi.biPlanes = 1; 
            bi.biBitCount = wBitCount; 
            bi.biCompression = BI_RGB; 
            bi.biSizeImage = 0; 
            bi.biXPelsPerMeter = 0; 
            bi.biYPelsPerMeter = 0; 
            bi.biClrUsed = 0; 
            bi.biClrImportant = 0; 

            DWORD dwBmBitsSize = (bm.bmWidth * wBitCount + 31) / 32 * 4 * bm.bmHeight; 
            HANDLE hDib = GlobalAlloc(GHND, dwBmBitsSize + dwPaletteSize + sizeof(BITMAPINFOHEADER)); 
            LPBITMAPINFOHEADER lpbi = (LPBITMAPINFOHEADER)GlobalLock(hDib); 
            *lpbi = bi; 

            HPALETTE hOldPal = NULL; 
            HPALETTE hPal = (HPALETTE)GetStockObject(DEFAULT_PALETTE); 
            if(hPal)
            {
                hDC = ::GetDC(NULL); 
                hOldPal = SelectPalette(hDC, hPal, FALSE); 
                RealizePalette(hDC); 
            }

            ::GetDIBits(hDC, hbm, 0, (UINT)bm.bmHeight, (LPSTR)lpbi + sizeof(BITMAPINFOHEADER) + dwPaletteSize, (BITMAPINFO*)lpbi, DIB_RGB_COLORS); 

            if(hOldPal)
            {
                SelectPalette(hDC, hOldPal, TRUE); 
                RealizePalette(hDC); 
                ::ReleaseDC(NULL, hDC); 
            }

            HANDLE fh = CreateFile("test.bmp", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL); 
            if(fh == INVALID_HANDLE_VALUE)
            {
                GlobalUnlock(hDib); 
                GlobalFree(hDib); 
                return; 
            }

            BITMAPFILEHEADER bmfh; 
            bmfh.bfType = 0x4D42; 
            DWORD dwDIBSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + dwPaletteSize + dwBmBitsSize; 
            bmfh.bfSize = dwDIBSize; 
            bmfh.bfReserved1 = 0; 
            bmfh.bfReserved2 = 0; 
            bmfh.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) + (DWORD)sizeof(BITMAPINFOHEADER) + dwPaletteSize; 

            DWORD dwWritten; 
            WriteFile(fh, (LPSTR)&bmfh, sizeof(BITMAPFILEHEADER), &dwWritten, NULL); 
            WriteFile(fh, (LPSTR)lpbi, dwDIBSize, &dwWritten, NULL); 

            GlobalUnlock(hDib); 
            GlobalFree(hDib); 
            CloseHandle(fh); 
        }
    }
    else
        CFrameWnd::OnLButtonUp(nFlags, point);
}

void CMainFrame::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
    if(m_bTrack)
    {
        CWnd* pWnd = GetDesktopWindow(); 
        pWnd->UpdateWindow(); 

        CWindowDC dc(pWnd);   
        CBrush* pOldBrush = (CBrush*)dc.SelectStockObject(NULL_BRUSH); 
        dc.Rectangle(m_rect);         
        dc.SelectObject(pOldBrush); 
        
        ClientToScreen(&point); 
        m_rect.right = point.x; 
        m_rect.bottom = point.y; 
    }
    else 
        CFrameWnd::OnMouseMove(nFlags, point);
}


void CMainFrame::OnCancelMode() 
{
	CFrameWnd::OnCancelMode();
	
	// TODO: Add your message handler code here
    m_bTrack = FALSE; 
    m_bSnap = FALSE; 
    ReleaseCapture(); 
}

HBITMAP CMainFrame::CopyScreenToBitmap(LPRECT lpRect)
{
    CDC dc; 
    dc.CreateDC("DISPLAY", NULL, NULL, NULL); 
    CDC dcMem; 
    dcMem.CreateCompatibleDC(&dc); 

    int xScrn = GetDeviceCaps(dc.GetSafeHdc(), HORZRES); 
    int yScrn = GetDeviceCaps(dc.GetSafeHdc(), VERTRES); 
    CRect rect(lpRect); 
    if(rect.left < 0)
        rect.left = 0; 
    if(rect.right > xScrn)
        rect.right = xScrn; 
    if(rect.top < 0)
        rect.top = 0; 
    if(rect.bottom > yScrn)
        rect.bottom = yScrn; 
    if(rect.IsRectEmpty())
        return NULL; 

    CBitmap bm; 
    bm.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height()); 
    CBitmap* bmOld = dcMem.SelectObject(&bm); 
    dcMem.BitBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY); 
    dcMem.SelectObject(bmOld); 
    return (HBITMAP)bm.Detach(); 
}