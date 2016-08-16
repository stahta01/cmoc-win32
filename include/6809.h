
#ifndef _6809_H
#define _6809_H

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE  1
#endif

typedef unsigned char byte;
typedef signed char   sbyte;
typedef unsigned int  word;
typedef signed int    sword;

typedef struct
{
    byte cmd;
    void* addr;
} _jump_t;

#define _BYTEPTR(addr) (*(byte*)(addr))
#define _WORDPTR(addr) (*(word*)(addr))
#define _TYPEPTR(addr,type) ((type*)*(word*)(addr))
#define _FUNCPTR(addr) ((void*)(addr))
#define _JUMPPTR(addr) (*(_jump_t*)(addr))

#define _HIBYTE(A) ((byte*)&(A))[0]
#define _LOBYTE(A) ((byte*)&(A))[1]

#endif

