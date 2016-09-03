call bat\setup

cd libvarptr || goto error
..\..\..\bin\cmoc2 -o ..\..\..\lib\libvarptr.a *.c || goto error
del *.c.i *.o *.asm *.asm.i
cd ..

echo DONE
pause
exit

:error

echo ERROR
pause
exit

