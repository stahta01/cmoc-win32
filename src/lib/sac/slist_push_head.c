
#include "_sac.h"

snode_t* slist_push_head(slist_t* list, snode_t* node)
{
    node->next = list->head.next;
    list->head.next = node;
    return node;
}

