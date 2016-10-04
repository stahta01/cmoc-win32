
#include "_sac.h"

dnode_t* dlist_push_head(dlist_t* list, dnode_t* node)
{
    return dnode_insert(node, &list->head, list->head.next);
}

