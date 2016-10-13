
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

#ifndef _VKEY_H
#define _VKEY_H

#define VK_AT           0x0101
#define VK_A            0x0102
#define VK_B            0x0104
#define VK_C            0x0108
#define VK_D            0x0110
#define VK_E            0x0120
#define VK_F            0x0140
#define VK_G            0x0180

#define VK_H            0x0201
#define VK_I            0x0202
#define VK_J            0x0204
#define VK_K            0x0208
#define VK_L            0x0210
#define VK_M            0x0220
#define VK_N            0x0240
#define VK_O            0x0280

#define VK_P            0x0401
#define VK_Q            0x0402
#define VK_R            0x0404
#define VK_S            0x0408
#define VK_T            0x0410
#define VK_U            0x0420
#define VK_V            0x0440
#define VK_W            0x0480

#define VK_X            0x0801
#define VK_Y            0x0802
#define VK_Z            0x0804
#define VK_UP           0x0808
#define VK_DOWN         0x0810
#define VK_LEFT         0x0820
#define VK_RIGHT        0x0840
#define VK_SPACE        0x0880

#define VK_0            0x1001
#define VK_1            0x1002
#define VK_2            0x1004
#define VK_3            0x1008
#define VK_4            0x1010
#define VK_5            0x1020
#define VK_6            0x1040
#define VK_7            0x1080

#define VK_8            0x2001
#define VK_9            0x2002
#define VK_COLON        0x2004
#define VK_SEMI         0x2008
#define VK_COMMA        0x2010
#define VK_MINUS        0x2020
#define VK_PERIOD       0x2040
#define VK_DIVIDE       0x2080

#define VK_RETURN       0x4001
#define VK_CLEAR        0x4002
#define VK_ESCAPE       0x4004
#define VK_MENU         0x4008                      // ALT KEY
#define VK_CONTROL      0x4010
#define VK_F1           0x4020
#define VK_F2           0x4040
#define VK_SHIFT        0x4080

#define VK_SHIFT1       (VK_SHIFT|VK_1)
#define VK_SHIFT2       (VK_SHIFT|VK_2)
#define VK_SHIFT3       (VK_SHIFT|VK_3)
#define VK_SHIFT4       (VK_SHIFT|VK_4)
#define VK_SHIFT5       (VK_SHIFT|VK_5)
#define VK_SHIFT6       (VK_SHIFT|VK_6)

bool vkey_state(int vkey);

#endif

