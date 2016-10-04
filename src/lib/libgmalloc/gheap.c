
#include "_gmalloc.h"

bool _static_gheap_setup;

heap_t* gheap(void)
{
    if (!_static_gheap_setup) {
        heap_init((heap_t*)_beggrp, _endgrp - _beggrp);
    }
    return (heap_t*)_beggrp;
}

