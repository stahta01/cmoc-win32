
#include "_sac.h"

node_t* list_pull_head(list_t* list)
{
    return node_remove(list_head(list));
}

