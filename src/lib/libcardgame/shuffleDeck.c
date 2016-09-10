
#include "_cardgame.h"

void shuffleDeck(byte deck[], byte numCards)
{
    for (byte i = 1; i < numCards; ++i) {
        byte other = (byte)(rand() % (numCards - i) + i);
        assertf(i - 1 < NUMCARDS, "%u", i);
        assertf(other < NUMCARDS, "%u", other);
        byte temp = deck[i - 1];
        deck[i - 1] = deck[other];
        deck[other] = temp;
    }
}

