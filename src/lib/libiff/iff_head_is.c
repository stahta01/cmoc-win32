
#include "_iff.h"

bool iff_head_is(iff_head_t* head, char* type)
{
    return
        (head->type[0] == type[0]) && (head->type[1] == type[1]) &&
        (head->type[2] == type[2]) && (head->type[3] == type[3]);
}

