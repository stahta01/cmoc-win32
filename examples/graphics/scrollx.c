
//#pragma options -machine=cocous

#include <equates.h>
#include <stdlib.h>
#include <conio.h>
#include <memory.h>

#include <crypt/image.h>

#include "images/game128x96.c"

// These changes shouldn't effect a CoCo1/2. They setup GIME
// for a nicer looking PMODE1

void coco3_pmode1(void)
{
    _init0 &= 127;                                  // Enable CoCo3 GIME Modes
    _videomod = 130;                                // Enable graphics & 96 rows
    _videores = 9;                                  // Set 32 bytes per row & 4 colors
    _v_scroll = 0;
    *(word*)_V_OFSET1 = 0xe000 + (_beggrp >> 3);    // Point GIME to beggrp

    bordercolor(colorrgb(1,1,1));

    remappalette(0, colorrgb(0,0,0));
    remappalette(1, colorrgb(0,3,0));
    remappalette(2, colorrgb(1,0,0));
    remappalette(3, colorrgb(2,0,1));
}

int main(void)
{
    system("PMODE1,0");
    cputs("PLEASE WAIT ...");
    crypt_decode(&((crypt_image_t*)image1)->crypt, (void*)_beggrp, 0);
    system("SCREEN1,0");

    coco3_pmode1();

    byte* row;
    int y;
    while (true) {
        row = (byte*)_beggrp + (9 << 5);
        for (y = 0; y < 17; y++, row += 32) {
            // Scrolling by one bit, causes color blinking in 4 color mode.
            // Which looks cool for the evil aliens :-)
            memrol(row, row[0], 32);
        }
        row = (byte*)_beggrp + (43 << 5);
        for (y = 0; y < 15; y++, row += 32) {
            memrol2(row, row[0], 32);
        }
        row = (byte*)_beggrp + (80 << 5);
        for (y = 0; y < 9; y++, row += 32) {
            memror2(row, row[31], 32);
        }
    }
    return 0;
}

