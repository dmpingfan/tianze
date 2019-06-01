// TipDayView.h : interface of the CTipDayView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIPDAYVIEW_H__9E4C8ED2_76BD_4D12_8698_DE52901504C9__INCLUDED_)
#define AFX_TIPDAYVIEW_H__9E4C8ED2_76BD_4D12_8698_DE52901504C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTipDayView : public CView
{
protected: // create from serialization only
	CTipDayView();
	DECLARE_DYNCREATE(CTipDayView)

// Attributes
public:
	CTipDayDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTipDayView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTipDayView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTipDayView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TipDayView.cpp
inline CTipDayDoc* CTipDayView::GetDocument()
   { return (CTipDayDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIPDAYVIEW_H__9E4C8ED2_76BD_4D12_8698_DE52901504C9__INCLUDED_)
