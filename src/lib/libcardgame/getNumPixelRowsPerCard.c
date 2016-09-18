
#include "_cardgame.h"

// Height of a card drawn by drawCompiledCard().
// A card is 4 bytes wide, i.e., 32 pixels.
//
byte _getNumPixelRowsPerCard()
{
    return ROWS_PER_CARD_TOP + ROWS_PER_CARD_VALUE + ROWS_ABOVE_SUIT
           + ROWS_PER_SUIT * 2 + ROWS_BELOW_SUIT + ROWS_PER_CARD_BOTTOM;
}

