#if !defined(AFX_DATASOCKET_H__C7F4265B_B3D5_4E7A_BD2B_F79B6D859984__INCLUDED_)
#define AFX_DATASOCKET_H__C7F4265B_B3D5_4E7A_BD2B_F79B6D859984__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CDataSocket command target

class CDataSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CDataSocket();
	virtual ~CDataSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CDataSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATASOCKET_H__C7F4265B_B3D5_4E7A_BD2B_F79B6D859984__INCLUDED_)
