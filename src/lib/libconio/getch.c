
#include "_conio.h"
#include <time.h>

int getch(void)
{
    int c;
    if (ungetch_buf) {
        c = ungetch_buf;
        ungetch_buf = 0;
    } else    {
        if (_conio.cursor) {
            clock_t clock_now = clock();
            unsigned char* curpos = (unsigned char*)_curpos;
            unsigned char curxor, curchr;
            if (isvidram()) {
                curchr = *curpos;
                curxor = 64;
            } else {
                struct _fontinfo* fi = _getfontinfo();

                curpos += ((unsigned)_horbyt << 3) - _horbyt;
                curchr = *curpos;
                curxor = fi->type ? fi->base & 128 ? 0xF : 0xF0 : 0xFF;
            }
            while (!kbhit()) {
                *curpos = (clock() - clock_now) & 16 ? curchr : curchr ^ curxor;
            }
            c = getch();
            *curpos = curchr;
        } else {
            while (!kbhit()) { }
            c = getch();
        }
    }
    return c;
}

