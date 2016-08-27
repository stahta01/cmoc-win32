call bat\setup

set LIBDIR=..\..\..\lib\

cd startups || goto error
..\..\..\bin\cmoc2 -c -o %LIBDIR%\program_end.o program_end.c || goto error
..\..\..\bin\cmoc2 -c -o %LIBDIR%\program_start.o program_start.c || goto error
del *.c.i *.o *.asm *.asm.i
cd ..

echo DONE
pause
exit

:error
echo ERROR!
pause
exit
