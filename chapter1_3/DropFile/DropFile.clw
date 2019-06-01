; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDropFileDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DropFile.h"

ClassCount=4
Class1=CDropFileApp
Class2=CDropFileDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DROPFILE_DIALOG

[CLS:CDropFileApp]
Type=0
HeaderFile=DropFile.h
ImplementationFile=DropFile.cpp
Filter=N

[CLS:CDropFileDlg]
Type=0
HeaderFile=DropFileDlg.h
ImplementationFile=DropFileDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=DropFileDlg.h
ImplementationFile=DropFileDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DROPFILE_DIALOG]
Type=1
Class=CDropFileDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_FILE_NAME,edit,1350631552

