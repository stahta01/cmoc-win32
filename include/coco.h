
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

extern byte isCoCo3;
extern byte textScreenWidth;
extern byte textScreenHeight;

void _newBasicProgram(void);
void _warmStart(void);
void _coldStart(void);
void _setCaseFlag(byte upperCase);
byte _inkey(void);
byte _waitkey(byte blinkCursor);
void _sound(byte tone, byte duration);
void _setOutputDevice(sbyte deviceNum);
void _setSAMRegisters(byte* samAddr, byte value, byte numBits);
void _showGraphicsAddress(byte pageNum);
void _showPmode4(byte colorset);
void _showLowResTextAddress(void);
void _showPmode0(void);
void _initCoCoSupport(void);
void _setHighSpeed(byte fast);
byte _resetPalette(byte isRGB);
byte _palette(byte slot, byte color);
void _paletteRGB(byte slot, byte red, byte green, byte blue);
byte _setBorderColor(byte color);
byte _width(byte columns);
byte _getTextMode(void);
void _cls(byte color);
byte _attr(byte foreColor, byte backColor, byte blink, byte underline);
byte _locate(byte column, byte row);
byte _hscreen(byte mode);
byte _hset(word x, word y, byte color);
void _pcls(byte* buffer, byte byteToClearWith);

#define _setTimer(newValue) (*(word*)0x112=(newValue))
#define _getTimer()         (*(word*)0x112)

#endif

