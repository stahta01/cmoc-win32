
#pragma target coco

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
#ifdef __COCO__
    printf("HELLO COCO WORLD!\n");
#endif
#ifdef __DRAGON__
    printf("HELLO DRAGON WORLD!\n");
#endif
    _beep(200, 1);
    _beep(100, 2);
    _beep(150, 1);
    _beep(200, 1);
    return 0;
}

