
#include "_bob.h"

bob_t* bob_create(int width, int height)
{
    return bob_create_with(width, height, (byte*)calloc(width, height), width, true);
}

