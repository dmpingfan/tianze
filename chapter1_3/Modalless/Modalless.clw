; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CModallessDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Modalless.h"

ClassCount=4
Class1=CModallessApp
Class2=CModallessDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MODALLESS_DIALOG

[CLS:CModallessApp]
Type=0
HeaderFile=Modalless.h
ImplementationFile=Modalless.cpp
Filter=N

[CLS:CModallessDlg]
Type=0
HeaderFile=ModallessDlg.h
ImplementationFile=ModallessDlg.cpp
Filter=D

[CLS:CAboutDlg]
Type=0
HeaderFile=ModallessDlg.h
ImplementationFile=ModallessDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MODALLESS_DIALOG]
Type=1
Class=CModallessDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

