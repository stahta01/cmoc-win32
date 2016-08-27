call bat\setup

..\..\bin\cmoc2 -o ..\..\lib\libcoco.a libcoco\*.c 

del libcoco\*.c.i
del libcoco\*.o
del libcoco\*.asm
del libcoco\*.asm.i

pause
