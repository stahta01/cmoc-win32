
#include <conio.h>
#include <equates.h>

void clrscr(void)
{
    if (conio_bgcolor == 1) {
        asm {
            JSR_CLS
        }
    } else {
        asm {
            ldb conio_bgcolor
            JSR_CLS_B
        }
    }
}






