
#include "_iff.h"

bool iff_head_read(iff_head_t* head, FILE* fp)
{
    return fread(head, sizeof(iff_head_t), 1, fp) == 1;
}

