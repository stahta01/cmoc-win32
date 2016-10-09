
#include "_bob.h"

bob_t* bob_create_with(int width, int height, int bytesperrow, void* bytes, bool owned)
{
    bob_t* bob = new(bob_t);
    if (bob) {
        bob_init(bob, width, height, bytesperrow, bytes, owned);
    }
    return bob;
}

