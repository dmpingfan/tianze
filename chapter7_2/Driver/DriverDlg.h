// DriverDlg.h : header file
//

#if !defined(AFX_DRIVERDLG_H__EB42603F_27CD_4EA7_BCF4_027AE291659A__INCLUDED_)
#define AFX_DRIVERDLG_H__EB42603F_27CD_4EA7_BCF4_027AE291659A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDriverDlg dialog

class CDriverDlg : public CDialog
{
// Construction
public:
	CDriverDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDriverDlg)
	enum { IDD = IDD_DRIVER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDriverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDriverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeComboDriver();
	afx_msg void OnButtonSetLabel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRIVERDLG_H__EB42603F_27CD_4EA7_BCF4_027AE291659A__INCLUDED_)
