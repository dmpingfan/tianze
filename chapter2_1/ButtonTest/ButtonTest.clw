; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=XButton
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ButtonTest.h"

ClassCount=5
Class1=CButtonTestApp
Class2=CButtonTestDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=XButton
Resource3=IDD_BUTTONTEST_DIALOG

[CLS:CButtonTestApp]
Type=0
HeaderFile=ButtonTest.h
ImplementationFile=ButtonTest.cpp
Filter=N

[CLS:CButtonTestDlg]
Type=0
HeaderFile=ButtonTestDlg.h
ImplementationFile=ButtonTestDlg.cpp
Filter=D

[CLS:CAboutDlg]
Type=0
HeaderFile=ButtonTestDlg.h
ImplementationFile=ButtonTestDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_BUTTONTEST_DIALOG]
Type=1
Class=CButtonTestDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BUTTON_TEST,button,1342242816
Control5=IDC_BUTTON_TEST2,button,1476460544
Control6=IDC_BUTTON1,button,1342242816
Control7=IDC_BUTTON2,button,1476460544

[CLS:XButton]
Type=0
HeaderFile=XButton.h
ImplementationFile=XButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

