
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <equates.h>
#include <font.h>

unsigned char* fontdata;
unsigned char fontbase;
unsigned char fontpack;

#define isvidram() (_curpos < 0x600 && _curpos >= 0x400)
#define isgrpram() (_curpos < _endgrp && _curpos >= _beggrp)

void putch(char c)
{
    unsigned char* dst = (unsigned char*)_curpos;
    unsigned char* src = fontdata + (((unsigned)c + fontbase) << 3);
    *dst ^= *src++;
    dst += 32;
    *dst ^= *src++;
    dst += 32;
    *dst ^= *src++;
    dst += 32;
    *dst ^= *src++;
    dst += 32;
    *dst ^= *src++;
    dst += 32;
    *dst ^= *src++;
    dst += 32;
    *dst ^= *src++;
    dst += 32;
    *dst ^= *src++;
    dst += 32;
    if (fontpack) {
        if (fontbase & 128) {
            _curpos++;
        }
        fontbase += 128;
    } else {
        _curpos++;
    }
}

void gputc(char c)
{
    switch (c) {
    case 8:
        //putlt();
        break;
    case 9:
        //putrt();
        break;
    case 10:
        putlf();
        break;
    default:
        putch(c);
        break;
    }
}

void gputs(char* s)
{
    while (*s) {
        gputc(*s++);
    }
}

int main(void)
{
    system("PMODE4,1");
    system("PCLS1");
    system("SCREEN1,0");

    _curpos = _beggrp;

    fontpack = 1;
    fontdata = font_atari_small;

    char s[100];
    int i;
    for (;;) {
        sprintf(s, "HELLO THERE %d\n", i++);
        gputs(s);
        gputs("DEREK EVANS WAS HERE\n");
    }
//    puts("HELLO");
    return 0;
}

