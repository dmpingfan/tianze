; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTipDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TipDay.h"
LastPage=0

ClassCount=10
Class1=CTipDayApp
Class2=CTipDayDoc
Class3=CTipDayView
Class4=CMainFrame
Class7=CChildFrame
Class9=CAboutDlg

ResourceCount=8
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Resource3=IDR_TIPDAYTYPE
Class10=CTipDlg
Resource8=IDD_TIP

[CLS:CTipDayApp]
Type=0
HeaderFile=TipDay.h
ImplementationFile=TipDay.cpp
Filter=N

[CLS:CTipDayDoc]
Type=0
HeaderFile=TipDayDoc.h
ImplementationFile=TipDayDoc.cpp
Filter=N

[CLS:CTipDayView]
Type=0
HeaderFile=TipDayView.h
ImplementationFile=TipDayView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CMDIFrameWnd
VirtualFilter=fWC


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=TipDay.cpp
ImplementationFile=TipDay.cpp
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
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_MRU_FILE1
Command4=ID_APP_EXIT
Command5=ID_APP_ABOUT
Command6=ID_TIP_OF_THE_DAY
CommandCount=6

[MNU:IDR_TIPDAYTYPE]
Type=1
Class=CTipDayView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_MRU_FILE1
Command7=ID_APP_EXIT
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_WINDOW_NEW
Command13=ID_WINDOW_CASCADE
Command14=ID_WINDOW_TILE_HORZ
Command15=ID_WINDOW_ARRANGE
Command16=ID_APP_ABOUT
Command17=ID_TIP_OF_THE_DAY
CommandCount=17

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_TIP]
Type=1
Class=?
ControlCount=6
Control1=65535,static,1342177287
Control2=IDC_TIPSTRING,static,1342308352
Control3=IDC_STARTUP,button,1342373891
Control4=IDC_NEXTTIP,button,1342373888
Control5=IDOK,button,1342373889
Control6=IDC_BULB,static,1342177294

[CLS:CTipDlg]
Type=0
HeaderFile=TipDlg.h
ImplementationFile=TipDlg.cpp
BaseClass=CDialog

