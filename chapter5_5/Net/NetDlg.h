// NetDlg.h : header file
//

#if !defined(AFX_NETDLG_H__C8DC32A3_A8AC_4CB0_9DBF_1003B7AC47ED__INCLUDED_)
#define AFX_NETDLG_H__C8DC32A3_A8AC_4CB0_9DBF_1003B7AC47ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNetDlg dialog

class CNetDlg : public CDialog
{
// Construction
public:
	CNetDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNetDlg)
	enum { IDD = IDD_NET_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
    CString GetBIOS(); 
    CString GetIP(); 

	// Generated message map functions
	//{{AFX_MSG(CNetDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonHangUp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETDLG_H__C8DC32A3_A8AC_4CB0_9DBF_1003B7AC47ED__INCLUDED_)
