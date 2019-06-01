; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDropEdit
LastTemplate=CEdit
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Drop.h"

ClassCount=6
Class1=CDropApp
Class2=CDropDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CDropEdti
Class6=CDropEdit
Resource2=IDD_DROP_DIALOG

[CLS:CDropApp]
Type=0
HeaderFile=Drop.h
ImplementationFile=Drop.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CDropDlg]
Type=0
HeaderFile=DropDlg.h
ImplementationFile=DropDlg.cpp
Filter=D



[DLG:IDD_DROP_DIALOG]
Type=1
Class=CDropDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_FILE,edit,1350631552

[CLS:CDropEdti]
Type=0
HeaderFile=DropEdti.h
ImplementationFile=DropEdti.cpp
BaseClass=CEdit
Filter=W

[CLS:CDropEdit]
Type=0
HeaderFile=DropEdit.h
ImplementationFile=DropEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC

