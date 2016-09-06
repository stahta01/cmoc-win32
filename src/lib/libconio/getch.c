
#include "_conio.h"

int __bufferchar = 0;
unsigned char __buffersize = 0;

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

unsigned char kbhit()
{
    if (__buffersize == 0) {
        unsigned char c;
        asm {
            jsr     [$a000] // POLCAT is always from the keyboard
            sta     c
        }
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

