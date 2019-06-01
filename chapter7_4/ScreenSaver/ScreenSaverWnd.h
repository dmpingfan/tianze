#if !defined(AFX_SCREENSAVERWND_H__60817612_6F4F_4A01_BBC3_96352975AD9E__INCLUDED_)
#define AFX_SCREENSAVERWND_H__60817612_6F4F_4A01_BBC3_96352975AD9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScreenSaverWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScreenSaverWnd window

class CScreenSaverWnd : public CWnd
{
// Construction
public:
	CScreenSaverWnd();

// Attributes
public:
    //BOOL IsAutoBlack() const; 
    //void SetAutoBlack(BOOL bAutoBlack = TRUE); 
    //CPalette* GetPalette() const; 
    //void SetPalette(CPalette* pPalette); 

// Operations
public:

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScreenSaverWnd)
	//}}AFX_VIRTUAL
    virtual void OnDraw(CDC* pDC); 
    virtual void OnInitialUpdate(); 
    //virtual void SaveOptions(); 
    //virtual void RestoreOptions(); 
protected:
    virtual LRESULT WindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam); 
    virtual LRESULT DefWindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam); 

// Implementation
public:
	virtual ~CScreenSaverWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CScreenSaverWnd)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
    afx_msg BOOL OnEraseBkgnd(CDC* pDC); 
    afx_msg void OnPaint(); 
    afx_msg BOOL OnQueryNewPalette(); 
    afx_msg void OnPaletteChanged(CWnd* pFocusWnd); 

	DECLARE_MESSAGE_MAP()
};

LRESULT WINAPI ScreenSaverProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCREENSAVERWND_H__60817612_6F4F_4A01_BBC3_96352975AD9E__INCLUDED_)
