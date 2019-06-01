// DeleteTreeDlg.h : header file
//

#if !defined(AFX_DELETETREEDLG_H__A8845F11_351E_4FEA_81FB_2365903E0492__INCLUDED_)
#define AFX_DELETETREEDLG_H__A8845F11_351E_4FEA_81FB_2365903E0492__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDeleteTreeDlg dialog

class CDeleteTreeDlg : public CDialog
{
// Construction
public:
	CDeleteTreeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDeleteTreeDlg)
	enum { IDD = IDD_DELETETREE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteTreeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

    BOOL DeleteTree(CString strPath); 
    BOOL RemoveDirectory(CString strDir); 

	// Generated message map functions
	//{{AFX_MSG(CDeleteTreeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonFolder();
	afx_msg void OnButtonDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETETREEDLG_H__A8845F11_351E_4FEA_81FB_2365903E0492__INCLUDED_)
