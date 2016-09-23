
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

// http://en.cppreference.com/w/cpp/language/ascii

#ifndef _ASCII_H
#define _ASCII_H

#define ASCII_NUL   0                           // NULL
#define ASCII_SOH   1                           // START OF HEADER
#define ASCII_STX   2                           // START OF TEXT
#define ASCII_ETX   3                           // END OF TEXT
#define ASCII_EOT   4                           // END OF TRANSMISSION
#define ASCII_ENQ   5                           // ENQUIRY
#define ASCII_ACK   6                           // ACKNOWLEDGE
#define ASCII_BEL   7                           // BELL
#define ASCII_BS    8                           // BACKSPACE
#define ASCII_HT    9                           // HORIZONTAL TAB
#define ASCII_LF    10                          // LINE FEED
#define ASCII_VT    11                          // VERTICAL TAB
#define ASCII_FF    12                          // FORM FEED
#define ASCII_CR    13                          // CARRIAGE RETURN
#define ASCII_SO    14                          // SHIFT OUT
#define ASCII_SI    15                          // SHIFT IN
#define ASCII_DLE   16                          // DATA LINK ESCAPE
#define ASCII_DC1   17                          // DEVICE CONTROL 1
#define ASCII_DC2   18                          // DEVICE CONTROL 2
#define ASCII_DC3   19                          // DEVICE CONTROL 3
#define ASCII_DC4   20                          // DEVICE CONTROL 4
#define ASCII_NAK   21                          // NEGATIVE ACKNOWLEDGE
#define ASCII_SYN   22                          // SYNCHRONOUS IDLE
#define ASCII_ETB   23                          // END OF TRANSMISSION BLOCK
#define ASCII_CAN   24                          // CANCEL
#define ASCII_EM    25                          // END OF MEDIUM
#define ASCII_SUB   26                          // SUBSTITUTE
#define ASCII_ESC   27                          // ESCAPE
#define ASCII_FS    28                          // FILE SEPARATOR
#define ASCII_GS    29                          // GROUP SEPARATOR
#define ASCII_RS    30                          // RECORD SEPARATOR
#define ASCII_US    31                          // UNIT SEPARATOR
#define ASCII_SPC   32                          // SPACE
#define ASCII_DEL   127                         // DELETE

#endif

