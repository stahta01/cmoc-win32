
#include "_sac.h"

node_t* list_pull_tail(list_t* list)
{
    node_t* node = list_tail(list);
    return node ? node_remove(node) : (node_t*)nullptr;
}

