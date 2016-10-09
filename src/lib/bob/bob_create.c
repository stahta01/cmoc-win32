
#include "_bob.h"

bob_t* bob_create(int width, int height)
{
    bob_t* bob = new(bob_t);
    if (bob) {
        void* bytes = calloc(width, height);
        if (bytes) {
            bob_init(bob, width, height, width, bytes, true);
        } else {
            free(bob);
            bob = nullptr;
        }
    }
    return bob;
}

