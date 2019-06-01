; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=XEdit
LastTemplate=CEdit
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TreeTest.h"

ClassCount=7
Class1=CTreeTestApp
Class2=CTreeTestDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=XTree
Class6=XListBox
Class7=XEdit
Resource3=IDD_TREETEST_DIALOG

[CLS:CTreeTestApp]
Type=0
HeaderFile=TreeTest.h
ImplementationFile=TreeTest.cpp
Filter=N

[CLS:CTreeTestDlg]
Type=0
HeaderFile=TreeTestDlg.h
ImplementationFile=TreeTestDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=TreeTestDlg.h
ImplementationFile=TreeTestDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TREETEST_DIALOG]
Type=1
Class=CTreeTestDlg
ControlCount=7
Control1=IDOK,button,1342242945
Control2=ID_REFRESH,button,1342243136
Control3=IDC_TREE_TEST,SysTreeView32,1350631431
Control4=IDC_TREE_TEST2,SysTreeView32,1350631431
Control5=IDC_LIST_TEST,listbox,1352728833
Control6=IDC_EDIT_TEST,edit,1350631552
Control7=IDC_SPIN_TEST,msctls_updown32,1342177458

[CLS:XTree]
Type=0
HeaderFile=XTree.h
ImplementationFile=XTree.cpp
BaseClass=CTreeCtrl
Filter=W
VirtualFilter=GWC

[CLS:XListBox]
Type=0
HeaderFile=XListBox.h
ImplementationFile=XListBox.cpp
BaseClass=CListBox
Filter=W
VirtualFilter=bWC

[CLS:XEdit]
Type=0
HeaderFile=XEdit.h
ImplementationFile=XEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC

