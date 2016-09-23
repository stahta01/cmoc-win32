
#include "_fix6.h"

void vector_rotate(vector_t* dst, vector_t* src, size_t n, matrix_t* mat)
{
    for (; n--; dst++, src++) {
        dst->x = src->x*mat->v[0][0]+src->y*mat->v[0][1]+src->z*mat->v[0][2]+i2f6(mat->v[0][3]);
        dst->y = src->x*mat->v[1][0]+src->y*mat->v[1][1]+src->z*mat->v[1][2]+i2f6(mat->v[1][3]);
        dst->z = src->x*mat->v[2][0]+src->y*mat->v[2][1]+src->z*mat->v[2][2]+i2f6(mat->v[2][3]);
    }
}

