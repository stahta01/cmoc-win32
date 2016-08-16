
#include <basic.h>
#include <conio.h>

int main(void)
{
    clrscr();

    cputs("PRESS ANY KEY TO EXIT");

    while (!kbhit()) {
        gotoxy(14, 7);
        cprintf("%d", TIMER());
    }
    return 0;
}


