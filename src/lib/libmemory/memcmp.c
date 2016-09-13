
#define memcmp __obsolete

#include "_memory.h"

int memcmp(void* buf1,  void* buf2, size_t count)
{
    char* p1, *p2;
    int result = 0;
    p1 = (char*)buf1;
    p2 = (char*)buf2;
    while (count) {
        if (*p1 != *p2) {
            result = 1;
            if (*p1 < *p2) {
                result = -1;
            }
            break;
        }
        p1++;
        p2++;
        count--;
    }
    return (result);
}

