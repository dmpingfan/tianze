// PrintView.h : interface of the CPrintView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRINTVIEW_H__02EF1A05_3BA1_4AA7_9E5C_0B9BE37195F0__INCLUDED_)
#define AFX_PRINTVIEW_H__02EF1A05_3BA1_4AA7_9E5C_0B9BE37195F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPrintView : public CEditView
{
protected: // create from serialization only
	CPrintView();
	DECLARE_DYNCREATE(CPrintView)

// Attributes
public:
	CPrintDoc* GetDocument();
    UINT m_nLineHeight; 
    UINT m_nCharWidth; 
    UINT m_nMaxLineChar; 
    UINT m_nLinesPerPage; 
    UINT m_nLines; 
    UINT m_nSize; 
    TCHAR* m_pBuf;

// Operations
public:
    void RedealTextData(); 
    UINT GetOffset(UINT nLine); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPrintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPrintView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PrintView.cpp
inline CPrintDoc* CPrintView::GetDocument()
   { return (CPrintDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTVIEW_H__02EF1A05_3BA1_4AA7_9E5C_0B9BE37195F0__INCLUDED_)
