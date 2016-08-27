call bat\setup

..\..\bin\cmoc2 -Werror -o ..\..\lib\lib6809.a lib6809\*.c

del lib6809\*.c.i
del lib6809\*.o
del lib6809\*.asm
del lib6809\*.asm.i

pause

