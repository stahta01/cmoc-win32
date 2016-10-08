
// This is a really silly demo of accessing the CoCo3's graphics RAM.

// Im not quite sure how the ROM graphics functions handle graphics RAM
// access, but, im pretty sure it wont work with CMOC programs. The reason
// being, ROM bank swaps RAM at $2000.

// Note, that doesn't stop you from calling ROM routines. It just stops you
// from writing your own graphics functions.

// The solution is to use libbank. Bank 12 contains the graphics pages.
// When you call bank_set(12), 32K of graphics RAM is made avaliable at $8000.
// So, thats where you draw your cool graphics.
// Always adhere to the bank_set() rules (ie: return the value bank_set gives you),
// and its all pretty easy. Use system("HSCREEN ?") to setup a graphics mode.
// Various palette variables are in coco/coco3.h

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include <charset.h>
#include <graph.h>
#include <bank.h>
#include <coco/coco3.h>

void ultra_small_string(char* s)
{
    struct _fontinfo* fi = _getfontinfo();

    bank_t bank = bank_set(12);
    for (char chr; chr = *s++;) {
        _outchar(chr);
        if (fi->base & 1) {
            if ((_curpos & 63) == 63) {
                _curpos += (80 * 8 + 16);
            }
            _curpos++;
        }
        fi->base ^= 1;
    }
    bank_set(bank);
}

int main(void)
{
    system("HSCREEN3");

    bordercolor(42);
    _remappalette(0, 0);

    _setcharset(1, 0, charset_atari_small);

    _beggrp = 0x8000;
    _endgrp = _beggrp + 15360;
    _curpos = _beggrp;

    for (int i = 0; i < 50; i++) {
        ultra_small_string("Ultra small text... PRESS A KEY TO EXIT");
        _remappalette(1, i);
    }
    while (!kbhit()) {
    }
    system("HSCREEN0:CLS");
    puts("BACK TO BASIC");
    return 0;
}

