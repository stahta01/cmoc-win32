
#include "_sac.h"

asm snode_t* slist_pull_head(slist_t* list)
{
    asm {
        ldx     [2,s]                               // x = head node ptr
        beq     return                              // exit if null
        ldd     ,x                                  // get next node
        std     [2,s]                               // store as head
        clr     0,x                                 // set nodes next to null
        clr     1,x
return:
        tfr     x,d                                 // return node ptr
    }
}

