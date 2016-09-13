
#include "_fix6.h"

void model_rotate(model_t* model, matrix_t* mat, vector_t* pro)
{
    matrix_process_vectors(mat, model->vectors, model->nvectors, pro);
}

