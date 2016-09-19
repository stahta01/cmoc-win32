
#include "_sac.h"

void list_init(list_t* list)
{
    node_link(&list->head, &list->tail);
}

