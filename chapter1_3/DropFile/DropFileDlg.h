// DropFileDlg.h : header file
//

#if !defined(AFX_DROPFILEDLG_H__63397A41_DCAB_4E15_8D96_BF73ABB3C8B4__INCLUDED_)
#define AFX_DROPFILEDLG_H__63397A41_DCAB_4E15_8D96_BF73ABB3C8B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DlgOleDropTarget.h"

/////////////////////////////////////////////////////////////////////////////
// CDropFileDlg dialog

class CDropFileDlg : public CDialog
{
// Construction
public:
	CDropFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDropFileDlg)
	enum { IDD = IDD_DROPFILE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDropFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
    CDlgOleDropTarget m_oleDropTarget; 

	// Generated message map functions
	//{{AFX_MSG(CDropFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DROPFILEDLG_H__63397A41_DCAB_4E15_8D96_BF73ABB3C8B4__INCLUDED_)
