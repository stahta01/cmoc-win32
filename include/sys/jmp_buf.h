
#ifndef _SYS_JMP_BUF_H
#define _SYS_JMP_BUF_H

typedef struct {
    word s, pc, u, y;
} jmp_buf_t;

#endif

