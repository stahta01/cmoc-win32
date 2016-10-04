call bat\setup

cd %1 || goto error
..\..\..\bin\cmoc2 -o ..\..\..\lib\lib%1.a *.c || goto error
del *.c.i *.o *.asm *.asm.i
cd ..

echo DONE
pause
exit

:error
echo ERROR
pause
exit
