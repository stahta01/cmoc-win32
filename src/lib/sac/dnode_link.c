
#include "_sac.h"

asm void dnode_link(dnode_t* n1, dnode_t* n2)
{
    asm {
        ldx     2,s                                 // x = n1
        beq     end_n1                              // end if null
        ldy     0,x                                 // y = n1->next
        beq     set_n1_next                         // skip if null
        clr     2,y                                 // n1->next->prev = nullptr
        clr     3,y
        set_n1_next:
        ldd     4,s                                 // d = n2
        std     0,x                                 // n1->next = d
        end_n1:

        ldx     4,s                                 // x = n2
        beq     end_n2                              // end if null
        ldy     2,x                                 // y = n2->prev
        beq     set_n2_prev                         // skip if null
        clr     0,y                                 // n2->prev->next = nullptr
        clr     1,y
        set_n2_prev:
        ldd     2,s                                 // d = n1
        std     2,x                                 // n2->prev = d
        end_n2:

    }
    /*
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
    */
}

