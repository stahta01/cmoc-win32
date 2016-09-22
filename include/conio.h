
#ifndef _CONIO_H
#define _CONIO_H

#include <stdarg.h>

// Clear the whole screen and put the cursor into the top left corner
void clrscr(void);

// Return true if there's a key waiting, return false if not
unsigned char kbhit(void);

// Set the cursor to the specified X position, leave the Y position untouched
void gotox(int x);

// Set the cursor to the specified Y position, leave the X position untouched
void gotoy(int y);

// Set the cursor to the specified position
void gotoxy(int x, int y);

// Return the X position of the cursor
int wherex(void);

// Return the Y position of the cursor
int wherey(void);

// Output one character at the current cursor position
void cputc(int c);

// Same as "gotoxy (x, y); cputc (c);"
void cputcxy(int x, int y, int c);

// Output a NUL-terminated string at the current cursor position
void cputs(char* s);

// Same as "gotoxy (x, y); puts (s);"
void cputsxy(int x, int y, char* s);

// Like printf(), but uses direct screen output
int cprintf(char* fmt, ...);

// Like vprintf(), but uses direct screen output
int vcprintf(char* fmt, va_list args);

// Return a character from the keyboard. If there is no character available,
// the function waits until the user does press a key. If cursor is set to
// 1 (see below), a blinking cursor is displayed while waiting.
int cgetc(void);

// Like scanf(), but uses direct keyboard input
int cscanf(char* format, ...);

// Like vscanf(), but uses direct keyboard input
int vcscanf(char* format, va_list ap);

// If onoff is 1, a cursor is displayed when waiting for keyboard input. If
// onoff is 0, the cursor is hidden when waiting for keyboard input. The
// function returns the old cursor setting.
bool cursor(bool onoff);

// Enable/disable reverse character display. This may not be supported by
// the output device. Return the old setting.
bool revers(bool onoff);

// Set the color for text output. The old color setting is returned.
int textcolor(int color);

// Set the color for the background. The old color setting is returned.
int bgcolor(int color);

// Set the color for the border. The old color setting is returned.
int bordercolor(int color);

// Output a horizontal line with the given length starting at the current
// cursor position.
void chline(int length);

// Same as "gotoxy (x, y); chline (length);"
void chlinexy(int x, int y, int length);

// Output a vertical line with the given length at the current cursor
// position.
void cvline(int length);

// Same as "gotoxy (x, y); cvline (length);"
void cvlinexy(int x, int y, int length);


// Clear part of a line (write length spaces).
void cclear(int length);

// Same as "gotoxy (x, y); cclear (length);"
void cclearxy(int x, int y, int length);

// Return the current screen size.
void screensize(int* x, int* y);


// Non-standard. Added for CMOC

char* cgets(char* s);                           // Borland
int getch(void);                                // Borland
int getche(void);                               // Borland
int putch(int c);                               // Borland
int ungetch(int c);                             // Borland

void putdn(void);                               // CMOC
void putup(void);                               // CMOC
void putlt(void);                               // CMOC
void putrt(void);                               // CMOC
void putlf(void);                               // CMOC

void scrclr(void);                              // CMOC - Clear screen without moving cursor
void scrup(void);                               // CMOC

// Use _tsleep() from os9.h. delay is normally milliseconds, and has no stable standard.
//void delay(unsigned ticks);                     // CMOC (Ticks are 60hz on a CoCo. Check time.h)

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

void textmode2(int newmode, unsigned char* fontdata); // CMOC

#endif

