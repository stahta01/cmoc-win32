
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

void* mallocr(size_t size)
{
    void* result = malloc(size);
    if (!result) {
        throw (ERRNO_OM, size);
    }
    return result;
}

int main(void)
{
    clrscr();
    // Example of catching bad filenames.
    try {
        cputs("TRY TO OPEN NONEXIST FILENAME\n");
        system("OPEN\"I\",1,\"nofile\"");
    }
    except {
        cprintf("OPEN FAILED #%d\n", current_exception->errno);
    }
    // Example of catching BASIC syntax errors.
    try {
        system("BLA BLA BLA");
    }
    except cprintf("BLA BLA BLA FAILED. #%d\n", current_exception->errno);
    // Example of a non-exception
    try system("?\"NO EXCEPTION HERE\"");
    except cprintf("PRINT FAILED. #%d\n", current_exception->errno);
    // Example of a non-exception with empty exception catcher
    try system("?\"NO EXCEPTION HERE EITHER\"");
    // Must include {}, otherwise next line will be skipped if no exceptions raised.
    except {}
    // Example of throwing exception with a string message
    try {
        throw (123, "RAISED EXCEPTION!");
    }
    except {
        cprintf("%s #%d\n", current_exception->line, current_exception->errno);
    }
    // Example of nested exception blocks
    try {
        cputs("OUTER TRY BLOCK\n");
        try {
            throw (ERRNO_FC, "INNER EXCEPTION");
            cputs("THIS WONT BE DISPLAYED\n");
        }
        except {
            cprintf("FIRST: #%d %s\n", current_exception->errno, current_exception->line);
            rethrow;
        }
    }
    except {
        cputs("EXCEPTION WAS RETHROWN\n");
        cprintf("SECOND: #%d %s\n", current_exception->errno, current_exception->line);
    }
    // Example of exceptions thrown from other functions, and the except/else syntax.
    void* mem;
    try {
        mem = mallocr(100);
    }
    except {
        cprintf("OUT OF MEMORY SIZE=%d", current_exception->line);
    } else {
        cprintf("FREE MEMORY SIZE=%d\n", _msize(mem));
        free(mem);
    }
    // Example of above, with a failure situation.
    try {
        mem = mallocr(20000);
    }
    except {
        cprintf("OUT OF MEMORY SIZE=%d", current_exception->line);
    } else {
        cprintf("FREE MEMORY SIZE=%d\n", _msize(mem));
        free(mem);
    }
    // Example of a non-caught exception falling back to BASIC.
    cputs("\nRETURN TO BASIC VIA EXCEPTION");

    // Note, BASIC will show the message as the line number.
    throw (ERRNO_SN, __LINE__);
    // Program wont get to return here.
    cputs("THIS WONT BE PRINTED\n");
    return 0;
}

