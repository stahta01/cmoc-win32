
// Exception examples. I tried to make the exception macros as
// C++ looking as possible.

#include <stdlib.h>
#include <conio.h>
#include <exception.h>

// Exceptions work on coco,coco3 and dragon. Cooooool!

int main(void)
{
    clrscr();
    cputs("EXCEPTION EXAMPLES\n\n");

    try {
        system("OPEN\"I\",1,\"nofile\"");
    }
    except {
        cprintf("OPEN FAILED #%d\n", current_exception->errno);
    }

    try {
        system("BLA BLA BLA");
    }
    except cprintf("BLA BLA BLA FAILED. #%d\n", current_exception->errno);

    try system("?\"NO EXCEPTION HERE\"");
    except cprintf("PRINT FAILED. #%d\n", current_exception->errno);

    try system("?\"NO EXCEPTION HERE EITHER\"");
    // Must include {}, otherwise next line will be skipped if no exceptions raised.
    except {}

    try {
        exception_raise(ERRNO_FC, "RAISED EXCEPTION!");
    }
    except {
        cprintf("#%d %s\n", current_exception->errno, current_exception->what);
    }
    cputs("\nRETURN TO BASIC VIA EXCEPTION");
    //exception_raise(ERRNO_SN, 0);

    return 0;
}

