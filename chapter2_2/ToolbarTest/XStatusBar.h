// XStatusBar.h: interface for the XStatusBar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XSTATUSBAR_H__5F325253_8504_471B_9907_275CC3A763D8__INCLUDED_)
#define AFX_XSTATUSBAR_H__5F325253_8504_471B_9907_275CC3A763D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class XStatusBar : public CStatusBar  
{
public:
	XStatusBar();
	virtual ~XStatusBar();

public:
    CProgressCtrl m_wndProgress; 
    CButton m_wndBtn; 
};

#endif // !defined(AFX_XSTATUSBAR_H__5F325253_8504_471B_9907_275CC3A763D8__INCLUDED_)
