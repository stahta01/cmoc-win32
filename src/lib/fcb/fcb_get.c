
#include "_fcb.h"

fcb_t* fcb_get(int index)
{
    return index >= 0 && index < fcb_act() ? (fcb_t*)((word*)_FCBV1)[index] : (fcb_t*)nullptr;
}

