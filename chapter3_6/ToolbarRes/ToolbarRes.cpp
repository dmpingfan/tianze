// ToolbarRes.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


static AFX_EXTENSION_MODULE ToolbarResDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("TOOLBARRES.DLL Initializing!\n");
		
		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(ToolbarResDLL, hInstance))
			return 0;

		// Insert this DLL into the resource chain
		// NOTE: If this Extension DLL is being implicitly linked to by
		//  an MFC Regular DLL (such as an ActiveX Control)
		//  instead of an MFC application, then you will want to
		//  remove this line from DllMain and put it in a separate
		//  function exported from this Extension DLL.  The Regular DLL
		//  that uses this Extension DLL should then explicitly call that
		//  function to initialize this Extension DLL.  Otherwise,
		//  the CDynLinkLibrary object will not be attached to the
		//  Regular DLL's resource chain, and serious problems will
		//  result.

		new CDynLinkLibrary(ToolbarResDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("TOOLBARRES.DLL Terminating!\n");
		// Terminate the library before destructors are called
		AfxTermExtensionModule(ToolbarResDLL);
	}
	return 1;   // ok
}

#include "resource.h"

AFX_EXT_API CToolBar* PASCAL CreateToolbar(CWnd* pParent, UINT nID)
{
    CToolBar* pToolbar = new CToolBar(); 
    BOOL bRes = pToolbar->CreateEx(pParent, TBSTYLE_FLAT, 
        WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC,
        CRect(0, 0, 0, 0), nID); 
    if(bRes)
        pToolbar->LoadToolBar(IDR_TOOLBAR_MAIN); 
    return pToolbar; 
}
