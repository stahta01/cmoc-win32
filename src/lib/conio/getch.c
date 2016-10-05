
#include "_conio.h"

int __bufferchar = 0;
byte __buffersize = 0;

int ungetch(int c)
{
    if (__buffersize || c < 0) {
        c = EOF;
    } else {
        __bufferchar = c;
        __buffersize = 1;
    }
    return c;
}

bool kbhit()
{
    if (__buffersize == 0) {
        int c = system_polcat();
        if (c) {
            ungetch(c);
        }
    }
    return __buffersize > 0;
}

int getch(void)
{
    int c;
    if (__buffersize) {
        c = __bufferchar;
        __buffersize = 0;
    } else    {
        if (_conio.cursor) {
            clock_t clock_now = clock();
            byte* curpos = (byte*)_curpos;
            byte curxor, curchr;
            if (isvidram()) {
                curchr = *curpos;
                curxor = 64;
            } else {
                if (_conio.getfontinfo) {
                    struct _fontinfo* fi = (struct _fontinfo*)_conio.getfontinfo();
                    curpos += ((word)_horbyt << 3) - _horbyt;
                    curchr = *curpos;
                    curxor = fi->type ? fi->base & 1 ? 0xF : 0xF0 : 0xFF;
                }
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
