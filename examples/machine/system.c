
#pragma target coco

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include <equates.h>

int main(void)
{
    system("PMODE4,1");
    system("PCLS0");
    system("SCREEN1,1");
    system("LINE(0,0)-(100,100),PSET");
    system("CIRCLE(128,96),50");

    _fretop = 0x2600;
    _strtab = _frespc = _memsiz = 0x2700;

    char s[100];

    putenv("A=COLOUR");
    putenvstr("B", "COMPUTER!");
    printf("A=%s\n", getenv("A"));
    printf("B=%s\n", getenv("B"));

    putenvuint("A", 30000);
    putenvuint("B", 20000);

    printf("A=%d\n", getenvuint("A"));
    printf("B=%d\n", getenvuint("B"));

    while (!kbhit()) {
    }

    system("PRINT \"END OF PROGRAM\"");

    return 0;
}

