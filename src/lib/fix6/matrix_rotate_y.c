
#include "_fix6.h"

void matrix_rotate_y(matrix_t* dst, int ang)
{
    matrix_identity(dst);
    dst->v[0][0] = +(dst->v[2][2] = cos6(ang));
    dst->v[0][2] = -(dst->v[2][0] = sin6(ang));
}

