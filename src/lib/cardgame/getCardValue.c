
#include "_cardgame.h"

byte _getCardValue(byte card)
{
    if (card == 0) {
        return BAD_CARD_VALUE;
    }
    if (card <= 52) {
        return (card - 1) % 13 + 1;
    }
    if (card <= 54) {
        return card - 52;
    }
    return BAD_CARD_VALUE;
}

