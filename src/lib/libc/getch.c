
#include <conio.h>
#include <equates.h>

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
        if (_conio.cursor) {
            unsigned char timer = ((unsigned char*)_TIMVAL)[1];
            unsigned char curchr = *(unsigned char*)_curpos;
            do {
                *(unsigned char*)_curpos = (((unsigned char*)_TIMVAL)[1] - timer) & 16 ? curchr : curchr ^ 64;
                c = inkey();
            } while (!c);
            *(unsigned char*)_curpos = curchr;
        } else {
            do {
                c = inkey();
            } while (!c);
        }
    }
    return c;
}

