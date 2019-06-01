; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=XButton
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Form.h"
LastPage=0

ClassCount=10
Class1=CFormApp
Class2=CFormDoc
Class3=CFormerView
Class4=CMainFrame
Class9=CAboutDlg

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class10=XButton
Resource3=IDD_FORM_FORM

[CLS:CFormApp]
Type=0
HeaderFile=Form.h
ImplementationFile=Form.cpp
Filter=N

[CLS:CFormDoc]
Type=0
HeaderFile=FormDoc.h
ImplementationFile=FormDoc.cpp
Filter=N

[CLS:CFormerView]
Type=0
HeaderFile=FormerView.h
ImplementationFile=FormerView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=Form.cpp
ImplementationFile=Form.cpp
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
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_FORM_FORM]
Type=1
Class=CFormerView
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDOK,button,1342242816
Control3=IDCANCEL,button,1342242816
Control4=IDC_ANIMATE_TEST,SysAnimate32,1350631427
Control5=IDC_BUTTON_NUM,button,1342242816
Control6=IDC_EDIT_NUM,edit,1350631552

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:XButton]
Type=0
HeaderFile=XButton.h
ImplementationFile=XButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

