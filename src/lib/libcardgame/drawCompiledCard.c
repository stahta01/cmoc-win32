
#include "_cardgame.h"

// cardValue: 1..13 (1 = ace).
// cardSuit: SUIT_* (0..3).
// Except for jokers: cardValue must be 1 (red) or 2 (black) and cardSuit must be SUIT_JOKER.
// byteColumn: 0..28 (maps to pixel columns 0, 8, 16, ..., 224).
// pixelRow: 0..150.
//
// The number of pixels rows occupied by the card is given by getNumPixelRowsPerCard().
// A card is 4 bytes wide, i.e., 32 pixels.
//
void drawCompiledCard(byte cardValue, byte cardSuit, byte byteColumn, byte pixelRow)
{
    --cardValue;                            // bring to 0..12 index

    // Draw top of card.
    drawCompiledPixMap(byteColumn,     pixelRow, cardTopLeft,  ROWS_PER_CARD_TOP, 1);
    drawCompiledPixMap(byteColumn + 2, pixelRow, cardTopRight, ROWS_PER_CARD_TOP, 1);
    drawCompiledPixMap(byteColumn + 2, pixelRow + ROWS_PER_CARD_TOP, cardRight, 1,
                       ROWS_PER_CARD_TOP * 2);

    // Draw card value (A, 2..10, J, Q, K, joker).
    word* pixmap;
    if (cardSuit == SUIT_JOKER) {
        pixmap = (cardValue == 1 ? redJokerValue : blackJokerValue);
    } else {
        pixmap = (word*)((cardSuit & 1) ? blackCards[cardValue] : redCards[cardValue]);
    }

    drawCompiledPixMap(byteColumn, pixelRow + ROWS_PER_CARD_TOP, pixmap, ROWS_PER_CARD_VALUE, 1);

    // Draw blank middle (the suit will be drawn over it).
    byte middleRow = pixelRow + ROWS_PER_CARD_TOP + ROWS_PER_CARD_VALUE;
    byte middleHeight = ROWS_ABOVE_SUIT + ROWS_PER_SUIT * 2 + ROWS_BELOW_SUIT;
    drawCompiledPixMap(byteColumn,     middleRow, cardLeft,  1, middleHeight);
    drawCompiledPixMap(byteColumn + 2, middleRow, cardRight, 1, middleHeight);

    // Draw bottom of card.
    drawCompiledPixMap(byteColumn,     middleRow + middleHeight, cardBottomLeft,  ROWS_PER_CARD_BOTTOM,
                       1);
    drawCompiledPixMap(byteColumn + 2, middleRow + middleHeight, cardBottomRight, ROWS_PER_CARD_BOTTOM,
                       1);

    // Draw suit.
    byte suitByteOffset = byteColumn + 1;
    byte suitRow        = pixelRow + ROWS_PER_CARD_TOP + ROWS_ABOVE_SUIT + ROWS_PER_CARD_VALUE;
    if (cardSuit == SUIT_JOKER) {
        drawCompiledPixMap(suitByteOffset, suitRow, cardValue == 1 ? redJokerSuit : blackJokerSuit,
                           ROWS_PER_SUIT, 2);
    } else {
        drawCompiledPixMap(suitByteOffset, suitRow, suits[cardSuit], ROWS_PER_SUIT, 2);
    }
}

