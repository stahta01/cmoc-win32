
#include "_sac.h"

bool list_is_empty(list_t* list)
{
    return !list || !list->head.next->next;
}

