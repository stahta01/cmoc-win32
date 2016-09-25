
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

#ifndef _FAR_H
#define _FAR_H

#include <sys/size.h>

#include <hank.h>

#define far_type(TYPE) typedef struct {hank_t* hank; TYPE* data; bank_t bank;}

far_type(void)  far_void_t;
far_type(char)  far_char_t;
far_type(int)   far_int_t;
far_type(byte)  far_byte_t;
far_type(word)  far_word_t;

far_void_t* far_malloc(far_void_t* dst, size_t size);
far_void_t* far_calloc(far_void_t* dst, size_t count, size_t size);
far_void_t* far_realloc(far_void_t* memory, size_t size);
void far_free(far_void_t* memory);
size_t far_size(far_void_t* memory);
void* far_zoom(far_void_t* memory);

far_void_t* far_memcpy(far_void_t* dst, far_void_t* src, size_t size);
far_void_t* far_memset(far_void_t* dst, int data, size_t size);
void far_memget(void* dst, far_void_t* src, size_t size);
void far_memput(far_void_t* dst, void* src, size_t size);

int far_strlen(far_char_t* str);
far_char_t* far_strcpy(far_char_t* dst, far_char_t* src);
far_char_t* far_strdup(far_char_t* dst, far_char_t* src);
int far_sprintf(far_char_t* dst, char* fmt, ...);

void far_strget(char* dst, far_char_t* src);
void far_strput(far_char_t* dst, char* src);
void far_strnew(far_char_t* dst, char* src);

#endif

