
#include "_sac.h"

snode_t* slist_pull_head(slist_t* list)
{
    snode_t* node = list->head.next;
    if (node) {
        list->head.next = node->next;
    }
    return node;
}

