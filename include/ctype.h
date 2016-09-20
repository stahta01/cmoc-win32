
#ifndef _CTYPE_H
#define _CTYPE_H

#include <stddef.h>

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

#define _isascii(_c) ((_c) >= 0 && (_c) <= 0x7f)
#define _iscntrl(_c) (((_c) >= 0) && (((_c) < ' ') || ((_c) == 0x7f)))
#define _isdigit(_c) ((_c) >= '0' && (_c) <= '9')
#define _isupper(_c) ((_c) >= 'A' && (_c) <= 'Z')
#define _islower(_c) ((_c) >= 'a' && (_c) <= 'z')
#define _isprint(_c) ((_c) >= ' ' && (_c) <= '~')
#define _isspace(_c) ((_c) == ' ' || (_c) == '\f' || (_c) == '\n' || (_c) == '\r' || (_c) == '\t')
#define _isalpha(_c) (_isupper(_c) || _islower(_c))
#define _isalnum(_c) (_isalpha(_c) || _isdigit(_c))
#define _isgraph(_c) ((_c) != ' ' && _isprint(_c))
#define _ispunct(_c) (((_c) > ' ' && (_c) <= '~') && !_isalnum(_c))
#define _isxupper(_c) (_isdigit(_c) || ((_c) >= 'A' && (_c) <= 'F'))
#define _isxlower(_c) (_isdigit(_c) || ((_c) >= 'a' && (_c) <= 'f'))
#define _isxdigit(_c) (_isxupper(_c) || _isxlower(_c))
#define _toascii(_c) ((_c) & 0x7f)
#define _toupper(_c) (_islower(_c) ? ((_c) - ' ') : (_c))
#define _tolower(_c) (_isupper(_c) ? ((_c) + ' ') : (_c))

#endif

