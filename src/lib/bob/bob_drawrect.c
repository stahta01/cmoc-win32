
#include "_bob.h"

bob_t* bob_drawrect(bob_t* dst, int x, int y, bob_t* src, int u1, int v1, int u2, int v2)
{
    return bob_copyrect(dst, x, y, x + (u2 - u1), y + (v2 - v1), src, u1, v1, u2, v2);
}

