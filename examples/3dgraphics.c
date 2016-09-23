
#include <stdio.h>
#include <stdlib.h>
#include <fix6.h>
#include <string.h>
#include <graph.h>
#include <system.h>
#include <equates.h>

#define S 32

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
    matrix_t matx, matz, mat;
    word grp[2][2], page = 0;
    vector_t tmp[20];

    *(byte*)65495 = 0;

    system("PMODE0");
    system("SCREEN1,1");

    grp[0][0] = _beggrp;
    grp[0][1] = _endgrp;
    system("PMODE,2");
    grp[1][0] = _beggrp;
    grp[1][1] = _endgrp;

    _setcolor(1);
    for (byte a = 0; ; a += 2) {
        system_screen(1);
        page ^= 1;
        _beggrp = grp[page][0];
        _endgrp = grp[page][1];
        memset((void*)_beggrp, 0, _endgrp - _beggrp);
        matrix_rotate_x(&matx, a);
        matrix_rotate_z(&matz, a * 3);
        matrix_multiply(&mat, &matx, &matz);
        mat.v[0][3] = 0;
        mat.v[2][3] = S<<1;
        model_rotate(&obj, &mat, tmp, 64, 48);
        _clearscreen(_GCLEARSCREEN);
        model_draw_edges(&obj, tmp);
    }
    return 0;
}

