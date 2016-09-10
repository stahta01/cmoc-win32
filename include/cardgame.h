
/*  cardgame.h - PMODE 4 playing cards library for the CoCo.
Assumes Disk Basic, i.e., the PMODE 4 screen starts at $0E00.

By Pierre Sarrazin <http:                   //sarrazip.com/>.
This file is in the public domain.

Version 0.1.0 - 2015-08-12 - First public release.
Version 0.1.1 - 2016-03-12 - New #defines. New function drawFaceDownCard().
Version 0.1.2 - 2016-??-?? - setConsoleOutHook() and resetConsoleOutHook()
                          now taken from <coco.h>.
*/

#ifndef _CARDGAME_H
#define _CARDGAME_H

#include <sys/byte.h>

#define NUMCARDS                54
#define BAD_CARD_SUIT           0xFF
#define BAD_CARD_VALUE          0
#define BAD_INDEX               0xFF

#define SUIT_HEARTS   0
#define SUIT_SPADES   1
#define SUIT_DIAMONDS 2
#define SUIT_CLUBS    3
#define SUIT_JOKER    4
#define SUIT_NONE     255

void closeCardGameScreenMode();
void concat(char* out, unsigned max, ...);
void drawCompiledCard(byte cardValue, byte cardSuit, byte byteColumn, byte pixelRow);
void drawFaceDownCard(byte rowInPixels, byte colInBytes);
void drawSuit(byte col, byte row, byte suit);
void eraseCard(byte byteColumn, byte pixelRow);
byte getCardType(byte card);
byte getCardValue(byte card);
char* getSuitName(byte suit);
void openCardGameScreenMode(void);
byte pickCardFromDeck(byte deck[], byte* pNumCards);
byte printCentered(byte row, char* str);
byte getNumPixelRowsPerCard();
void shuffleDeck(byte deck[], byte numCards);

#endif

