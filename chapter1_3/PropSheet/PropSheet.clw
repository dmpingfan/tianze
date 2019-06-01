; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCommonPage
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PropSheet.h"
LastPage=0

ClassCount=7
Class1=CPropSheetApp
Class3=CMainFrame
Class4=CAboutDlg

ResourceCount=4
Resource1=IDR_MAINFRAME
Class2=CChildView
Class5=CPropertySheetEx
Class6=CPropertyContainer
Resource2=IDR_TOOLBAR256
Class7=CCommonPage
Resource3=IDD_ABOUTBOX
Resource4=IDD_PROPERTY_PAGE

[CLS:CPropSheetApp]
Type=0
HeaderFile=PropSheet.h
ImplementationFile=PropSheet.cpp
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
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_VIEW_PROPSHEET




[CLS:CAboutDlg]
Type=0
HeaderFile=PropSheet.cpp
ImplementationFile=PropSheet.cpp
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
Command8=ID_VIEW_PROPSHEET
Command9=ID_APP_ABOUT
CommandCount=9

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
Command5=ID_APP_ABOUT
CommandCount=5

[CLS:CPropertySheetEx]
Type=0
HeaderFile=PropertySheetEx.h
ImplementationFile=PropertySheetEx.cpp
BaseClass=CPropertySheet
Filter=W
LastObject=CPropertySheetEx

[CLS:CPropertyContainer]
Type=0
HeaderFile=PropertyContainer.h
ImplementationFile=PropertyContainer.cpp
BaseClass=CPropertySheet
Filter=D
VirtualFilter=hWC

[DLG:IDD_PROPERTY_PAGE]
Type=1
Class=CCommonPage
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_CHECK1,button,1342242819
Control5=IDC_RADIO1,button,1342177289
Control6=IDC_EDIT1,edit,1350631552

[CLS:CCommonPage]
Type=0
HeaderFile=CommonPage.h
ImplementationFile=CommonPage.cpp
BaseClass=CPropertyPage
Filter=D

[TB:IDR_TOOLBAR256]
Type=1
Class=?
Command1=ID_BUTTON32772
Command2=ID_BUTTON32773
Command3=ID_BUTTON32774
Command4=ID_BUTTON32775
Command5=ID_BUTTON32776
Command6=ID_BUTTON32777
CommandCount=6

