
#include "_machine.h"

// Note: As far as I know, there is no easy way to identity a 64K CoCo.
// The reason is, 32K CoCo's are often 64K with faulty upper memory.
// XRoar even supports this. Setting "-ram 32" still gives you 64K, except the
// upper 32K is dodgy.

// I'll keep looking for information. On the other hand, a 64K Dragon can be
// identified, because the ROM was written to support 64K.
// But, again, it might be possible to upgrade a Dragon32 to 64K, or some
// Dragon32's might have dodgy 64K mem, in which case, its not possible
// to identity them easily.

void machine_init(void)
{
    if (MAC_IS_COCO) {
        if (MAC_IS_COCO3) {
            machine.typ = MAC_TYP_COCO3;
            machine.rom = MAC_ROM_SUPER;
            // TODO: Can we detect 512?
            machine.ram = 128;
        } else {
            if (MAC_IS_COCO1) {
                machine.typ = MAC_TYP_COCO1;
            } else {
                machine.typ = MAC_TYP_COCO2;
            }
            if (MAC_HAS_EXTBAS) {
                machine.rom = MAC_ROM_EXTENDED;
            } else {
                machine.rom = MAC_ROM_STANDARD;
            }
            machine.ram = (_topram + 2) >> 10;
        }
    } else {
        if (MAC_IS_DRAGON) {
            if (MAC_IS_DRAGON64) {
                machine.typ = MAC_TYP_DRAGON64;
                machine.ram = 64;
            } else {
                machine.typ = MAC_TYP_DRAGON32;
                machine.ram = 32;
            }
            machine.rom = MAC_ROM_EXTENDED;
        }
    }
    machine.dos = MAC_HAS_DOS;
}

