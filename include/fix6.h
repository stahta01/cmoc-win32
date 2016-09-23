
/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

Derek John Evans <https://sourceforge.net/u/buzzphp/profile/>
*/

#ifndef _FIX6_H
#define _FIX6_H

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
    byte nvectors;
    vector_t* vectors;
    byte nedges;
    edge_t* edges;
} model_t;

#define i2f6(X) (((int)(X))<<6)
#define f2i6(X) (((int)(X))>>6)

char sin6(int x);
char cos6(int x);

void vector_set(vector_t* dst, int x, int y, int z);

void matrix_scale(matrix_t* dst, int x, int y, int z);
void matrix_identity(matrix_t* dst);
void matrix_position(matrix_t* dst, int x, int y, int z);
void matrix_rotate_x(matrix_t* dst, int a);
void matrix_rotate_y(matrix_t* dst, int a);
void matrix_rotate_z(matrix_t* dst, int a);
void matrix_multiply(matrix_t* a, matrix_t* b, matrix_t* c);
void matrix_process_vectors(matrix_t* mat, vector_t* v, int n, vector_t* o);

void model_rotate(model_t* model, matrix_t* mat, vector_t* pro);
void model_draw_points(model_t* model, vector_t* pv);
void model_draw_edges(model_t* model, vector_t* pv);

#endif

