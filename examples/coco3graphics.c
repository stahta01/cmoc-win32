
#include <basic.h>

int main(void)
{
    HSCREEN(2);

    HLINE_B(0, 0, 256, 100, 1);

    for (int i = 0; i < 200; i += 5) {
        HCIRCLE(i, 50, i >> 4);
    }
    while (!INKEY()) {

    }
    HSCREEN(0);
    return 0;
}

