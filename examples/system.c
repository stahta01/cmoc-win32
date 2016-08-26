
// This is a sandbox file for the new system commands.

#pragma target dragon

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include <equates.h>

int main(void)
{
    system("PMODE 4,1");
    system("PCLS 0");
    system("SCREEN 1,1");
    system("LINE(0,0)-(100,100),PSET");
    system("CIRCLE(128,96),50");

    _fretop = 0x2600;
    _strtab = _frespc = _memsiz = 0x2700;

    char s[100];

    setstr("A", "DEREK");
    setstr("B", "EVANS");
    puts(getstr("A"));
    puts(getstr("B"));

    setuint("A", 30000);
    printf("A=%d\n", getuint("A"));
    printf("A=%d\n", getuint("A"));
    while (!kbhit()) {
    }
    puts("END OF PROGRAM");
    return 0;
}

