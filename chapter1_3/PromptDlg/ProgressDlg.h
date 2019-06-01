#if !defined(AFX_PROGRESSDLG_H__572935FB_90F0_47B8_8FE8_997BD713B515__INCLUDED_)
#define AFX_PROGRESSDLG_H__572935FB_90F0_47B8_8FE8_997BD713B515__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProgressDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg dialog

class CProgressDlg : public CDialog
{
// Construction
public:
	CProgressDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProgressDlg)
	enum { IDD = IDD_DIALOG_PROMPT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

    //virtual void OnOK(); 
    virtual void OnCancel(); 

	static DWORD PASCAL StartProcess(LPVOID lpParam); 
	DWORD ProcessProc(); 

	BOOL Create(); 
	void SetProgressInfo(int min, int max, int step); 
	void StepIt(); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgressDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:
	UINT m_nID; 
	CWnd* m_pParent; 
	BOOL m_bCancel; 

	// Generated message map functions
	//{{AFX_MSG(CProgressDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRESSDLG_H__572935FB_90F0_47B8_8FE8_997BD713B515__INCLUDED_)
