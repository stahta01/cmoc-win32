
#include "_cardgame.h"

// Concatenates one or more strings into an output buffer.
// out: Output buffer.
// max: Maximum number of characters to write to the output buffer,
//      including the terminating '\0'.
//
// CAUTION: The last argument MUST be a null pointer.
//
// If the input strings together contain too many characters,
// the concatenation stops at 'max'.
// The returned string always finishes with a terminating '\0'.
//
void _concat(char* out, unsigned max, ...)
{
    va_list ap;
    va_start(ap, max);
    for (char* src; src = va_arg(ap, char*);) { // for each string passed as an argument
        word len = strlen(src);
        if (len > max - 1) {
            len = max - 1;
        }
        max -= len;
        while (len--) {                     // while that string is not finished
            *out++ = *src++;
        }
        if (max <= 1) {
            break;
        }
    }
    va_end(ap);
    *out = '\0';
}

