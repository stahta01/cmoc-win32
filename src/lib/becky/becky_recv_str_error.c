
#include "_becky.h"

bool becky_recv_str_error(char* dst)
{
    return becky_send_null(BECKY_ERROR) && becky_recv_str(BECKY_READ, dst, BECKY_ERROR_SIZE - 1);
}

