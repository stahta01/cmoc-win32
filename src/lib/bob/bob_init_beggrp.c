
#include "_bob.h"

void bob_init_beggrp(bob_t* bob)
{
    bob_init(bob, _horbyt, (_endgrp - _beggrp) / _horbyt, _horbyt, (void*)_beggrp, false);
}

