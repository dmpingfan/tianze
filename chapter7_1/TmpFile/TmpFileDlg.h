// TmpFileDlg.h : header file
//

#if !defined(AFX_TMPFILEDLG_H__00193776_5CC8_47F0_B6D2_24D6693CC369__INCLUDED_)
#define AFX_TMPFILEDLG_H__00193776_5CC8_47F0_B6D2_24D6693CC369__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTmpFileDlg dialog

class CTmpFileDlg : public CDialog
{
// Construction
public:
	CTmpFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTmpFileDlg)
	enum { IDD = IDD_TMPFILE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTmpFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	CString GetUniqueTmpFileName(); 

	// Generated message map functions
	//{{AFX_MSG(CTmpFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonCreate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TMPFILEDLG_H__00193776_5CC8_47F0_B6D2_24D6693CC369__INCLUDED_)
