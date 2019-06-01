; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CExitDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Exit.h"

ClassCount=4
Class1=CExitApp
Class2=CExitDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_EXIT_DIALOG

[CLS:CExitApp]
Type=0
HeaderFile=Exit.h
ImplementationFile=Exit.cpp
Filter=N

[CLS:CExitDlg]
Type=0
HeaderFile=ExitDlg.h
ImplementationFile=ExitDlg.cpp
Filter=T
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ExitDlg.h
ImplementationFile=ExitDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_EXIT_DIALOG]
Type=1
Class=CExitDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BUTTON_SHUTDOWN,button,1342242816
Control5=IDC_BUTTON_LOGOFF,button,1342242816
Control6=IDC_BUTTON_RESTART,button,1342242816
Control7=IDC_BUTTON_SLEEP,button,1342242816

