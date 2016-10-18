
#include "_coco.h"

// pageNum: 512-byte page index in 0..127.
// Sets the SAM registers to show the PMODE 4 graphics
// at address pageNum * 512.
//
void _showGraphicsAddress(byte pageNum)
{
    _setSAMRegisters((byte*)0xFFC6, pageNum, 7);
    _setSAMRegisters((byte*)0xFFC0, 6, 3);
}

