
#pragma target dragon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <basic.h>

int main(void)
{
    bgcolor(0);
    textmode(MODE_L0_32X12);
    CLIP(0, 0, 256, 192);
    char s[100];
    int i;
    for (;;) {
        for (i = 0; i < 10; i++) {
            gotox((unsigned char)i);
            sprintf(s, "Hello There %d,%d\n", wherex(), wherey());
            cputs(s);
        }
        s[0] = 63;
        cgets(s);
        cputc('\n');
        printf("You entered %s\n", s + 2);
        CIRCLE(150, 100, 50, 0);
    }
    return 0;
}

