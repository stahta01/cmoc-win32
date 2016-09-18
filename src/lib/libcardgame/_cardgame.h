
/*  cardgame.h - PMODE 4 playing cards library for the CoCo.
    Assumes Disk Basic, i.e., the PMODE 4 screen starts at $0E00.

    By Pierre Sarrazin <http://sarrazip.com/>.
    This file is in the public domain.

    Version 0.1.0 - 2015-08-12 - First public release.
    Version 0.1.1 - 2016-03-12 - New #defines. New function drawFaceDownCard().
    Version 0.1.2 - 2016-??-?? - setConsoleOutHook() and resetConsoleOutHook()
                                 now taken from <coco.h>.
*/

#include <coco.h>
#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <cardgame.h>

#define NDEBUG

#ifndef NDEBUG
void _restoreOriginalTextMode();
#define assertf(cond, ...) do { if (!(cond)) { \
            _restoreOriginalTextMode(); \
            printf("***ASSERT FAILED (%s): %u: %s: ", __TIME__, __LINE__, #cond); \
            printf(__VA_ARGS__); putchar('\n'); \
            for (;;); } } while (0)
#else
#define assertf(cond, ...) ((void) 0)
#endif

// Standard addresses of 6k PMODE 4 screens. Must be divisible by 512.
// To be put in scrnBuffer.
#define PMODE4_PAGE0            0x0E00
#define PMODE4_PAGE1            (PMODE4_PAGE0 + BYTES_PER_SCREEN)

#define WORDS_PER_SCREEN_ROW    16
#define BYTES_PER_SCREEN_ROW    32
#define TEXT_COLS_PER_ROW       32
#define TEXT_ROWS_PER_SCREEN    24
#define PIXEL_ROWS_PER_SCREEN   192
#define BYTES_PER_SCREEN        0x1800          // 256 * 192 / 8 == 6144 == 6 kB
#define PIXEL_ROWS_PER_GLYPH    7               // see 8-bit-wide-font.h
#define PIXEL_ROWS_PER_TEXT_ROW 8               // PIXEL_ROWS_PER_GLYPH plus one separator row
#define BYTES_PER_TEXT_ROW      256             // 32 bytes per row of pixels, 8 rows of pixels per text row

#define ROWS_ABOVE_SUIT 2
#define ROWS_BELOW_SUIT 6
#define ROWS_PER_CARD_TOP 5
#define ROWS_PER_CARD_BOTTOM ROWS_PER_CARD_TOP
#define BYTES_PER_CARD_WIDTH 4
#define ROWS_PER_CARD_VALUE 10
#define ROWS_PER_SUIT 7

extern byte* scrnBuffer;                        // 1st PMODE 4 buffer

extern unsigned short redCard_1[10];
extern unsigned short redCard_2[10];
extern unsigned short redCard_3[10];
extern unsigned short redCard_4[10];
extern unsigned short redCard_5[10];
extern unsigned short redCard_6[10];
extern unsigned short redCard_7[10];
extern unsigned short redCard_8[10];
extern unsigned short redCard_9[10];
extern unsigned short redCard_10[10];
extern unsigned short redCard_11[10];
extern unsigned short redCard_12[10];
extern unsigned short redCard_13[10];
extern unsigned short blackCard_1[10];
extern unsigned short blackCard_2[10];
extern unsigned short blackCard_3[10];
extern unsigned short blackCard_4[10];
extern unsigned short blackCard_5[10];
extern unsigned short blackCard_6[10];
extern unsigned short blackCard_7[10];
extern unsigned short blackCard_8[10];
extern unsigned short blackCard_9[10];
extern unsigned short blackCard_10[10];
extern unsigned short blackCard_11[10];
extern unsigned short blackCard_12[10];
extern unsigned short blackCard_13[10];
extern unsigned short* redCards[13];
extern unsigned short* blackCards[13];
extern unsigned short suit_hearts[7];
extern unsigned short suit_spades[7];
extern unsigned short suit_diamonds[7];
extern unsigned short suit_clubs[7];
extern unsigned short* suits[4];
extern unsigned short cardTopLeft[5];
extern unsigned short cardBottomLeft[5];
extern unsigned short cardTopRight[5];
extern unsigned short cardBottomRight[5];
extern unsigned short cardLeft[1];
extern unsigned short cardRight[1];
extern unsigned short redJokerValue[10];
extern unsigned short blackJokerValue[10];
extern unsigned short redJokerSuit[7];
extern unsigned short blackJokerSuit[7];

byte _getNumPixelRowsPerCard();
byte* _drawCompiledPixMap(byte byteOffset, byte pixelRow, word* wordArray, byte numRows,
                          byte rowRepetitions);

