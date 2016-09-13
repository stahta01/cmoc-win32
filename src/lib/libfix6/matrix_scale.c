
#include "_fix6.h"

void matrix_scale(matrix_t* dst, char x, char y, char z)
{
    memset(dst, 0, sizeof(matrix_t));
    dst->v[0][0] = x;
    dst->v[1][1] = y;
    dst->v[2][2] = z;
}
