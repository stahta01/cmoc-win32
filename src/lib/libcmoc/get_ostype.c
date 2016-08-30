
#include <cmoc.h>
#include <equates.h>

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
    // Look for "CO" (Color Computer copyright message)
    if (*((unsigned*)0xa147) == 0x434f) {
        ostype = CMOC_MAC_COCO;
        // Look for "EX" (Extended BASIC)
        if (*((unsigned*)0x8000) == 0x4558) {
            ostype |= CMOC_FLG_EXT;
        }
        ostype |= (char)(((_topram >> 10) + 1) & 0x70);
    } else {
        if (*((unsigned*)0x8000) == 0x7ebb) {
            ostype = CMOC_MAC_DRAGON;
            ostype |= CMOC_FLG_EXT;
            if (*((char*)0x8002) == 0x3c) {
                ostype |= 64;
            } else {
                ostype |= 32;
            }
        }
    }
    if (_grpram > 6) {
        ostype |= CMOC_FLG_DOS;
    }
    return ostype;
}

