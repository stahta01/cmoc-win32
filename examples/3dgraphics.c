
#include <stdio.h>
#include <stdlib.h>
#include <fix6.h>
#include <string.h>
#include <graph.h>
#include <system.h>
#include <equates.h>

#define S 32
                   //9,057 bytes
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

int main(void)
{
    int page = 0;
    matrix_t matx, matz, mat;
    vector_t tmp[20];

    // Speed poke. We are using ROM's line draw routine, so this will speed
    // up rendering.
    *(byte*)65495 = 0;

    _setvideomode(0, 1);
    _setcolor(1);

    for (byte a = 0; ; a += 2) {
        page ^= 1;
        _setactivepage(page + 1);
        _clearscreen(_GCLEARSCREEN);
        matrix_rotate_x(&matx, a);
        matrix_rotate_z(&matz, a * 3);
        matrix_multiply(&mat, &matx, &matz);
        mat.v[0][3] = 0;
        mat.v[2][3] = S<<1;
        model_rotate(&obj, &mat, tmp, 64, 48);
        model_draw_edges(&obj, tmp);
        _setvisualpage(page + 1);
    }
    return 0;
}

