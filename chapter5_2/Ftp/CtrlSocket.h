#if !defined(AFX_CTRLSOCKET_H__4FC25E77_C8CA_431D_BD82_3F66A5707589__INCLUDED_)
#define AFX_CTRLSOCKET_H__4FC25E77_C8CA_431D_BD82_3F66A5707589__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CtrlSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CCtrlSocket command target

class CCtrlSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CCtrlSocket();
	virtual ~CCtrlSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtrlSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CCtrlSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTRLSOCKET_H__4FC25E77_C8CA_431D_BD82_3F66A5707589__INCLUDED_)
