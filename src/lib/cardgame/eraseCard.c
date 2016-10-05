
#include "_cardgame.h"

void _eraseCard(byte byteColumn, byte pixelRow)
{
    word* p = (word*)(scrnBuffer + (((word) pixelRow) << 5) + byteColumn);
    byte h = _getNumPixelRowsPerCard();
    for (byte i = 0; i < h; ++i, p += WORDS_PER_SCREEN_ROW) {
        p[0] = 0;
        p[1] = 0;
    }
}

