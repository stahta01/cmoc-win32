call bat\setup

..\..\bin\cmoc2 -Werror -o ..\..\lib\libc.a libc\*.c

del libc\*.o
del libc\*.asm
del libc\*.asm.i
del libc\*.c.i

pause

