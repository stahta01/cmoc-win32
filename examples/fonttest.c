
// Note: This demo crashes XRoar, but works fine in Vcc.
// It looks like a bug in XRoar.

#pragma target coco

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <basic.h>
#include <fix6.h>

void cputs_center(char* s)
{
    int w, h;
    screensize(&w, &h);
    gotox((w - strlen(s)) >> 1);
    cputs(s);
    cputc('\n');
}

int main(void)
{
    int mode = MODE_L0_16X12;
    char s[100];
    int w, h;

    MCLIP(0, 0, 256, 192);

    for (;;) {
        bgcolor(0);
        textmode(mode);
        screensize(&w, &h);

        for (unsigned i = 0; i < 1024; i += 8) {
            gotox((sin6((char)i) >> 5) + (w >> 1));
            cputs("*<>*\n");
        }
        clrscr();

        cprintf("size=%dx%d\n", w, h);
        cputs_center("Welcome to");
        cputs_center("CMOC CONIO");
        cputs_center("1) 32x16t");
        cputs_center("2) 16x12u");
        cputs_center("3) 32x12p");
        cputs_center("4) 16x24u");
        cputs_center("5) 32x24p");
        cputs_center("6) 32x24u");
        cputs_center("7) 64x24p");
        cputs_center("X) EXIT  ");
        cputs("Enter: ");
        s[0] = 80;
        cgets(s);
        switch (s[2]) {
        case '1':
            mode = MODE_T0_32X16;
            break;
        case '2':
            mode = MODE_L0_16X12;
            break;
        case '3':
            mode = MODE_L0_32X12;
            break;
        case '4':
            mode = MODE_M0_16X24;
            break;
        case '5':
            mode = MODE_M0_32X24;
            break;
        case '6':
            mode = MODE_H0_32X24;
            break;
        case '7':
            mode = MODE_H0_64X24;
            break;
        case 'X':
            textmode(MODE_T0_32X16);
            cputs("RETURN TO BASIC\n");
            exit(0);
        }
    }
    return 0;
}

