; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPortDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Port.h"

ClassCount=4
Class1=CPortApp
Class2=CPortDlg

ResourceCount=3
Resource2=IDR_MAINFRAME
Resource3=IDD_PORT_DIALOG

[CLS:CPortApp]
Type=0
HeaderFile=Port.h
ImplementationFile=Port.cpp
Filter=N

[CLS:CPortDlg]
Type=0
HeaderFile=PortDlg.h
ImplementationFile=PortDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_PORT_DIALOG]
Type=1
Class=CPortDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_RECEIVE,edit,1342242884
Control5=IDC_BUTTON_SEND,button,1342242816
Control6=IDC_EDIT_SEND,edit,1342242884

