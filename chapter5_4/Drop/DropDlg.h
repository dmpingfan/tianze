// DropDlg.h : header file
//

#if !defined(AFX_DROPDLG_H__1F15E220_3FAD_492A_8B8A_8DD2B801D55A__INCLUDED_)
#define AFX_DROPDLG_H__1F15E220_3FAD_492A_8B8A_8DD2B801D55A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DropEdit.h"

/////////////////////////////////////////////////////////////////////////////
// CDropDlg dialog

class CDropDlg : public CDialog
{
// Construction
public:
	CDropDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDropDlg)
	enum { IDD = IDD_DROP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDropDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
    CDropEdit m_wndEdit; 

	// Generated message map functions
	//{{AFX_MSG(CDropDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DROPDLG_H__1F15E220_3FAD_492A_8B8A_8DD2B801D55A__INCLUDED_)
