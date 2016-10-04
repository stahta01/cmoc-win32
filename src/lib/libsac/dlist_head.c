
#include "_sac.h"

dnode_t* dlist_head(dlist_t* list)
{
    return dlist_is_empty(list) ? (dnode_t*)nullptr : list->head.next;
}

