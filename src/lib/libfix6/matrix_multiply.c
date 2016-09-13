
#include "_fix6.h"

void matrix_multiply(matrix_t* a, matrix_t* b, matrix_t* c)
{
    for (char i = 3; i--;) {
        a->v[i][0] = f2i6(c->v[i][0]*b->v[0][0]+c->v[i][1]*b->v[1][0]+c->v[i][2]*b->v[2][0]);
        a->v[i][1] = f2i6(c->v[i][0]*b->v[0][1]+c->v[i][1]*b->v[1][1]+c->v[i][2]*b->v[2][1]);
        a->v[i][2] = f2i6(c->v[i][0]*b->v[0][2]+c->v[i][1]*b->v[1][2]+c->v[i][2]*b->v[2][2]);
        a->v[i][3] = f2i6(c->v[i][0]*b->v[0][3]+c->v[i][1]*b->v[1][3]+c->v[i][2]*b->v[2][3]);
    }
}

