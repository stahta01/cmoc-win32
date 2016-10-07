
#include "_system.h"

void system_init(void)
{
    machine_init();
    switch (_machine.typ) {
    case MAC_TYP_COCO1:
    case MAC_TYP_COCO2:
    case MAC_TYP_COCO3:
        handle_init_coco();
        break;
    case MAC_TYP_DRAGON32:
    case MAC_TYP_DRAGON64:
        handle_init_dragon();
        break;
    }
}

