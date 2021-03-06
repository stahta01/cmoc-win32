
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

#ifndef _BASIC_H
#define _BASIC_H

#include <sys/size.h>

#define COLOR_BLACK       0
#define COLOR_GREEN       1
#define COLOR_YELLOW      2
#define COLOR_BLUE        3
#define COLOR_RED         4
#define COLOR_BUFF        5
#define COLOR_CYAN        6
#define COLOR_MAGENTA     7
#define COLOR_ORANGE      8

// Color BASIC

int ABS(int numeric);
byte PEEK(word addr);
void POKE(word addr, word value);
void* VARPTR(char* s);
size_t INPUT(int f, char* s);

void SOUND(int tone, int duration);
byte JOYSTK(int j);
int INKEY(void);
word TIMER(void);

void CLS(int c);
void COLOR(int c1, int c2);
void SET(int x, int y, int c);
void RESET(int x, int y);

// Extended Color BASIC V1

void SCREEN(int mode, int css);
void PMODE(int mode, int page);
void PCOPY(int p1, int p2);
void PCLS(int c);
void PAINT(int x, int y, int c, int b);
void LINE(int x1, int y1, int x2, int y2, int onoff);
void LINE_B(int x1, int y1, int x2, int y2, int onoff);
void LINE_BF(int x1, int y1, int x2, int y2, int onoff);

// Tape Functions

int CLOADM(char* fn, word offset);
int CSAVEM(char* fn, void* start, void* finish, void* exec);

// Disk BASIC Functions

int PRINT(int fd, char* fmt, ...);
int BACKUP(int dr);
int BACKUP2(int dr1, int dr2);
int DIR(int dr);
int DSKINI(int dr);
int DRIVE(int dr);
int KILL(char* fn);
int LOADM(char* fn, word offset);
int SAVEM(char* fn, void* start, void* finish, void* exec);
int COPY(char* fn1, char* fn2);
int UNLOAD(int dr);
void CLOSE(int fd);
int VERIFY(int onoff);
int VERIFY_ON(void);
int VERIFY_OFF(void);
int OPEN(char mode, int fd, char* fn, size_t len);
int OPEN_I(int fd, char* fn);
int OPEN_O(int fd, char* fn);
int OPEN_D(int fd, char* fn, size_t len);


// Super Extended Color BASIC (CoCo 3)

void HSCREEN(int mode);
void HCIRCLE(int x, int y, int r);
void HCLS(int c);
void HCOLOR(int c1, int c2);
void HPAINT(int x, int y, int c, int b);
void HLINE(int x1, int y1, int x2, int y2, int onoff);
void HLINE_B(int x1, int y1, int x2, int y2, int onoff);
void HLINE_BF(int x1, int y1, int x2, int y2, int onoff);

// New V2 Commands (TODO)

// PALETTE, PALETTE RGB, PALETTE CMP
// WIDTH, LOCATE, ATTR,
// BUTTON
// HDRAW
// HRESET
// HSET
// HPOINT
// HPRINT
// HBUFF
// HPUT HGET
// HSTAT
// ERLIN ERNO ONERR ONBRK

// New lores functions written in C

void LSET(int x, int y, int c);
int LPOINT(int x, int y);
void LRESET(int x, int y);
void LLINE(int x1, int y1, int x2, int y2, int c);
void LLINE_B(int x1, int y1, int x2, int y2, int c);
void LLINE_BF(int x1, int y1, int x2, int y2, int c);
void LARC(int x, int y, int w, int h, int s, int e, int c);
void LELLIPSE(int x, int y, int w, int h, int c);
void LCIRCLE(int x, int y, int r, int c);

// New medium resolution functions written in C

void MSET(int x, int y, byte c);
void MSET1(int x, int y, byte c);
void MSET2(int x, int y, byte c);
byte MPOINT(int x, int y);
byte MPOINT1(int x, int y);
byte MPOINT2(int x, int y);
void MRESET(int x, int y);
void MLINE(int x1, int y1, int x2, int y2, byte c);
void MARC(int x, int y, int w, int h, int s, int e, byte c);
void MELLIPSE(int x, int y, int w, int h, byte c);
void MCIRCLE(int x, int y, int r, byte c);
void MCLIP(int x1, int y1, int x2, int y2);

#endif

