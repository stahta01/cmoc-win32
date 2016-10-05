
#include "_fix6.h"

void vector_project(vector_t* dst, vector_t* src, size_t n, int x, int y)
{
    for (; n--; dst++, src++) {
        int z = dst->z = src->z >> 4;
        if (z > 0) {
            dst->x = x + src->x / z;
            dst->y = y - src->y / z;
        }
    }
}

