
#include "_far.h"

void* far_zoom(far_void_t* memory)
{
    memory->bank = bank_set(memory->bank);
    return memory->data;
}

