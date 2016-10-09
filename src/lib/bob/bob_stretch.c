
#include "_bob.h"

bob_t* bob_stretch(bob_t* dst, int x1, int y1, int x2, int y2, bob_t* src)
{
    return bob_copyrect(dst, x1, y1, x2, y2, src, 0, 0, src->width, src->height);
}

