// TicketDlg.h : header file
//

#if !defined(AFX_TICKETDLG_H__352A73C8_C8AE_44C1_B74F_CE27DE88A42F__INCLUDED_)
#define AFX_TICKETDLG_H__352A73C8_C8AE_44C1_B74F_CE27DE88A42F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTicketDlg dialog

class CTicketDlg : public CDialog
{
// Construction
public:
	CTicketDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTicketDlg)
	enum { IDD = IDD_TICKET_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTicketDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HANDLE m_hThreadArray[10]; 
	
public:
	int m_nTicket; 
	CRITICAL_SECTION m_cs; 
	static DWORD PASCAL StartThreadProc(LPVOID pParam); 
	DWORD SellTicketProc(); 

	// Generated message map functions
	//{{AFX_MSG(CTicketDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonSell();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TICKETDLG_H__352A73C8_C8AE_44C1_B74F_CE27DE88A42F__INCLUDED_)
