// BroadCastDlg.h : header file
//

#if !defined(AFX_BROADCASTDLG_H__1E80B8B8_E738_4740_90FD_CF2E0A2AED0E__INCLUDED_)
#define AFX_BROADCASTDLG_H__1E80B8B8_E738_4740_90FD_CF2E0A2AED0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBroadCastDlg dialog

class CBroadCastDlg : public CDialog
{
// Construction
public:
	CBroadCastDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBroadCastDlg)
	enum { IDD = IDD_BROADCAST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBroadCastDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBroadCastDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROADCASTDLG_H__1E80B8B8_E738_4740_90FD_CF2E0A2AED0E__INCLUDED_)
