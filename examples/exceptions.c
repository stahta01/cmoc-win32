
#include <stdlib.h>
#include <conio.h>
#include <errno.h>
#include <exception.h>

// Exceptions work on coco,coco3 and dragon. Cooooool!

//#pragma options -machine=coco

int main(void)
{
    clrscr();
    cputs("EXCEPTION EXAMPLES\n\n");

    exception_t e;

    _try(&e) {
        system("OPEN\"I\",1,\"nofile\"");
    }
    _catch(&e) {
        cprintf("OPEN FAILED. #%d\n", e.code);
    }
    _try(&e) {
        system("blablabla");
    }
    _catch(&e) {
        cprintf("BLA BLA BLA FAILED. #%d\n", e.code);
    }
    cputs("\nRETURN TO BASIC\n");

    return 0;
}

