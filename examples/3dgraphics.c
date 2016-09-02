
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
    m[1][1] = (m[2][2] = (char)fxcos(a));
    m[1][2] = - (m[2][1] = (char)fxsin(a));
}

void matroty(defmat3(m), char a)
{
    matident(m);
    m[0][0] = (m[2][2] = (char)fxcos(a));
    m[0][2] = - (m[2][0] = (char)fxsin(a));
}

void matrotz(defmat3(m), char a)
{
    matident(m);
    m[0][0] = (m[1][1] = (char)fxcos(a));
    m[0][1] = - (m[1][0] = (char)fxsin(a));
}

#define asm_dot() asm{ lda ,y+} asm{ ldb ,s+} asm{ mul} asm{ addd ,x} asm{ std ,x}

void test(int* dst, char* src, char* mat)
{
    int stack;
    asm {
        sts     stack
        ldx     dst
        ldy     src
        lds     mat
        clra
        clrb
        std     ,x
    }
    asm_dot();
    asm_dot();
    asm_dot();
    asm {
        leax    2,x
        ldy     src
    }
    asm_dot();
    asm_dot();
    asm_dot();
    asm {
        leax    2,x
        ldy     src
    }
    asm_dot();
    asm_dot();
    asm_dot();
    asm {
        lds    stack
    }
}

void testing(void)
{
    char s[3];
    char m[3][3];
    int d[3];

    s[0] = 1;
    s[1] = 2;
    s[2] = 3;

    m[0][0] = 10;
    m[0][1] = 20;
    m[0][2] = 30;
    // (1 * 10) + (2 * 20) = 50

    test(d, s, m[0]);

    printf("%d\n", d[0]);
}

int main(void)
{
    defmat3(m);
    defvec3(v1);
    defvec3(v2);

    //testing();
    //return 0;

    system("PMODE4,1");
    system("SCREEN1,1");
    system("PCLS");

    char x = 10, y = 20;
    printf("%d\n", x * y);

    for (int a = 0; a < 256; a++) {
        matrotz(m, (char)a);
        vec3set(v1, 64, 64, 0);
        v2[0] = f2i((int)v1[0]*m[0][0]) + f2i((int)v1[1]*m[0][1]) + f2i((int)v1[2]*m[0][2]);
        v2[1] = f2i((int)v1[0]*m[1][0]) + f2i((int)v1[1]*m[1][1]) + f2i((int)v1[2]*m[1][2]);
        v2[2] = f2i((int)v1[0]*m[2][0]) + f2i((int)v1[1]*m[2][1]) + f2i((int)v1[2]*m[2][2]);
        MSET(128 + (v2[0] >> 1), 96 + (v2[1] >> 1), 1);
    }
    return 0;
}

