
#include "_bob.h"

void bob_memcpy_unpack(bob_t* dst, int x, int y, bob_t* src)
{
    memcpy_unpack(dst->bytes + (y * dst->bytesperrow) + x,
                  src->bytes, src->height, src->width, dst->bytesperrow);
}

