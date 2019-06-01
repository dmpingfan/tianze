; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DB.h"
LastPage=0

ClassCount=9
Class1=CDBApp
Class2=CDBDoc
Class3=CDBView
Class4=CMainFrame
Class6=CDBSet
Class9=CAboutDlg

ResourceCount=7
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Resource7=IDD_DB_FORM

[CLS:CDBApp]
Type=0
HeaderFile=DB.h
ImplementationFile=DB.cpp
Filter=N

[CLS:CDBDoc]
Type=0
HeaderFile=DBDoc.h
ImplementationFile=DBDoc.cpp
Filter=N

[CLS:CDBView]
Type=0
HeaderFile=DBView.h
ImplementationFile=DBView.cpp
Filter=D
BaseClass=CRecordView
VirtualFilter=RVWC


[CLS:CDBSet]
Type=0
HeaderFile=DBSet.h
ImplementationFile=DBSet.cpp
Filter=N

[DB:CDBSet]
DB=1
DBType=ODBC
ColumnCount=22
Column1=[ID], 4, 4
Column2=[Name], 12, 100
Column3=[Remark], -1, 2147483646
Column4=[ImagePath], -1, 2147483646
Column5=[SN], -1, 2147483646
Column6=[Length], 7, 4
Column7=[LengthUnit], 12, 100
Column8=[Weight], 7, 4
Column9=[WeightUnit], 12, 100
Column10=[OutterDiameter], 7, 4
Column11=[OutterDiameterUnit], 12, 100
Column12=[InnerDiameter], 7, 4
Column13=[InnerDiameterUnit], 12, 100
Column14=[TemperatureEndure], 7, 4
Column15=[TemperatureEndureUnit], 12, 100
Column16=[PressureEndure], 7, 4
Column17=[PressureEndureUnit], 12, 100
Column18=[MaxSpeed], 7, 4
Column19=[MaxSpeedUnit], 12, 100
Column20=[DisplayMask], 5, 2
Column21=[TopTransformer], 12, 510
Column22=[BottomTransformer], 12, 510


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=DB.cpp
ImplementationFile=DB.cpp
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
Command6=ID_RECORD_FIRST
Command7=ID_RECORD_PREV
Command8=ID_RECORD_NEXT
Command9=ID_RECORD_LAST
Command10=ID_VIEW_TOOLBAR
Command11=ID_VIEW_STATUS_BAR
Command12=ID_APP_ABOUT
CommandCount=12

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_NEXT_PANE
Command10=ID_PREV_PANE
CommandCount=10

[DLG:IDD_DB_FORM]
Type=1
Class=CDBView
ControlCount=3
Control1=IDC_LIST_RECORD,SysListView32,1342275585
Control2=IDC_LIST_COLUMN,listbox,1344340233
Control3=IDC_BUTTON_QUERY,button,1342242816

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_RECORD_FIRST
Command6=ID_RECORD_PREV
Command7=ID_RECORD_NEXT
Command8=ID_RECORD_LAST
Command9=ID_APP_ABOUT
CommandCount=9

