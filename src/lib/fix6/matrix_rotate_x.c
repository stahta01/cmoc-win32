
#include "_fix6.h"

void matrix_rotate_x(matrix_t* dst, int a)
{
    matrix_identity(dst);
    dst->v[1][1] = +(dst->v[2][2] = cos6(a));
    dst->v[1][2] = -(dst->v[2][1] = sin6(a));
}

