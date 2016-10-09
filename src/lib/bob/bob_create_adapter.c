
#include "_bob.h"

bob_t* bob_create_adapter(int width, int height, int bytesperrow, void* bytes)
{
    bob_t* bob = new(bob_t);
    if (bob) {
        bob_init(bob, width, height, bytesperrow, bytes, false);
    }
    return bob;
}

