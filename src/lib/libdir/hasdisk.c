
#include "_dir.h"

// Chekcing the value of _grpram seems like the most
// common way to check for a disk rom. There might be better
// ways. Note: This works for a Dragon too.

bool hasdisk(void)
{
    return _grpram > 6;
}

