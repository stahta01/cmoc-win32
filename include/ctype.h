/*---------------------------------------------------------------------------*/
/* ctype.h - character class tests                                           */
/*---------------------------------------------------------------------------*/

#ifndef _CTYPE_H
#define _CTYPE_H

#include <stddef.h>
#include <stdbool.h>

/*---------------------------------------------------------------------------*/
/* function prototpes                                                        */
/*---------------------------------------------------------------------------*/

bool isascii(int c);
bool iscntrl(int c);
bool isdigit(int c);
bool isupper(int c);
bool islower(int c);
bool isprint(int c);
bool isspace(int c);
bool isalpha(int c);
bool isalnum(int c);
bool isgraph(int c);
bool ispunct(int c);
bool isxupper(int c);
bool isxlower(int c);
bool isxdigit(int c);

int toascii(int c);
int toupper(int c);
int tolower(int c);

/*---------------------------------------------------------------------------*/
/* macro definitions                                                         */
/*---------------------------------------------------------------------------*/

#define _isascii(c)  (c > 0 && c <= 0x7f)
#define _iscntrl(c)  ((c > 0) && ((c < ' ') || (c == 0x7f)))
#define _isdigit(c)  (c >= '0' && c <= '9')
#define _isupper(c)  (c >=  'A' && c <= 'Z')
#define _islower(c)  (c >=  'a' && c <= 'z')
#define _isprint(c)  (c >= ' ' && c <= '~')
#define _isspace(c)  (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t')
#define _isalpha(c)  (_isupper(c) || _islower(c))
#define _isalnum(c)  (_isalpha(c) || _isdigit(c))
#define _isgraph(c)  (c != ' ' && _isprint(c))
#define _ispunct(c)  ((c > ' ' && c <= '~') && !_isalnum(c))
#define _isxupper(c) (_isdigit(c) || (c >= 'A' && c <= 'F'))
#define _isxlower(c) (_isdigit(c) || (c >= 'a' && c <= 'f'))
#define _isxdigit(c) (_isxupper(c) || _isxlower(c))
#define _toascii(c)  (c & 0x7f)
#define _toupper(c)  (_islower(c) ? (c - ' ') : (c))
#define _tolower(c)  (_isupper(c) ? (c + ' ') : (c))

#endif

