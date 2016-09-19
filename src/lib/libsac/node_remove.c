
#include "_sac.h"

node_t* node_remove(node_t* node)
{
    node_link(node->prev, node->next);
    return node;
}

