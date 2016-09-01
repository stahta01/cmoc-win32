
#include "_conio.h"

int getch(void)
{
    int c;
    if (ungetch_buf) {
        c = ungetch_buf;
        ungetch_buf = 0;
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
            while (!kbhit()) {
                *curpos = (((unsigned char*)_TIMVAL)[1] - timer) & 16 ? curchr : curchr ^ curxor;
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

