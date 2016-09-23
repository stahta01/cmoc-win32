
#include "_fix6.h"

void model_rotate(model_t* model, matrix_t* mat, vector_t* vec, int x, int y)
{
    vector_rotate(vec, model->vectors, model->nvectors, mat);
    vector_project(vec, vec, model->nvectors, x, y);
}

