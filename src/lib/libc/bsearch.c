
/*---------------------------------------------------------------------------*/
/* bsearch() - perform a binary search on an array                           */
/*---------------------------------------------------------------------------*/

#include <stdlib.h>

void* bsearch(void* keyval,  void* base, size_t num, size_t width,
              int(*cmp)(void* keyval,  void* elem))
{
    int mid;
    int low = 0;
    int high = num - 1;
    char* ptr, *midptr;
    ptr = (char*)base;
    while (low <= high) {
        mid = (low + high) / 2;
        midptr = ptr + (mid * width);
        if ((*cmp)(keyval, midptr) < 0) {
            high = mid - 1;
        } else if ((*cmp)(keyval, midptr) > 0) {
            low = mid + 1;
        } else {
            return ((void*)midptr);
        }
    }
    return (NULL);
}



