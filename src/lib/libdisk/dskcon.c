
#include "_disk.h"

// operation: DSKCON operation code
// dest: non null pointer to a 256-byte region.
// drive: 0..3.
// track: 0..34.
// sector: 1..18 (sic).
// Returns TRUE for success, FALSE for failure.
//
byte dskcon(byte operation, byte* buffer, byte drive, byte track, byte sector)
{
    //printf("- dskcon(%u, 0x%04x, %u, %u, %u)\n", operation, buffer, drive, track, sector);
    if (operation != DSKCON_READ && operation != DSKCON_WRITE) {
        return FALSE;
    }
    if (buffer == 0) {
        return FALSE;
    }
    if (drive >= 4) {
        return FALSE;
    }
    if (track >= 35) {
        return FALSE;
    }
    if (sector == 0) {
        return FALSE;
    }
    if (sector > 18) {
        return FALSE;
    }

    // Fill DSKCON input variables.
    * (byte*) 0x00EA = operation;   // DCOPC
    * (byte*) 0x00EB = drive;       // DCDRV
    * (byte*) 0x00EC = track;       // DCTRK
    * (byte*) 0x00ED = sector;      // DCSEC
    * (word*) 0x00EE = buffer;        // DCBPT

    asm("PSHS", "U,Y,X,A");  // protect against BASIC routine
    asm("JSR", "[$C004]");  // call DSKCON
    asm("PULS", "A,X,Y,U");

    return (* (byte*) 0x00F0) == 0;   // zero in DCSTA means success
}


