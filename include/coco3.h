
/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

Derek John Evans <https://sourceforge.net/u/buzzphp/profile/>
*/

#ifndef _COCO3_H
#define _COCO3_H

#include <point.h>

// ADDITIONAL VARIABLES USED BY SUPER EXTENDED BASIC

typedef struct {
    word crsloc;                                // CURRENT LOCATION OF CURSOR
    byte cursx;                                 // X POSITION OF CURSOR
    byte cursy;                                 // Y POSITION OF CURSOR
    byte column;                                // COLUMNS ON HI-RES ALPHA SCREEN
    byte row;                                   // ROWS ON HI-RES ALPHA SCREEN
    word dispen;                                // END OF HI-RES DISPLAY SCREEN
    byte crsatt;                                // CURRENT CURSOR'S ATTRIBUTES
    byte unused;
    byte fcolor;                                // FOREGROUND COLOR
    byte bcolor;                                // BACKGROUND COLOR
    word onbrk;                                 // ON BRK GOTO LINE NUMBER
    word onerr;                                 // ON ERR GOTO LINE NUMBER
    byte error;                                 // ERROR NUMBER ENCOUNTERED OR $FF (NO ERROR)
    word onerrs;                                // ON ERR SOURCE LINE NUMBER
    word erline;                                // LINE NUMBER WHERE ERROR OCCURRED
    word onbrks;                                // ON BRK SOURCE LINE NUMBER
    byte errbrk;                                // STILL UNKNOWN, HAS TO DO WITH ERR, BRK
    byte pcount;                                // PRINT COUNT, CHARACTERS TO BE HPRINTED
    byte pbuf[7];                               // PRINT BUFFER, HPRINT CHARS. STORED HERE
} coco3_data_t;

coco3_data_t* coco3_data_enter(void);
void coco3_data_leave(void);

void coco3_screensize(int* x, int* y);

void coco3_gotox(int x);
void coco3_gotoy(int y);
void coco3_gotoxy(int x, int y);
void coco3_gotoat(int at);

int coco3_wherex(void);
int coco3_wherey(void);
void coco3_wherexy(point_t* point);
int coco3_whereat(void);

#endif

