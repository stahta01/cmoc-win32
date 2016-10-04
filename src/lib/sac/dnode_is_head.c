
#include "_sac.h"

bool dnode_is_head(dnode_t* node)
{
    return !node->prev || !node->prev->prev;
}

