
#pragma target coco

#include <conio.h>
#include <stdlib.h>
#include <system.h>

#include <equates.h>

int main(void)
{
//    clrscr();
    system("WIDTH40");

    for (;;)  {
        system_cputs("WELCOME TO...\r THE COLOR COMPUTER\r\r");
        cputs("OUTPUT WITH A NEW LINE INPUT\n");
        cputs("PRESS SHIFT+LEFT TO MOVE CURSOR BACK\n");
        char s[100];
        s[0] = 31;
        cgets(s);
        cputc('\n');
    }
    return 0;
}

