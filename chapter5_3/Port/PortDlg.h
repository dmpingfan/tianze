// PortDlg.h : header file
//

#if !defined(AFX_PORTDLG_H__501F2793_EC24_4E64_A41D_2837D8DAA851__INCLUDED_)
#define AFX_PORTDLG_H__501F2793_EC24_4E64_A41D_2837D8DAA851__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPortDlg dialog

class CPortDlg : public CDialog
{
// Construction
public:
	CPortDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPortDlg)
	enum { IDD = IDD_PORT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPortDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPortDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnButtonSend();
	//}}AFX_MSG
    afx_msg LRESULT OnReceive(WPARAM wParam, LPARAM lParam); 
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PORTDLG_H__501F2793_EC24_4E64_A41D_2837D8DAA851__INCLUDED_)
