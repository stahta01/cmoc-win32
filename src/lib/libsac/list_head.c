
#include "_sac.h"

node_t* list_head(list_t* list)
{
    return list_is_empty(list) ? (node_t*)nullptr : list->head.next;
}

