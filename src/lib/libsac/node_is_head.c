
#include "_sac.h"

bool node_is_head(node_t* node)
{
    return !node->prev || !node->prev->prev;
}

