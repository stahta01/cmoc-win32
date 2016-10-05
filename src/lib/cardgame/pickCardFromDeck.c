
#include "_cardgame.h"

// Removes a card from the end of the designated deck, which
// initially contains a number of cards given by *pNumCards,
// decrements this number, then returns the removed card.
// (The "top" of a deck is at the highest valid index,
// while the "bottom" is at index 0.)
//
byte _pickCardFromDeck(byte deck[], byte* pNumCards)
{
    if (*pNumCards == 0) {
        return BAD_CARD_VALUE;
    }
    byte card = deck[--*pNumCards];
    assertf(card >= 1 && card <= NUMCARDS, "%u", card);
    return card;
}

