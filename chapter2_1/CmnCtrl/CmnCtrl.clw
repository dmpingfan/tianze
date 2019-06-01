; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=XCheckTree
LastTemplate=CTreeCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CmnCtrl.h"

ClassCount=4
Class1=CCmnCtrlApp
Class2=CCmnCtrlDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=XCheckTree
Resource3=IDD_CMNCTRL_DIALOG

[CLS:CCmnCtrlApp]
Type=0
HeaderFile=CmnCtrl.h
ImplementationFile=CmnCtrl.cpp
Filter=N

[CLS:CCmnCtrlDlg]
Type=0
HeaderFile=CmnCtrlDlg.h
ImplementationFile=CmnCtrlDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST_TEST

[CLS:CAboutDlg]
Type=0
HeaderFile=CmnCtrlDlg.h
ImplementationFile=CmnCtrlDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CMNCTRL_DIALOG]
Type=1
Class=CCmnCtrlDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST_TEST,SysListView32,1350631426
Control4=IDC_TREE_TEST,SysTreeView32,1350631439
Control5=IDC_BUTTON_ADD,button,1342242816
Control6=IDC_BUTTON_DELETE,button,1342242816

[CLS:XCheckTree]
Type=0
HeaderFile=XCheckTree.h
ImplementationFile=XCheckTree.cpp
BaseClass=CTreeCtrl
Filter=W
VirtualFilter=GWC

