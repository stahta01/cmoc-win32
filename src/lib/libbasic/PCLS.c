
#include <basic.h>
#include <string.h>

void PCLS(int c)
{
    memset((void*)_beggrp, c ? 255 : 0, _endgrp - _beggrp);
}

