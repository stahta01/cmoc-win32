
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
    unsigned char nvectors;
    vector_t* vectors;
    unsigned char nedges;
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

