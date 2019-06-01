// HitMoveDlg.h : header file
//

#if !defined(AFX_HITMOVEDLG_H__8D09A513_28FC_4D96_A58E_F7C971585CEA__INCLUDED_)
#define AFX_HITMOVEDLG_H__8D09A513_28FC_4D96_A58E_F7C971585CEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHitMoveDlg dialog

class CHitMoveDlg : public CDialog
{
// Construction
public:
	CHitMoveDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHitMoveDlg)
	enum { IDD = IDD_HITMOVE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHitMoveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHitMoveDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg UINT OnNcHitTest(CPoint point);
	//}}AFX_MSG
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HITMOVEDLG_H__8D09A513_28FC_4D96_A58E_F7C971585CEA__INCLUDED_)
