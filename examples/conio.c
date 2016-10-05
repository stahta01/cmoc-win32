
#pragma target coco

#include <conio.h>
#include <stdlib.h>

int main(void)
{
//    clrscr();
system("WIDTH40");
    for (;;)  {
        cputs("WELCOME TO...\n THE COLOR COMPUTER\n\n");
        cputs("OUTPUT WITH A NEW LINE INPUT\n");
        cputs("PRESS SHIFT+LEFT TO MOVE CURSOR BACK\n");
        char s[100];
        s[0] = 31;
        cgets(s);
        cputc('\n');
    }

    return -1;
}

