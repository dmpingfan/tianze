// TreeTestDlg.h : header file
//

#if !defined(AFX_TREETESTDLG_H__23B9FAC4_8CC2_49C3_B873_D3455941E664__INCLUDED_)
#define AFX_TREETESTDLG_H__23B9FAC4_8CC2_49C3_B873_D3455941E664__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XTree.h"
#include "XListBox.h"
#include "XEdit.h"

/////////////////////////////////////////////////////////////////////////////
// CTreeTestDlg dialog

class CTreeTestDlg : public CDialog
{
// Construction
public:
	CTreeTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTreeTestDlg)
	enum { IDD = IDD_TREETEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
    XTree m_tree; 
    XListBox m_listbox; 
    XEdit m_edit; 
    int m_nTop; 
    void AddTreeNode(CTreeCtrl* pTree, HTREEITEM hParent, CString strPath); 
    void AddListItem(CListBox* pList, CString strPath); 
    BOOL OnValidateParams(WPARAM wParam, LPARAM lParam); 

	// Generated message map functions
	//{{AFX_MSG(CTreeTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRefresh();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnKillfocusEditTest();
	afx_msg void OnKillfocusListTest();
	afx_msg void OnKillfocusTreeTest(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKillfocusTreeTest2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREETESTDLG_H__23B9FAC4_8CC2_49C3_B873_D3455941E664__INCLUDED_)
