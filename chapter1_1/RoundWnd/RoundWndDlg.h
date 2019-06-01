// RoundWndDlg.h : header file
//

#if !defined(AFX_ROUNDWNDDLG_H__7B585D24_7B66_43DD_8DFE_83A183F2960B__INCLUDED_)
#define AFX_ROUNDWNDDLG_H__7B585D24_7B66_43DD_8DFE_83A183F2960B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRoundWndDlg dialog

class CRoundWndDlg : public CDialog
{
// Construction
public:
	CRoundWndDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRoundWndDlg)
	enum { IDD = IDD_ROUNDWND_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoundWndDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
    CRgn m_rgn; 

	// Generated message map functions
	//{{AFX_MSG(CRoundWndDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg UINT OnNcHitTest(CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROUNDWNDDLG_H__7B585D24_7B66_43DD_8DFE_83A183F2960B__INCLUDED_)
