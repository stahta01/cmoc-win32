
#pragma org $3600

#include <basic.h>

int main(void)
{
    PMODE(4, 1);
    SCREEN(1, 0);
    PCLS(0);
    for (byte radius = 1; radius <= 100; radius += 5) {
        CIRCLE(128, 96, radius, 1);
    }
    while (!INKEY()) {}

    return 0;
}

