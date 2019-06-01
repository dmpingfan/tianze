; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDesktopDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Desktop.h"

ClassCount=3
Class1=CDesktopApp
Class2=CDesktopDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DESKTOP_DIALOG

[CLS:CDesktopApp]
Type=0
HeaderFile=Desktop.h
ImplementationFile=Desktop.cpp
Filter=N

[CLS:CDesktopDlg]
Type=0
HeaderFile=DesktopDlg.h
ImplementationFile=DesktopDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_TREE_WND

[CLS:CAboutDlg]
Type=0
HeaderFile=DesktopDlg.h
ImplementationFile=DesktopDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DESKTOP_DIALOG]
Type=1
Class=CDesktopDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TREE_WND,SysTreeView32,1350631431
Control4=IDC_BUTTON_REFRESH,button,1342242816
Control5=IDC_BUTTON_CLOSE,button,1342242816
Control6=IDC_CHECK_HIDE,button,1342246915
Control7=IDC_CHECK_DISABLE,button,1342246915
Control8=IDC_BTN_ACTIVE,button,1342242816
Control9=IDC_CHECK_SHOW_HIDE,button,1342242819
Control10=IDC_CHECK_SHOW_DISABLE,button,1342242819

