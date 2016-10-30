
#include "_sac.h"

asm snode_t* slist_head(slist_t* list)
{
    asm {
        ldd     [2,s]                               // get list head
    }
}

