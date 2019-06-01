// ProgramGroupDlg.h : header file
//

#if !defined(AFX_PROGRAMGROUPDLG_H__3ED3EA62_4AD4_459E_BFFE_EB09945DFA98__INCLUDED_)
#define AFX_PROGRAMGROUPDLG_H__3ED3EA62_4AD4_459E_BFFE_EB09945DFA98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProgramGroupDlg dialog

class CProgramGroupDlg : public CDialog
{
// Construction
public:
	CProgramGroupDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CProgramGroupDlg)
	enum { IDD = IDD_PROGRAMGROUP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgramGroupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

public:
    CString m_strGroup; 
    CString m_strItem; 
    CString m_strFile; 

// Implementation
protected:
	HICON m_hIcon;

    virtual void OnOK(); 

	// Generated message map functions
	//{{AFX_MSG(CProgramGroupDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG    
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRAMGROUPDLG_H__3ED3EA62_4AD4_459E_BFFE_EB09945DFA98__INCLUDED_)
