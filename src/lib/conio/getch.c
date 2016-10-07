
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
    if (!__buffersize) {
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
                clock_t clock_now = clock();
                bank_t bank = bank_set(13);
                byte* curpos = (byte*)_h_crsloc + 0xa001;
                byte curchr = *curpos;
                int kb;
                do {
                    *curpos = (clock() - clock_now) & 16 ? curchr : curchr ^ 64;
                    bank = bank_set(bank);
                    kb = kbhit();
                    bank = bank_set(bank);
                } while (!kb);
                *curpos = curchr;
                bank_set(bank);
                chr = getch();
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
                        curxor = fi->packed ? fi->base & 1 ? 0xF : 0xF0 : 0xFF;
                    }
                }
                while (!kbhit()) {
                    *curpos = (clock() - clock_now) & 16 ? curchr : curchr ^ curxor;
                }
                *curpos = curchr;
                chr = getch();
            }
        } else {
            while (!kbhit());
            chr = getch();
        }
    }
    return chr;
}

