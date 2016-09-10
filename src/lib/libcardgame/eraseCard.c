
#include "_cardgame.h"

void eraseCard(byte byteColumn, byte pixelRow)
{
    word* p = (word*)(scrnBuffer + (((word) pixelRow) << 5) + byteColumn);
    byte h = getNumPixelRowsPerCard();
    for (byte i = 0; i < h; ++i, p += WORDS_PER_SCREEN_ROW) {
        p[0] = 0;
        p[1] = 0;
    }
}

