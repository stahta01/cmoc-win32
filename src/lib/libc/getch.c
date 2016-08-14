
#include <conio.h>

char inkey();

char last_key;

unsigned char kbhit()
{
    if (!last_key) {
        last_key = inkey();
    }
    return last_key ? 1 : 0;
}

char getch(void)
{
    char c;
    if (last_key) {
        c = last_key;
        last_key = 0;
    } else    {
        do {
            c = inkey();
        } while (!c);
    }
    return c;
}













