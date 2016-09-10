
/*  cardgame.c
    Skeleton CoCo program that draws playing cards.
    Assumes Disk Basic, i.e., the PMODE 4 screen starts at $0E00.

    By Pierre Sarrazin <http:               //sarrazip.com/>.
    This file is in the public domain.

    Version 0.1.0 - 2015-08-12 - First public release.
    Version 0.1.1 - 2016-03-12 - Adaptation to cardgame.h v0.1.1.
*/

#pragma options -machine=cocous

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <cardgame.h>

#define PIXEL_ROWS_PER_SCREEN 192

int main()
{
    // Initialize the PMODE 4 screen at the given address.
    // This initializes scrnBuffer.
    openCardGameScreenMode();

    // Initialize the random number generator.
    word seed = clock();
    srand(seed);

    // Precompute the number of pixel rows per card, for the coming loops.
    byte cardHeight = getNumPixelRowsPerCard();

    // Draw the 52 ordinary cards in a grid, which each card overlapping
    // its predecessor in the current row.
    byte pixelRow = 0;
    byte horizSkip = 4;
    for (byte suit = SUIT_HEARTS; suit <= SUIT_CLUBS; ++suit, pixelRow += cardHeight + horizSkip) {
        for (byte value = 1; value <= 13; ++value) { // ace to king
            byte byteCol = (value - 1) <<
                           1;               // 2 bytes of visible width per card (other 2 bytes gets overlapped)
            drawCompiledCard(value, suit, byteCol, pixelRow);
        }
    }

    // Draw the two jokers at top right.
    for (byte joker = 1; joker <= 2; ++joker) {
        drawCompiledCard(joker, SUIT_JOKER, 28, (joker - 1) * (cardHeight + 4));
    }

    // Draw a face-down card at bottom right.
    drawFaceDownCard(PIXEL_ROWS_PER_SCREEN - getNumPixelRowsPerCard(), 28);

    // Show a prompt at the bottom and wait for the user to quit.
    gotoxy(0, 23);
    printf("PRESS BREAK TO QUIT.");
    while (getch() != 3) {}

    // Erase the jokers over a short delay, as an example of erasing cards.
    eraseCard(28, cardHeight + 4);
    delay(30);
    eraseCard(28, 0);
    delay(30);

    // Go back to the text screen.
    closeCardGameScreenMode();

    // printf() now prints to the hardware CoCo text screen.
    printf("THANKS FOR PLAYING.\n");
    return 0;
}

