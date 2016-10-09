
//#pragma options -machine=cocous

#include <conio.h>
#include <stdlib.h>
#include <bob.h>
#include <equates.h>

#include <crypt/image.h>

#include "../images/game128x96.c"

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

    bob_t cmoc, land, aliens;

    bob_init(&cmoc, 30, 9, 32, (void*)(_beggrp + (80 << 5) + 1), false);
    bob_init(&land, 32, 15, 32, (void*)(_beggrp + (43 << 5)), false);
    bob_init(&aliens, 32, 17, 32, (void*)(_beggrp + (9 << 5)), false);

    while (true) {
        // Scrolling by one bit, causes color blinking in 4 color mode.
        // Which looks cool for the evil aliens :-)
        bob_rol(&aliens);
        bob_rol2(&land);
        bob_ror2(&cmoc);
    }
    return 0;
}

