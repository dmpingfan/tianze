// PrintView.cpp : implementation of the CPrintView class
//

#include "stdafx.h"
#include "Print.h"

#include "PrintDoc.h"
#include "PrintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrintView

IMPLEMENT_DYNCREATE(CPrintView, CEditView)

BEGIN_MESSAGE_MAP(CPrintView, CEditView)
	//{{AFX_MSG_MAP(CPrintView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintView construction/destruction

CPrintView::CPrintView()
{
    m_nLineHeight = 0; 
    m_nCharWidth = 0;
    m_nMaxLineChar = 0; 
    m_nLinesPerPage = 0; 
    m_nLines = 0; 
    m_nSize = 0; 
    m_pBuf = NULL; 
}

CPrintView::~CPrintView()
{
}

BOOL CPrintView::PreCreateWindow(CREATESTRUCT& cs)
{
	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CPrintView drawing

void CPrintView::OnDraw(CDC* pDC)
{
	CPrintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CPrintView diagnostics

#ifdef _DEBUG
void CPrintView::AssertValid() const
{
	CEditView::AssertValid();
}

void CPrintView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CPrintDoc* CPrintView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPrintDoc)));
	return (CPrintDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPrintView message handlers

/////////////////////////////////////////////////////////////////////////////
// CPrintView printing

BOOL CPrintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CPrintView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	//CEditView::OnPrepareDC(pDC, pInfo);
    CView::OnPrepareDC(pDC, pInfo); 
}

void CPrintView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	//CEditView::OnEndPrinting(pDC, pInfo);
    CView::OnEndPrinting(pDC, pInfo); 

    delete[] m_pBuf; 
    m_pBuf = NULL; 
    m_nSize = 0; 
}

void CPrintView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	//CEditView::OnBeginPrinting(pDC, pInfo);
    //short cxInch = pDC->GetDeviceCaps(LOGPIXELSX); 
    //short cyInch = pDC->GetDeviceCaps(LOGPIXELSY); 
    //CFont* pFont = pDC->GetCurrentFont(); 
    
    //LOGFONT logFont; 
    //pFont->GetLogFont(&logFont); 
    //LOGFONT logFontNew = logFont; 
    //logFontNew.lfWidth = (long)(logFont.lfWidth / 2.0 * (cxInch / 72.0)); 
    //logFontNew.lfHeight = (long)(logFont.lfHeight / 2.0 * (cyInch / 72.0)); 

    //CFont fontNew; 
    //fontNew.CreateFontIndirect(&logFontNew); 
    //CFont* pOldFont = pDC->SelectObject(&fontNew); 
    
    TEXTMETRIC tm; 
    pDC->GetTextMetrics(&tm); 
    int nPageHeight = pDC->GetDeviceCaps(VERTRES); 
    int nPageWidth = pDC->GetDeviceCaps(HORZRES); 
    m_nLineHeight = tm.tmHeight; 
    m_nCharWidth = tm.tmAveCharWidth; 
    m_nMaxLineChar = nPageWidth / m_nCharWidth - 8; 
    m_nLinesPerPage = nPageHeight / m_nLineHeight; 

    RedealTextData(); 

    int nPrintableLineCount = INT_MAX / m_nLineHeight; 
    if(m_nLines < nPrintableLineCount)
        nPrintableLineCount = m_nLines; 

    UINT nMaxPage = (nPrintableLineCount + m_nLinesPerPage) / m_nLinesPerPage; 
    pInfo->SetMaxPage(nMaxPage); 
    pInfo->m_nCurPage = 1; 

    //pDC->SelectObject(pOldFont); 
}

void CPrintView::RedealTextData()
{
    m_nSize = GetEditCtrl().GetWindowTextLength(); 
    m_pBuf = new TCHAR[m_nSize + 1]; 
    GetEditCtrl().GetWindowText(m_pBuf, m_nSize + 1); 
    
    int i = 0; 
    m_nLines = 0; 
    UINT nLength = 0; 
    while(i++ < m_nSize)
    {
        if(m_pBuf[i] == 0x0d && m_pBuf[i+1] == 0x0a)
        {
            m_nLines ++; 
            nLength = 0; 
        }
        else 
        {
            if(m_pBuf[i] == VK_TAB)
                nLength += 8; 
            else 
                nLength ++; 

            if(nLength > (m_nMaxLineChar - 2) * m_nCharWidth)
            {
                m_pBuf[i] = 0x0d; 
                m_pBuf[++i] = 0x0a; 
            }
        }
    }
}


void CPrintView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	//CEditView::OnPrint(pDC, pInfo);
    
    int nTop = (pInfo->m_nCurPage - 1) * m_nLinesPerPage * m_nLineHeight; 
    int nWidth = pDC->GetDeviceCaps(HORZRES); 
    CRect rcClip(0, nTop, nWidth, nTop + m_nLinesPerPage * m_nLineHeight); 
    pDC->SetViewportOrg(m_nCharWidth * 2, -nTop); 
    
    UINT nStartLine = (pInfo->m_nCurPage - 1) * m_nLinesPerPage; 
    UINT nEndLine = nStartLine + m_nLinesPerPage; 
    if(nEndLine > m_nLines)
        nEndLine = m_nLines; 

    UINT nStartOffset = GetOffset(nStartLine); 
    UINT nEndOffset = GetOffset(nEndLine); 
    pDC->DrawText(m_pBuf + nStartOffset, nEndOffset - nStartOffset, &rcClip, DT_NOCLIP | DT_NOPREFIX | DT_EXPANDTABS); 
}

UINT CPrintView::GetOffset(UINT nLine)
{
    int i=0; 
    UINT line = 0; 
    while(i++ < m_nSize)
    {
        if(m_pBuf[i] == 0x0d && m_pBuf[i+1] == 0x0a)
            line++;
        
        if(line == nLine)
            return i; 
    }

    return m_nSize - 1; 
}