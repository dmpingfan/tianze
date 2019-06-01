// DesktopDlg.h : header file
//

#if !defined(AFX_DESKTOPDLG_H__F6A0296A_4446_4849_883C_0F18607027D7__INCLUDED_)
#define AFX_DESKTOPDLG_H__F6A0296A_4446_4849_883C_0F18607027D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDesktopDlg dialog

class CDesktopDlg : public CDialog
{
// Construction
public:
	CDesktopDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDesktopDlg)
	enum { IDD = IDD_DESKTOP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDesktopDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	BOOL m_bCancelEvent; 
	void AddWindow(CTreeCtrl* pTree, HTREEITEM hRoot, HWND hWndParent); 

	// Generated message map functions
	//{{AFX_MSG(CDesktopDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonRefresh();
	afx_msg void OnButtonClose();
	afx_msg void OnCheckHide();
	afx_msg void OnCheckEnable();
	afx_msg void OnBtnActive();
	afx_msg void OnSelchangedTreeWnd(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESKTOPDLG_H__F6A0296A_4446_4849_883C_0F18607027D7__INCLUDED_)
