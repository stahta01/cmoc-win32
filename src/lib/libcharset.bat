call bat\setup

cd libcharset || goto error
..\..\..\bin\cmoc2 -o ..\..\..\lib\libcharset.a *.c || goto error
del *.c.i *.o *.asm *.asm.i
cd ..

echo DONE
pause
exit

:error

echo ERROR
pause
exit

