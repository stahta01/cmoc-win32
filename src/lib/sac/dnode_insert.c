
#include "_sac.h"

dnode_t* dnode_insert(dnode_t* node, dnode_t* prev, dnode_t* next)
{
    dnode_link(prev, node);
    dnode_link(node, next);
    return node;
}

