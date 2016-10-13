
#include "_fix6.h"

void matrix_rotate_z(matrix_t* dst, int ang)
{
    matrix_identity(dst);
    dst->v[0][0] = +(dst->v[1][1] = cos6(ang));
    dst->v[0][1] = -(dst->v[1][0] = sin6(ang));
}

