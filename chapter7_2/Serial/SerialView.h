// SerialView.h : interface of the CSerialView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERIALVIEW_H__6531FCA1_A873_4372_A39B_6A53BD948C4E__INCLUDED_)
#define AFX_SERIALVIEW_H__6531FCA1_A873_4372_A39B_6A53BD948C4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSerialView : public CView
{
protected: // create from serialization only
	CSerialView();
	DECLARE_DYNCREATE(CSerialView)

// Attributes
public:
	CSerialDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerialView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSerialView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSerialView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SerialView.cpp
inline CSerialDoc* CSerialView::GetDocument()
   { return (CSerialDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIALVIEW_H__6531FCA1_A873_4372_A39B_6A53BD948C4E__INCLUDED_)
