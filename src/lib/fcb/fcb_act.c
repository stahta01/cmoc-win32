
#include "_fcb.h"

int fcb_act(void)
{
    // TODO: Maybe fcbact is 0 anyway?
    return _grpram > 6 ? _fcbact : 0;
}

