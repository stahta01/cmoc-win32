
#include <basic.h>

void SCREEN(int agr, int css)
{
    if (agr) {
        POKE(0xff22, PEEK(0xff22) | 128);
    } else {
        POKE(0xff22, PEEK(0xff22) & 127);
    }
    if (css) {
        POKE(0xff22, PEEK(0xff22) | 8);
    } else {
        POKE(0xff22, PEEK(0xff22) & 247);
    }
}



