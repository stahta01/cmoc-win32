
#include "_cardgame.h"

// byteOffset: Offset in bytes from the left of the screen (must be < BYTES_PER_SCREEN_ROW).
// pixelRow: Vertical position (in pixels) of the row at which to start drawing (downwards).
//           Must be < PIXEL_ROWS_PER_SCREEN.
// numRows: Must be > 0.
// rowRepetitions: Must be > 0.
// Returns the address of the top left byte of the region that was modified.
// Uses scrnBuffer as the start of the PMODE 4 screen buffer.
//
byte* drawCompiledPixMap(byte byteOffset, byte pixelRow, word* wordArray, byte numRows,
                         byte rowRepetitions)
{
    assertf(byteOffset < BYTES_PER_SCREEN_ROW, "%u", byteOffset);
    assertf(pixelRow < PIXEL_ROWS_PER_SCREEN, "%u", pixelRow);
    assertf(numRows <= PIXEL_ROWS_PER_SCREEN, "%u", numRows);
    assertf(pixelRow + numRows <= PIXEL_ROWS_PER_SCREEN, "%u, %u", pixelRow, numRows);
    assertf(rowRepetitions > 0, "%u", rowRepetitions);

    /*  Logic implemented in assembly language that follows:
    word *dest = (word *) (scrnBuffer + (word) pixelRow * BYTES_PER_SCREEN_ROW + byteOffset);
    for (byte i = 0; i < numRows; ++i)
    {
        word w = wordArray[i];
        for (byte r = 0; r < rowRepetitions; ++r)
        {
            *dest = w;
            dest += WORDS_PER_SCREEN_ROW;
        }
    }
    */

    byte* topLeft;
    byte r;                                     // temp row counter

    asm {
        pshs    y                               // per CMOC convention

        lda     pixelRow
        ldb     #BYTES_PER_SCREEN_ROW
        mul
        addb    byteOffset
        adca    #0
        addd    scrnBuffer
        tfr     d,x                             // make X point to first screen byte to write to
        stx     topLeft

        ldy     wordArray

        drawCompiledPixMap_foreach_word:
        ldb     rowRepetitions                  // reinit rep counter
        stb     r
        ldd     ,y++
        drawCompiledPixMap_foreach_rep:
        std     ,x
        leax    BYTES_PER_SCREEN_ROW,x          // move to next row down

        dec     r
        bne     drawCompiledPixMap_foreach_rep

        dec     numRows
        bne     drawCompiledPixMap_foreach_word

        puls    y
    }

    return topLeft;
}

