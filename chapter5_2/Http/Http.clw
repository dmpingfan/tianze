; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHttpDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Http.h"

ClassCount=4
Class1=CHttpApp
Class2=CHttpDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_HTTP_DIALOG

[CLS:CHttpApp]
Type=0
HeaderFile=Http.h
ImplementationFile=Http.cpp
Filter=N

[CLS:CHttpDlg]
Type=0
HeaderFile=HttpDlg.h
ImplementationFile=HttpDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=HttpDlg.h
ImplementationFile=HttpDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_HTTP_DIALOG]
Type=1
Class=CHttpDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BUTTON_TEST,button,1342242816

