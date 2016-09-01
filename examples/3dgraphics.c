
#include <stdio.h>
#include <stdlib.h>
#include <fixpt.h>

void vec3set(int* vec, int x, int y, int z)
{
    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
}

int main(void)
{
    int a = 100;
    int m[3][3];
    int v1[3], v2[3];

    system("PMODE4,1");
    system("SCREEN1,1");
    system("PCLS");

    vec3set(m[0], 1 << 8, 0, 0);
    vec3set(m[1], 0, 1 << 8, 0);
    vec3set(m[2], 0, 0, 1 << 8);

    vec3set(v1, -127, 64, 0);

    v2[0] = f2i(v1[0]*m[0][0]) + f2i(v1[1]*m[0][1]) + f2i(v1[2]*m[0][2]);
    v2[1] = f2i(v1[0]*m[1][0]) + f2i(v1[1]*m[1][1]) + f2i(v1[2]*m[1][2]);
    v2[2] = f2i(v1[0]*m[2][0]) + f2i(v1[1]*m[2][1]) + f2i(v1[2]*m[2][2]);

    printf("%d\n", v2[0]);

    printf("PSET(%d,%d),1",  f2i(v2[0]), 96 + f2i(v2[1]));

    return 0;
}

