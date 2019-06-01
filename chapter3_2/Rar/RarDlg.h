// RarDlg.h : header file
//

#if !defined(AFX_RARDLG_H__70018F71_F0C0_4718_8D56_F612E4B0782C__INCLUDED_)
#define AFX_RARDLG_H__70018F71_F0C0_4718_8D56_F612E4B0782C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRarDlg dialog

class CRarDlg : public CDialog
{
// Construction
public:
	CRarDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRarDlg)
	enum { IDD = IDD_RAR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

	BOOL CreateBatchFile(CString strInputFile, CString strOutputFile, CString& strBatch); 
	BOOL RunBatch(CString strBatch); 
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonBrowseInput();
	afx_msg void OnButtonBrowseOutput();
	afx_msg void OnButtonRun();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RARDLG_H__70018F71_F0C0_4718_8D56_F612E4B0782C__INCLUDED_)
