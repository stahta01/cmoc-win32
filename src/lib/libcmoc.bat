call bat\setup

cd libcmoc || goto error
..\..\..\bin\cmoc2 -o ..\..\..\lib\libcmoc.a *.c || goto error
del *.c.i *.o *.asm *.asm.i
cd ..

echo DONE
pause
exit

:error

echo ERROR
pause
exit

