
// This is a very basic example of the new mob library. A mob is 4 bobs (byte objects).
// The idea is, you init a bob from the screen (or other memory), and then create
// a mob, which will make 4 copies of the bob. 3 will be bit shifted by 2, 4, & 6 bits.
// The bob must therefore be 1 byte wider than you require. So, a 24x24 image needs
// a src bob of 4 bytes by 24 rows.

// For this example, I've made the src bob higher than need be, because im not using
// double buffering. I just draw the bobs over the old bobs.

// Bob's currently dont support masking, so you cant have overlapping mobs.

// And... they might never support masking, because mask drawing in C is never
// going to cut the mustard.
// What I will be doing is, writing a mob compiler, which will create the 6809 code
// required to swap a bob with the screen. The code will contain the bob data, so,
// after a bob is compiled, it can be freed.

// Anyway, thats a few weeks away. Until then, here is a bouncing red ball for you
// to play with...

#include <stdlib.h>
#include <equates.h>
#include <mob.h>

int main(void)
{
    system("PMODE3,1:PCLS3:CIRCLE(12,12),11,0:PAINT(12,12),2,0");

    bob_t bob;
    bob_init(&bob, 4, 28, 32, (void*)_beggrp, false);
    mob_t* mob = mob_create(&bob);

    system("PCLS3:SCREEN1,0");

    bob_init(&bob, 32, 192, 32, (void*)_beggrp, false);

    int x = 0, y = 60 << 6, xx = 40, yy = 14;

    for (;;) {
        x += xx;
        if (x < 0 || x > (115 << 6)) {
            x += xx = -xx;
        }
        y += yy += 1;
        if (y < 0 || y > (170 << 6)) {
            y += yy = -yy;
        }
        mob_memcpy_unpack(mob, x >> 6, y >> 6, &bob);
    }
    return 0;
}

