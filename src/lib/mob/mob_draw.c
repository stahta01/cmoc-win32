
#include "_mob.h"

void mob_draw(mob_t* mob, int x, int y, bob_t* dst)
{
    bob_draw(dst, x >> 2, y, mob->bobs[x & 3]);
}

