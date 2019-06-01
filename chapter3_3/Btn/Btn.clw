; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=XButton
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Btn.h"

ClassCount=5
Class1=CBtnApp
Class2=CBtnDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=XButton
Resource3=IDD_BTN_DIALOG

[CLS:CBtnApp]
Type=0
HeaderFile=Btn.h
ImplementationFile=Btn.cpp
Filter=N

[CLS:CBtnDlg]
Type=0
HeaderFile=BtnDlg.h
ImplementationFile=BtnDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=BtnDlg.h
ImplementationFile=BtnDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_BTN_DIALOG]
Type=1
Class=CBtnDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BUTTON_OK,button,1342242827
Control5=IDC_BUTTON_CANCEL,button,1342242827

[CLS:XButton]
Type=0
HeaderFile=XButton.h
ImplementationFile=XButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

