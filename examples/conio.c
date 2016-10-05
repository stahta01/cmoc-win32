
//#pragma options -machine=cocous

#include <conio.h>
#include <stdlib.h>
#include <system.h>
#include <exception.h>

#include <equates.h>
#include <vt52.h>

int main(void)
{
    clrscr();
    try system("WIDTH80"); except {}

    for (;;)  {
        cputs("WELCOME TO...\n THE COLOR COMPUTER\n\n");
        cputs("OUTPUT WITH A NEW LINE INPUT\n");
        cputs("PRESS SHIFT+LEFT TO MOVE CURSOR BACK\n");
        char s[100];
        s[0] = 32;
        cgets(s);
        cputc('\n');
    }
    return 0;
}

