// CmnCtrlDlg.h : header file
//

#if !defined(AFX_CMNCTRLDLG_H__C814FD68_789A_4493_A294_480A23255CA7__INCLUDED_)
#define AFX_CMNCTRLDLG_H__C814FD68_789A_4493_A294_480A23255CA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XCheckTree.h"

/////////////////////////////////////////////////////////////////////////////
// CCmnCtrlDlg dialog

class CCmnCtrlDlg : public CDialog
{
// Construction
public:
	CCmnCtrlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCmnCtrlDlg)
	enum { IDD = IDD_CMNCTRL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCmnCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
    XCheckTree m_tree; 
    CImageList m_imageState; 

	// Generated message map functions
	//{{AFX_MSG(CCmnCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnItemchangedListTest(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMNCTRLDLG_H__C814FD68_789A_4493_A294_480A23255CA7__INCLUDED_)
