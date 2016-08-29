
#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H

#include <sys/size.h>

int mlock(void* addr, size_t len);
int munlock(void* addr, size_t len);

int mlockall(int flags);
int munlockall(void);

#endif

