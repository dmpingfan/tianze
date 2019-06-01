// ScreenSaverDlg.h : header file
//

#if !defined(AFX_SCREENSAVERDLG_H__BA63CDF3_9B4D_4B58_B6F5_6D873EBC9183__INCLUDED_)
#define AFX_SCREENSAVERDLG_H__BA63CDF3_9B4D_4B58_B6F5_6D873EBC9183__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// CScreenSaverDlg dialog

class CScreenSaverDlg : public CDialog
{
// Construction
public:
	CScreenSaverDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CScreenSaverDlg)
	enum { IDD = IDD_SCREENSAVER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

public:
    virtual ~CScreenSaverDlg(); 
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScreenSaverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
protected:
    virtual LRESULT WindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam); 
    virtual LRESULT DefWindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam); 

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScreenSaverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

BOOL WINAPI ScreenSaverConfigureDialog(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam); 
BOOL WINAPI RegisterDialogClasses(HANDLE hInstance); 

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCREENSAVERDLG_H__BA63CDF3_9B4D_4B58_B6F5_6D873EBC9183__INCLUDED_)
