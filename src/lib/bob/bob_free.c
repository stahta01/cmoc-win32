
#include "_bob.h"

void bob_free(bob_t* bob)
{
    if (bob->owned) {
        free(bob->bytes);
    }
    free(bob);
}


