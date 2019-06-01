; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNetDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Net.h"

ClassCount=4
Class1=CNetApp
Class2=CNetDlg

ResourceCount=3
Resource2=IDR_MAINFRAME
Resource3=IDD_NET_DIALOG

[CLS:CNetApp]
Type=0
HeaderFile=Net.h
ImplementationFile=Net.cpp
Filter=N

[CLS:CNetDlg]
Type=0
HeaderFile=NetDlg.h
ImplementationFile=NetDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_NET_DIALOG]
Type=1
Class=CNetDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_BIOS,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_IP,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_BUTTON_HANG_UP,button,1342242816

