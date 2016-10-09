
#include "_mob.h"

void mob_memcpy_unpack(mob_t* mob, int x, int y, bob_t* dst)
{
    bob_memcpy_unpack(dst, x >> 2, y, mob->bobs[x & 3]);
}

