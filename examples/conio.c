
#include <conio.h>
#include <stdlib.h>
#include <system.h>
#include <graph.h>
#include <memory.h>

#include <coco/coco3.h>
#include <coco/super.h>

//#pragma options -machine=cocous

int main(void)
{
    system("WIDTH40");

    bgcolor(0);                                 // palette pen = 0
    textcolor(0);                               // palette pen = 8
    // CoCo3 palettes are 16 bytes. The first 8 are used by bgcolor().
    // The second 8 are used by textcolor()
    // palettes contain rgb information. 2 bits each. ie: values 0..3
    remappalette(0, palettecolor(2, 0, 1));
    remappalette(8, palettecolor(3, 3, 0));

    // bordercolor() accepts a palettecolor(). ie: it doesn't map to the palette via a pen.
    bordercolor(palettecolor(1, 0, 1));

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

