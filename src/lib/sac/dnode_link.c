
#include "_sac.h"

void dnode_link(dnode_t* n1, dnode_t* n2)
{
    if (n1) {
        if (n1->next) {
            n1->next->prev = nullptr;
        }
        n1->next = n2;
    }
    if (n2) {
        if (n2->prev) {
            n2->prev->next = nullptr;
        }
        n2->prev = n1;
    }
}

