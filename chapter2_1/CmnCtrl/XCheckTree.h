#if !defined(AFX_XCHECKTREE_H__3F6CC446_CECB_46B4_9B5B_CDCD4D1C887D__INCLUDED_)
#define AFX_XCHECKTREE_H__3F6CC446_CECB_46B4_9B5B_CDCD4D1C887D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XCheckTree.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// XCheckTree window

class XCheckTree : public CTreeCtrl
{
// Construction
public:
	XCheckTree();

// Attributes
public:

// Operations
public:
    //HTREEITEM InsertItem(LPTV_INSERTSTRUCT lpInsertStruct); 
    //HTREEITEM InsertItem(LPCTSTR lpszItem); 
    BOOL IsItemChecked(HTREEITEM hItem); 
    HTREEITEM GetFirstCheckedItem(); 
    HTREEITEM GetNextCheckedItem(HTREEITEM hItem); 
    HTREEITEM GetPrevCheckedItem(HTREEITEM hItem); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(XCheckTree)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~XCheckTree();

	// Generated message map functions
protected:
	//{{AFX_MSG(XCheckTree)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XCHECKTREE_H__3F6CC446_CECB_46B4_9B5B_CDCD4D1C887D__INCLUDED_)
