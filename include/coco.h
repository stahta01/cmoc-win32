
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

#ifndef _COCO_H
#define _COCO_H

#include <motorola/types.h>
#include <coco/equates.h>

extern byte isCoCo3;
extern byte textScreenWidth;
extern byte textScreenHeight;

void newBasicProgram();
void warmStart();
void coldStart();
void setCaseFlag(byte upperCase);
byte inkey();
byte waitkey(byte blinkCursor);
void sound(byte tone, byte duration);
void setOutputDevice(sbyte deviceNum);
void setSAMRegisters(byte* samAddr, byte value, byte numBits);
void showGraphicsAddress(byte pageNum);
void showPmode4(byte colorset);
void showLowResTextAddress();
void showPmode0();
void initCoCoSupport();
void setHighSpeed(byte fast);
byte resetPalette(byte isRGB);
byte palette(byte slot, byte color);
void paletteRGB(byte slot, byte red, byte green, byte blue);
byte setBorderColor(byte color);
byte width(byte columns);
byte getTextMode();
void cls(byte color);
byte attr(byte foreColor, byte backColor, byte blink, byte underline);
byte locate(byte column, byte row);
byte hscreen(byte mode);
byte hset(word x, word y, byte color);
void pcls(byte* buffer, byte byteToClearWith);

#define setTimer(newValue) (* (word *) 0x112 = (newValue))
#define getTimer() (* (word *) 0x112)

#endif

