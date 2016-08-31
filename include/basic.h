
#ifndef _BASIC_H
#define _BASIC_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

#include <motorola/types.h>
// Use dragon equates to ensure we are compatible
#include <dragon/equates.h>
//#include <equates.h>

#define COLOR_BLACK       0
#define COLOR_GREEN       1
#define COLOR_YELLOW      2
#define COLOR_BLUE        3
#define COLOR_RED         4
#define COLOR_BUFF        5
#define COLOR_CYAN        6
#define COLOR_MAGENTA     7
#define COLOR_ORANGE      8

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} TRECT;

typedef struct {
    TRECT pclip, clip;
} _basic_t;

extern _basic_t _basic;

int ABS(int numeric);
byte PEEK(word addr);
void POKE(word addr, byte value);
void* VARPTR(char* s);
size_t INPUT(int f, char* s);

void SOUND(byte tone, byte duration);
byte JOYSTK(int j);
char INKEY(void);
word TIMER(void);

void CLS(byte c);
void SET(int x, int y, byte c);
int POINT(int x, int y);
void RESET(int x, int y);

// TODO: These should really be LLINE/LBOX etc. To fit in with V2

void SETLINE(int x1, int y1, int x2, int y2, byte c);
void SETBOX(int x1, int y1, int x2, int y2, byte c, bool fill);
void SETARC(int x, int y, int w, int h, int s, int e, byte c, bool fill);
void SETELLIPSE(int x, int y, int w, int h, byte c, bool fill);
void SETCIRCLE(int x, int y, int r, byte c, bool fill);

void SCREEN(int agr, int css);
void PMODE(int mode, int page);
int PCOPY(byte p1, byte p2);
void PSECT(int sect);

void PCLS(byte c);

void PSET(int x, int y, byte c);
void PSET1(int x, int y, byte c);
void PSET2(int x, int y, byte c);

byte PPOINT(int x, int y);
byte PPOINT1(int x, int y);
byte PPOINT2(int x, int y);

void PRESET(int x, int y);

void LINE(int x1, int y1, int x2, int y2, byte c);
void ARC(int x, int y, int w, int h, int s, int e, byte c);
void ELLIPSE(int x, int y, int w, int h, byte c);
void CIRCLE(int x, int y, int r, byte c);

void PAINT(int x, int y, byte c, byte b);

void CLIP(int x1, int y1, int x2, int y2);

bool LINECLIPPER(void);

// Bitmap functions

typedef struct {
    byte* data;
    word bytesperline, width, height;
    bool freememory;
} BITMAP;

BITMAP* BITMAPATTACH(word width, word height, byte* data, word bytesperline, bool freememory);
BITMAP* BITMAPCREATE(word width, word height);
void BITMAPFREE(BITMAP* bitmap);
void BITMAPCOPYRECT(BITMAP* dst, int x1, int y1, int x2, int y2, BITMAP* src,
                    int u1, int v1, int u2, int v2);
void BITMAPSTRETCH(BITMAP* dst, int x1, int y1, int x2, int y2, BITMAP* src);
void BITMAPDRAW(BITMAP* dst, int x, int y, BITMAP* src);

// Tape Functions

int CLOADM(char* fn, void* offset);
int CSAVEM(char* fn, void* start, void* finish, void* exec);

// Disk BASIC Functions

int PRINT(int fd, char* fmt, ...);
int BACKUP(byte dr);
int BACKUP2(byte dr1, byte dr2);
int DIR(byte dr);
int DSKINI(byte dr);
int DRIVE(byte dr);
int KILL(char* fn);
int LOADM(char* fn, void* offset);
int SAVEM(char* fn, void* start, void* finish, void* exec);
int COPY(char* fn1, char* fn2);
int UNLOAD(byte dr);
void CLOSE(int fd);
int VERIFY(byte onoff);
int VERIFY_ON(void);
int VERIFY_OFF(void);
int OPEN(char mode, int fd, char* fn, size_t len);
int OPEN_I(int fd, char* fn);
int OPEN_O(int fd, char* fn);
int OPEN_D(int fd, char* fn, size_t len);


// Extended Color BASIC Version 2 (CoCo 3)

void HSCREEN(int mode);
void HCIRCLE(int x, int y, int r);
void HCLS(int c);
void HCOLOR(int c1, int c2);
void HPAINT(int x, int y, int c, int b);
void HLINE(int x1, int y1, int x2, int y2, byte c);

// New V2 Commands

// PALETTE, PALETTE RGB, PALETTE CMP
// WIDTH, LOCATE, ATTR,
// BUTTON
// HDRAW
// HLINE
// HRESET
// HSET
// HPOINT
// HPRINT
// HBUFF
// HPUT HGET
// HSTAT
// ERLIN ERNO ONERR ONBRK

#endif

