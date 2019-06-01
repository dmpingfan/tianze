; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRarDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Rar.h"

ClassCount=4
Class1=CRarApp
Class2=CRarDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_RAR_DIALOG

[CLS:CRarApp]
Type=0
HeaderFile=Rar.h
ImplementationFile=Rar.cpp
Filter=N

[CLS:CRarDlg]
Type=0
HeaderFile=RarDlg.h
ImplementationFile=RarDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=RarDlg.h
ImplementationFile=RarDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_RAR_DIALOG]
Type=1
Class=CRarDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BUTTON_BROWSE_INPUT,button,1342242816
Control5=IDC_EDIT_INPUT,edit,1350631552
Control6=IDC_BUTTON_BROWSE_OUTPUT,button,1342242816
Control7=IDC_EDIT_OUTPUT,edit,1350631552
Control8=IDC_BUTTON_RUN,button,1342242816

