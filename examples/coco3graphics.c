
#include <basic.h>

void LLINE(int x1, int y1, int x2, int y2, int mode, int shape)
{
    systemf("HLINE(%d,%d)-(%d,%d),%s,%s", x1, y1, x2, y2, mode, shape);
}

int main(void)
{
    HSCREEN(2);

    for (int i = 0; i < 200; i += 5) {
        HCIRCLE(i, 100, i >> 4);
    }
    while (!INKEY()) {

    }
    HSCREEN(0);
    return 0;
}

