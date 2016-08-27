
/*---------------------------------------------------------------------------*/
/* _strtoul() - low level conversion of a string of base n to an unsigned    */
/*              long integer                                                 */
/*                                                                           */
/* Note: this module also includes the strtol() and strtoul() functions.     */
/*---------------------------------------------------------------------------*/

#include <crt.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <llmath.h>

unsigned long _strtoul(char* nptr, char** endptr, int base, int svalue)
{
    char nbmax;
    int tbase = 0;
    int ovflo = 0;
    char sign = 0;
    char cbmax = 0;
    unsigned long digit;
    unsigned long tvalue;
    unsigned long maxval;
    unsigned long errval;
    unsigned long maxpos;
    unsigned long value = 0;
    while ((*nptr == ' ') || (*nptr == '\t') || *nptr == '\n' || *nptr == '\r') {
        nptr++;
    }
    if ((*nptr == '-') || (*nptr == '+')) {
        sign = *nptr;
        nptr++;
    }
    if (*nptr == '0') {
        nptr++;
        if ((*nptr == 'X') || (*nptr == 'x')) {
            tbase = 16;
        } else {
            tbase = 8;
        }
    } else {
        tbase = 10;
    }
    if (!base) {
        base = tbase;
    }
    if ((base == 16) && (tbase == 16)) {
        nptr++;
    }
    if (base <= 10) {
        nbmax = (char)((char)'0' + (char)(base - 1));
    } else {
        nbmax = '9';
        cbmax = (char)((char)'a' + (char)(base - 11));
    }
    if (svalue) {
        maxval = LONG_MAX;
        errval = LONG_MAX;
        if (sign == '-') {
            maxval = -LONG_MIN;
            errval = (unsigned long)LONG_MIN;
        } else {
            maxval = LONG_MAX;
            errval = LONG_MAX;
        }
    } else {
        maxval = ULONG_MAX;
        errval = ULONG_MAX;
    }
    maxpos = _div32(maxval, (unsigned long)base);
    while (*nptr && !ovflo) {
        if ((*nptr >= '0') && (*nptr <= nbmax)) {
            digit = *nptr - '0';
        } else if ((*nptr >= 'a') && (*nptr <= cbmax)) {
            digit = (*nptr - 'a') + 10;
        } else if ((*nptr >= 'A') && (*nptr <= (char)toupper(cbmax))) {
            digit = (*nptr - 'A') + 10;
        } else {
            break;
        }
        if (value > maxpos) {
            ovflo++;
        } else {
            tvalue = _mul32(value, (unsigned long)base);
            if (digit > (maxval - tvalue)) {
                ovflo++;
            } else {
                value = tvalue + digit;
                nptr++;
            }
        }
    }
    if (!ovflo) {
        if (sign == '-') {
            value = -(long)value;
        }
    } else {
        _crt_base->_crt_errno = ERANGE;
        value = errval;
    }
    if (endptr != NULL) {
        *endptr = (char*)nptr;
    }
    return (value);
}

/*---------------------------------------------------------------------------*/
/* strtoul() - convert a string of base n to an unsigned long integer        */
/*---------------------------------------------------------------------------*/
unsigned long strtoul(const char* nptr, char** endptr, int base)
{
    return (_strtoul(nptr, endptr, base, 0));
}

/*---------------------------------------------------------------------------*/
/* strtol() - convert a string of base n to a signed long integer            */
/*---------------------------------------------------------------------------*/
long strtol(const char* nptr, char** endptr, int base)
{
    return (_strtoul(nptr, endptr, base, 1));
}

