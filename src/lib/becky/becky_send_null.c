
#include "_becky.h"

bool becky_send_null(word type)
{
    return becky_send_data(type, nullptr, 0);
}

