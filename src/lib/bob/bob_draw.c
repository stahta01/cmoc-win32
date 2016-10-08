
#include "_bob.h"

void bob_draw(bob_t* dst, int x, int y, bob_t* src)
{
    bob_draw_rect(dst, x, y, src, 0, 0, src->width, src->height);
}

