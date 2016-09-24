
#include "_graph.h"

int _getactivepage(void)
{
    return ((_beggrp - ((word)_grpram << 8)) / 1536) + 1;
}

