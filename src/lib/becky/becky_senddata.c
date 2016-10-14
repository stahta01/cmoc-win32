
#include "_becky.h"

bool becky_senddata(word type, byte* src, size_t size)
{
    bool result = becky_sendword(type) && becky_sendword(size);
    while (result && size-- && (result = becky_sendbyte(*src++)));
    return result;
}

