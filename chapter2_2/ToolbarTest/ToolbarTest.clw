; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ToolbarTest.h"
LastPage=0

ClassCount=4
Class1=CToolbarTestApp
Class3=CMainFrame
Class4=CAboutDlg

ResourceCount=4
Resource1=IDR_TOOLBAR256
Resource2=IDR_MAINFRAME
Class2=CChildView
Resource3=IDR_MENU_TOOLBAR
Resource4=IDD_ABOUTBOX

[CLS:CToolbarTestApp]
Type=0
HeaderFile=ToolbarTest.h
ImplementationFile=ToolbarTest.cpp
Filter=N

[CLS:CChildView]
Type=0
HeaderFile=ChildView.h
ImplementationFile=ChildView.cpp
Filter=N

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=W
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_MAKE_TOP




[CLS:CAboutDlg]
Type=0
HeaderFile=ToolbarTest.cpp
ImplementationFile=ToolbarTest.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_VIEW_TOOLBAR256
Command9=ID_MAKE_TOP
Command10=ID_APP_ABOUT
CommandCount=10

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_EDIT_PASTE
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_NEXT_PANE
Command6=ID_PREV_PANE
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_CUT
Command10=ID_EDIT_UNDO
CommandCount=10

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_COMBO_BOX
Command6=ID_CHECK_BOX
Command7=ID_RADIO_BOX
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_TOOLBAR256]
Type=1
Class=?
Command1=ID_TOOLBTN1
Command2=ID_TOOLBTN2
Command3=ID_TOOLBTN3
Command4=ID_TOOLBTN4
CommandCount=4

[MNU:IDR_MENU_TOOLBAR]
Type=1
Class=?
Command1=ID_VIEW_TOOLBAR
Command2=ID_VIEW_STATUS_BAR
Command3=ID_VIEW_TOOLBAR256
CommandCount=3

