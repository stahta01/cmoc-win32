
#include "_sac.h"

node_t* list_push_tail(list_t* list, node_t* node)
{
    return node_insert(node, list->tail.prev, &list->tail);
}

