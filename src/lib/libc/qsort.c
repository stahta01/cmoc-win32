/*---------------------------------------------------------------------------*/
/* qsort() - perform a quicksort on an array                                 */
/*---------------------------------------------------------------------------*/

#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include <winerror.h>

void _qsort(char* ptr, char* temp, int left, int right, size_t width,
            int(*cmp)(void* elem1, void* elem2));

void _qswap(char* ptr, char* temp, int i, int j, size_t width);

void qsort(void* base, size_t num, size_t width,
           int(*cmp)(void* elem1, void* elem2))
{
    char* temp;
    int left = 0;
    int right = num - 1;
    if (left >= right) {
        return;
    }
    temp = (char*) malloc(width);
    if (temp != NULL) {
        _qsort((char*)base, temp, left, right, width, cmp);
        free(temp);
    } else {
        _crt_base->_crt_errno = ENOMEM;
        _crt_base->_crt_doserrno = ERROR_NOT_ENOUGH_MEMORY;
    }
}

void _qsort(char* ptr, char* temp, int left, int right, size_t width,
            int(*cmp)(void* elem1, void* elem2))
{
    int i, last;
    if (left >= right) {
        return;
    }
    _qswap(ptr, temp, left, (left + right) / 2, width);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*cmp)(ptr + (i * width), ptr + (left * width)) < 0) {
            _qswap(ptr, temp, ++last, i, width);
        }
    _qswap(ptr, temp, left, last, width);
    _qsort(ptr, temp, left, last - 1, width, cmp);
    _qsort(ptr, temp, last + 1, right, width, cmp);
}

void _qswap(char* ptr, char* temp, int i, int j, size_t width)
{
    size_t index;
    char* p1, *p2;
    p1 = ptr + (i * width);
    p2 = ptr + (j * width);
    for (index = 0; index < width; index++) {
        *temp++ = *p1++;
    }
    p1 -= width;
    temp -= width;
    for (index = 0; index < width; index++) {
        *p1++ = *p2++;
    }
    p2 -= width;
    for (index = 0; index < width; index++) {
        *p2++ = *temp++;
    }
}
