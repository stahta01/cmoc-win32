
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
} _jmp6809_t;

// Byte variable
#define _BYTEVAR(addr) (*(byte*)(addr))

// Word variable
#define _WORDVAR(addr) (*(word*)(addr))

// Address variable
#define _ADDRVAR(addr) (*(word*)(addr))

// Pointer to type variable
#define _PTRTYPE(addr,type) ((type*)_ADDRVAR(addr))

// Pointer to function
#define _FUNCVAR(addr) ((void*)(addr))

// Pointer to jump
#define _JUMPVAR(addr) (*(_jmp6809_t*)(addr))

#define _HIBYTE(A) ((byte*)&(A))[0]
#define _LOBYTE(A) ((byte*)&(A))[1]

#endif

