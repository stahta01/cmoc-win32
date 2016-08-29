
#ifndef _COCO_H
#define _COCO_H

#include <motorola/types.h>
#include <coco/equates.h>

#define DEV_SCREEN      ( 0)
#define DEV_CASSETTE    (-1)
#define DEV_SERIAL      (-2)
#define DEV_PRINTER     DEV_SERIAL

#define ROM_OPEN        [$015E]
#define ROM_INPUT       $A390
#define ROM_POLCAT      [$A000]
#define ROM_CHROUT      [$A002]
#define ROM_CSRDON      [$A004]
#define ROM_BLKIN       [$A006]
#define ROM_BLKOUT      [$A008]
#define ROM_JOYIN       [$A00A]
#define ROM_WRTLDR      [$A00C]
#define ROM_INTCNV      [$B3ED]
#define ROM_GIVABF      [$B4F4]

#define ROM_DSKCON      [$C004]
#define ROM_INKEY       $A1B1
#define ROM_CLRSCN2     $A91C
#define ROM_CLRSCN      $A928
#define ROM_DISPL       $B99C

extern byte isCoCo3;
extern byte textScreenWidth;
extern byte textScreenHeight;

void newBasicProgram();
void warmStart();
void coldStart();
void setCaseFlag(byte upperCase);
byte asm inkey();
byte waitkey(byte blinkCursor);
void sound(byte tone, byte duration);
void asm setOutputDevice(sbyte deviceNum);
void setSAMRegisters(byte* samAddr, byte value, byte numBits);
void showGraphicsAddress(byte pageNum);
void showPmode4(byte colorset);
void showLowResTextAddress();
void asm showPmode0();
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
void sleep(int seconds);

// newValue: word value.
//
#define setTimer(newValue) (* (word *) 0x112 = (newValue))

// Returns a word.
//
#define getTimer() (* (word *) 0x112)

#endif // _COCO_H





