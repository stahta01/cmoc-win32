
#include <conio.h>
#include <stdlib.h>
#include <system.h>
#include <memory.h>

#include <coco/coco3.h>
#include <coco/super.h>

//#pragma options -machine=cocous

int main(void)
{
    system("WIDTH40");

    _h_crsatt = (3<<3)|2;
    bordercolor(0x88);

    clrscr();

    for (;;)  {
        cputs("WELCOME TO...\n THE COLOR COMPUTER\n\n");
        cputs("OUTPUT WITH A NEW LINE INPUT\n");
        cputs("PRESS SHIFT+LEFT TO MOVE CURSOR BACK\n");
        char s[100];
        s[0] = 80;
        cgets(s);
        cputc('\n');
    }
    return 0;
}

