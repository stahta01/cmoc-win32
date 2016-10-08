
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>

int main(void)
{
    char s[20];
    clrscr();
    cputs("PRESS ANY KEY TO EXIT");
    while (!kbhit()) {
        clock_t t = clock();
        sprintf(s, "CLOCK: %d SECONDS (%d)", t / CLOCKS_PER_SEC, t);
        gotoxy((32 - strlen(s)) >> 1, 6);
        cputs(s);
    }
    return 0;
}

