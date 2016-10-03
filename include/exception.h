
/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

Derek John Evans <https://sourceforge.net/u/buzzphp/profile/>
*/

#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#include <errno.h>
#include <setjmp.h>
#include <rvec.h>

typedef struct {
    errno_t errno;
    word line;
} exception_t, *exception_ptr;

typedef struct try_block_t {
    struct try_block_t* prev;
    jmp_buf_t jump;
    rvec_t rvec;
    exception_t exception;
} try_block_t;

#define current_exception  (&_current_exception)

void exception_throw(errno_t errno, word line);

#define try {try_block_t try_block;if(try_block_init(&try_block,setjmp(&try_block.jump)))
#define except try_block_done(&try_block);}if(_current_exception.errno!=ERRNO_NONE)
#define throw(_ERRNO,_LINE) exception_throw(_ERRNO,_LINE)
#define rethrow throw(_current_exception.errno,_current_exception.line)

// internal use only

extern exception_t _current_exception;

bool try_block_init(try_block_t* try_block, int jmp_return);
void try_block_done(try_block_t* try_block);

#endif

