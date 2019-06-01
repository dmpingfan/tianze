// ButtonTestDlg.h : header file
//

#if !defined(AFX_BUTTONTESTDLG_H__7B97F8D2_2B88_404B_B823_65394E285B59__INCLUDED_)
#define AFX_BUTTONTESTDLG_H__7B97F8D2_2B88_404B_B823_65394E285B59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XButton.h"

/////////////////////////////////////////////////////////////////////////////
// CButtonTestDlg dialog

class CButtonTestDlg : public CDialog
{
// Construction
public:
	CButtonTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CButtonTestDlg)
	enum { IDD = IDD_BUTTONTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
    XButton m_btnTest; 
    XButton m_btnTestDisabled; 

	// Generated message map functions
	//{{AFX_MSG(CButtonTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTONTESTDLG_H__7B97F8D2_2B88_404B_B823_65394E285B59__INCLUDED_)
