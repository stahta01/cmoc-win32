
// This is work in progress. Its the start of a minimal 3d maths library


//#pragma options -machine=cocous

#include <stdio.h>
#include <stdlib.h>
#include <fixpt.h>
#include <stdint.h>
#include <string.h>

#include <graph.h>
#include <equates.h>
#include <system.h>

typedef struct {
    int x, y, z;
} vector_t;

typedef struct {
    int v[4][4];
} matrix_t;

typedef struct {
    unsigned char a, b;
} edge_t;

typedef struct {
    unsigned char nvectors;
    vector_t* vectors;
    unsigned char nedges;
    edge_t* edges;
} model_t;

typedef struct {
    int x, y, z, sx, sy;
    int sz;
} projected3_t;

void vector_set(vector_t* dst, char x, char y, char z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

void matrix_scale(matrix_t* dst, char x, char y, char z)
{
    memset(dst, 0, sizeof(matrix_t));
    dst->v[0][0] = x;
    dst->v[1][1] = y;
    dst->v[2][2] = z;
}

void matrix_identity(matrix_t* dst)
{
    matrix_scale(dst, 127, 127, 127);
}

void matrix_position(matrix_t* dst, char x, char y, char z)
{
    matrix_identity(dst);
    dst->v[0][3] = x;
    dst->v[1][3] = y;
    dst->v[2][4] = z;
}

void matrix_rotate_x(matrix_t* dst, char a)
{
    matrix_identity(dst);
    dst->v[1][1] = +(dst->v[2][2] = fxcos(a));
    dst->v[1][2] = -(dst->v[2][1] = fxsin(a));
}

void matrix_rotate_y(matrix_t* dst, char a)
{
    matrix_identity(dst);
    dst->v[0][0] = +(dst->v[2][2] = fxcos(a));
    dst->v[0][2] = -(dst->v[2][0] = fxsin(a));
}

void matrix_rotate_z(matrix_t* dst, char a)
{
    matrix_identity(dst);
    dst->v[0][0] = +(dst->v[1][1] = fxcos(a));
    dst->v[0][1] = -(dst->v[1][0] = fxsin(a));
}

void matrix_process_vectors(matrix_t* mat, vector_t* v, size_t n, projected3_t* o)
{
    for (; n > 0; v++, o++, n--) {
        o->x=(int)v->x*mat->v[0][0]+(int)v->y*mat->v[0][1]+(int)v->z*mat->v[0][2]+((int)mat->v[0][3]<<8);
        o->y=(int)v->x*mat->v[1][0]+(int)v->y*mat->v[1][1]+(int)v->z*mat->v[1][2]+((int)mat->v[1][3]<<8);
        o->z=(int)v->x*mat->v[2][0]+(int)v->y*mat->v[2][1]+(int)v->z*mat->v[2][2]+((int)mat->v[2][3]<<8);
        o->sz = o->z >> 2;
        if (o->sz > 0) {
            o->sx = 64 + ((o->x << 2) / o->sz);
            o->sy = 48 - ((o->y << 2) / o->sz);
        }
    }
}

void matrix_multiply(matrix_t* a, matrix_t* b, matrix_t* c)
{
    for (char i = 3; i--;) {
        a->v[i][0] = ((int)c->v[i][0]*b->v[0][0]+(int)c->v[i][1]*b->v[1][0]+(int)c->v[i][2]*b->v[2][0])>>7;
        a->v[i][1] = ((int)c->v[i][0]*b->v[0][1]+(int)c->v[i][1]*b->v[1][1]+(int)c->v[i][2]*b->v[2][1])>>7;
        a->v[i][2] = ((int)c->v[i][0]*b->v[0][2]+(int)c->v[i][1]*b->v[1][2]+(int)c->v[i][2]*b->v[2][2])>>7;
        a->v[i][3] = ((int)c->v[i][0]*b->v[0][3]+(int)c->v[i][1]*b->v[1][3]+(int)c->v[i][2]*b->v[2][3])>>7;
    }
}

void model_rotate(model_t* model, matrix_t* mat, projected3_t* pro)
{
    matrix_process_vectors(mat, model->vectors, model->nvectors, pro);
}

void model_draw_points(model_t* model, projected3_t* pv)
{
    for (unsigned char n = model->nvectors; n > 0; n--, pv++) {
        if (pv->sz > 0) {
            _setpixel(pv->sx, pv->sy);
        }
    }
}

void model_draw_edges(model_t* model, projected3_t* pv)
{
    _allcol = -1;
    edge_t* edges = model->edges;
    for (unsigned char n = model->nedges; n > 0; n--, edges++) {
        if (pv[edges->a].sz > 0) {
            _horbeg = pv[edges->a].sx;
            _verbeg = pv[edges->a].sy;
            _horend = pv[edges->b].sx;
            _verend = pv[edges->b].sy;
            system_line();
        }
    }
}


#define S 3

vector_t vectors[8] = {
    {+S, +S, +S},
    {+S, -S, +S},
    {-S, -S, +S},
    {-S, +S, +S},
    {+S, +S, -S},
    {+S, -S, -S},
    {-S, -S, -S},
    {-S, +S, -S}
};

edge_t edges[12] = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0},
    {4, 5}, {5, 6}, {6, 7}, {7, 4},
    {0, 4}, {1, 5}, {2, 6}, {3, 7}
};

model_t obj = {
    8, vectors,
    12, edges
};



unsigned asm test(char a, char b)
{
    asm {
        lda 3,s
        ldb 5,s
        mul
    }
}

int main(void)
{

    char a = -10, b = 2;

    printf("%d\n", a * b);

    return 0;

    matrix_t matx, matz, mat;
    projected3_t pro1[10];
    projected3_t pro2[10];

    *(char*)65495 = 0;

    system("PMODE0,1");
    system("SCREEN1,1");
    system("PCLS");

    _setcolor(1);
    for (unsigned char a = 0; ; a += 2) {
        matrix_rotate_x(&matx, (char)a);
        matrix_rotate_z(&matz, (char)a * 3);
        matrix_multiply(&mat, &matx, &matz);
        mat.v[0][3] = 3;
        mat.v[2][3] = 4;
        model_rotate(&obj, &mat, pro1);
        mat.v[0][3] = -3;
        mat.v[2][3] = 4;
        model_rotate(&obj, &mat, pro2);
        _clearscreen(_GCLEARSCREEN);
        model_draw_edges(&obj, pro1);
        model_draw_edges(&obj, pro2);
    }
    return 0;
}

