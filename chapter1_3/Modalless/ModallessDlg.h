// ModallessDlg.h : header file
//

#if !defined(AFX_MODALLESSDLG_H__DB3B116A_7EC4_45FA_ABC5_9C4F625EA39E__INCLUDED_)
#define AFX_MODALLESSDLG_H__DB3B116A_7EC4_45FA_ABC5_9C4F625EA39E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CModallessDlg dialog

class CModallessDlg : public CDialog
{
// Construction
public:
	CModallessDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CModallessDlg)
	enum { IDD = IDD_MODALLESS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModallessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CModallessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODALLESSDLG_H__DB3B116A_7EC4_45FA_ABC5_9C4F625EA39E__INCLUDED_)
