#if !defined(AFX_PROPERTYCONTAINER_H__04ED363E_6BA8_412D_B8F4_01A7B294EC43__INCLUDED_)
#define AFX_PROPERTYCONTAINER_H__04ED363E_6BA8_412D_B8F4_01A7B294EC43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PropertyContainer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropertyContainer

class CPropertyContainer : public CPropertySheet
{
	DECLARE_DYNAMIC(CPropertyContainer)

// Construction
public:
	CPropertyContainer(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPropertyContainer(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
    CEdit m_edit; 
    CFont m_fontEdit; 
    CImageList m_imageTab; 

// Operations
public:
    HBITMAP LoadResourceBitmap(HINSTANCE hInstance, LPSTR lpString); 
    HPALETTE CreateDIBPalette(LPBITMAPINFO lpbmi, LPINT lpiNumColors); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertyContainer)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPropertyContainer();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPropertyContainer)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTYCONTAINER_H__04ED363E_6BA8_412D_B8F4_01A7B294EC43__INCLUDED_)
