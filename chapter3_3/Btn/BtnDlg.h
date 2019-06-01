// BtnDlg.h : header file
//

#if !defined(AFX_BTNDLG_H__A9660E06_2D31_4A66_A3F6_ADEB4BEE3A34__INCLUDED_)
#define AFX_BTNDLG_H__A9660E06_2D31_4A66_A3F6_ADEB4BEE3A34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XButton.h"

/////////////////////////////////////////////////////////////////////////////
// CBtnDlg dialog

class CBtnDlg : public CDialog
{
// Construction
public:
	CBtnDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBtnDlg)
	enum { IDD = IDD_BTN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBtnDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	XButton m_btnOK; 
	XButton m_btnCancel; 

	// Generated message map functions
	//{{AFX_MSG(CBtnDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon(); 
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BTNDLG_H__A9660E06_2D31_4A66_A3F6_ADEB4BEE3A34__INCLUDED_)
