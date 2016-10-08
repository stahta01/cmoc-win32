
#include "_bob.h"

bob_t* bob_create_with(int width, int height, void* data, int bytesperrow, bool owned)
{
    bob_t* bob = new(bob_t);
    if (bob) {
        bob_init(bob, width, height, data, bytesperrow, owned) ;
    }
    return bob;
}

