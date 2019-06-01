// Serial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void SendFile(char* fname); 
void SendFileName(char* fname); 
void Send(int s); 

void ReceiveFile(); 
void GetFileName(char* fname); 
int Receive(int port, int* g); 

void InitPort(int port, unsigned char param); 
void SendPort(int port, char c); 
int ReadPort(int port); 
int CheckState(int port); 

int main(int argc, char* argv[])
{
	printf("Hello World!\n");
    if(argc < 2)
    {
        printf("Please input R(eceive) or S(end) parameter:\n"); 
        exit(1); 
    }

    InitPort(PORT, 231); 
    if(argv[1] == "S")
        SendFile(argv[2]); 
    else if(argv[1] == "R")
        ReceiveFile(); 
    else 
    {
        printf("Error parameter. Please input again."); 
        exit(1); 
    }

	return 0;
}

void InitPort(int port, unsigned char param)
{
    union REGS reg; 
    reg.x.dx = port; 
    reg.h.ah = 0; 
    reg.h.al = param; 
    int86(0x14, &reg, &reg); 
}

void SendFile(char* fname)
{
    FILE* fp = fopen(fname, "rb"); 
    if(!fp)
    {
        printf("Can't open the file.\n"); 
        exit(1); 
    }

    SendFileName(fname); 
    int ch, s; 
    do
    {
        ch = (int)getc(fp); 
        if(ferror(fp))
        {
            printf("Error reading file.\n"); 
            break; 
        }

        s = ch % 16; 
        Send(s); 
        s = ch / 16; 
        Send(s); 
    }while(!feof(fp)); 

    s = 46; 
    Send(s); 
    Send(s); 
    fclose(fp);    
}

void SendFileName(char* fname)
{
    int s, ch; 
    printf("Now transmit the file. Please wait...\n"); 
    while(*fname)
    {
        ch = (int)fname++; 
        s = ch % 16; 
        Send(s); 
        s = ch / 16; 
        Send(s); 
    }

    s = 32; 
    Send(s); 
    Send(s); 
}

void Send(int s)
{
    SendPort(PORT, s); 
    int g = ReadPort(PORT); 
    if(s != g)
        s = s + 16; 

    do
    {
        SendPort(PORT, s); 
        g = ReadPort(PORT); 
    }while(s != g); 
}

void SendPort(int port, char c)
{
    union REGS reg; 
    reg.x.dx = port; 
    reg.h.al = c; 
    reg.h.ah = 1; 
    int86(0x14, &reg, &reg); 
    
    if(reg.h.ah & 128)
    {
        printf("Send mistakes!\n"); 
        exit(1); 
    }
}

void ReceiveFile()
{
    char fname[15]; 
    GetFileName(fname); 
    printf("Receiving file %s.\n", fname); 

    remove(fname); 
    FILE* fp = fopen(fname, "wb"); 
    if(!fp)
    {
        printf("Can't open output file.\n"); 
        exit(1); 
    }

    char ch; 
    int g1, g2, g3; 
    g1 = ReadPort(PORT); 
    g2 = Receive(PORT, &g1); 
    do
    {
        g3 = Receive(PORT, &g2); 
        ch = (char)(g1 % 16 + g2 * 16); 
        putc(ch, fp); 
        if(ferror(fp))
        {
            printf("Error writing file.\n"); 
            exit(1); 
        }
        
        g2 = Receive(PORT, &g3); 
        g1 = g3; 
    }while(g1 / 16 != 48); 

    printf("Transmit finished!\n"); 
    fclose(fp); 
}

void GetFileName(char* fname)
{
    char ch; 
    int g1, g2, g3; 
    g1 = ReadPort(PORT); 
    g2 = ReadPort(PORT); //g2 = Receive(PORT, &g1); 

    do
    {
        g3 = Receive(PORT, &g3);  //g3 = Receive(PORT, &g2); 
        ch = (char)(g1 % 16 + g2 / 16); //ch = (char)(g1 % 16 + g2 * 16); 
        *fname = ch; 
        *fname ++; 
        g2 = Receive(PORT, &g3); 
        g1 = g3; 
    }while(g1 / 16 != 32); 

    printf("File name transmit finished.\n"); 
}

int Receive(int port, int* g)
{
    SendPort(port, *g); 
    int gm = ReadPort(port); 
    if(gm / 16 == 0)
        return gm; 
    else if(gm / 16 == 1)
    {
        do 
        {
            *g = gm; 
            SendPort(port, gm); 
            gm = ReadPort(port); 
        }while(gm / 16 == 1); 
    }

    return gm; 
}

int ReadPort(int port)
{
    union REGS reg; 
    while(!(CheckState(port) & 256))
    {
        if(kbhit())
        {
            printf("Press any key to exit!"); 
            getch(); 
            exit(1); 
        }
    }

    reg.x.dx = port; 
    reg.h.ah = 2; 
    int86(0x14, &reg, &reg); 
    if(reg.h.ah & 128)
    {
        printf("Read mistake!\n"); 
        exit(1); 
    }

    return reg.h.al; 
}

int CheckState(int port)
{
    union REGS reg; 
    reg.x.dx = port; 
    reg.h.ah = 3; 
    int86(0x14, &reg, &reg); 
    return reg.x.ax; 
}