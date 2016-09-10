
#include "_cardgame.h"

//#define optDelay(ticks) ((void) 0)
#define optDelay(ticks) delay(ticks)

byte* scrnBuffer;                           // 1st PMODE 4 buffer

// Initializes CoCo support functions.
// Goes to PMODE 4, with the 6k buffer at the address given by
// _scrnBuffer, which is typically 0x0E00 under Disk Basic.
// Global variable scrnBuffer is initialized with _scrnBuffer.
// Initializes the 32x24 software text screen's cursor at the home position.
// Remembers the initial text mode (32, 40, 80).
// Initializes globals textScreenWidth and textScreenHeight.
// Redirects printf() so that it prints to the software text screen.
//
// Call closeCardGameScreenMode() to go back to text mode.
//
void openCardGameScreenMode(void* _scrnBuffer)
{
    //initCoCoSupport();

    scrnBuffer = (byte*) _scrnBuffer;
    //initTextMode = getTextMode();           // for restoreOriginalTextMode()
    //width(32);
    //pcls(scrnBuffer, 0);
    //showGraphicsAddress((byte)(scrnBuffer >> 9)); // set SAM registers to show PMODE 4 at scrnBuffer
    //showPmode4(1);                          // white/black

    // Hi-res text screen:
    gotoxy(0, 0);

    // Set screen dimensions for functions in coco.h.
    textScreenWidth  = BYTES_PER_SCREEN_ROW;
    textScreenHeight = TEXT_ROWS_PER_SCREEN;

    // Redirect printf().
    //oldCHROOT = setConsoleOutHook(hiResTextConsoleOutHook);
}

