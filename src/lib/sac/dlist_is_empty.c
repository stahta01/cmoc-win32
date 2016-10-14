
#include "_sac.h"

bool dlist_is_empty(dlist_t* list)
{
    return !list->head.next->next;
}

