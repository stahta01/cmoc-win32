
#pragma target coco

#include <stdio.h>
#include <basic.h>

int main()
{
    CLS(0);
    SETBOX(0, 0, 63, 31, 4, false);
    SETBOX(2, 2, 61, 29, 3, true);
    SETELLIPSE(32, 16, 25, 13, 0, false);
    SETBOX(14, 10, 49, 21, 1, true);
    SETBOX(14, 10, 49, 21, 0, false);
    return 0;
}


