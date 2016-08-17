
#include <basic.h>
#include <string.h>

void PCLS(byte c)
{
    memset((void*)_beggrp, c ? 255 : 0, _endgrp - _beggrp);
}

