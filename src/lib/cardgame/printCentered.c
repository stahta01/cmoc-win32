
#include "_cardgame.h"

// row: Text line where to print (2nd argument to moveCursor()).
//      Must not be more than 'textScreenWidth' characters.
// Returns the text column where 'str' gets printed.
//
byte _printCentered(byte row, char* str)
{
    word len = strlen(str);
    if (len > textScreenWidth) {
        len = textScreenWidth;
    }
    byte col = (byte)(textScreenWidth - len) >> 1;
    gotoxy(0, row);
    for (byte x = 0; x < col; ++x) {
        cputc(' ');
    }
    cputs(str);
    for (byte x = col; x < BYTES_PER_SCREEN_ROW; ++x) {
        cputc(' ');
    }
    return col;
}

