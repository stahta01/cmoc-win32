
#include "_basic.h"

void SCREEN(int mode, int css)
{
    systemf("SCREEN%d,%d", mode, css);
}

