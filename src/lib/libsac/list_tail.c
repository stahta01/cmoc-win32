
#include "_sac.h"

node_t* list_tail(list_t* list)
{
    return list_is_empty(list) ? (node_t*)nullptr : list->tail.prev;
}

