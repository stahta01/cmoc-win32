
#include <coco/ecb_equates.h>
#include "_system.h"
#include <machine.h>

// Note: As far as I know, there is no easy way to identity a 64K CoCo.
// The reason is, 32K CoCo's are often 64K with faulty upper memory.
// XRoar even supports this. Setting "-ram 32" still gives you 64K, except the
// upper 32K is dodgy.

// I'll keep looking for information. On the other hand, a 64K Dragon can be
// identify, because the ROM was written to support 64K.
// But, again, it might be possible to upgrade a Dragon32 to 64K, or some
// Dragon32's might have dodgy 64K mem, in which case, its not possible
// to identity them easily.

byte get_ostype(void)
{
    byte ostype = 0;
    char* bas = _LA147;                 // Color Basic Copyright Message
    char* ext = _L80E8;                 // Extended Color Basic Copyright Message

    if (MAC_IS_COCO) {
        if (MAC_IS_COCO3) {
            ostype |= SYSTEM_MAC_COCO3;
            ostype |= SYSTEM_FLG_EXT;
            ostype |= 64;
        } else {
            ostype |= MAC_IS_COCO1 ? SYSTEM_MAC_COCO1 : SYSTEM_MAC_COCO2;
            if (MAC_HAS_EXTBAS) {
                ostype |= SYSTEM_FLG_EXT;
            }
            ostype |= (char)(((_topram >> 10) + 1) & 0x70);
        }
    } else {
        if (MAC_IS_DRAGON) {
            if (MAC_IS_DRAGON64) {
                ostype |= SYSTEM_MAC_DRAGON64;
                ostype |= 64;
            } else {
                ostype |= SYSTEM_MAC_DRAGON32;
                ostype |= 32;
            }
            ostype |= SYSTEM_FLG_EXT;
        }
    }
    if (MAC_HAS_DOS) {
        ostype |= SYSTEM_FLG_DOS;
    }
    return ostype;
}

