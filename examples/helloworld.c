
#pragma target dragon

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <equates.h>

int main()
{
#ifdef __COCO__
    printf("HELLO COCO WORLD!\n");
#endif
#ifdef __DRAGON__
    printf("HELLO DRAGON WORLD!\n");
#endif
    beep(100, 2);
    beep(150, 1);
    beep(200, 1);
    return 0;
}

