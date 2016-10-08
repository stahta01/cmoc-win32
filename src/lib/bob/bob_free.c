
#include "_bob.h"

void bob_free(bob_t* bob)
{
    if (bob->freememory) {
        free(bob->data);
    }
    free(bob);
}


