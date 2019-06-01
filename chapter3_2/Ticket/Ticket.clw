; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTicketDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ticket.h"

ClassCount=4
Class1=CTicketApp
Class2=CTicketDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TICKET_DIALOG

[CLS:CTicketApp]
Type=0
HeaderFile=Ticket.h
ImplementationFile=Ticket.cpp
Filter=N

[CLS:CTicketDlg]
Type=0
HeaderFile=TicketDlg.h
ImplementationFile=TicketDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=TicketDlg.h
ImplementationFile=TicketDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TICKET_DIALOG]
Type=1
Class=CTicketDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BUTTON_SELL,button,1342242816

