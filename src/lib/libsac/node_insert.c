
#include "_sac.h"

node_t* node_insert(node_t* node, node_t* prev, node_t* next)
{
    node_link(prev, node);
    node_link(node, next);
    return node;
}

