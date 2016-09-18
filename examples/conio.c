
#pragma target coco

#include <conio.h>

int main(void)
{
    clrscr();

    for (;;)  {
        cputs("WELCOME TO...\n THE COLOR COMPUTER\n\n");
        cputs("CONIO NOW HAS TRUE CONSOLE\n");
        cputs("OUTPUT WITH A NEW LINE INPUT\n");
        cputs("PRESS SHIFT+LEFT TO MOVE CURSOR BACK\n");
        char s[100];

        s[0] = 31;
        cgets(s);
        cputc('\n');
    }

    return -1;
}

