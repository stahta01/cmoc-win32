
#include "_system.h"

int system_fgetc(dev_t dev)
{
    if (dev == DEV_PRINTER || (dev == DEV_CASSETTE && !_cinctr) ||
        (dev > 0 && fcb_get(dev - 1)->cnt.seq.dfl)) {
        return EOF;
    }
    byte chr, devold = _devnum;
    _devnum = (byte)dev;
    asm {
        jsr     [handle_fgetc]
        sta     chr
    }
    _devnum = devold;
    return chr;
}

