
#include <basic.h>
#include <unistd.h>

int main(void)
{
    PMODE(1, 1);
    PCLS(0);
    SCREEN(1, 1);
    byte y = 0;
    for (byte x = 0; x <= 200; x += 10)
    {
        byte oy = y;
        y = 30 - oy;
        MLINE(x, 100 - y, x + 10, 100 - oy, 1);
    }
    while (!INKEY()) {}

    return 0;
}

