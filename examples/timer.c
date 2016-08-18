
#include <basic.h>
#include <conio.h>

int main(void)
{
    char s[20];

    clrscr();

    cputs("PRESS ANY KEY TO EXIT");

    while (!kbhit()) {
        sprintf(s, "COCO TIMER=%d", TIMER());
        gotoxy((byte)((32 - strlen(s)) >> 1), 7);
        cputs(s);
    }
    return 0;
}


