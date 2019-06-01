#if !defined(AFX_DROPEDIT_H__463C5E46_D603_4CB3_B286_6FE67D7C9E2D__INCLUDED_)
#define AFX_DROPEDIT_H__463C5E46_D603_4CB3_B286_6FE67D7C9E2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DropEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDropEdit window

class CDropEdit : public CEdit
{
// Construction
public:
	CDropEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDropEdit)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDropEdit();
    CString ExpandShortcut(CString strFile); 

	// Generated message map functions
protected:
	//{{AFX_MSG(CDropEdit)
	afx_msg void OnDropFiles(HDROP hDropInfo);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DROPEDIT_H__463C5E46_D603_4CB3_B286_6FE67D7C9E2D__INCLUDED_)
