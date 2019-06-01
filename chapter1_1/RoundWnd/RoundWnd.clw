; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRoundWndDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RoundWnd.h"

ClassCount=4
Class1=CRoundWndApp
Class2=CRoundWndDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ROUNDWND_DIALOG

[CLS:CRoundWndApp]
Type=0
HeaderFile=RoundWnd.h
ImplementationFile=RoundWnd.cpp
Filter=N

[CLS:CRoundWndDlg]
Type=0
HeaderFile=RoundWndDlg.h
ImplementationFile=RoundWndDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=RoundWndDlg.h
ImplementationFile=RoundWndDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ROUNDWND_DIALOG]
Type=1
Class=CRoundWndDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

