
#pragma org $3600

#include <basic.h>
#include <unistd.h>

int main(void)
{
    // For some reason, xroar will crash when we autorun.
    // A delay fixes it. Hopefully they fix xroar.
    sleep(1);

    PMODE(4, 1);
    SCREEN(1, 0);
    PCLS(0);
    for (byte radius = 1; radius <= 100; radius += 5) {
        CIRCLE(128, 96, radius, 1);
    }
    while (!INKEY()) {}

    return 0;
}

