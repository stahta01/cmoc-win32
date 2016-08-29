
#include "_disk.h"

// Normalizes the filename in 'src' into the 12-byte buffer
// designated by 'dest'.
// Expects period as extension separator in 'src'.
// Converts letters to upper case.
// Pads filename and extension with spaces.
// Writes 11 non-null characters to the destination buffer,
// followed by a terminating '\0' character.
//
void _normalizeFilename(char* dest, char* src)
{
    char* reader = src;
    byte i;
    for (i = 0; i < 8; ++i) { // copy filename until period
        if (*reader == '.') {
            ++reader;  // skip the point: it is not part of the extension
            break;
        }
        if (*reader == 0) {
            break;
        }
        *dest = (char) toupper(*reader);
        ++dest;
        ++reader;
    }
    if (i == 8) { // if filename is at least 8 chars long
        // Check if filename too long.
        while (*reader != 0 && *reader != '.') {
            ++reader;
        }
        if (*reader == '.') { // skip the point
            ++reader;
        }
    } else
        while (i < 8) { // pad filename with spaces
            *dest++ = ' ';
            ++i;
        }
    for (i = 0; i < 3; ++i) { // copy extension
        if (*reader == 0) {
            break;
        }
        *dest = (char) toupper(*reader);
        ++reader;
        ++dest;
    }
    while (i < 3) { // pad extension with spaces
        *dest++ = ' ';
        ++i;
    }
    *dest = '\0';
}


