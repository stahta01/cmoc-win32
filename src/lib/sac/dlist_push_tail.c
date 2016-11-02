
#include "_sac.h"

dnode_t* dlist_push_tail(dlist_t* list, dnode_t* node)
{
    return dnode_insert(node, list->tail.prev, &list->tail);
}

