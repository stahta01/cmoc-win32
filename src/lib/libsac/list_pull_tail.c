
#include "_sac.h"

node_t* list_pull_tail(list_t* list)
{
    return node_remove(list_tail(list));
}

