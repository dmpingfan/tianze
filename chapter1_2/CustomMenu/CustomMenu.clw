; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCustomMenuDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CustomMenu.h"

ClassCount=4
Class1=CCustomMenuApp
Class2=CCustomMenuDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CUSTOMMENU_DIALOG

[CLS:CCustomMenuApp]
Type=0
HeaderFile=CustomMenu.h
ImplementationFile=CustomMenu.cpp
Filter=N

[CLS:CCustomMenuDlg]
Type=0
HeaderFile=CustomMenuDlg.h
ImplementationFile=CustomMenuDlg.cpp
Filter=D

[CLS:CAboutDlg]
Type=0
HeaderFile=CustomMenuDlg.h
ImplementationFile=CustomMenuDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CUSTOMMENU_DIALOG]
Type=1
Class=CCustomMenuDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

