
#pragma target dragon

#include <basic.h>
#include <stdio.h>

int main(void)
{
    CLS(0);

    while (!INKEY()) {
        byte x = JOYSTK(0);
        byte y = JOYSTK(1);
        if ((PEEK(65280) & 1) == 0) {
            SET(x, y, 3);
        }
    }
    return 0;
}





