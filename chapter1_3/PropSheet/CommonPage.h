#if !defined(AFX_COMMONPAGE_H__ACBD471A_D879_40DF_B98F_364655721AB9__INCLUDED_)
#define AFX_COMMONPAGE_H__ACBD471A_D879_40DF_B98F_364655721AB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CommonPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCommonPage dialog

class CCommonPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CCommonPage)

// Construction
public:
	CCommonPage();
	~CCommonPage();

// Dialog Data
	//{{AFX_DATA(CCommonPage)
	enum { IDD = IDD_PROPERTY_PAGE };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CCommonPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCommonPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMONPAGE_H__ACBD471A_D879_40DF_B98F_364655721AB9__INCLUDED_)
