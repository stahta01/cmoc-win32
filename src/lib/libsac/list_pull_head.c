
#include "_sac.h"

node_t* list_pull_head(list_t* list)
{
    node_t* node = list_head(list);
    return node ? node_remove(node) : (node_t*)nullptr;
}

