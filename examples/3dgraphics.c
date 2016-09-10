
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
    char x, y, z;
} vector_t;

typedef struct {
    unsigned char a, b;
} edge_t;

typedef struct {
    unsigned char nvectors;
    vector_t* vectors;
    unsigned char nedges;
    edge_t* edges;
} object_t;

typedef struct {
    int x, y, z, sx, sy;
    char sz;
} projected_t;

void vecset(vector_t* v, char x, char y, char z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

void matscale(char* m, char x, char y, char z)
{
    memset(m, 0, 12);
    m[0] = x;
    m[5] = y;
    m[10] = z;
}

void matident(char* m)
{
    matscale(m, 127, 127, 127);
}

void matpos(char* m, char x, char y, char z)
{
    matident(m);
    m[3] = x;
    m[7] = y;
    m[11] = z;
}

void matrotx(char* m, char a)
{
    matident(m);
    m[5] = +(m[10] = fxcos(a));
    m[6] = -(m[11] = fxsin(a));
}

void matroty(char* m, char a)
{
    matident(m);
    m[0] = +(m[10] = fxcos(a));
    m[2] = -(m[8] = fxsin(a));
}

void matrotz(char* m, char a)
{
    matident(m);
    m[0] = +(m[5] = fxcos(a));
    m[1] = -(m[4] = fxsin(a));
}

void matmulnvec(char* m, vector_t* v, size_t n, projected_t* o)
{
    for (; n > 0; v++, o++, n--) {
        o->x=(int)v->x*m[0]+(int)v->y*m[1]+(int)v->z*m[2]+((int)m[3]<<8);
        o->y=(int)v->x*m[4]+(int)v->y*m[5]+(int)v->z*m[6]+((int)m[7]<<8);
        o->z=(int)v->x*m[8]+(int)v->y*m[9]+(int)v->z*m[10]+((int)m[11]<<8);
        o->sz = (char)(o->z >> 4);
        if (o->sz > 0) {
            o->sx = 64 + (o->x / o->sz);
            o->sy = 48 - (o->y / o->sz);
        }
    }
}

void objectrotate(object_t* obj, char* mat, projected_t* pro)
{
    matmulnvec(mat, obj->vectors, obj->nvectors, pro);
}

void objectdrawpoints(object_t* obj, projected_t* pv)
{
    for (unsigned char n = obj->nvectors; n > 0; n--, pv++) {
        if (pv->sz > 0) {
            _setpixel(pv->sx, pv->sy);
        }
    }
}

void test(int x1, int y1, int x2, int y2)
{
    _allcol = -1;
    _horbeg = x1;
    _verbeg = y1;
    _horend = x2;
    _verend = y2;
    system_line();
}

void objectdrawedges(object_t* obj, projected_t* pv)
{
    edge_t* edges = obj->edges;
    for (unsigned char n = obj->nedges; n > 0; n--, edges++) {
        if (pv[edges->a].sz > 0) {
            test(pv[edges->a].sx, pv[edges->a].sy, pv[edges->b].sx, pv[edges->b].sy);
        }
    }
}


vector_t vectors[8] = {
    {+1, +1, +1},
    {+1, -1, +1},
    {-1, -1, +1},
    {-1, +1, +1},
    {+1, +1, -1},
    {+1, -1, -1},
    {-1, -1, -1},
    {-1, +1, -1}
};

edge_t edges[12] = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0},
    {4, 5}, {5, 6}, {6, 7}, {7, 4},
    {0, 4}, {1, 5}, {2, 6}, {3, 7}
};

object_t obj = {
    8, vectors,
    12, edges
};



int main(void)
{
    char mat[12];
    projected_t pro[20];

    system("PMODE0,1");
    system("SCREEN1,1");
    system("PCLS");

    _setcolor(1);
    for (unsigned char a = 0; ; a += 5) {
        matrotz(mat, (char)a);
        mat[11] = 1;
        objectrotate(&obj, mat, pro);
        _clearscreen(_GCLEARSCREEN);
        objectdrawedges(&obj, pro);
    }
    return 0;
}

