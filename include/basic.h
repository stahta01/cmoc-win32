
#ifndef _BASIC_H
#define _BASIC_H

#include <6809.h>
#include <dragon/equates.h>

int ABS(int numeric);
void CLS(byte c);
void SOUND(byte tone, byte duration);
void SET(byte x, byte y, byte c);
sbyte POINT(byte x, byte y);
void RESET(byte x, byte y);
void DRAWLINE(int x1, int y1, int x2, int y2, byte c);
void DRAWRECT(byte x1, byte y1, byte x2, byte y2, byte c);
void FILLRECT(byte x1, byte y1, byte x2, byte y2, byte c);
void DRAWARC(byte x, byte y, int w, int h, int s, int e, byte c);
void DRAWELLIPSE(byte x, byte y, int w, int h, byte c);
byte JOYSTK(int j);
char INKEY(void);
word TIMER(void);

#define PEEK(X) (*(byte*)(X))
#define POKE(X,Y) (PEEK(X)=(byte)(Y))

#endif

