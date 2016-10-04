
#include "_sac.h"

dnode_t* list_pull_tail(dlist_t* list)
{
    dnode_t* node = dlist_tail(list);
    return node ? dnode_remove(node) : (dnode_t*)nullptr;
}

