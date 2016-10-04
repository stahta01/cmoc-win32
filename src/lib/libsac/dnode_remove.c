
#include "_sac.h"

dnode_t* dnode_remove(dnode_t* node)
{
    dnode_link(node->prev, node->next);
    return node;
}

