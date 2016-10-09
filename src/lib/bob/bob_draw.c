
#include "_bob.h"

bob_t* bob_draw(bob_t* dst, int x, int y, bob_t* src)
{
    return bob_drawrect(dst, x, y, src, 0, 0, src->width, src->height);
}

