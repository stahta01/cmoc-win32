
#include "_system.h"

unsigned sysptr_polcat, sysptr_chrout, sysptr_csrdon, sysptr_blkin, sysptr_blkout,
         sysptr_joyin, sysptr_wrtldr, sysptr_line, sysptr_getchr, sysptr_putchr, sysptr_sound,
         sysptr_crunch, sysptr_execute, sysptr_screen;

unsigned char _get_ostype;

void system_init(void)
{
    _get_ostype = get_ostype();

    sysptr_polcat = *(unsigned*)0xa000;
    sysptr_chrout = *(unsigned*)0xa002;
    sysptr_csrdon = *(unsigned*)0xa004;
    sysptr_blkin  = *(unsigned*)0xa006;
    sysptr_blkout = *(unsigned*)0xa008;
    sysptr_joyin  = *(unsigned*)0xa00a;
    sysptr_wrtldr = *(unsigned*)0xa00c;

    switch (_get_ostype & 7) {
    case SYSTEM_MAC_COCO1:
    case SYSTEM_MAC_COCO2:
    case SYSTEM_MAC_COCO3:
        system_init_coco();
        break;
    case SYSTEM_MAC_DRAGON32:
    case SYSTEM_MAC_DRAGON64:
        system_init_dragon();
        break;
    }
}

