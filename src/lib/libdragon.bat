@echo off

cd libdragon || goto error
..\..\..\bin\cmoc2 -t dragon -o ..\..\..\lib\libdragon.a *.c || goto error
del *.c.i *.o *.asm *.asm.i
cd ..

echo DONE
pause
exit

:error

echo ERROR
pause
exit

