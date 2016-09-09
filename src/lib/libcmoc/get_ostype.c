
#include "_cmoc.h"

// Note: As far as I know, there is no easy way to identity a 64K CoCo.
// The reason is, 32K CoCo's are often 64K with faulty upper memory.
// XRoar even supports this. Setting "-ram 32" still gives you 64K, except the
// upper 32K is dodgy.

// I'll keep looking for information. On the other hand, a 64K Dragon can be
// identify, because the ROM was written to support 64K.
// But, again, it might be possible to upgrade a Dragon32 to 64K, or some
// Dragon32's might have dodgy 64K mem, in which case, its not possible
// to identity them easily.

unsigned char get_ostype(void)
{
    unsigned char ostype = 0;
    char* bas = 0xa147;                 // Color Basic Copyright Message
    char* ext = 0x80e8;                 // Extended Color Basic Copyright Message

    if (bas[0] == 'C' && bas[1] == 'O') {
        if (ext[0] == 'E' && ext[1] == 'X' && ext[21] == '2') {
            ostype |= CMOC_MAC_COCO3;
            ostype |= CMOC_FLG_EXT;
            ostype |= 64;
        } else {
            ostype |= bas[14] < '2' ? CMOC_MAC_COCO1 : CMOC_MAC_COCO2;
            if (ext[0] == 'E' && ext[1] == 'X') {
                ostype |= CMOC_FLG_EXT;
            }
            ostype |= (char)(((_topram >> 10) + 1) & 0x70);
        }
    } else {
        if (*((unsigned*)0x8000) == 0x7ebb) {
            if (*((char*)0x8002) == 0x3c) {
                ostype |= CMOC_MAC_DRAGON64;
                ostype |= 64;
            } else {
                ostype |= CMOC_MAC_DRAGON32;
                ostype |= 32;
            }
            ostype |= CMOC_FLG_EXT;
        }
    }
    if (_grpram > 6) {
        ostype |= CMOC_FLG_DOS;
    }
    return ostype;
}

