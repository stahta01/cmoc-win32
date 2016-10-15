
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

#ifndef _BECKY_H
#define _BECKY_H

#include <sys/size.h>
#include <sys/long.h>

#define BECKY_TIMEOUT           500

#define BECKY_STAT              (*(byte*)0xff41)
#define BECKY_BYTE              (*(byte*)0xff42)
#define BECKY_TICK              (*(word*)0x0112)

#define BECKY_MAGIC             0
#define BECKY_TITLE             1
#define BECKY_ERROR             2

#define BECKY_HTTP              10
#define BECKY_READ              11
#define BECKY_WRITE             12
#define BECKY_REWIND            13
#define BECKY_REWRITE           14
#define BECKY_LOAD              15
#define BECKY_SAVE              16

#define BECKY_IMAGE_WIDTH       20
#define BECKY_IMAGE_HEIGHT      21
#define BECKY_IMAGE_LOAD        22
#define BECKY_IMAGE_RESAMPLE    23
#define BECKY_IMAGE_SAVE_RAW    25

bool becky_data_wait(word wait);
bool becky_data_ready(void);

bool becky_recv_byte(byte* dst);
bool becky_recv_word(word* dst);

bool becky_send_data(word type, byte* src, size_t size);
bool becky_send_null(word type);
bool becky_send_byte(word type, byte src);
bool becky_send_word(word type, word src);
bool becky_send_str(word type, char* src);

bool becky_recv_data(word type, byte* dst, size_t size);
bool becky_recv_str(word type, char* dst, size_t size);

extern long_t becky_result;

#endif

