// CustomMenuDlg.h : header file
//

#if !defined(AFX_CUSTOMMENUDLG_H__7F302428_1F11_48CE_AC66_2139EF9EBFEE__INCLUDED_)
#define AFX_CUSTOMMENUDLG_H__7F302428_1F11_48CE_AC66_2139EF9EBFEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Menu.h"

/////////////////////////////////////////////////////////////////////////////
// CCustomMenuDlg dialog

class CCustomMenuDlg : public CDialog
{
// Construction
public:
	CCustomMenuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCustomMenuDlg)
	enum { IDD = IDD_CUSTOMMENU_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomMenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CCustomMenu m_menu;
	MENUDATA m_data; 

	// Generated message map functions
	//{{AFX_MSG(CCustomMenuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMMENUDLG_H__7F302428_1F11_48CE_AC66_2139EF9EBFEE__INCLUDED_)
