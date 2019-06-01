// HttpDlg.h : header file
//

#if !defined(AFX_HTTPDLG_H__9F16BA00_3EA5_4D41_9ED6_81D506F27A81__INCLUDED_)
#define AFX_HTTPDLG_H__9F16BA00_3EA5_4D41_9ED6_81D506F27A81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHttpDlg dialog

class CHttpDlg : public CDialog
{
// Construction
public:
	CHttpDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHttpDlg)
	enum { IDD = IDD_HTTP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHttpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	BOOL HttpClient(); 

	// Generated message map functions
	//{{AFX_MSG(CHttpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTTPDLG_H__9F16BA00_3EA5_4D41_9ED6_81D506F27A81__INCLUDED_)
