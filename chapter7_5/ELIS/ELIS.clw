; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CELISView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ELIS.h"
LastPage=0

ClassCount=6
Class1=CELISApp
Class2=CELISDoc
Class3=CELISView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=3
Resource1=IDD_ELIS_FORM
Resource2=IDD_ABOUTBOX
Class5=CELISSet
Resource3=IDR_MAINFRAME

[CLS:CELISApp]
Type=0
HeaderFile=ELIS.h
ImplementationFile=ELIS.cpp
Filter=N

[CLS:CELISDoc]
Type=0
HeaderFile=ELISDoc.h
ImplementationFile=ELISDoc.cpp
Filter=N

[CLS:CELISView]
Type=0
HeaderFile=ELISView.h
ImplementationFile=ELISView.cpp
Filter=D
LastObject=CELISView


[CLS:CELISSet]
Type=0
HeaderFile=ELISSet.h
ImplementationFile=ELISSet.cpp
Filter=N

[DB:CELISSet]
DB=1
DBType=ODBC
ColumnCount=28
Column1=[SensorInformation].[ID], 4, 4
Column2=[ToolID], 4, 4
Column3=[SensorInformation].[Name], 12, 100
Column4=[Offset], 7, 4
Column5=[OffsetUnit], 12, 100
Column6=[IsDisplay], 12, 100
Column7=[ToolInformation].[ID], 4, 4
Column8=[ToolInformation].[Name], 12, 100
Column9=[Remark], -1, 2147483646
Column10=[ImagePath], -1, 2147483646
Column11=[SN], -1, 2147483646
Column12=[Length], 7, 4
Column13=[LengthUnit], 12, 100
Column14=[Weight], 7, 4
Column15=[WeightUnit], 12, 100
Column16=[OutterDiameter], 7, 4
Column17=[OutterDiameterUnit], 12, 100
Column18=[InnerDiameter], 7, 4
Column19=[InnerDiameterUnit], 12, 100
Column20=[TemperatureEndure], 7, 4
Column21=[TemperatureEndureUnit], 12, 100
Column22=[PressureEndure], 7, 4
Column23=[PressureEndureUnit], 12, 100
Column24=[MaxSpeed], 7, 4
Column25=[MaxSpeedUnit], 12, 100
Column26=[DisplayMask], 5, 2
Column27=[TopTransformer], 12, 510
Column28=[BottomTransformer], 12, 510


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=ELIS.cpp
ImplementationFile=ELIS.cpp
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
Command1=ID_EDIT_COPY
Command2=ID_EDIT_PASTE
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_NEXT_PANE
Command6=ID_PREV_PANE
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_RECORD_PREV
Command10=ID_RECORD_NEXT
Command11=ID_EDIT_CUT
Command12=ID_EDIT_UNDO
CommandCount=12

[DLG:IDD_ELIS_FORM]
Type=1
Class=CELISView
ControlCount=44
Control1=IDC_STATIC,static,1342308354
Control2=IDC_EDIT_ID,edit,1350631552
Control3=IDC_STATIC,static,1342308354
Control4=IDC_EDIT_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308354
Control6=IDC_EDIT_REMARK,edit,1350631552
Control7=IDC_STATIC,static,1342308354
Control8=IDC_EDIT_IMAGE_PATH,edit,1350631552
Control9=IDC_STATIC,static,1342308354
Control10=IDC_EDIT_SN,edit,1350631552
Control11=IDC_STATIC,static,1342308354
Control12=IDC_EDIT_LENGTH,edit,1350631552
Control13=IDC_STATIC,static,1342308354
Control14=IDC_EDIT_LENGTH_UNIT,edit,1350631552
Control15=IDC_STATIC,static,1342308354
Control16=IDC_EDIT_WEIGHT,edit,1350631552
Control17=IDC_STATIC,static,1342308354
Control18=IDC_EDIT_WEIGHT_UNIT,edit,1350631552
Control19=IDC_STATIC,static,1342308354
Control20=IDC_EDIT_OUTTER_DIAMETER,edit,1350631552
Control21=IDC_STATIC,static,1342308354
Control22=IDC_EDIT_OUTTER_DIAMETER_UNIT,edit,1350631552
Control23=IDC_STATIC,static,1342308354
Control24=IDC_EDIT_INNER_DIAMETER,edit,1350631552
Control25=IDC_STATIC,static,1342308354
Control26=IDC_EDIT_INNER_DIAMETER_UNIT,edit,1350631552
Control27=IDC_STATIC,static,1342308354
Control28=IDC_EDIT_TEMPERATURE_ENDURE,edit,1350631552
Control29=IDC_STATIC,static,1342308354
Control30=IDC_EDIT_TEMPERATURE_ENDURE_UNIT,edit,1350631552
Control31=IDC_STATIC,static,1342308354
Control32=IDC_EDIT_PRESSURE_ENDURE,edit,1350631552
Control33=IDC_STATIC,static,1342308354
Control34=IDC_EDIT_PRESSURE_ENDURE_UNIT,edit,1350631552
Control35=IDC_STATIC,static,1342308354
Control36=IDC_EDIT_MAX_SPEED,edit,1350631552
Control37=IDC_STATIC,static,1342308354
Control38=IDC_EDIT_MAX_SPEED_UNIT,edit,1350631552
Control39=IDC_STATIC,static,1342308354
Control40=IDC_EDIT_DISPLAY_MASK,edit,1350631552
Control41=IDC_STATIC,static,1342308354
Control42=IDC_EDIT_TOP_TRANSFORMER,edit,1350631552
Control43=IDC_STATIC,static,1342308354
Control44=IDC_EDIT_BOTTOM_TRANSFORMER,edit,1350631552

[DLG:IDR_MAINFRAME]
Type=1
Class=?
ControlCount=3
Control1=IDC_STATIC,static,1342308354
Control2=IDC_EDIT_NAME_LIKE,edit,1350631552
Control3=IDC_BUTTON_GO,button,1342242816

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

