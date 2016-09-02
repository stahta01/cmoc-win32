
/*****************************************************************************/
/*                                                                           */
/*                                  conio.h                                  */
/*                                                                           */
/*                            Direct console I/O                             */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 1998-2007 Ullrich von Bassewitz                                       */
/*               Roemerstrasse 52                                            */
/*               D-70794 Filderstadt                                         */
/* EMail:        uz@cc65.org                                                 */
/*                                                                           */
/*                                                                           */
/* This software is provided 'as-is', without any expressed or implied       */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.                                    */
/*                                                                           */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:                            */
/*                                                                           */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated but is not required.                                       */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.                      */
/* 3. This notice may not be removed or altered from any source              */
/*    distribution.                                                          */
/*                                                                           */
/*****************************************************************************/

// This is the direct console interface for cmoc. I do not like the function
// names very much, but the first version started as a rewrite of Borland's
// conio, and, even if the interface has changed, the names did not.
//
// The interface does direct screen I/O, so it is fast enough for most
// programs. I did not implement text windows, since many applications do
// not need them and should not pay for the additional overhead. It should
// be easy to add text windows on a higher level if needed,
//
// Most routines do not check the parameters. This may be unfortunate but is
// also related to speed. The coordinates are always 0/0 based.

#ifndef _CONIO_H
#define _CONIO_H

#include <stdarg.h>

// Clear the whole screen and put the cursor into the top left corner
void clrscr(void);

// Return true if there's a key waiting, return false if not
unsigned char kbhit(void);

// Set the cursor to the specified X position, leave the Y position untouched
void gotox(unsigned char x);

// Set the cursor to the specified Y position, leave the X position untouched
void gotoy(unsigned char y);

// Set the cursor to the specified position
void gotoxy(unsigned char x, unsigned char y);

// Return the X position of the cursor
unsigned char wherex(void);

// Return the Y position of the cursor
unsigned char wherey(void);

// Output one character at the current cursor position
void cputc(int c);

// Same as "gotoxy (x, y); cputc (c);"
void cputcxy(unsigned char x, unsigned char y, int c);

// Output a NUL-terminated string at the current cursor position
void cputs(const char* s);

// Same as "gotoxy (x, y); puts (s);"
void cputsxy(unsigned char x, unsigned char y, const char* s);

// Like printf(), but uses direct screen output
int cprintf(const char* format, ...);

// Like vprintf(), but uses direct screen output
int vcprintf(const char* format, va_list ap);

// Return a character from the keyboard. If there is no character available,
// the function waits until the user does press a key. If cursor is set to
// 1 (see below), a blinking cursor is displayed while waiting.
int cgetc(void);

// Like scanf(), but uses direct keyboard input
int cscanf(const char* format, ...);

// Like vscanf(), but uses direct keyboard input
int vcscanf(const char* format, va_list ap);

// If onoff is 1, a cursor is displayed when waiting for keyboard input. If
// onoff is 0, the cursor is hidden when waiting for keyboard input. The
// function returns the old cursor setting.
unsigned char cursor(unsigned char onoff);

// Enable/disable reverse character display. This may not be supported by
// the output device. Return the old setting.
unsigned char revers(unsigned char onoff);

// Set the color for text output. The old color setting is returned.
unsigned char textcolor(unsigned char color);

// Set the color for the background. The old color setting is returned.
unsigned char bgcolor(unsigned char color);

// Set the color for the border. The old color setting is returned.
unsigned char bordercolor(unsigned char color);

// Output a horizontal line with the given length starting at the current
// cursor position.
void chline(unsigned char length);

// Same as "gotoxy (x, y); chline (length);"
void chlinexy(unsigned char x, unsigned char y, unsigned char length);

// Output a vertical line with the given length at the current cursor
// position.
void cvline(unsigned char length);

// Same as "gotoxy (x, y); cvline (length);"
void cvlinexy(unsigned char x, unsigned char y, unsigned char length);


// Clear part of a line (write length spaces).
void cclear(unsigned char length);

// Same as "gotoxy (x, y); cclear (length);"
void cclearxy(unsigned char x, unsigned char y, unsigned char length);

// Return the current screen size.
void screensize(unsigned char* x, unsigned char* y);


// Non-standard. Added for CMOC

char* cgets(char* s);
int getch(void);
int getche(void);
int putch(int c);
int ungetch(int c);

extern int ungetch_buf;

void putdn(void);
void putup(void);
void putlt(void);
void putrt(void);
void putlf(void);

void scrclr(void);                      // Clear screen without moving cursor
void scrup(void);

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

void textmode(int newmode);

// You can save 2K by calling textmode2. textmode() refers to 2 fonts, when you
// may only need 1. Calling textmode2 with the font you need, will prevent the
// linker from adding the second, but, you must make sure you select a mode
// which matchs the font. ie: packed vs unpacked fonts.

void textmode2(int newmode, unsigned char* fontdata);

#endif

