
#ifndef _BASIC_H
#define _BASIC_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

#include <motorola/types.h>
#include <equates.h>

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
} TBASIC;

extern TBASIC _basic;

int ABS(int numeric);
byte PEEK(word addr);
void POKE(word addr, byte value);

void SOUND(byte tone, byte duration);
byte JOYSTK(int j);
char INKEY(void);
word TIMER(void);

void CLS(byte c);
void SET(int x, int y, byte c);
int POINT(int x, int y);
void RESET(int x, int y);

void SETLINE(int x1, int y1, int x2, int y2, byte c);
void SETBOX(int x1, int y1, int x2, int y2, byte c, bool fill);
void SETARC(int x, int y, int w, int h, int s, int e, byte c, bool fill);
void SETELLIPSE(int x, int y, int w, int h, byte c, bool fill);
void SETCIRCLE(int x, int y, int r, byte c, bool fill);

void SCREEN(int agr, int css);
void PMODE(int mode, int page);

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

void PCLIP(int x1, int y1, int x2, int y2);

bool LINECLIPPER(void);

// Internal use only

void _SET(void);

void _PSET1(void);
void _PSET2(void);

#define X  (*(int*)_HORDEF)
#define Y  (*(int*)_VERDEF)
#define C  _wcolor

#define X1 (*(int*)_HORBEG)
#define Y1 (*(int*)_VERBEG)
#define X2 (*(int*)_HOREND)
#define Y2 (*(int*)_VEREND)

#endif

