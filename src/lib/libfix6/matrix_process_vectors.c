
#include "_fix6.h"

void matrix_process_vectors(matrix_t* mat, vector_t* v, int n, vector_t* o)
{
    for (; n > 0; v++, o++, n--) {
        o->x = v->x*mat->v[0][0]+v->y*mat->v[0][1]+v->z*mat->v[0][2]+i2f6(mat->v[0][3]);
        o->y = v->x*mat->v[1][0]+v->y*mat->v[1][1]+v->z*mat->v[1][2]+i2f6(mat->v[1][3]);
        o->z = v->x*mat->v[2][0]+v->y*mat->v[2][1]+v->z*mat->v[2][2]+i2f6(mat->v[2][3]);
        o->z = o->z >> 4;
        if (o->z > 0) {
            o->x = 64 + o->x / o->z;
            o->y = 48 - o->y / o->z;
        }
    }
}

