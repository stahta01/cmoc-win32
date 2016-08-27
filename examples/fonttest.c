
#include <stdio.h>
#include <stdlib.h>

#include <equates.h>
#include <font.h>

unsigned char* fontdata;
unsigned char fontbase;
unsigned char fontpack;

void gputc(char c)
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

    gputs("DEREK EVANS WAS HERE");
//    puts("HELLO");
    return 0;
}

