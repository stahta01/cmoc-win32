
#include "_sac.h"

void dlist_init(dlist_t* list)
{
    dnode_link(&list->head, &list->tail);
}

