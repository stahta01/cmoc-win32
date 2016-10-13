
#include <vkey.h>
#include <equates.h>

bool vkey_state(word vkey)
{
    vkey = (vkey | 0x80) ^ -1;
    _pia0[2] = (byte)vkey;
    return _pia0[0] == (byte)(vkey >> 8);
}

