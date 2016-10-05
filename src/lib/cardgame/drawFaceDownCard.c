
#include "_cardgame.h"

// rowInPixels: Offset in pixels down the top of the screen.
// colInBytes: Horizontal position of the card, in bytes (0..28).
//
void _drawFaceDownCard(byte rowInPixels, byte colInBytes)
{
    word* writer = (word*)(scrnBuffer + (word) rowInPixels * BYTES_PER_SCREEN_ROW + colInBytes);
    byte rowsPerCard = _getNumPixelRowsPerCard();
    word wordToWrite = 0x5555;
    for (byte row = 0; row < rowsPerCard; ++row, writer += WORDS_PER_SCREEN_ROW) {
        *writer = writer[1] = wordToWrite;  // blue
        if (row == rowsPerCard - 2) {
            wordToWrite = 0x5555;
        } else if (row & 1) {
            wordToWrite = 0x0505;
        } else {
            wordToWrite = 0x5050;
        }
    }
}

