
#include "_system.h"

byte _get_ostype;

void system_init(void)
{
    _get_ostype = get_ostype();

    switch (_get_ostype & 7) {
    case SYSTEM_MAC_COCO1:
    case SYSTEM_MAC_COCO2:
    case SYSTEM_MAC_COCO3:
        handle_init_coco();
        break;
    case SYSTEM_MAC_DRAGON32:
    case SYSTEM_MAC_DRAGON64:
        handle_init_dragon();
        break;
    }
}

