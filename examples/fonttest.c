
#pragma target dragon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(void)
{
    bgcolor(0);
    textmode(MODE_H1_32X24);
    char s[100];
    int i;
    for (;;) {
        for (i = 0; i < 20; i++) {
            gotox((unsigned char)i);
            sprintf(s, "HELLO THERE %d\n", wherex());
            cputs(s);
        }
        s[0] = 63;
        cgets(s);
        cputc('\n');
        printf("YOU ENTERED %s\n", s + 2);
    }
    return 0;
}

