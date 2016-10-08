
#pragma options -machine=cocous

#include <bob.h>
#include <stdlib.h>
#include <conio.h>
#include <equates.h>

int main(void)
{
    bob_t screen;

    system("PMODE4,1:SCREEN1,1:PCLS0");

    _pmode = 3;

    system("CIRCLE(12,12),12,2");
    system("CIRCLE(12,12),9,3");
    system("CIRCLE(12,12),4,0");

    bob_init_beggrp(&screen);

    bob_t* bob = bob_create(4, 32);
    if (bob) {
        bob_drawrect(bob, 0, 0, &screen, 0, 0, 4, 32);
        for (int y = -10; y < 192; y += 24) {
            for (int x = -2; x < 32; x += 3) {
                bob_draw(&screen, x, y, bob);
            }
        }
        bob_free(bob);
    }
    return 0;
}

