
#ifndef _BASIC_H
#define _BASIC_H

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
void CLS(byte c);
void SOUND(byte tone, byte duration);
void SET(int x, int y, byte c);
int POINT(int x, int y);
void RESET(int x, int y);
void LINE(int x1, int y1, int x2, int y2, byte c);
void RECT(int x1, int y1, int x2, int y2, byte c);
void FILLRECT(int x1, int y1, int x2, int y2, byte c);
void ARC(int x, int y, int w, int h, int s, int e, byte c);
void ELLIPSE(int x, int y, int w, int h, byte c);
byte JOYSTK(int j);
char INKEY(void);
word TIMER(void);

void PCLS(byte c);
void PSET(int x, int y, byte c);
void PRESET(int x, int y);
void PLINE(int x1, int y1, int x2, int y2, byte c);
void PARC(int x, int y, int w, int h, int s, int e, byte c);
void PELLIPSE(int x, int y, int w, int h, byte c);
void PCLIP(int x1, int y1, int x2, int y2);

#define PEEK(X) (*(byte*)(X))
#define POKE(X,Y) (PEEK(X)=(byte)(Y))

// Internal use only

void _SET(void);

void _PSET2(void);
void _PSET4(void);

#define X  (*(int*)_HORDEF)
#define Y  (*(int*)_VERDEF)
#define C  _wcolor

#define X1 (*(int*)_HORBEG)
#define Y1 (*(int*)_VERBEG)
#define X2 (*(int*)_HOREND)
#define Y2 (*(int*)_VEREND)

#define CLIP(a,b,w,h,lo,hi)if(a<lo){b+=(h)*(lo-a)/(w);a=lo;}else if(a>hi){b+=(h)*(hi-a)/(w);a=hi;}

#endif

