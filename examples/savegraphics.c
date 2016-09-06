
#include <basic.h>
#include <conio.h>

int main(void)
{
    bgcolor(0);
    textmode(MODE_L0_16X12);
    MCLIP(0, 0, 256, 192);
    for (byte i = 0; i < 50; i += 6) {
        MELLIPSE(128,96, 80 + i, 20 + i, 2);
    }
    cprintf("Saving graphics to disk\n");
    SAVEM("PICTURE.IMG", (void*)_beggrp, (void*)_endgrp - 1, 0);
    PCLS(0);
    LOADM("PICTURE.IMG", 0);
    cprintf("\n\nGraphics Loaded\n");
    cprintf("Press any key\n");
    getch();
    textmode(MODE_T0_32X16);
    puts("BACK TO BASIC");
    return 0;
}

