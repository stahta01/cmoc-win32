
#include "_becky.h"

bool becky_data_ready(void)
{
    return becky_data_wait(BECKY_DATA_READY_WAIT);
}

