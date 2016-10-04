
#include "_sac.h"

bool dnode_is_tail(dnode_t* node)
{
    return !node->next || !node->next->next;
}

