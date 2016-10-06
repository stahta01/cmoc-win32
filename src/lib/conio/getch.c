
#include "_conio.h"

int __bufferchar = 0;
byte __buffersize = 0;

int ungetch(int chr)
{
    if (__buffersize || chr < 0) {
        chr = EOF;
    } else {
        __bufferchar = chr;
        __buffersize = 1;
    }
    return chr;
}

bool kbhit(void)
{
    if (__buffersize == 0) {
        int chr = system_polcat();
        if (chr) {
            ungetch(chr);
        }
    }
    return __buffersize > 0;
}

int getch(void)
{
    int chr;
    if (__buffersize) {
        chr = __bufferchar;
        __buffersize = 0;
    } else    {
        if (_conio.cursor) {
            if (_is_coco3_mode) {
                chr = system_waitkey(true);
            } else {
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
                chr = getch();
                *curpos = curchr;
            }
        } else {
            chr = system_waitkey(false);
        }
    }
    return chr;
}

