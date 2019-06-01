// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__2D69D1AE_659F_488E_A880_2354A4806A45__INCLUDED_)
#define AFX_STDAFX_H__2D69D1AE_659F_488E_A880_2354A4806A45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <ras.h>
#include <nb30.h>
#include <afxsock.h>

typedef struct _ASTAT_
{
    ADAPTER_STATUS adapt; 
    NAME_BUFFER NameBuff[30]; 
}ASTAT, *PASTAT; 

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__2D69D1AE_659F_488E_A880_2354A4806A45__INCLUDED_)
