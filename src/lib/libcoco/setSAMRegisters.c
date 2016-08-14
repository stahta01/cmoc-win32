
#include <coco.h>

// samAddr: Base address to write to (0xFFC0 for screen mode,
//          0xFFC6 for graphics page address).
// value:   Value to write.
// numBits: Number of bits to write to samAddr. (Refers to the
//          least significant bits of 'value'.)
//
void setSAMRegisters(byte* samAddr, byte value, byte numBits)
{
    while (numBits) {
        // Write at even address to send a 0, odd to send a 1.
        //
        *(samAddr + (value & 1)) = 0;

        value = value >> 1;

        --numBits;

        // Next SAM bit is two addresses further.
        //
        samAddr += 2;
    }
}



