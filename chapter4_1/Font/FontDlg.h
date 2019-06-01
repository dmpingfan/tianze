// FontDlg.h : header file
//

#if !defined(AFX_FONTDLG_H__0DE3782B_7229_4B1A_ACDB_6BAB4AAABD72__INCLUDED_)
#define AFX_FONTDLG_H__0DE3782B_7229_4B1A_ACDB_6BAB4AAABD72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFontDlg dialog

class CFontDlg : public CDialog
{
// Construction
public:
	CFontDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFontDlg)
	enum { IDD = IDD_FONT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
    void ChangeDlgFont(CFont* pFont); 

	// Generated message map functions
	//{{AFX_MSG(CFontDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnFont();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTDLG_H__0DE3782B_7229_4B1A_ACDB_6BAB4AAABD72__INCLUDED_)
