
#ifndef _WINDEF_H
#define _WINDEF_H

#define VOID void
#define CHAR char
#define INT int
#define BYTE unsigned char
#define WORD unsigned int
#define BOOL unsigned char
#define PBYTE unsigned char*
#define PWORD unsigned int*

#define HIBYTE(A) ((BYTE*)&(A))[0]
#define LOBYTE(A) ((BYTE*)&(A))[1]

#endif

