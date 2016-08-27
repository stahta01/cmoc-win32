
#include "_conio.h"

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
            unsigned char* curpos = (unsigned char*)_curpos;
            unsigned char curxor, curchr;
            if (isvidram()) {
                curchr = *curpos;
                curxor = 64;
            } else {
                curpos += ((unsigned)_horbyt << 3) - _horbyt;
                curchr = *curpos;
                curxor = _conio.fontpack ? _conio.fontbase & 128 ? 0xF : 0xF0 : 0xFF;
            }
            do {
                *curpos = (((unsigned char*)_TIMVAL)[1] - timer) & 16 ? curchr : curchr ^ curxor;
                c = inkey();
            } while (!c);
            *curpos = curchr;
        } else {
            do {
                c = inkey();
            } while (!c);
        }
    }
    return c;
}

