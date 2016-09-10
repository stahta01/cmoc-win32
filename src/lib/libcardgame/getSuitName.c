
#include "_cardgame.h"

char* getSuitName(byte suit)
{
    switch (suit) {
    case SUIT_HEARTS:
        return "hearts";
    case SUIT_SPADES:
        return "spades";
    case SUIT_DIAMONDS:
        return "diamonds";
    case SUIT_CLUBS:
        return "clubs";
    default:
        return "ERROR";
    }
}

