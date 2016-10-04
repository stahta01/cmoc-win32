
#include "_sac.h"

dnode_t* dlist_pull_head(dlist_t* list)
{
    dnode_t* node = dlist_head(list);
    return node ? dnode_remove(node) : (dnode_t*)nullptr;
}

