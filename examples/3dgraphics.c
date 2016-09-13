
#pragma options -machine=coco3

#include <stdio.h>
#include <stdlib.h>
#include <fix6.h>
#include <string.h>
#include <graph.h>
#include <equates.h>
#include <system.h>

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
    unsigned grp[2][2], page = 0;
    vector_t pro1[10], pro2[10];

    *(char*)65495 = 0;

    system("PMODE0");
    system("SCREEN1,1");

    grp[0][0] = _beggrp;
    grp[0][1] = _endgrp;
    system("PMODE,2");
    grp[1][0] = _beggrp;
    grp[1][1] = _endgrp;

    _setcolor(1);
    for (unsigned char a = 0; ; a += 2) {
        system_screen(1);
        page ^= 1;
        _beggrp = grp[page][0];
        _endgrp = grp[page][1];
        memset((void*)_beggrp, 0, _endgrp - _beggrp);
        matrix_rotate_x(&matx, (char)a);
        matrix_rotate_z(&matz, (char)a * 3);
        matrix_multiply(&mat, &matx, &matz);
        mat.v[0][3] = 0;
        mat.v[2][3] = S<<1;
        model_rotate(&obj, &mat, pro1);
        //mat.v[0][3] = -3;
        //mat.v[2][3] = 4;
        //model_rotate(&obj, &mat, pro2);
        _clearscreen(_GCLEARSCREEN);
        model_draw_edges(&obj, pro1);
        //model_draw_edges(&obj, pro2);
    }
    return 0;
}

