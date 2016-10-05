
#include "_fix6.h"

void matrix_rotate_y(matrix_t* dst, int a)
{
    matrix_identity(dst);
    dst->v[0][0] = +(dst->v[2][2] = cos6(a));
    dst->v[0][2] = -(dst->v[2][0] = sin6(a));
}

