
#include "_disk.h"

// Output:
// *track: 0..16, 18..34.
// *sec: 0 or 9.
//
void _granuleToTrack(byte granule, byte* track, byte* sec)
{
    byte t = granule;
    asm("LSR", t);  // t = granule / 2
    if (t >= 17) { // if granule is after dir track
        asm("INC", t);
    }
    byte s = granule;
    asm("ANDB", "#1");  // we assume that B still holds 's'
    asm("STB", s);
    if (s > 0) {
        s = 9;
    }

    *track = t;
    *sec = s;
}


