
#include "_conio.h"

void clearkeybuf(void)
{
    while (kbhit()) {
        getch();
    }
}

