
#include "_cardgame.h"

// col: Byte offset in targeted row.
// row: Pixel row where to draw top of suit.
// suit: Index into suits[].
//
void drawSuit(byte col, byte row, byte suit)
{
    byte* topLeft = drawCompiledPixMap(col, row, suits[suit], ROWS_PER_SUIT, 2);

    // Draw a white horizontal line above and below the suit pixmap just drawn at topLeft:
    //
    byte* aboveRow = topLeft - BYTES_PER_SCREEN_ROW;
    *((word*) aboveRow) = 0xFFFF;
    *((word*) topLeft + (ROWS_PER_SUIT << 5)) = 0xFFFF;

    // Draw a white vertical line at the left of that pixmap:
    //
    byte* leftSide = aboveRow - 1;
    for (byte numRows = (ROWS_PER_SUIT << 1) + 2; numRows;
         --numRows, leftSide += BYTES_PER_SCREEN_ROW) {
        *leftSide |= 0x01;
    }
}

