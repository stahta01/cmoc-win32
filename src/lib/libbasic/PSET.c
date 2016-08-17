
#include <basic.h>

byte pset_set[8] = {128, 64, 32, 16, 8, 4, 2, 1};
byte pset_clr[8] = {127, 191, 223, 239, 247, 251, 253, 254};

void PSET(int x, int y, byte c)
{
    if (c) {
        *((byte*)_beggrp + (y * _horbyt) + (x >> 3)) |= pset_set[x & 7];
    } else {
        *((byte*)_beggrp + (y * _horbyt) + (x >> 3)) &= pset_clr[x & 7];
    }
}


