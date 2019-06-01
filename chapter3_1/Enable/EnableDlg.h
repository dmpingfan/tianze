// EnableDlg.h : header file
//

#if !defined(AFX_ENABLEDLG_H__304E3ABB_07EA_4784_B702_D05CF5279E4A__INCLUDED_)
#define AFX_ENABLEDLG_H__304E3ABB_07EA_4784_B702_D05CF5279E4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEnableDlg dialog

class CEnableDlg : public CDialog
{
// Construction
public:
	CEnableDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEnableDlg)
	enum { IDD = IDD_ENABLE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnableDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEnableDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonDisable();
	afx_msg void OnButtonEnable();
	afx_msg void OnEnable(BOOL bEnable);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENABLEDLG_H__304E3ABB_07EA_4784_B702_D05CF5279E4A__INCLUDED_)
