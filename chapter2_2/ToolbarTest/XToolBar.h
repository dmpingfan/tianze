// XToolBar.h: interface for the XToolBar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XTOOLBAR_H__E975BEB0_61EE_42A2_9BB2_E3702D182D80__INCLUDED_)
#define AFX_XTOOLBAR_H__E975BEB0_61EE_42A2_9BB2_E3702D182D80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class XToolBar : public CToolBar  
{
public:
	XToolBar();
	virtual ~XToolBar();

public:
    CComboBox m_wndCombo; 
    CButton m_wndCheck; 
    CButton m_wndRadio; 

	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_XTOOLBAR_H__E975BEB0_61EE_42A2_9BB2_E3702D182D80__INCLUDED_)
