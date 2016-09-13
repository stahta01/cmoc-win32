
#include "_fix6.h"

void matrix_rotate_z(matrix_t* dst, char a)
{
    matrix_identity(dst);
    dst->v[0][0] = +(dst->v[1][1] = cos6(a));
    dst->v[0][1] = -(dst->v[1][0] = sin6(a));
}

