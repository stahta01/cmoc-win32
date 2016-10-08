
#pragma options -machine=cocous

#include <equates.h>
#include <stdlib.h>
#include <conio.h>
#include <memory.h>

#include <crypt/image.h>

#include "images/game128x96.c"

int main(void)
{
    system("PMODE1,1");
    cputs("PLEASE WAIT ...");
    crypt_decode(&((crypt_image_t*)image1)->crypt, (void*)_beggrp, 0);
    system("SCREEN1,0");
    byte* row;
    int y;
    while (true) {
        row = (byte*)_beggrp + (9 << 5);
        for (y = 0; y < 17; y++, row += 32) {
            // Scrolling by one bit, causes color blinking in 2 color mode.
            // Which looks cool for the evil aliens :-)
            memrol(row, row[0], 32);
        }
        row = (byte*)_beggrp + (43 << 5);
        for (y = 0; y < 15; y++, row += 32) {
            memror2(row, row[31], 32);
        }
        row = (byte*)_beggrp + (80 << 5);
        for (y = 0; y < 9; y++, row += 32) {
            memrol2(row, row[0], 32);
        }
    }
    return 0;
}

