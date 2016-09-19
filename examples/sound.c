

#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <basic.h>

#define SIMPLE_EFFECT(X) for (unsigned i = 0; i < 256; i++) beep(X, 0)

void PlayEffect(int c)
{
    switch (c) {
    case '0':
        SIMPLE_EFFECT(i | 170);
        break;
    case '1':
        SIMPLE_EFFECT((i >> 3) * i);
        break;
    case '2':
        SIMPLE_EFFECT(i * i << 1);
        break;
    case '3':
        SIMPLE_EFFECT(i & 223);
        break;
    case '4':
        SIMPLE_EFFECT((i << 1) & 87);
        break;
    case '5':
        SIMPLE_EFFECT(i * 87);
        break;
    case '6':
        SIMPLE_EFFECT((i << 3) ^ 170);
        break;
    case '7':
        SIMPLE_EFFECT(-i ^ 231);
        break;
    case '8':
        SIMPLE_EFFECT(i ^ 170);
        break;
    case '9':
        SIMPLE_EFFECT(i & 170);
        break;
    case 'Q':
        SIMPLE_EFFECT(-i << 1 & 180);
        break;
    case 'W':
        SIMPLE_EFFECT(-i << 1 & 99);
        break;
    case 'E':
        SIMPLE_EFFECT(-i & 180);
        break;
    case 'R':
        SIMPLE_EFFECT(i & 22 ^ 3);
        break;
    case 'T':
        SIMPLE_EFFECT(i ^ 24 * 8);
        break;
    case 'Y':
        SIMPLE_EFFECT(-i | 170 * (i >> (i & 3)));
        break;
    }
}

void PlayAll(void)
{
    char s[] = "0123456789QWERTY";
    for (;;) {
        for (int i = 0; i < strlen(s); i++) {
            CLS(i & 7);
            gotoxy(0, 7);
            cputs("      PLAYING ALL EFFECTS       ");
            cputs("     PRESS ANY KEY TO STOP      ");
            if (kbhit()) {
                getch();
                return;
            }
            PlayEffect(s[i]);
        }
    }
}

void PrintTitle(void)
{
    clrscr();
    cputs("     SOUND EFFECTS MACHINE\n");
    cputs("     ---------------------\n\n");
    cputs("KEYS 0-9,Q,W,E,R,T,Y FOR EFFECTS");
    cputs("PRESS A TO PLAY ALL");
}

int main(void)
{
    PrintTitle();
    for (;;) {
        int c = getch();
        if (c == 'A') {
            PlayAll();
            PrintTitle();
        } else {
            PlayEffect(c);
        }
    }
    return 0;
}

