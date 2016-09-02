
#include <stdio.h>
#include <stdlib.h>
#include <fixpt.h>
#include <stdint.h>

#include <basic.h>

#define defvec2(a) char a[2]
#define defvec3(a) char a[3]
#define defmat2(a) char a[2][3]
#define defmat3(a) char a[3][4]

void vec3set(defvec3(v), char x, char y, char z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

void matident(defmat3(m))
{
    vec3set(m[0], 127, 0, 0);
    vec3set(m[1], 0, 127, 0);
    vec3set(m[2], 0, 0, 127);
}

void matpos(defmat3(m), char x, char y, char z)
{
    matident(m);
    m[0][3] = x;
    m[1][3] = y;
    m[2][3] = z;
}

void matscale(defmat3(m), char x, char y, char z)
{
    matident(m);
    m[0][0] = x;
    m[1][1] = y;
    m[2][2] = z;
}

void matrotx(defmat3(m), char a)
{
    matident(m);
    m[1][1] = (m[2][2] = fxcos(a));
    m[1][2] = - (m[2][1] = fxsin(a));
}

void matroty(defmat3(m), char a)
{
    matident(m);
    m[0][0] = (m[2][2] = fxcos(a));
    m[0][2] = - (m[2][0] = fxsin(a));
}

void matrotz(defmat3(m), char a)
{
    matident(m);
    m[0][0] = (m[1][1] = fxcos(a));
    m[0][1] = - (m[1][0] = fxsin(a));
}

int main(void)
{
    defmat3(mat);
    defvec3(v1);
    int v2[3];

    system("PMODE4,1");
    system("SCREEN1,1");
    system("PCLS");

    for (int a = 0; a < 256; a++) {
        matrotz(mat, (char)a);
        char* m = &mat[0][0];
        vec3set(v1, 0, 64, 0);
        v2[0]=(int)v1[0]*m[0]+(int)v1[1]*m[1]+(int)v1[2]*m[2];
        v2[1]=(int)v1[0]*m[4]+(int)v1[1]*m[5]+(int)v1[2]*m[6];
        v2[2]=(int)v1[0]*m[8]+(int)v1[1]*m[9]+(int)v1[2]*m[10];
        MSET(128 - (v2[0] >> 8), 96 - (v2[1] >> 8), 1);
    }
    return 0;
}

