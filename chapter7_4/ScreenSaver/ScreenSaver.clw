; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CScreenSaverWnd
LastTemplate=generic CWnd
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ScreenSaver.h"

ClassCount=5
Class1=CScreenSaverApp
Class2=CScreenSaverDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CScreenSaverWnd
Resource2=IDD_SCREENSAVER_DIALOG

[CLS:CScreenSaverApp]
Type=0
HeaderFile=ScreenSaver.h
ImplementationFile=ScreenSaver.cpp
Filter=N

[CLS:CScreenSaverDlg]
Type=0
HeaderFile=ScreenSaverDlg.h
ImplementationFile=ScreenSaverDlg.cpp
Filter=D



[DLG:IDD_SCREENSAVER_DIALOG]
Type=1
Class=CScreenSaverDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[CLS:CScreenSaverWnd]
Type=0
HeaderFile=ScreenSaverWnd.h
ImplementationFile=ScreenSaverWnd.cpp
BaseClass=generic CWnd
Filter=W

