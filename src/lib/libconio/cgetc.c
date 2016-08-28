
#include <conio.h>

unsigned char show_cursor = 1;

unsigned char cursor(unsigned char onoff)
{
    unsigned char result = show_cursor;
    show_cursor = onoff;
    return result;
}

char cgetc(void)
{
    if (!show_cursor) {
        while (!kbhit()) {}
    }
    return getch();
}

