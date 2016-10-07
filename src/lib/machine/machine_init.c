
#include "_machine.h"

// Note: As far as I know, there is no easy way to identity a 64K CoCo.
// The reason is, 32K CoCo's are often 64K with faulty upper memory.
// XRoar even supports this. Setting "-ram 32" still gives you 64K, except the
// upper 32K is dodgy.

// I'll keep looking for information. On the other hand, a 64K Dragon can be
// identify, because the ROM was written to support 64K.
// But, again, it might be possible to upgrade a Dragon32 to 64K, or some
// Dragon32's might have dodgy 64K mem, in which case, its not possible
// to identity them easily.

void machine_init(void)
{
    if (MAC_IS_COCO) {
        if (MAC_IS_COCO3) {
            _machine.typ = MAC_TYP_COCO3;
            _machine.rom = MAC_ROM_SUPER;
            _machine.ram = 128;
        } else {
            if (MAC_IS_COCO1) {
                _machine.typ = MAC_TYP_COCO1;
            } else {
                _machine.typ = MAC_TYP_COCO2;
            }
            if (MAC_HAS_EXTBAS) {
                _machine.rom = MAC_ROM_EXTENDED;
            } else {
                _machine.rom = MAC_ROM_STANDARD;
            }
            _machine.ram = (_topram + 2) >> 10;
        }
    } else {
        if (MAC_IS_DRAGON) {
            if (MAC_IS_DRAGON64) {
                _machine.typ = MAC_TYP_DRAGON64;
                _machine.ram = 64;
            } else {
                _machine.typ = MAC_TYP_DRAGON32;
                _machine.ram = 32;
            }
            _machine.rom = MAC_ROM_EXTENDED;
        }
    }
    _machine.dos = MAC_HAS_DOS;
}

