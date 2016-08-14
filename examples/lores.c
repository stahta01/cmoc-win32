
#pragma target dragon

#include <stdio.h>
#include <basic.h>

int main()
{
    CLS(0);
    DRAWRECT(0, 0, 64, 32, 4);
    FILLRECT(2, 2, 62, 30, 7);
    DRAWELLIPSE(32, 16, 25, 12, 0);
    return 0;
}

