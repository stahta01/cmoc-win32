
#include "_cardgame.h"

byte _getCardType(byte card)
{
    if (card <= 13) {
        return SUIT_HEARTS;
    }
    if (card <= 26) {
        return SUIT_SPADES;
    }
    if (card <= 39) {
        return SUIT_DIAMONDS;
    }
    if (card <= 52) {
        return SUIT_CLUBS;
    }
    if (card <= 54) {
        return SUIT_JOKER;
    }
    return BAD_CARD_SUIT;
}

