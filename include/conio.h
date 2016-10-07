
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

#ifndef _CONIO_H
#define _CONIO_H

#include <stdarg.h>

bool cursor(bool onoff);
bool kbhit(void);
bool revers(bool onoff);
int bgcolor(int color);
int bordercolor(int color);
int cgetc(void);
int cprintf(char* fmt, ...);
int cprintfxy(int x, int y, char* fmt, ...);    // CMOC
int cscanf(char* fmt, ...);                     // TODO
int textcolor(int color);
int vcprintf(char* fmt, va_list args);
int vcscanf(char* fmt, va_list args);           // TODO

int wherex(void);
int wherey(void);
void wherexy(int* x, int* y);                   // CMOC
int whereat(void);                              // CMOC

void cclear(int len);
void cclearxy(int x, int y, int len);
void chline(int len);
void chlinexy(int x, int y, int len);
void clrscr(void);
void cputc(int chr);
void cputcxy(int x, int y, int chr);
void cputs(char* str);
void cputsxy(int x, int y, char* str);
void cvline(int len);                           // TODO
void cvlinexy(int x, int y, int len);

void gotox(int x);
void gotoxy(int x, int y);
void gotoy(int y);
void gotoat(int at);                            // CMOC

void screensize(int* x, int* y);

// Non-standard. Added for CMOC

char* cgets(char* str);                         // Borland
int getch(void);                                // Borland
int getche(void);                               // Borland
int putch(int chr);                             // Borland
int ungetch(int chr);                           // Borland
void _putstr(char* str);                        // CMOC

// Moves the cursor given a vt52 direction. ie: A,B,C or D

void cursormove(int vt52_char);                 // CMOC
void cedits(char* str, size_t size, char* eolchars, bool leaveatend);

void screenwipe(void);                          // CMOC - Wipe screen without moving cursor
void screenmove(int dir);                       // CMOC

// write functions use a micro version of sprintf

int vcwritef(char* fmt, va_list args);          // CMOC
int cwritef(char* fmt, ...);                    // CMOC

// 1 bit for the color set

#define MODE_CSS0           0
#define MODE_CSS1           1

// 3 bits for the resolution (Just incase we support CoCo3 modes)

#define MODE_TEXT           0
#define MODE_LRES           2
#define MODE_MRES           4
#define MODE_HRES           6

// 1 bit for font type. ie: packed or unpacked

#define MODE_FONT_UNPACK    0
#define MODE_FONT_PACKED    16

#define MODE_T0_32X16 (MODE_CSS0 | MODE_TEXT)
#define MODE_T1_32X16 (MODE_CSS1 | MODE_TEXT)

#define MODE_L0_16X12 (MODE_CSS0 | MODE_LRES)
#define MODE_L1_16X12 (MODE_CSS1 | MODE_LRES)

#define MODE_L0_32X12 (MODE_CSS0 | MODE_LRES | MODE_FONT_PACKED)
#define MODE_L1_32X12 (MODE_CSS1 | MODE_LRES | MODE_FONT_PACKED)

#define MODE_M0_16X24 (MODE_CSS0 | MODE_MRES)
#define MODE_M1_16X24 (MODE_CSS1 | MODE_MRES)

#define MODE_M0_32X24 (MODE_CSS0 | MODE_MRES | MODE_FONT_PACKED)
#define MODE_M1_32X24 (MODE_CSS1 | MODE_MRES | MODE_FONT_PACKED)

#define MODE_H0_32X24 (MODE_CSS0 | MODE_HRES)
#define MODE_H1_32X24 (MODE_CSS1 | MODE_HRES)

#define MODE_H0_64X24 (MODE_CSS0 | MODE_HRES | MODE_FONT_PACKED)
#define MODE_H1_64X24 (MODE_CSS1 | MODE_HRES | MODE_FONT_PACKED)

void textmode(int newmode);                     // Watcom

// You can save 2K by calling textmode2. textmode() refers to 2 fonts, when you
// may only need 1. Calling textmode2 with the font you need, will prevent the
// linker from adding the second, but, you must make sure you select a mode
// which matchs the font. ie: packed vs unpacked fonts.

void textmode2(int newmode, byte* fontdata);    // CMOC

void conio_uses_graph(void);                    // CMOC

#endif

