
#include "_sac.h"

node_t* list_push_head(list_t* list, node_t* node)
{
    return node_insert(node, &list->head, list->head.next);
}

