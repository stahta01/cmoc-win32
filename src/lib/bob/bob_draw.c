
#include "_bob.h"

void bob_draw(bob_t* dst, int x, int y, bob_t* src)
{
    bob_copyrect(dst, x, y, x + src->width, y + src->height, src, 0, 0, src->width, src->height);
}

