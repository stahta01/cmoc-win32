
#include <stdio.h>
#include <stdlib.h>
#include <fixpt.h>
#include <stdint.h>

#include <graph.h>

void vecset(char* v, char x, char y, char z, char t)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = t;
}

void matident(char* m)
{
    vecset(m + 0, 127, 0, 0, 0);
    vecset(m + 4, 0, 127, 0, 0);
    vecset(m + 8, 0, 0, 127, 0);
}

void matpos(char* m, char x, char y, char z)
{
    matident(m);
    m[3] = x;
    m[7] = y;
    m[11] = z;
}

void matscale(char* m, char x, char y, char z)
{
    matident(m);
    m[0] = x;
    m[5] = y;
    m[10] = z;
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

void matmulvec(char* m, char* v, int* out)
{
    out[0]=(int)v[0]*m[0]+(int)v[1]*m[1]+(int)v[2]*m[2]+((int)m[3]<<8);
    out[1]=(int)v[0]*m[4]+(int)v[1]*m[5]+(int)v[2]*m[6]+((int)m[7]<<8);
    out[2]=(int)v[0]*m[8]+(int)v[1]*m[9]+(int)v[2]*m[10]+((int)m[11]<<8);
}


int main(void)
{
    char m[12];
    char v1[4];
    int v2[4];

    system("PMODE4,1");
    system("SCREEN1,1");
    system("PCLS");

    vecset(v1, 0, 64, 0, 0);

    _setcolor(3);
    for (int a = 0; a < 256; a++) {
        matrotz(m, (char)a);
        matmulvec(m, v1, v2);
        _setpixel(128 + (v2[0] >> 8), 96 - (v2[1] >> 8));
    }
    return 0;
}

