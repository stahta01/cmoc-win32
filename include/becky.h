
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

#define BECKY_TIMEOUT           500

#define BECKY_STAT              (*(byte*)0xff41)
#define BECKY_BYTE              (*(byte*)0xff42)
#define BECKY_TICK              (*(word*)0x0112)

#define BECKY_NULL              0
#define BECKY_TITLE             1
#define BECKY_REQUEST           2
#define BECKY_RESPONSE          3
#define BECKY_FLUSH_SOCKET      4
#define BECKY_FLUSH_RESPONSE    5
#define BECKY_FLUSH_REQUEST     6

#define BECKY_IMAGE_WIDTH       10
#define BECKY_IMAGE_HEIGHT      11
#define BECKY_IMAGE_LOAD        12
#define BECKY_IMAGE_RESAMPLE    13
#define BECKY_IMAGE_SAVE_BMP    14
#define BECKY_IMAGE_SAVE_RAW    15

#define BECKY_FAILURE           255

bool becky_data_wait(word wait);
bool becky_data_ready(void);
bool becky_data_stop(void);

bool becky_recvbyte(byte* dst);
bool becky_recvword(word* dst);

bool becky_sendbyte(word val);
bool becky_sendword(word val);

bool becky_senddata(byte* src, size_t size);
bool becky_recvdata(byte* dst, size_t* size);

bool becky_recvstring(char* dst, size_t size);
bool becky_sendstring(char* src);
bool becky_sendrequest(char* src);

bool becky_sendbyte_wait(word val, word wait);
bool becky_sendword_wait(word val, word wait);

#endif

