
#include "_conio.h"

// textmode() refers to two charset's. Therefore, they both will be linked into your
// binary. If you only need one, use textmode2(), but, you need to provide the
// correct font type. ie: packed or unpacked.

void textmode(int newmode)
{
    textmode2(newmode, newmode & MODE_FONT_PACKED ? charset_atari_small : charset_c64);
}

