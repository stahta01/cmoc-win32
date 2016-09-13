
#include "_fix6.h"

void matrix_position(matrix_t* dst, char x, char y, char z)
{
    matrix_identity(dst);
    dst->v[0][3] = x;
    dst->v[1][3] = y;
    dst->v[2][4] = z;
}

