
#pragma target dragon

#include <stdio.h>
#include <basic.h>

int main()
{
    CLS(0);
    return 0;
    DRAWRECT(0, 0, 63, 31, 4);
    FILLRECT(2, 2, 61, 29, 3);
    DRAWELLIPSE(32, 16, 25, 13, 0);
    FILLRECT(14, 10, 49, 21, 1);
    DRAWRECT(14, 10, 49, 21, 0);
    return 0;
}


