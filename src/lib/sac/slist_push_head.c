
#include "_sac.h"

asm snode_t* slist_push_head(slist_t* list, snode_t* node)
{
    asm {
        ldd     [2,s]                               // get head node
        std     [4,s]                               // set nodes next to head
        ldd     4,s                                 // get node ptr
        std     [2,s]                               // set as new head and return node ptr
    }
}

