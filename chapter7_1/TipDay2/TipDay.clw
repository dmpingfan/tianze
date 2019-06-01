; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTipDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TipDay.h"

ClassCount=5
Class1=CTipDayApp
Class2=CTipDayDlg

ResourceCount=4
Resource2=IDR_MAINFRAME
Resource3=IDD_TIPDAY_DIALOG
Class5=CTipDlg
Resource4=IDD_TIP

[CLS:CTipDayApp]
Type=0
HeaderFile=TipDay.h
ImplementationFile=TipDay.cpp
Filter=N

[CLS:CTipDayDlg]
Type=0
HeaderFile=TipDayDlg.h
ImplementationFile=TipDayDlg.cpp
Filter=D



[DLG:IDD_TIPDAY_DIALOG]
Type=1
Class=CTipDayDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

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
Filter=D
VirtualFilter=dWC

