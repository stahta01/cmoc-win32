
#include "_sac.h"

bool node_is_tail(node_t* node)
{
    return !node->next || !node->next->next;
}

