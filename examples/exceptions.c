
// Exception examples. I tried to make the exception macros as
// C++ looking as possible. This example show the different
// exception structures that work. You can also use
// exception_raise() to throw an exception errno, a line value.
// This uses BASIC's error system, which displays an error message
// (based on a error number), with a line number.
// Therefore, exceptions which are not handled, will be passed
// back to BASIC.

// You can also pass a string pointer via line, but be careful
// that the address is still valid when printing. ie: stack memory.

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
        cprintf("#%d %s\n", current_exception->errno, current_exception->line);
    }
    cputs("\nRETURN TO BASIC VIA EXCEPTION");

    // Note, BASIC will show the message as the line number.
    exception_raise(ERRNO_SN, __LINE__);

    return 0;
}

